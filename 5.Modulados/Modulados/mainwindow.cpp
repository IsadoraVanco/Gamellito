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

    // Verifica o arquivo de configurações gerais
    configurarArquivoGeral();

    // Faz a configuração dos atributos dos perfis
    configurarPerfis();

    // Configura os perfis para selecionar no widget
    adicionarPerfisParaSelecao();

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

    // Reseta o ultimo botão apertado nas perguntas
    ultimoApertado = nullptr;
}

void MainWindow::configurarTelas(){

    // O índice das páginas foram definidos manualmente na edição do design dos mesmos
    // Não mudar as páginas de lugar!
    // A sequência deve ser a mesma do enum Pagina

    // icone do botão de som
    atualizarIconeSom();

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
 * GERENCIAMENTO DAS CONFIGURAÇÕES
 *************************************************************/

// ***** GERAL *********************************************

void MainWindow::configurarArquivoGeral(){
    if(!Arquivos::arquivoExiste(ARQUIVO_CONFIGURACAO_GERAL)){
        // Lê uma nova senha válida
        QString input = senha->definirSenha("Olá profissional! Vamos definir sua senha? Ela será necessária para as configurações do programa e para a troca de usuário");

        bool ok = arquivos->criarArquivoGeral(input);

        if(!ok){
            QMessageBox::critical(this, "ERRO", "Não foi possível preencher o arquivo de configurações iniciais. Por favor, entre em contato com o suporte");
            this->close();
            return;
        }else{
            QMessageBox::about(this, "Pronto :)", "Os arquivos de configuração inicial do programa foram criados. Aproveite o software! :)");
        }
    }else{
        senha->carregarSenha();

        // Aumenta o número de "visitas"
        Arquivos::aumentarVisitas();

        // Altera a data da última visita
        Arquivos::atualizarUltimoAcesso();
    }
}

// ***** SEQUÊNCIAS *********************************************

void MainWindow::carregarSequencias(){

    // Adiciona os perfis para seleção
    for(const auto& user : perfis){
        TipoPerfil perfil = user.first;

        // Carrega a sequência
        perfis[perfil]->carregarSequencia();
    }

    carregarListaPerfilAtual();
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

void MainWindow::removerItemSelecionado(){
    // Remove o item da lista de edição
    QListWidgetItem *item = ui->listWidget->currentItem();

    if(item){

        // Obtém o índice do item selecionado na lista do widget
        int index = ui->listWidget->row(item);

        // Remove o item na lista da sequência real
        perfis[perfilAtual]->sequencia->removerItem(index);

        // Atualiza a lista do widget
        delete item;

        // Atualiza o arquivo
        arquivos->salvarSequenciaNoArquivo(perfis[perfilAtual]->sequencia->getSequencia(), perfis[perfilAtual]->arquivos.sequencia);
    }
}

void MainWindow::editarItemSelecionado(){

    // Edita o item da lista de edição
    QListWidgetItem *item = ui->listWidget->currentItem();

    if(item){

        // Obtém o índice do item selecionado na lista do widget
        int index = ui->listWidget->row(item);

        // Analisa se é vídeo ou pergunta
        TipoItem tipo = perfis[perfilAtual]->sequencia->tipoItem(index);

        if(tipo == TipoItem::Video){
            // Copia um vídeo no backup
            QString nomeArquivoVideo = arquivos->salvarVideoBackup(perfis[perfilAtual]->arquivos.pasta);

            // Caso não tenha sido selecionado nenhum arquivo ("")
            if(nomeArquivoVideo.isEmpty()){
                return;
            }

            // Adiciona o vídeo na sequência
            perfis[perfilAtual]->sequencia->editarVideo(index, nomeArquivoVideo);

            // Atualiza a sequência no arquivo
            arquivos->salvarSequenciaNoArquivo(perfis[perfilAtual]->sequencia->getSequencia(), perfis[perfilAtual]->arquivos.sequencia);

            // Recarrega a lista no widget
            carregarListaPerfilAtual();

        }else if(tipo == TipoItem::Pergunta){

            // Carrega a pergunta existente na tela
            carregarEdicaoPergunta();

            // Mostra a tela de pergunta
            mostrarTela(Pagina::EditarPergunta);
        }
    }
}

// ***** TELAS *********************************************

void MainWindow::carregarTelaAtual(){

    QJsonObject objetoJson = perfis[perfilAtual]->sequencia->getItemNoIndexAtual();

    TipoItem tipo = perfis[perfilAtual]->sequencia->tipoItemNoIndexAtual();

    if(tipo == TipoItem::Video){
        mostrarTela(Pagina::Video);
        configurarTelaVideo(objetoJson);
    }else if(tipo == TipoItem::Pergunta){
        configurarTelaPergunta(objetoJson);
        mostrarTela(Pagina::Pergunta);
    }
}

void MainWindow::mostrarProximaTela(){
    if(perfis[perfilAtual]->sequencia->proximoIndice()){
        carregarTelaAtual();
    }else{
        somAmbiente->ligar();
        atualizarIconeSom();

        mostrarTela(Pagina::Inicial);
    }
}

void MainWindow::mostrarTelaAnterior(){
    if(perfis[perfilAtual]->sequencia->indiceAnterior()){
        carregarTelaAtual();
    }else{
        somAmbiente->ligar();
        atualizarIconeSom();

        mostrarTela(Pagina::Inicial);
    }
}

void MainWindow::configurarTelaVideo(QJsonObject objetoAtual){

    QString nomeVideo = perfis[perfilAtual]->sequencia->valorItemNoIndexAtual();

    // Reproduz o video que está no backup do perfil
    QString caminhoVideo = arquivos->pastas.backups + '/' + perfis[perfilAtual]->arquivos.pasta + '/' + nomeVideo;

    reprodutor->configurarVideo(caminhoVideo);
    reprodutor->tocarVideo();
}

void MainWindow::configurarTelaPergunta(QJsonObject objetoAtual){
    // Muda as configurações da pergunta do questionário
    QString pergunta = perfis[perfilAtual]->sequencia->getPerguntaNoIndiceAtual();
    ui->label_pergunta->setText(pergunta);

    // Muda as respostas
    QString opcao1 = perfis[perfilAtual]->sequencia->getOpcao1NoIndiceAtual();
    ui->radioButton_resposta1->setText(opcao1);
    ui->radioButton_resposta1->setAutoExclusive(false);
    ui->radioButton_resposta1->setChecked(false);
    ui->radioButton_resposta1->setAutoExclusive(true);

    QString opcao2 = perfis[perfilAtual]->sequencia->getOpcao2NoIndiceAtual();
    ui->radioButton_resposta2->setText(opcao2);
    ui->radioButton_resposta2->setAutoExclusive(false);
    ui->radioButton_resposta2->setChecked(false);
    ui->radioButton_resposta2->setAutoExclusive(true);

    QString opcao3 = perfis[perfilAtual]->sequencia->getOpcao3NoIndiceAtual();
    ui->radioButton_resposta3->setText(opcao3);
    ui->radioButton_resposta3->setAutoExclusive(false);
    ui->radioButton_resposta3->setChecked(false);
    ui->radioButton_resposta3->setAutoExclusive(true);

    QString opcao4 = perfis[perfilAtual]->sequencia->getOpcao4NoIndiceAtual();
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

bool MainWindow::todosCamposPreenchidos(){
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

bool MainWindow::existemCamposVazios(){

    QString pergunta = ui->textEdit_pergunta->toPlainText();
    if(pergunta == ""){
        qDebug() << "[Main][ERRO] O campo de pergunta está vazio";
        return true;
    }

    QString opcao1 = ui->textEdit_opcao1->toPlainText();
    if(opcao1 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 1 está vazio";
        return true;
    }

    QString opcao2 = ui->textEdit_opcao2->toPlainText();
    if(opcao2 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 2 está vazio";
        return true;
    }

    QString opcao3 = ui->textEdit_opcao3->toPlainText();
    if(opcao3 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 3 está vazio";
        return true;
    }

    QString opcao4 = ui->textEdit_opcao4->toPlainText();
    if(opcao4 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 4 está vazio";
        return true;
    }

    return false;
}

bool MainWindow::salvarNovaPergunta(){

    // Verifica se todos os campos foram preenchidos
    if(existemCamposVazios()){
        QMessageBox::about(this, "Campos vazios", "Existem campos que estão vazios. Por favor, complete-os antes de salvar.");

        return false;
    }

    // Converte textos
    QString pergunta = ui->textEdit_pergunta->toPlainText();
    QString opcao1 = ui->textEdit_opcao1->toPlainText();
    QString opcao2 = ui->textEdit_opcao2->toPlainText();
    QString opcao3 = ui->textEdit_opcao3->toPlainText();
    QString opcao4 = ui->textEdit_opcao4->toPlainText();

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

    // Adiciona a pergunta na sequência
    perfis[perfilAtual]->sequencia->adicionarPergunta(pergunta, opcao1, opcao2, opcao3, opcao4, correta);

    // Atualiza a sequência no arquivo
    arquivos->salvarSequenciaNoArquivo(perfis[perfilAtual]->sequencia->getSequencia(), perfis[perfilAtual]->arquivos.sequencia);

    // Recarrega a lista do widget
    carregarListaPerfilAtual();

    QMessageBox::about(this, "Pergunta salva", "A pergunta foi salva na sequência");
    qDebug() << "[Main][OK] Pergunta adicionada na sequência";

    return true;
}

// ***** EDITAR PERGUNTA *********************************************

void MainWindow::carregarEdicaoPergunta(){

    QListWidgetItem *item = ui->listWidget->currentItem();

    // Obtém o índice do item selecionado na lista do widget
    int index = ui->listWidget->row(item);

    // Carrega as infos da pergunta
    QString pergunta = perfis[perfilAtual]->sequencia->getPergunta(index);
    QString opcao1 = perfis[perfilAtual]->sequencia->getOpcao1(index);
    QString opcao2 = perfis[perfilAtual]->sequencia->getOpcao2(index);
    QString opcao3 = perfis[perfilAtual]->sequencia->getOpcao3(index);
    QString opcao4 = perfis[perfilAtual]->sequencia->getOpcao4(index);
    int correta = perfis[perfilAtual]->sequencia->getRespostaCorreta(index);

    // Coloca na página de edição
    ui->textEdit_editar_pergunta->setText(pergunta);
    ui->textEdit_editar_opcao1->setText(opcao1);
    ui->textEdit_editar_opcao2->setText(opcao2);
    ui->textEdit_editar_opcao3->setText(opcao3);
    ui->textEdit_editar_opcao4->setText(opcao4);

    // Analisa qual a correta
    switch(correta){
    case 1:
        ui->radioButton_editar_opcao1->setChecked(true);
        break;

    case 2:
        ui->radioButton_editar_opcao2->setChecked(true);
        break;

    case 3:
        ui->radioButton_editar_opcao3->setChecked(true);
        break;

    case 4:
        ui->radioButton_editar_opcao4->setChecked(true);
        break;

    default:
        break;
    }
}

bool MainWindow::salvarPerguntaEditada(){

    // Verifica se todos os campos foram preenchidos
    if(existemCamposVaziosEditada()){
        QMessageBox::about(this, "Campos vazios", "Existem campos que estão vazios. Por favor, complete-os antes de salvar.");
        return false;
    }

    // Converte textos
    QString pergunta = ui->textEdit_editar_pergunta->toPlainText();
    QString opcao1 = ui->textEdit_editar_opcao1->toPlainText();
    QString opcao2 = ui->textEdit_editar_opcao2->toPlainText();
    QString opcao3 = ui->textEdit_editar_opcao3->toPlainText();
    QString opcao4 = ui->textEdit_editar_opcao4->toPlainText();

    // Verificar qual a correta
    int correta = 0;

    if(ui->radioButton_editar_opcao1->isChecked()){
        correta = 1;
    }else if(ui->radioButton_editar_opcao2->isChecked()){
        correta = 2;
    }else if(ui->radioButton_editar_opcao3->isChecked()){
        correta = 3;
    }else if(ui->radioButton_editar_opcao4->isChecked()){
        correta = 4;
    }

    // Obtém o índice do item selecionado na lista do widget
    QListWidgetItem *item = ui->listWidget->currentItem();
    int index = ui->listWidget->row(item);

    // Edita a pergunta na sequência
    perfis[perfilAtual]->sequencia->editarPergunta(index, pergunta, opcao1, opcao2, opcao3, opcao4, correta);

    // Atualiza a sequência no arquivo
    arquivos->salvarSequenciaNoArquivo(perfis[perfilAtual]->sequencia->getSequencia(), perfis[perfilAtual]->arquivos.sequencia);

    // Recarrega a lista do widget
    carregarListaPerfilAtual();

    QMessageBox::about(this, "Pergunta salva", "A pergunta foi editada com sucesso");
    qDebug() << "[Main][OK] Pergunta editada na sequência";

    return true;
}

bool MainWindow::todosCamposPreenchidosEditada(){
    QString pergunta = ui->textEdit_editar_pergunta->toPlainText();
    if(pergunta != ""){
        return true;
    }

    QString opcao1 = ui->textEdit_editar_opcao1->toPlainText();
    if(opcao1 != ""){
        return true;
    }

    QString opcao2 = ui->textEdit_editar_opcao2->toPlainText();
    if(opcao2 != ""){
        return true;
    }

    QString opcao3 = ui->textEdit_editar_opcao3->toPlainText();
    if(opcao3 != ""){
        return true;
    }

    QString opcao4 = ui->textEdit_editar_opcao4->toPlainText();
    if(opcao4 != ""){
        return true;
    }

    return false;
}

bool MainWindow::existemCamposVaziosEditada(){

    QString pergunta = ui->textEdit_editar_pergunta->toPlainText();
    if(pergunta == ""){
        qDebug() << "[Main][ERRO] O campo de pergunta editada está vazio";
        return true;
    }

    QString opcao1 = ui->textEdit_editar_opcao1->toPlainText();
    if(opcao1 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 1 editada está vazio";
        return true;
    }

    QString opcao2 = ui->textEdit_editar_opcao2->toPlainText();
    if(opcao2 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 2 editada está vazio";
        return true;
    }

    QString opcao3 = ui->textEdit_editar_opcao3->toPlainText();
    if(opcao3 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 3 editada está vazio";
        return true;
    }

    QString opcao4 = ui->textEdit_editar_opcao4->toPlainText();
    if(opcao4 == ""){
        qDebug() << "[Main][ERRO] O campo da opção 4 editada está vazio";
        return true;
    }

    return false;
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

void MainWindow::salvarResposta(){

    int selecionada = verificarRespostaSelecionada();

    if(selecionada <= 0){
        return;
    }

    // Salva a resposta no arquivo
    arquivos->salvarResposta(perfis[perfilAtual]->sequencia->getItemNoIndexAtual(), selecionada, perfis[perfilAtual]->arquivos.respostas);
}

// ***** PERFIS *********************************************

void MainWindow::configurarPerfis(){

    // Configurando o nome de cada arquivo para os perfis
    paciente->nome = "Paciente";
    paciente->arquivos.pasta = "paciente";
    paciente->arquivos.respostas = "respostasPaciente.json";
    paciente->arquivos.sequencia = "sequenciaPaciente.json";

    responsavel->nome = "Responsável";
    responsavel->arquivos.pasta = "responsavel";
    responsavel->arquivos.respostas = "respostasResponsavel.json";
    responsavel->arquivos.sequencia = "sequenciaResponsavel.json";

    profissional->nome = "Profissional";
    profissional->arquivos.pasta = "profissional";
    profissional->arquivos.respostas = "respostasProfissional.json";
    profissional->arquivos.sequencia = "sequenciaProfissional.json";

    // Carrega a sequência de cada perfil
    carregarSequencias();
}

void MainWindow::carregarListaPerfilAtual(){
    // Limpa a lista do widget
    ui->listWidget->clear();

    Perfil *perfil = perfis[perfilAtual];
    int tamanho = perfil->sequencia->tamanho();

    for(int i = 0; i < tamanho; i++){

        QListWidgetItem *item = new QListWidgetItem();

        QString texto = perfil->sequencia->valorItem(i);

        item->setText(texto);
        ui->listWidget->addItem(item);
    }
}

void MainWindow::selecionarPerfil(QString nomePerfil){
    // Percorre o mapeamento procurando o perfil selecionado
    for(const auto& user : perfis){
        Perfil *perfil = user.second;
        QString nome = perfil->nome;

        if(nomePerfil == nome){
            // Atualiza o perfil atual
            perfilAtual = user.first;

            // Carrega a sequência na lista de itens aparentes
            carregarListaPerfilAtual();

            qDebug() << "[Main][INFO] Perfil selecionado:" << nomePerfil;

            break;
        }
    }
}

void MainWindow::adicionarPerfisParaSelecao(){
    // Percorre todo o mapeamento adicionando os perfis no widget
    for(const auto& user : perfis){
        Perfil *perfil = user.second;

        QString nome = perfil->nome;

        ui->comboBox_perfis->addItem(nome);
    }

    // Evento para quando selecionar outro perfil
    QObject::connect(ui->comboBox_perfis, QOverload<int>::of(&QComboBox::currentIndexChanged),
                         [&](int index) {
                            selecionarPerfil(ui->comboBox_perfis->itemText(index));
                         });
}

/* ************************************************************
 * BOTÕES E AÇÕES
 *************************************************************/

// ***** INICIAR *********************************************

void MainWindow::on_pushButton_iniciar_clicked()
{
    Arquivos::aumentarReproducoes();

    perfis[perfilAtual]->sequencia->resetarIndice();

    if(perfis[perfilAtual]->sequencia->estaVazia()){
        // Exibe mensagem de erro
        QMessageBox::about(this, "Sequência não definida", "A sequência de vídeos e perguntas para o perfil atual não foi definida! Por favor, acesse o menu de configurações para definir a sequência.");
    }else{
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
    mostrarTela(Pagina::Configurar);
}

// ***** CONFIGURAR *********************************************

void MainWindow::on_pushButton_configurar_perfil_clicked()
{
    mostrarTela(Pagina::ConfigurarPerfil);
}

// ***** CONFIGURAR PERFIL *********************************************

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
    QString nomeArquivoVideo = arquivos->salvarVideoBackup(perfis[perfilAtual]->arquivos.pasta);

    // Caso não tenha sido selecionado nenhum arquivo ("")
    if(nomeArquivoVideo.isEmpty()){
        return;
    }

    // Adiciona o vídeo na sequência
    perfis[perfilAtual]->sequencia->adicionarVideo(nomeArquivoVideo);

    // Atualiza a sequência no arquivo
    arquivos->salvarSequenciaNoArquivo(perfis[perfilAtual]->sequencia->getSequencia(), perfis[perfilAtual]->arquivos.sequencia);

    // Recarrega a lista no widget
    carregarListaPerfilAtual();

    qDebug() << "[Main][INFO] Vídeo adicionado na sequência:" << nomeArquivoVideo;
}

void MainWindow::on_pushButton_adicionar_pergunta_clicked()
{
    limparCamposPergunta();
    mostrarTela(Pagina::AdicionarPergunta);
}

void MainWindow::on_pushButton_salvar_video_clicked()
{
    arquivos->salvarVideoBackup(perfis[perfilAtual]->arquivos.pasta);
}

void MainWindow::on_pushButton_editarItem_clicked()
{
    if(ui->listWidget->currentItem()){
        editarItemSelecionado();
    }
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
}

void MainWindow::on_pushButton_voltar_pergunta_clicked()
{
    // Reseta o ultimo botão apertado nas perguntas
    ultimoApertado = nullptr;

    mostrarTelaAnterior();
}

void MainWindow::on_pushButton_proximo_pergunta_clicked()
{
    salvarResposta();
    mostrarProximaTela();

    // Reseta o ultimo botão apertado nas perguntas
    ultimoApertado = nullptr;
}

void MainWindow::on_radioButton_resposta1_clicked()
{
    if(ultimoApertado == ui->radioButton_resposta1){
        ui->radioButton_resposta1->setAutoExclusive(false);
        ui->radioButton_resposta1->setChecked(false);
        ui->radioButton_resposta1->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_resposta1;
    }
}

void MainWindow::on_radioButton_resposta2_clicked()
{
    if(ultimoApertado == ui->radioButton_resposta2){
        ui->radioButton_resposta2->setAutoExclusive(false);
        ui->radioButton_resposta2->setChecked(false);
        ui->radioButton_resposta2->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_resposta2;
    }
}

void MainWindow::on_radioButton_resposta3_clicked()
{
    if(ultimoApertado == ui->radioButton_resposta3){
        ui->radioButton_resposta3->setAutoExclusive(false);
        ui->radioButton_resposta3->setChecked(false);
        ui->radioButton_resposta3->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_resposta3;
    }
}

void MainWindow::on_radioButton_resposta4_clicked()
{
    if(ultimoApertado == ui->radioButton_resposta4){
        ui->radioButton_resposta4->setAutoExclusive(false);
        ui->radioButton_resposta4->setChecked(false);
        ui->radioButton_resposta4->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_resposta4;
    }
}

// ***** ADICIONAR PERGUNTA *********************************************

void MainWindow::on_pushButton_inicial_adicionar_pergunta_clicked()
{
    if(todosCamposPreenchidos()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::Inicial);
        }
    }else{
        mostrarTela(Pagina::Inicial);
    }
}

void MainWindow::on_pushButton_voltar_adicionar_pergunta_clicked()
{
    if(todosCamposPreenchidos()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::ConfigurarPerfil);
        }
    }else{
        mostrarTela(Pagina::ConfigurarPerfil);
    }
}

void MainWindow::on_pushButton_salvar_pergunta_clicked()
{
    if(salvarNovaPergunta()){
        carregarListaPerfilAtual();
        mostrarTela(Pagina::ConfigurarPerfil);
    }
}

void MainWindow::on_radioButton_opcao1_clicked()
{
    if(ultimoApertado == ui->radioButton_opcao1){
        ui->radioButton_opcao1->setAutoExclusive(false);
        ui->radioButton_opcao1->setChecked(false);
        ui->radioButton_opcao1->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_opcao1;
    }
}

void MainWindow::on_radioButton_opcao2_clicked()
{
    if(ultimoApertado == ui->radioButton_opcao2){
        ui->radioButton_opcao2->setAutoExclusive(false);
        ui->radioButton_opcao2->setChecked(false);
        ui->radioButton_opcao2->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_opcao2;
    }
}

void MainWindow::on_radioButton_opcao3_clicked()
{
    if(ultimoApertado == ui->radioButton_opcao3){
        ui->radioButton_opcao3->setAutoExclusive(false);
        ui->radioButton_opcao3->setChecked(false);
        ui->radioButton_opcao3->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_opcao3;
    }
}

void MainWindow::on_radioButton_opcao4_clicked()
{
    if(ultimoApertado == ui->radioButton_opcao4){
        ui->radioButton_opcao4->setAutoExclusive(false);
        ui->radioButton_opcao4->setChecked(false);
        ui->radioButton_opcao4->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_opcao4;
    }
}

// ***** EDITAR PERGUNTA *********************************************

void MainWindow::on_pushButton_inicial_editar_pergunta_clicked()
{
    if(todosCamposPreenchidosEditada()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::Inicial);
        }
    }else{
        mostrarTela(Pagina::Inicial);
    }
}

