#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>

// Para o vídeo
#include <QtMultimediaWidgets/QVideoWidget>
#include <QGraphicsVideoItem>
#include <QGraphicsScene>
#include <QtMultimedia/QtMultimedia>
#include <QtMultimedia/QMediaPlayer>

// Para diretório
#include <QtCore>
#include <QtGui>

namespace Ui {
class Video;
}

class Video : public QWidget
{
    Q_OBJECT

public:

    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    explicit Video(QWidget *parent = nullptr);

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~Video();

    /* ************************************************************
     * CONFIGURAÇÃO
     *************************************************************/

    /**
     * @brief Configura um vídeo para ser exibido em loop
     * @param caminhoVideo O caminho relativo do arquivo de vídeo
     * @return true caso tenha sucesso, false para caso contrário
     */
    bool configurarVideo(QString caminhoVideo);

private:

    Ui::Video *ui;

    // Para o vídeo
    QVideoWidget *videoWidget;
    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;
    QMediaPlayer *player;
    QMediaPlaylist *playlist;

    // Para o arquivo
    QUrl urlVideo;

};

#endif // VIDEO_H
