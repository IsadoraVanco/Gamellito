#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Para debugar
#include <QDebug>

// Para manipular diretorios
#include <QtCore>

// Caixas de diálogo
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializa a primeira tela
    configurarTelas();

    // Tela inicial
    mostrarTela(Pagina::Inicial);

    // Verifica os arquivos de configurações
    configurarArquivoGeral();

    // Configura os perfis para selecionar
    configurarPerfis();

    // Carrega as sequências
    carregarSequencias();

    // Configura o som ambiente
    configurarSomAmbiente("assets/sons/som-ambiente.wav");
    ligarSomAmbiente();

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
 * SOM AMBIENTE DO MENU
 *************************************************************/

void MainWindow::configurarSomAmbiente(QString path)
{
    // O arquivo de som deve estar na pasta de assets!
    QDir dir = QDir::current();
    QString caminho = dir.filePath("assets/sons/som-ambiente.wav");
    somAmbiente = new QSound(QString(caminho));
    somAmbiente->setLoops(QSound::Infinite);

    //qDebug() << caminho;
}

void MainWindow::ligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/icones/som/com-som-preto.png"));
    somAmbiente->play();
    somAmbienteMutado = false;
}

void MainWindow::desligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/icones/som/sem-som-preto.png"));
    somAmbiente->stop();
    somAmbienteMutado = true;
}

/* ************************************************************
 * GERENCIAMENTO DE TELAS
 *************************************************************/

void MainWindow::mostrarTela(Pagina tipo){
    // Converte o enum para int e carrega a página
    ui->stackedWidget->setCurrentIndex(static_cast<int>(tipo));
}

void MainWindow::configurarTelas(){

    // A página de Inicio, Sobre e Configurações já estão configuradas!
    // O índice das páginas foram definidos manualmente na edição do design dos mesmos
    // Não mudar as páginas de lugar!
    // A sequência deve ser a mesma do enum Pagina

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

    // Adiciona as páginas dinamicamente, passando o index da stack e o widget a ser adicionado
    //ui->stackedWidget->insertWidget(Pagina::Configurar, widget);

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
        desligarSomAmbiente();
        carregarTelaAtual();
    }
}

void MainWindow::on_pushButton_sobre_clicked()
{
    mostrarTela(Pagina::Sobre);
}

void MainWindow::on_pushButton_som_clicked()
{
    if(somAmbienteMutado){
        ligarSomAmbiente();
    }else{
        desligarSomAmbiente();
    }
}