void MainWindow::on_pushButton_voltar_editar_pergunta_clicked()
{
    if(todosCamposPreenchidos()){
        if(mostrarConfirmarSairPergunta()){
            mostrarTela(Pagina::ConfigurarPerfil);
        }
    }else{
        mostrarTela(Pagina::ConfigurarPerfil);
    }
}

void MainWindow::on_pushButton_salvar_pergunta_editada_clicked()
{
    if(salvarPerguntaEditada()){
        carregarListaPerfilAtual();
        mostrarTela(Pagina::ConfigurarPerfil);
    }
}

void MainWindow::on_radioButton_editar_opcao1_clicked()
{
    if(ultimoApertado == ui->radioButton_editar_opcao1){
        ui->radioButton_editar_opcao1->setAutoExclusive(false);
        ui->radioButton_editar_opcao1->setChecked(false);
        ui->radioButton_editar_opcao1->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_editar_opcao1;
    }
}

void MainWindow::on_radioButton_editar_opcao2_clicked()
{
    if(ultimoApertado == ui->radioButton_editar_opcao2){
        ui->radioButton_editar_opcao2->setAutoExclusive(false);
        ui->radioButton_editar_opcao2->setChecked(false);
        ui->radioButton_editar_opcao2->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_editar_opcao2;
    }
}

void MainWindow::on_radioButton_editar_opcao3_clicked()
{
    if(ultimoApertado == ui->radioButton_editar_opcao3){
        ui->radioButton_editar_opcao3->setAutoExclusive(false);
        ui->radioButton_editar_opcao3->setChecked(false);
        ui->radioButton_editar_opcao3->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_editar_opcao3;
    }
}

void MainWindow::on_radioButton_editar_opcao4_clicked()
{
    if(ultimoApertado == ui->radioButton_editar_opcao4){
        ui->radioButton_editar_opcao4->setAutoExclusive(false);
        ui->radioButton_editar_opcao4->setChecked(false);
        ui->radioButton_editar_opcao4->setAutoExclusive(true);
        ultimoApertado = nullptr;
    }else{
        ultimoApertado = ui->radioButton_editar_opcao4;
    }
}
