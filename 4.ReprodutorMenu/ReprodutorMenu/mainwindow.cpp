#include "mainwindow.h"
#include "ui_mainwindow.h"

// Para fins de debugação
#include <QDebug>

MainWindow::MainWindow(char* argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     *  Utilizar quando a imagem estiver melhor >.< (tamanho minimo da label = 300)
    */
    //QPixmap gamellito("");
    //ui->label->setPixmap(gamellito.scaled(100, 100, Qt::KeepAspectRatio);

    // Inicializa o video (ainda não funcionando)
    videoWidget = new QVideoWidget;
    player = new QMediaPlayer;
    //playlist = new QMediaPlaylist;

    // Inicializa o arquivo de configurações gerais
    if(!Arquivos::inicializarArquivo(QString(ARQUIVO_CONFIGURACAO_GERAL))){
        QMessageBox::information(this, "Erro", "Não foi possível carregar os arquivos de inicialização. Por favor, consulte o cara da TI!");
        close();
    }

    //Conexões
    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));

    // Som ambiente do menu
    inicializarSomAmbiente();

    // Inicializa a primeira tela
    mostrarInicio(); // Tela inicial
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ************************************************************
 * SOM AMBIENTE
 *************************************************************/

void MainWindow::inicializarSomAmbiente()
{
    // O arquivo de som deve estar na pasta de assets!
    QDir dir = QDir::current();
    QString caminho = dir.filePath("assets/somAmbiente.wav");
    som = new QSound(QString(caminho));
    som->setLoops(QSound::Infinite);

    qDebug() << caminho;

    ligarSomAmbiente();
}

void MainWindow::ligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/som.png"));
    som->play();
    mutado = false;
}

void MainWindow::desligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/sem-som.png"));
    som->stop();
    mutado = true;
}

/* ************************************************************
 * SEQUÊNCIA DE VÍDEO E PERGUNTA
 *************************************************************/

void MainWindow::carregarSequencia(){

}

void MainWindow::proximoDaSequencia(){

}

void MainWindow::anteriorDaSequencia(){

}

/* ************************************************************
 * TELA INICIAL (0)
 *************************************************************/

void MainWindow::voltarInicio(){
    ligarSomAmbiente();
    mostrarInicio();
}

void MainWindow::mostrarInicio()
{
     ui->stackedWidget->setCurrentIndex(PAGINA_INICIAL);
}

void MainWindow::on_pushButton_som_clicked()
{
    if(mutado){
        ligarSomAmbiente();
    }else{
        desligarSomAmbiente();
    }
}

void MainWindow::on_pushButton_iniciar_clicked()
{
    // Desliga o som ambiente do menu
    //desligarSomAmbiente();

    // Carrega a sequência => como?
    //carregarSequencia();
    configuraVideo(QUrl::fromLocalFile("/home/game/Vídeos/videos-exemplos/exemplo720.mp4"));
    mostrarTelaVideo();
}

// Trocar para evento
void MainWindow::on_pushButton_configurar_clicked()
{
    mostrarTelaConfigurar();
}

// Trocar para evento
void MainWindow::on_pushButton_sobre_clicked()
{
    mostrarTelaSobre();
}

/* ************************************************************
 * TELA SOBRE (1)
 *************************************************************/

void MainWindow::mostrarTelaSobre()
{
    ui->stackedWidget->setCurrentIndex(PAGINA_SOBRE);
}

void MainWindow::on_pushButton_versao_qt_clicked()
{
    // Abre um diálogo (barra do sistema tbm)
    QMessageBox::aboutQt(this, "Sobre o Qt");
}

// Trocar para evento
void MainWindow::on_pushButton_voltar_sobre_clicked()
{
    voltarInicio();
}

/* ************************************************************
 * TELA CONFIGURAR (2)
 *************************************************************/

void MainWindow::mostrarTelaConfigurar()
{
    ui->stackedWidget->setCurrentIndex(PAGINA_CONFIGURAR);
}

// Trocar para evento
void MainWindow::on_pushButton_voltar_configurar_clicked()
{
    voltarInicio();
}