void MainWindow::on_pushButton_configurar_clicked()
{
    bool senhaAutenticada = autenticarSenha();

    if(senhaAutenticada){
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
    alterarSenha();
}

void MainWindow::on_pushButton_adicionar_video_clicked()
{
    // Copia um vídeo no backup
    QString nomeArquivoVideo = salvarVideoBackup();

    // Caso não tenha sido selecionado nenhum arquivo
    if(nomeArquivoVideo == ""){
        return;
    }

    // Cria a pasta de configurações caso não exista
    Arquivos::criarPasta(pastas.configuracoes);

    // Adiciona o vídeo no arquivo de sequencia
    QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

    // Adiciona o vídeo na sequência
    sequencias[perfilAtual] = Arquivos::adicionarVideo(caminho, nomeArquivoVideo);

    qDebug() << "[Main] [INFO] Vídeo adicionado na sequência";
}

void MainWindow::on_pushButton_salvar_video_clicked()
{
    salvarVideoBackup();
}

// ***** REPRODUTOR *********************************************

void MainWindow::on_pushButton_inicio_reprodutor_clicked()
{
    mostrarTela(Pagina::Inicial);
    reprodutor->pararVideo();
    ligarSomAmbiente();
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
    ligarSomAmbiente();
}

void MainWindow::on_pushButton_voltar_pergunta_clicked()
{
    mostrarTelaAnterior();
}

void MainWindow::on_pushButton_proximo_pergunta_clicked()
{
    mostrarProximaTela();
}

/* ************************************************************
 * GERENCIAMENTO DA SENHA
 *************************************************************/

bool MainWindow::ehSenhaValida(QString senha){
    return senha.length() >= tamanhoMinSenha;
}

bool MainWindow::compararSenha(QString input){
    return senhaArquivo == input;
}

bool MainWindow::autenticarSenha(){
    // A senha do arquivo estará necessariamente carregada em "senhaArquivo"!

    QString input = QInputDialog::getText(nullptr, "Autenticação", "Digite a senha para acessar as configurações:");

    bool senhaVerificada = compararSenha(input);

    // Senha não digitada ou botão "cancelar"
    if(input != "" && !senhaVerificada){
        QMessageBox::about(this, "Senha incorreta", "A senha digitada está incorrreta. Caso tenha perdido a senha, consulte o manual do programa ou entre em contato com o suporte.");
    }

    return senhaVerificada;
}

QString MainWindow::definirSenha(QString textoInicio, bool verificarTamanho){
    QString input = QInputDialog::getText(nullptr, "Definição de senha", textoInicio);

    while(!ehSenhaValida(input) && verificarTamanho){
        input = QInputDialog::getText(nullptr, "Definição de senha", QString("Senha muito curta! Utilize no mínimo %1 caracteres quaisquer").arg(tamanhoMinSenha));
    }

    if(verificarTamanho && ehSenhaValida(input)){
        QMessageBox::about(this, "Senha cadastrada", "Sua senha foi cadastrada com sucesso! Não a esqueça e não conte para ninguém :)");
    }

    return input;
}

void MainWindow::alterarSenha(){
    QString novaSenha = definirSenha("Digite sua nova senha: ", false);

    if(ehSenhaValida(novaSenha)){
        // Salva a senha no arquivo
        senhaArquivo = novaSenha;
        Arquivos::alterarSenha(novaSenha);
        QMessageBox::about(this, "Senha cadastrada", "Sua nova senha foi cadastrada com sucesso!");
    }
}

/* ************************************************************
 * GERENCIAMENTO DAS CONFIGURAÇÕES
 *************************************************************/

// ***** GERAL *********************************************

void MainWindow::criarArquivoGeral(){
    // Lê uma nova senha válida
    QString senha = definirSenha("Olá profissional! Vamos definir sua senha? Ela será necessária para as configurações do programa e para a troca de usuário", true);

    // Cria um arquivo
    if(!Arquivos::criarArquivo(QString(ARQUIVO_CONFIGURACAO_GERAL))){
        QMessageBox::critical(this, "ERRO", "Não foi possível criar um arquivo de configuração, por favor, entre em contato com o suporte");
        this->close();
        return;
    }

    // Preenche com as configs
    if(!Arquivos::preencherArquivoGeral(senha, arquivos[Perfil::Paciente], arquivos[Perfil::Responsavel], arquivos[Perfil::Profissional])){
        QMessageBox::critical(this, "ERRO", "Não foi possível preencher o arquivo de configurações iniciais. Por favor, entre em contato com o suporte");
        this->close();
        return;
    }

    QMessageBox::about(this, "Pronto :)", "Os arquivos de configuração inicial do programa foram criados. Aproveite o software! :)");

    // Carrega a nova senha do arquivo
    senhaArquivo = senha;
}

void MainWindow::configurarArquivoGeral(){
    if(!Arquivos::arquivoExiste(ARQUIVO_CONFIGURACAO_GERAL)){
        criarArquivoGeral();
    }else{
        // Carrega a senha do arquivo
        senhaArquivo = Arquivos::carregarSenha();

        qDebug() << "[Main] [INFO] Senha atual:" << senhaArquivo;

        // Caso a senha tenha sido alterada, ou houve algum erro ao carregar
        if(!ehSenhaValida(senhaArquivo)){
            senhaArquivo = definirSenha("Ops! Parece que sua senha não está definida. Por favor, defina uma nova senha: ", true);
            // Salva a senha no arquivo
            Arquivos::alterarSenha(senhaArquivo);
        }

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

        QString caminho = pastas.configuracoes + '/' + arquivos[perfilAtual].sequencia;

        if(!Arquivos::arquivoExiste(caminho)){
            // Cria um arquivo vazio para a sequência
            criarArquivoSequencia();
        }else{
            // E se o arquivo existe mas está corrompido?
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

    }
}

void MainWindow::mostrarProximaTela(){
    if(indiceAtual + 1 >= sequencias[perfilAtual].size()){
        mostrarTela(Pagina::Inicial);
        ligarSomAmbiente();
    }else{
        indiceAtual++;
        carregarTelaAtual();
    }
}

void MainWindow::mostrarTelaAnterior(){
    if(indiceAtual - 1 < 0){
        mostrarTela(Pagina::Inicial);
        ligarSomAmbiente();
    }else{
        indiceAtual--;
        carregarTelaAtual();
    }
}

void MainWindow::configurarTelaVideo(QJsonObject objetoAtual){

    QString nomeVideo = Arquivos::retornarValorChaveObjeto(objetoAtual, "caminho");

    QString caminhoVideo = "./backups/" + arquivos[perfilAtual].pasta + '/' + nomeVideo;

    reprodutor->configurarVideo(caminhoVideo);
    reprodutor->tocarVideo();
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

void MainWindow::encontrarPerfil(QString perfil){
    QString perfilCapitalizado = capitalizarTexto(perfil);

    for(const auto& item : arquivos){
        if(perfilCapitalizado == capitalizarTexto(item.second.pasta)){
            perfilAtual = item.first;
            qDebug() << "[Main] [INFO] Perfil selecionado:" << perfilCapitalizado;
            break;
        }
    }
}

void MainWindow::selecionarPerfil(QString perfil){

    encontrarPerfil(perfil);
    // Talvez haja mais coisas aqui ...
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



