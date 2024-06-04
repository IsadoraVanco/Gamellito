#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Para debugar
#include <QDebug>

// Caixas de diálogo
#include <QMessageBox>
#include <QFileDialog>


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Verifica os arquivos de configurações
    configurarArquivoGeral();

    // Configura os perfis para selecionar
    configurarPerfis();

    // Carrega as sequências
    carregarSequencias();

    // Inicializa a primeira tela
    configurarTelas();

    // Tela inicial
    mostrarTela(Pagina::Inicial);

    // Configura o som ambiente
    somAmbiente->configurar("som-ambiente.wav");
    somAmbiente->ligar();

    //Conexões
    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));
}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

MainWindow::~MainWindow()
{
    delete ui;
}

/* ************************************************************
 * GERENCIAMENTO DE TELAS
 *************************************************************/

void MainWindow::mostrarTela(Pagina tipo){
    // Converte o enum para int e carrega a página
    ui->stackedWidget->setCurrentIndex(static_cast<int>(tipo));
}

void MainWindow::configurarTelas(){

    // O índice das páginas foram definidos manualmente na edição do design dos mesmos
    // Não mudar as páginas de lugar!
    // A sequência deve ser a mesma do enum Pagina

    // icone do botão de som
    ui->pushButton_som->setIcon(QIcon("assets/icones/som/com-som-preto.png"));

    // Adiciona a imagem do menu
    QPixmap gamellito("assets/gamellito.png");
    ui->label_imagemMenu->setPixmap(gamellito);

    // Reprodutor
    if(!ui->widget_reprodutor){
        qDebug() << "[Main] [ERRO] Widget de vídeo não encontrado ou é nullptr";
        return; // Saia da função para evitar o travamento
    }else{
        qDebug() << "[Main] [OK] Widget de vídeo encontrado";

        // Verificar se o widget_reprodutor possui um layout
        if (!ui->widget_reprodutor->layout()) {
            // Se não houver layout, crie um QVBoxLayout
            QVBoxLayout *layoutReprodutor = new QVBoxLayout(ui->widget_reprodutor);
            ui->widget_reprodutor->setLayout(layoutReprodutor);
            qDebug() << "[Main] [OK] Layout para o vídeo criado";
        }

        reprodutor = new Reprodutor(ui->widget_reprodutor);
        ui->widget_reprodutor->layout()->addWidget(reprodutor);

        qDebug() << "[Main] [OK] Configuração do vídeo concluída";
    }

    //reprodutor = new Reprodutor(ui->reprodutor);
    //QVBoxLayout *layoutReprodutor = new QVBoxLayout(ui->reprodutor);
    //ui->reprodutor->setLayout(layoutReprodutor);
    //layoutReprodutor->addWidget(reprodutor);

    // Configura os RadioButtons para edição de pergunta
    QString estiloRadioButton = "QRadioButton{ color: black; }"
                                    "QRadioButton::indicator { width: 30px; height: 30px; }"
                                    "QRadioButton::indicator:checked { background-color: light-blue;}";
    ui->radioButton_opcao1->setStyleSheet(estiloRadioButton);
    ui->radioButton_opcao2->setStyleSheet(estiloRadioButton);
    ui->radioButton_opcao3->setStyleSheet(estiloRadioButton);
    ui->radioButton_opcao4->setStyleSheet(estiloRadioButton);

    // Adiciona as páginas dinamicamente, passando o index da stack e o widget a ser adicionado
    //ui->stackedWidget->insertWidget(Pagina::Configurar, widget);

}

/* ************************************************************
 * ICONES
 *************************************************************/

void MainWindow::atualizarIconeSom(){
    if(somAmbiente->estaMutado()){
        ui->pushButton_som->setIcon(QIcon("assets/icones/som/sem-som-preto.png"));
    }else{
        ui->pushButton_som->setIcon(QIcon("assets/icones/som/com-som-preto.png"));
    }
}

/* ************************************************************
 * BOTÕES E AÇÕES
 *************************************************************/

