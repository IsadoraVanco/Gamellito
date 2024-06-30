#include "video.h"
#include "ui_video.h"


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Video::Video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Video::mudarStatus);
}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Video::~Video()
{
    delete ui;
    delete player;
    delete videoItem;
    delete scene;
}

/* ************************************************************
 * CONFIGURAÇÃO
 *************************************************************/

void Video::mudarStatus(QMediaPlayer::MediaStatus status){
    if(status == QMediaPlayer::EndOfMedia){
        player->setPosition(0);
        player->play();
    }
}

bool Video::configurarVideo(QString caminhoVideo){
    // Obtem o caminho absoluto do arquivo
    QString caminhoAbsoluto = QFileInfo(caminhoVideo).absoluteFilePath();
    QUrl url = QUrl::fromLocalFile(caminhoAbsoluto);

    player = new QMediaPlayer;
    player->setMedia(url);

    // Saída de vídeo do player
    videoItem = new QGraphicsVideoItem;
    player->setVideoOutput(videoItem);

    scene = new QGraphicsScene;
    scene->addItem(videoItem);
    ui->graficos->setScene(scene);

    // Atualiza o tamanho do vídeo
    videoItem->setSize(ui->graficos->size());
    ui->graficos->viewport()->update();

    player->play();

    qDebug() << "[Video][OK] Video de tela ociosa reproduzindo";
    return true;
}
