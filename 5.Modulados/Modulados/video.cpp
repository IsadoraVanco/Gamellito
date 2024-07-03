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

    player = new QMediaPlayer;
    videoItem = new QGraphicsVideoItem;
    scene = new QGraphicsScene;
    playlist = new QMediaPlaylist;
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
    delete playlist;
}

/* ************************************************************
 * CONFIGURAÇÃO
 *************************************************************/

void Video::mudarStatus(QMediaPlayer::MediaStatus status){
    qDebug() << status;
    qDebug() << player->position();
    qDebug() << player->duration();

    if(status == QMediaPlayer::EndOfMedia){
        player->setPosition(0);
        player->play();
        qDebug() << "fim de arquivo";
    }else if(status == QMediaPlayer::BufferedMedia || status == QMediaPlayer::LoadedMedia){
        player->play();
        qDebug() << "play";
    }else if(status == QMediaPlayer::InvalidMedia){
        player->setMedia(urlVideo);
        qDebug() << "set media";
    }
}

bool Video::configurarVideo(QString caminhoVideo){
    // Obtem o caminho absoluto do arquivo
    QString caminhoAbsoluto = QFileInfo(caminhoVideo).absoluteFilePath();
    QUrl url = QUrl::fromLocalFile(caminhoAbsoluto);
    urlVideo = url;

    player->setMedia(url);
    playlist->addMedia(player->media());
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player->setPlaylist(playlist);

    // Saída de vídeo do player
    player->setVideoOutput(videoItem);

    scene->addItem(videoItem);
    ui->graficos->setScene(scene);

    // Atualiza o tamanho do vídeo
    videoItem->setSize(ui->graficos->size());
    ui->graficos->viewport()->update();

    player->play();

//    connect(player, &QMediaPlayer::mediaStatusChanged, this, &Video::mudarStatus);

    qDebug() << "[Video][OK] Video de tela ociosa reproduzindo";
    return true;
}
