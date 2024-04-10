#ifndef REPRODUTOR_H
#define REPRODUTOR_H

#include <QWidget>

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudio>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtCore>
#include <QtGui>
#include <QGraphicsVideoItem>

#include "videographicsview.h"

class Reprodutor
{
public:
    // Construtor
    Reprodutor();

    /**
     * @brief Reproduz o vídeo
     */
    void tocarVideo();

    /**
     * @brief Para o vídeo
     */
    void pararVideo();

    /**
     * @brief Configura o vídeo que será tocado
     * @param pathVideo Caminho completo do vídeo
     */
    void configurarVideo(QUrl pathVideo);

private:

    // Reprodutor
    QMediaPlayer *player;

    // Widget de vídeo
    QVideoWidget *videoWidget;

    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;

    //QMediaPlaylist *playlist;
    // Estado do vídeo
    QMediaPlayer::State estadoVideo;
};

#endif // REPRODUTOR_H