// ***** INICIAR *********************************************

void MainWindow::on_pushButton_iniciar_clicked()
{
    Arquivos::aumentarReproducoes();
    indiceAtual = 0;

    if(configurarSequenciaAtual()){
        somAmbiente->desligar();
        carregarTelaAtual();
    }
}

void MainWindow::on_pushButton_sobre_clicked()
{
    mostrarTela(Pagina::Sobre);
}

void MainWindow::on_pushButton_som_clicked()
{
    if(somAmbiente->estaMutado()){
        somAmbiente->ligar();
    }else{
        somAmbiente->desligar();
    }

    atualizarIconeSom();
}

void MainWindow::on_pushButton_configurar_clicked()
{
    if(senha->autenticarSenha()){
        mostrarTela(Pagina::Configurar);
    }
}

// ***** SOBRE *********************************************

void MainWindow::on_pushButton_voltar_sobre_clicked()
{
    mostrarTela(Pagina::Inicial);
}

// ***** CONFIGURAR *********************************************

void MainWindow::on_pushButton_voltar_configurar_clicked()
{
    mostrarTela(Pagina::Inicial);
}

void MainWindow::on_pushButton_alterar_senha_clicked()
{
    senha->alterarSenha();
}

void MainWindow::on_pushButton_adicionar_video_clicked()
{
    // Copia um vídeo no backup
    QString nomeArquivoVideo = salvarVideoBackup();

    // Caso não tenha sido selecionado nenhum arquivo ("")
    if(nomeArquivoVideo.isEmpty()){
        return;
    }

    // Cria a pasta de configurações caso não exista
    Arquivos::criarPasta(pastas.configuracoes);

    // Adiciona o vídeo no arquivo de sequencia
    QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

    // Adiciona o vídeo na sequência
    sequencias[perfilAtual] = Arquivos::adicionarVideo(caminho, nomeArquivoVideo);

    qDebug() << "[Main] [INFO] Vídeo adicionado na sequência";

    carregarListaPerfil();
}

void MainWindow::on_pushButton_adicionar_pergunta_clicked()
{
    limparCamposPergunta();
    mostrarTela(Pagina::AdicionarPergunta);
}

void MainWindow::on_pushButton_salvar_video_clicked()
{
    salvarVideoBackup();
}

void MainWindow::on_pushButton_editarItem_clicked()
{
    editarItemSelecionado();
}

void MainWindow::on_pushButton_removerItem_clicked()
{
    // Confirma se gostaria de remover
    if(ui->listWidget->currentItem() && mostrarConfirmarRemoverItem()){
        removerItemSelecionado();
    }
}


// ***** REPRODUTOR *********************************************

void MainWindow::on_pushButton_inicio_reprodutor_clicked()
{
    reprodutor->pararVideo();

    somAmbiente->ligar();
    atualizarIconeSom();

    mostrarTela(Pagina::Inicial);
}

void MainWindow::on_pushButton_voltar_reprodutor_clicked()
{
    reprodutor->pararVideo();
    mostrarTelaAnterior();
}

void MainWindow::on_pushButton_proximo_reprodutor_clicked()
{
    reprodutor->pararVideo();
    mostrarProximaTela();
}

// ***** PERGUNTA *********************************************

void MainWindow::on_pushButton_pergunta_inicio_clicked()
{
    mostrarTela(Pagina::Inicial);
    somAmbiente->ligar();
    atualizarIconeSom();
//    ligarSomAmbiente();
}

void MainWindow::on_pushButton_voltar_pergunta_clicked()
{
    mostrarTelaAnterior();
}

void MainWindow::on_pushButton_proximo_pergunta_clicked()
{
    salvarResposta();
    mostrarProximaTela();
}

// ***** ADICIONAR PERGUNTA *********************************************

void MainWindow::on_pushButton_inicial_adicionar_pergunta_clicked()
{
    if(verificarCamposPreenchidos()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::Inicial);
        }
    }else{
        mostrarTela(Pagina::Inicial);
    }
}

