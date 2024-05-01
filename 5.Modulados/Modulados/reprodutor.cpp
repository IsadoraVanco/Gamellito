#include "reprodutor.h"
#include "ui_reprodutor.h"


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Reprodutor::Reprodutor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reprodutor)
{
    ui->setupUi(this);

    // Conexões
    //connect(ui->pushButton_video_tocar, &QPushButton::clicked, player, &QMediaPlayer::play);
    //connect(ui->pushButton_video_parar, &QPushButton::clicked, player, &QMediaPlayer::pause);

    //connect(ui->pushButton_video_parar, &QPushButton::clicked, this, SLOT(pararVideo()));
    //connect(ui->pushButton_video_tocar, &QPushButton::clicked, this, SLOT(tocarVideo()));

    // Conectar o sinal mediaStatusChanged() para uma função de tratamento
    //connect(player, &QMediaPlayer::mediaStatusChanged, this, &Reprodutor::verificarStatusMedia);

}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Reprodutor::~Reprodutor()
{
    delete ui;
}

/* ************************************************************
 * REPRODUÇÃO DO VÍDEO
 *************************************************************/

void Reprodutor::tocarVideo(){
    if(videoParado){
        // Troca o ícone do reprodutor

        player->play();
        videoParado = false;

        qDebug() << "[Reprodutor] [INFO] Video tocando";
    }
}

void Reprodutor::pararVideo(){
    if(!videoParado){
        // Trocar o ícone do reprodutor

        player->pause();
        videoParado = true;

        qDebug() << "[Reprodutor] [INFO] Video parado";
    }
}

void Reprodutor::configurarVideo(QString caminhoVideo){

    // Obter o caminho absoluto do arquivo
    QString caminhoAbsoluto = QFileInfo(caminhoVideo).absoluteFilePath();

    // Criar a URL a partir do caminho absoluto
    QUrl url = QUrl::fromLocalFile(caminhoAbsoluto);

    player = new QMediaPlayer;

    player->setMedia(url);

    // Crie um QGraphicsVideoItem
    videoItem = new QGraphicsVideoItem;

    // Defina o QGraphicsVideoItem como a saída de vídeo do player
    player->setVideoOutput(videoItem);

    // Crie um QGraphicsScene e adicione o QGraphicsVideoItem a ele
    scene = new QGraphicsScene;
    scene->addItem(videoItem);

    // Defina a QGraphicsScene para o seu QGraphicsView
    ui->graficosVideo->setScene(scene);

    // Defina o tamanho do QGraphicsVideoItem para o tamanho do QGraphicsView
    videoItem->setSize(ui->graficosVideo->size());

    qDebug() << "[Reprodutor] [INFO] Tamanho da janela " << ui->graficosVideo->height() << ui->graficosVideo->width();

    ui->graficosVideo->viewport()->update();

    qDebug() << "[Reprodutor] [INFO] Configuração pronta para " << caminhoVideo;
}

/* ************************************************************
 * AÇÕES
 *************************************************************/

void Reprodutor::on_pushButton_video_tocar_clicked()
{
    if(videoParado){
        tocarVideo();
    }else{
        pararVideo();
    }
}
