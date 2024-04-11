#include "reprodutor.h"
#include "ui_reprodutor.h"

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

}

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
    }
}


void Reprodutor::pararVideo(){
    if(!videoParado){
        // Trocar o ícone do reprodutor

        player->pause();
        videoParado = true;
    }
}

void Reprodutor::configurarVideo(QUrl pathVideo){

    player = new QMediaPlayer;

    player->setMedia(pathVideo);

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

    //videoItem->setSize(QSizeF(480, 360)); // Substitua por seu tamanho desejado

    qDebug() << "Configuração pronta";
}