void MainWindow::on_pushButton_voltar_adicionar_pergunta_clicked()
{
    if(verificarCamposPreenchidos()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::Configurar);
        }
    }else{
        mostrarTela(Pagina::Configurar);
    }
}

void MainWindow::on_pushButton_salvar_pergunta_clicked()
{
    if(salvarPergunta()){
        carregarListaPerfil();
        mostrarTela(Pagina::Configurar);
    }
}

/* ************************************************************
 * GERENCIAMENTO DAS CONFIGURAÇÕES
 *************************************************************/

// ***** GERAL *********************************************

void MainWindow::criarArquivoGeral(){
    // Lê uma nova senha válida
    QString input = senha->definirSenha("Olá profissional! Vamos definir sua senha? Ela será necessária para as configurações do programa e para a troca de usuário");

    // Cria um arquivo
    if(!Arquivos::criarArquivo(QString(ARQUIVO_CONFIGURACAO_GERAL))){
        QMessageBox::critical(this, "ERRO", "Não foi possível criar um arquivo de configuração, por favor, entre em contato com o suporte");
        this->close();
        return;
    }

    // Preenche com as configs
    if(!Arquivos::preencherArquivoGeral(input, arquivos[Perfil::Paciente], arquivos[Perfil::Responsavel], arquivos[Perfil::Profissional])){
        QMessageBox::critical(this, "ERRO", "Não foi possível preencher o arquivo de configurações iniciais. Por favor, entre em contato com o suporte");
        this->close();
        return;
    }

    QMessageBox::about(this, "Pronto :)", "Os arquivos de configuração inicial do programa foram criados. Aproveite o software! :)");
}

void MainWindow::configurarArquivoGeral(){
    if(!Arquivos::arquivoExiste(ARQUIVO_CONFIGURACAO_GERAL)){
        criarArquivoGeral();
    }else{
        senha->carregarSenha();

        // Aumenta o número de "visitas"
        Arquivos::aumentarVisitas();

        // Altera a data da última visita
        Arquivos::atualizarUltimoAcesso();
    }
}

// ***** SEQUÊNCIAS *********************************************

bool MainWindow::criarArquivoSequencia(){

    QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

    // Se houver problema ao criar o arquivo
    if(!Arquivos::criarArquivo(caminho)){
        QMessageBox::critical(this, "ERRO", "O arquivo de sequência não pôde ser criado. Por favor, entre em contato com o suporte.");
        return false;
    }

    return true;
}

bool MainWindow::ehSequenciaVazia(QJsonArray sequencia){
    return sequencia.isEmpty();
}

bool MainWindow::configurarSequenciaAtual(){

    // Verifica se a sequencia está definida
    if(ehSequenciaVazia(sequencias[perfilAtual])){
        // Caso a sequência esteja corrompida, também será tratada como sequencia vazia

        QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

        if(!Arquivos::arquivoExiste(caminho)){
            // Cria um arquivo vazio para a sequência
            criarArquivoSequencia();
        }

        QMessageBox::about(this, "Sequência não definida", "A sequência de vídeos e perguntas para o perfil atual não foi definida! Por favor, acesse o menu de configurações para definir a sequência.");

        return false;
    }

    // A sequência já foi carregada no setup!
    return true;
}

void MainWindow::carregarSequencias(){

    // Adiciona os perfis para seleção (utiliza o nome das pastas capitalizado)
    for(const auto& perfil : arquivos){
        // Acessa o valor do mapeamento 'arquivos'
        structArquivos arquivo = perfil.second;

        QString caminho = pastas.configuracoes + '/' + arquivo.sequencia;

        // Carrega a sequência
        QJsonArray sequencia = Arquivos::converterJsonParaArray(caminho);

        // Atualiza o mapeamento 'sequencias' com a sequência carregada
        sequencias[perfil.first] = sequencia;
    }

    carregarListaPerfil();
}

