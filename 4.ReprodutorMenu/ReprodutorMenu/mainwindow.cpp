#include "mainwindow.h"
#include "ui_mainwindow.h"

// Para fins de debugação
#include <QDebug>

MainWindow::MainWindow(char* argv, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , caminho(argv) // Deve ser adicionado no .h (private)
{
    ui->setupUi(this);

    /*
     *  Ainda precisa trocar para um caminho relativo :P
     *  Utilizar quando a imagem estiver melhor >.< (tamanho minimo da label = 300)
    */
    QPixmap gamellito("/home/game/Área de Trabalho/Menus/Menus-QT5/assets/gamellito.png");
    //ui->label->setPixmap(gamellito.scaled(100, 100, Qt::KeepAspectRatio);

    // Som ambiente do menu
    inicializaSomAmbiente();

    // Inicializa o video (ainda não funcionando)
    video = new QVideoWidget(this);
    player = new QMediaPlayer(video);
    playlist = new QMediaPlaylist;

    // Inicializa o arquivo de configurações
    if(!Arquivos::inicializarArquivo(QString(ARQUIVO_CONFIGURACAO))){
        QMessageBox::information(this, "Erro", "Não foi possível carregar os arquivos de inicialização. Por favor, consulte o cara da TI!");
        close();
    }

    //Conexões
    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));

    // Inicializa a primeira tela
    voltarInicio(); // Tela inicial
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ************************************************************
 * SOM AMBIENTE
 *************************************************************/

void MainWindow::inicializaSomAmbiente()
{
    som = new QSound("/home/game/Área de Trabalho/Roadmap/Roadmap/assets/funny-and-comical-melody-glide-synth-bass-and-trumpet-21398 (online-audio-converter.com).wav");
    som->setLoops(QSound::Infinite);
    ligaSomAmbiente();
}

void MainWindow::ligaSomAmbiente()
{
    ui->pushButton_som->setIcon(QIcon(":/icones/assets/som.png"));
    som->play();
    mutado = false;
}

void MainWindow::desligaSomAmbiente()
{
    ui->pushButton_som->setIcon(QIcon(":/icones/assets/sem-som.png"));
    som->stop();
    mutado = true;
}

/* ************************************************************
 * TELA INICIAL (0)
 *************************************************************/

void MainWindow::on_pushButton_som_clicked()
{
    if(mutado){
        ligaSomAmbiente();
    }else{
        desligaSomAmbiente();
    }
}

void MainWindow::voltarInicio()
{
    // Volta para a tela inicial e retorna a música
     ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_iniciar_clicked()
{
    // Vai para a tela "reprodutor" e para o som ambiente
    desligaSomAmbiente();
    iniciaVideo();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_configurar_clicked()
{
    // Vai para a tela "configurar"
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_sobre_clicked()
{
    // Vai para a tela "sobre"
    ui->stackedWidget->setCurrentIndex(1);
}

/* ************************************************************
 * TELA SOBRE (1)
 *************************************************************/

void MainWindow::on_pushButton_versao_qt_clicked()
{
    // Abre um diálogo (barra do sistema tbm)
    QMessageBox::aboutQt(this, "Sobre o Qt");
}

void MainWindow::on_pushButton_voltar_sobre_clicked()
{
    voltarInicio();
}

/* ************************************************************
 * TELA CONFIGURAR (2)
 *************************************************************/

void MainWindow::on_pushButton_voltar_configurar_clicked()
{
    voltarInicio();
}

void MainWindow::on_pushButton_adicionar_video_clicked()
{
    // Inicializa o arquivo de configurações
    if(!Arquivos::inicializarArquivo(QString(ARQUIVO_CONFIGURACAO))){
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
    QJsonArray arrayJson = Arquivos::converterJsonParaArray(QString(ARQUIVO_CONFIGURACAO));

    // Cria um novo objeto JSON para o vídeo
    QJsonObject objetoJson;
    objetoJson["id"] = arrayJson.size() + 1;
    objetoJson["tipo"] = "video";
    objetoJson["caminho"] = caminhoArquivo;

    // Adiciona no fim da lista
    arrayJson.append(objetoJson);

    Arquivos::escreverJson(QString(ARQUIVO_CONFIGURACAO), arrayJson);
}

void MainWindow::on_pushButton_adicionar_pergunta_clicked()
{
    // Vai para a tela "Adicionar pergunta"
    ui->stackedWidget->setCurrentIndex(5);
}

/* ************************************************************
 * TELA VIDEO (3)
 *************************************************************/

void MainWindow::iniciaVideo(){

    //player->setMedia(QUrl::fromLocalFile("qrc:/videos/exemplo1080.mp4"));
    player->setPlaylist(playlist);
    ui->horizontalSlider->setRange(0,player->duration()/1000);

    video->resize(600,300);
    video->setGeometry(20, 20, 640, 480);
    player->setVideoOutput(video);
    player->setMedia(QUrl("qrc:/videos/exemplo1080.mp4"));

    video->setParent(ui->stackedWidget);
    video->show();
}

void MainWindow::on_pushButton_video_tocar_clicked()
{
    estadoVideo = QMediaPlayer::PlayingState;
    player->play();
}

void MainWindow::on_pushButton_video_parar_clicked()
{
    estadoVideo = QMediaPlayer::PlayingState;
    player->stop();
}

void MainWindow::on_pushButton_video_proximo_clicked()
{
    estadoVideo = QMediaPlayer::PlayingState;
    player->stop();
    video->hide();

    ui->stackedWidget->setCurrentIndex(4);
}

/* ************************************************************
 * TELA QUESTIONARIO (4)
 *************************************************************/

void MainWindow::on_pushButton_voltar_iniciar_clicked()
{
    // Volta para a tela inicial e liga o som ambiente
     voltarInicio();
     ligaSomAmbiente();
}

void MainWindow::on_pushButton_voltar_video_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

/* ************************************************************
 * TELA ADICIONAR PERGUNTA (5)
 *************************************************************/