void MainWindow::on_pushButton_adicionar_video_clicked()
{
    // Inicializa o arquivo de configurações
    if(!Arquivos::inicializarArquivo(QString(ARQUIVO_CONFIGURACAO_GERAL))){
        QMessageBox::information(this, "Erro", "Não foi possível carregar os arquivos de inicialização. Por favor, consulte o cara da TI!");
        close();
    }

    // O usuário escolhe um vídeo
    QString caminhoArquivo = QFileDialog::getOpenFileName(this, tr("Escolha um vídeo"), tr("./"), tr("MP4 (*.mp4);; MKV (*.mkv)"));

    // Se não escolheu um arquivo
    if(caminhoArquivo.isEmpty()){
        qDebug() << "Arquivo não escolhido";
        return;
    }

    // Carrega as informações do arquivo JSON para o array
    QJsonArray arrayJson = Arquivos::converterJsonParaArray(QString(ARQUIVO_CONFIGURACAO_GERAL));

    // Cria um novo objeto JSON para o vídeo
    QJsonObject objetoJson;
    objetoJson["id"] = arrayJson.size() + 1; // Melhorar lógica para o ID
    objetoJson["tipo"] = "video";
    objetoJson["caminho"] = caminhoArquivo;

    // Adiciona no fim da lista
    arrayJson.append(objetoJson);

    Arquivos::escreverJson(QString(ARQUIVO_CONFIGURACAO_GERAL), arrayJson);
}

// Trocar para evento
void MainWindow::on_pushButton_adicionar_pergunta_clicked()
{
    mostrarTelaAdicionarPergunta();
}

/* ************************************************************
 * TELA VIDEO (3)
 *************************************************************/

void MainWindow::mostrarTelaVideo(){
    ui->stackedWidget->setCurrentIndex(PAGINA_VIDEO);
}

void MainWindow::tocarVideo(){
    // Troca o ícone do reprodutor

    //estadoVideo = QMediaPlayer::PlayingState;
    player->play();
}

void MainWindow::pararVideo(){
    // Trocar o ícone do reprodutor

    //estadoVideo = QMediaPlayer::PlayingState;
    player->stop();
}

void MainWindow::configuraVideo(QUrl pathVideo){

    player->setMedia(pathVideo);

    // Crie um QGraphicsVideoItem
    QGraphicsVideoItem* videoItem = new QGraphicsVideoItem;

    // Defina o QGraphicsVideoItem como a saída de vídeo do player
    player->setVideoOutput(videoItem);

    // Crie um QGraphicsScene e adicione o QGraphicsVideoItem a ele
    QGraphicsScene* scene = new QGraphicsScene;
    scene->addItem(videoItem);

    // Crie um VideoGraphicsView e defina a QGraphicsScene para ele
    //VideoGraphicsView* view = new VideoGraphicsView(videoItem);
    //view->setScene(scene);

    // Defina a QGraphicsScene para o seu QGraphicsView
    ui->graficosVideo->setScene(scene);

    // Defina o tamanho do QGraphicsVideoItem para o tamanho do QGraphicsView
    //videoItem->setSize(ui->graficosVideo->size());

    videoItem->setSize(QSizeF(480, 360)); // Substitua por seu tamanho desejado

    // Defina o modo de proporção
    //videoItem->setAspectRatioMode(Qt::KeepAspectRatio); // Mantém a proporção do vídeo
}

// Trocar para evento
void MainWindow::on_pushButton_video_tocar_clicked()
{
    tocarVideo();
}

// Trocar para evento
void MainWindow::on_pushButton_video_parar_clicked()
{
    pararVideo();
}

void MainWindow::on_pushButton_video_proximo_clicked()
{
    pararVideo();

    //videoWidget->hide();

    // Vai para o próximo item da sequência
    //proximoDaSequencia();

    voltarInicio();
}

/* ************************************************************
 * TELA QUESTIONARIO (4)
 *************************************************************/

void MainWindow::mostrarQuestionario(){
    ui->stackedWidget->setCurrentIndex(PAGINA_QUESTIONARIO);
}

void MainWindow::configurarPergunta()
{

}

// Trocar para evento
void MainWindow::on_pushButton_voltar_iniciar_clicked()
{
    voltarInicio();
}

// Trocar para evento
void MainWindow::on_pushButton_voltar_video_clicked()
{
    anteriorDaSequencia();
}

void MainWindow::on_radioButton_opcao1_clicked()
{

}

/* ************************************************************
 * TELA ADICIONAR PERGUNTA (5)
 *************************************************************/

void MainWindow::mostrarTelaAdicionarPergunta(){
    ui->stackedWidget->setCurrentIndex(PAGINA_ADICIONAR_PERGUNTA);
}