bool MainWindow::mostrarConfirmarRemoverItem(){
    // Crie a caixa de diálogo
    QMessageBox msgBox;
    msgBox.setWindowTitle("Certeza que quer remover?");
    msgBox.setText("Tem certeza que gostaria de remover o item? A ação não poderá ser desfeita.");

    // Adicione os botões personalizados
    QPushButton *simButton = msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
    QPushButton *naoButton = msgBox.addButton(tr("Não"), QMessageBox::NoRole);

    // Defina o botão padrão (geralmente o "Não")
    msgBox.setDefaultButton(naoButton);

    // Exiba a caixa de diálogo e espere por uma resposta
    msgBox.exec();

    return msgBox.clickedButton() == simButton;
}

// ***** TELAS *********************************************

void MainWindow::carregarTelaAtual(){
    // Dá pra melhorar ... :)

    QJsonObject objetoJson = sequencias[perfilAtual][indiceAtual].toObject();

    QString tipo = Arquivos::retornarValorChaveObjeto(objetoJson, "tipo");

    if(tipo == "video"){
        mostrarTela(Pagina::Video);
        configurarTelaVideo(objetoJson);
    }else if(tipo == "pergunta"){
        configurarTelaPergunta(objetoJson);
        mostrarTela(Pagina::Pergunta);
    }
}

void MainWindow::mostrarProximaTela(){
    if(indiceAtual + 1 >= sequencias[perfilAtual].size()){
        mostrarTela(Pagina::Inicial);
        somAmbiente->ligar();
        atualizarIconeSom();
//        ligarSomAmbiente();
    }else{
        indiceAtual++;
        carregarTelaAtual();
    }
}

void MainWindow::mostrarTelaAnterior(){
    if(indiceAtual - 1 < 0){
        mostrarTela(Pagina::Inicial);
        somAmbiente->ligar();
        atualizarIconeSom();
//        ligarSomAmbiente();
    }else{
        indiceAtual--;
        carregarTelaAtual();
    }
}

void MainWindow::configurarTelaVideo(QJsonObject objetoAtual){

    QString nomeVideo = Arquivos::retornarValorChaveObjeto(objetoAtual, "caminho");

    QString caminhoVideo = pastas.backups + '/' + arquivos[perfilAtual].pasta + '/' + nomeVideo;

    reprodutor->configurarVideo(caminhoVideo);
    reprodutor->tocarVideo();
}

void MainWindow::configurarTelaPergunta(QJsonObject objetoAtual){
    // Muda as configurações da pergunta do questionário
    QString pergunta = Arquivos::retornarValorChaveObjeto(objetoAtual, "pergunta");
    ui->label_pergunta->setText(pergunta);

    // Muda as respostas
    QString opcao1 = Arquivos::retornarValorChaveObjeto(objetoAtual, "opcao1");
    ui->radioButton_resposta1->setText(opcao1);
    ui->radioButton_resposta1->setAutoExclusive(false);
    ui->radioButton_resposta1->setChecked(false);
    ui->radioButton_resposta1->setAutoExclusive(true);

    QString opcao2 = Arquivos::retornarValorChaveObjeto(objetoAtual, "opcao2");
    ui->radioButton_resposta2->setText(opcao2);
    ui->radioButton_resposta2->setAutoExclusive(false);
    ui->radioButton_resposta2->setChecked(false);
    ui->radioButton_resposta2->setAutoExclusive(true);

    QString opcao3 = Arquivos::retornarValorChaveObjeto(objetoAtual, "opcao3");
    ui->radioButton_resposta3->setText(opcao3);
    ui->radioButton_resposta3->setAutoExclusive(false);
    ui->radioButton_resposta3->setChecked(false);
    ui->radioButton_resposta3->setAutoExclusive(true);

    QString opcao4 = Arquivos::retornarValorChaveObjeto(objetoAtual, "opcao4");
    ui->radioButton_resposta4->setText(opcao4);
    ui->radioButton_resposta4->setAutoExclusive(false);
    ui->radioButton_resposta4->setChecked(false);
    ui->radioButton_resposta4->setAutoExclusive(true);
}

// ***** ADICIONAR PERGUNTA *********************************************

bool MainWindow::mostrarConfirmarSairPergunta(){
    // Crie a caixa de diálogo
    QMessageBox msgBox;
    msgBox.setWindowTitle("Certeza que quer sair?");
    msgBox.setText("Existem alterações que não foram salvas. Gostaria de sair mesmo assim?");

    // Adicione os botões personalizados
    QPushButton *simButton = msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
    QPushButton *naoButton = msgBox.addButton(tr("Não"), QMessageBox::NoRole);

    // Defina o botão padrão (geralmente o "Não")
    msgBox.setDefaultButton(naoButton);

    // Exiba a caixa de diálogo e espere por uma resposta
    msgBox.exec();

    return msgBox.clickedButton() == simButton;
}

void MainWindow::limparCamposPergunta(){
    ui->textEdit_pergunta->setText("");
    ui->textEdit_opcao1->setText("");
    ui->radioButton_opcao1->setAutoExclusive(false);
    ui->radioButton_opcao1->setChecked(false);
    ui->radioButton_opcao1->setAutoExclusive(true);

    ui->textEdit_opcao2->setText("");
    ui->radioButton_opcao2->setAutoExclusive(false);
    ui->radioButton_opcao2->setChecked(false);
    ui->radioButton_opcao2->setAutoExclusive(true);

    ui->textEdit_opcao3->setText("");
    ui->radioButton_opcao3->setAutoExclusive(false);
    ui->radioButton_opcao3->setChecked(false);
    ui->radioButton_opcao3->setAutoExclusive(true);

    ui->textEdit_opcao4->setText("");
    ui->radioButton_opcao4->setAutoExclusive(false);
    ui->radioButton_opcao4->setChecked(false);
    ui->radioButton_opcao4->setAutoExclusive(true);
}

bool MainWindow::verificarCamposPreenchidos(){
    QString pergunta = ui->textEdit_pergunta->toPlainText();
    if(pergunta != ""){
        return true;
    }

    QString opcao1 = ui->textEdit_opcao1->toPlainText();
    if(opcao1 != ""){
        return true;
    }

    QString opcao2 = ui->textEdit_opcao2->toPlainText();
    if(opcao2 != ""){
        return true;
    }

    QString opcao3 = ui->textEdit_opcao3->toPlainText();
    if(opcao3 != ""){
        return true;
    }

    QString opcao4 = ui->textEdit_opcao4->toPlainText();
    if(opcao4 != ""){
        return true;
    }

    return false;
}

bool MainWindow::verificarCamposVazios(){

    QString pergunta = ui->textEdit_pergunta->toPlainText();
    if(pergunta == ""){
        qDebug() << "[Main] [ERRO] O campo de pergunta está vazio";
        return true;
    }

    QString opcao1 = ui->textEdit_opcao1->toPlainText();
    if(opcao1 == ""){
        qDebug() << "[Main] [ERRO] O campo da opção 1 está vazio";
        return true;
    }

    QString opcao2 = ui->textEdit_opcao2->toPlainText();
    if(opcao2 == ""){
        qDebug() << "[Main] [ERRO] O campo da opção 2 está vazio";
        return true;
    }

    QString opcao3 = ui->textEdit_opcao3->toPlainText();
    if(opcao3 == ""){
        qDebug() << "[Main] [ERRO] O campo da opção 3 está vazio";
        return true;
    }

    QString opcao4 = ui->textEdit_opcao4->toPlainText();
    if(opcao4 == ""){
        qDebug() << "[Main] [ERRO] O campo da opção 4 está vazio";
        return true;
    }

    return false;
}

bool MainWindow::salvarPergunta(){
    // Verifica se todos os campos foram preenchidos
    if(verificarCamposVazios()){
        QMessageBox::about(this, "Campos vazios", "Existem campos que estão vazios. Por favor, complete-os antes de salvar.");

        return false;
    }

    // Verificar qual a correta
    int correta = 0;

    if(ui->radioButton_opcao1->isChecked()){
        correta = 1;
    }else if(ui->radioButton_opcao2->isChecked()){
        correta = 2;
    }else if(ui->radioButton_opcao3->isChecked()){
        correta = 3;
    }else if(ui->radioButton_opcao4->isChecked()){
        correta = 4;
    }

    // Cria a pasta de configurações caso não exista
    Arquivos::criarPasta(pastas.configuracoes);

    // Adiciona a pergunta no arquivo de sequencia
    QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

    QString pergunta = ui->textEdit_pergunta->toPlainText();
    QString opcao1 = ui->textEdit_opcao1->toPlainText();
    QString opcao2 = ui->textEdit_opcao2->toPlainText();
    QString opcao3 = ui->textEdit_opcao3->toPlainText();
    QString opcao4 = ui->textEdit_opcao4->toPlainText();

    sequencias[perfilAtual] = Arquivos::adicionarPergunta(caminho, pergunta, opcao1, opcao2, opcao3, opcao4, correta);

    if(ehSequenciaVazia(sequencias[perfilAtual])){
        QMessageBox::critical(this, "ERRO", "Ocorreu um erro ao salvar a pergunta. Entre em contato com o suporte.");
        return false;
    }

    QMessageBox::about(this, "Pergunta salva", "A pergunta foi salva na sequência");
    qDebug() << "[Main] [OK] Pergunta adicionada na sequência";

    return true;
}

// ***** PERGUNTA *********************************************

int MainWindow::verificarRespostaSelecionada(){
    // Verifica se alguma resposta foi selecionada
    int selecionada = 0;

    if(ui->radioButton_resposta1->isChecked()){
        selecionada = 1;
    }else if(ui->radioButton_resposta2->isChecked()){
        selecionada = 2;
    }else if(ui->radioButton_resposta3->isChecked()){
        selecionada = 3;
    }else if(ui->radioButton_resposta4->isChecked()){
        selecionada = 4;
    }

    return selecionada;
}

bool MainWindow::criarArquivoRespostas(){
    // Cria pasta de configurações
    Arquivos::criarPasta(pastas.configuracoes);

    QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].respostas;

    // Se houver problema ao criar o arquivo
    if(!Arquivos::criarArquivo(caminho)){
        QMessageBox::critical(this, "ERRO", "O arquivo de respostas não pôde ser criado. Por favor, entre em contato com o suporte.");
        return false;
    }

    return true;
}

void MainWindow::salvarResposta(){

    int selecionada = verificarRespostaSelecionada();

    if(selecionada <= 0){
        return;
    }

    // Arquivo de respostas
    QString arquivo = pastas.configuracoes + '/' + arquivos[perfilAtual].respostas;

    if(!Arquivos::arquivoExiste(arquivo)){
        // Cria um arquivo vazio para a resposta
        criarArquivoRespostas();
    }

    QJsonObject objeto = sequencias[perfilAtual][indiceAtual].toObject();

    // Salva a resposta no arquivo
    Arquivos::salvarResposta(objeto, arquivo, selecionada);

}

// ***** VIDEO *********************************************

QString MainWindow::selecionarVideo(){
    // Obtem o diretório home do usuário
    QString diretorioInicial = QDir::homePath();

    // Adiciona uma barra no final se não houver
    if (!diretorioInicial.endsWith(QDir::separator())) {
        diretorioInicial += QDir::separator();
    }

    QString caminhoArquivo = QFileDialog::getOpenFileName(this, tr("Selecione o video"), diretorioInicial, tr("MP4 (*.mp4);; MKV (*.mkv)"));

    return caminhoArquivo;
}

QString MainWindow::salvarVideoBackup(){
    // Cria pasta de backup geral
    Arquivos::criarPasta(pastas.backups);

    // Pasta do perfil
    QString pastaPerfil = pastas.backups + '/' + arquivos[perfilAtual].pasta + '/';

    // Cria pasta de backup do perfil
    Arquivos::criarPasta(pastaPerfil);

    // Seleciona o vídeo
    QString caminhoArquivo = selecionarVideo();

    // Verifica se o arquivo foi escolhido e existe
    if(caminhoArquivo == "" || !Arquivos::arquivoExiste(caminhoArquivo)){
        return QString();
    }

    // Copia o nome do arquivo
    QFileInfo arquivo(caminhoArquivo);
    QString nomeArquivo = arquivo.fileName();

    // Monta o caminho completo de destino
    QString destinoCompleto = pastaPerfil + nomeArquivo;

    if(Arquivos::copiarArquivo(caminhoArquivo, destinoCompleto)) {
        QMessageBox::about(this, "Arquivo copiado", "Arquivo copiado para o backup!");
        qDebug() << "[Main] [OK] Arquivo copiado com sucesso:" << caminhoArquivo;
    }else{
        //QMessageBox::critical(this, "ERRO", "Erro ao copiar o arquivo para o backup. Por favor, tente novamente.");
        QMessageBox::about(this, "Arquivo duplicado", "O arquivo já está no backup");
        qDebug() << "[Main] [ERRO] Falha ao copiar o arquivo:" << caminhoArquivo;
    }

    return nomeArquivo;
}

// ***** PERFIS *********************************************

QString MainWindow::capitalizarTexto(QString texto){
    return texto.left(1).toUpper() + texto.right(texto.length() - 1).toLower();
}

void MainWindow::removerItemSelecionado(){
    // Remove o item da lista de edição
    QListWidgetItem *item = ui->listWidget->currentItem();

    if(item){
        delete item;
    }

    // Procura e remove o item na lista da sequência real
}

void MainWindow::editarItemSelecionado(){
    // Edita o item da lista de edição
    QListWidgetItem *item = ui->listWidget->currentItem();

    if(item){

        // Edita o item da lista

        // Edita do JSON
    }
}

void MainWindow::carregarListaPerfil(){
    // Limpa a lista
    ui->listWidget->clear();

    QJsonArray array = sequencias[perfilAtual];

    for(int i = 0; i < array.size(); i++){
        QJsonObject objetoJson = array[i].toObject();

        QString tipo = Arquivos::retornarValorChaveObjeto(objetoJson, "tipo");

        QListWidgetItem *item = new QListWidgetItem();

        if(tipo == "video"){
            QString caminho = Arquivos::retornarValorChaveObjeto(objetoJson, "caminho");
            item->setText(caminho);
            qDebug() << "Video na lista";
        }else if(tipo == "pergunta"){
            QString pergunta = Arquivos::retornarValorChaveObjeto(objetoJson, "pergunta");
            item->setText(pergunta);
            qDebug() << "Pergunta na lista";
        }

        ui->listWidget->addItem(item);
    }
}

void MainWindow::selecionarPerfil(QString perfil){

    QString perfilCapitalizado = capitalizarTexto(perfil);

    for(const auto& item : arquivos){
        if(perfilCapitalizado == capitalizarTexto(item.second.pasta)){
            // Atualiza o perfil atual
            perfilAtual = item.first;

            // Carrega a sequência na lista de itens aparentes
            carregarListaPerfil();

            qDebug() << "[Main] [INFO] Perfil selecionado:" << perfilCapitalizado;

            break;
        }
    }
}

void MainWindow::configurarPerfis(){

    // Adiciona os perfis para seleção (utiliza o nome das pastas capitalizado)
    for(const auto& item : arquivos){
        structArquivos dadosArquivos = item.second;
        QString nome = dadosArquivos.pasta;

        // Transforma em um texto capitalizado
        QString nomecapitalizado = capitalizarTexto(nome);

        ui->comboBox_perfis->addItem(nomecapitalizado);
    }

    // Evento para quando selecionar outro perfil
    QObject::connect(ui->comboBox_perfis, QOverload<int>::of(&QComboBox::currentIndexChanged),
                         [&](int index) {
                            selecionarPerfil(ui->comboBox_perfis->itemText(index));
                         });
}
