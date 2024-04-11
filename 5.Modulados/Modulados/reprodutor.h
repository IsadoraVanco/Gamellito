#ifndef REPRODUTOR_H
#define REPRODUTOR_H

#include <QWidget>

// Para o video
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudio>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtCore>
#include <QtGui>
#include <QGraphicsVideoItem>

namespace Ui {
class Reprodutor;
}

class Reprodutor : public QWidget
{
    Q_OBJECT

    // Por ser widget, não aceita slots
public:
    explicit Reprodutor(QWidget *parent = nullptr);
    ~Reprodutor();

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
    Ui::Reprodutor *ui;

    // Reprodutor
    QMediaPlayer *player;
    bool videoParado = false;

    // Widget de vídeo
    QVideoWidget *videoWidget;

    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;
};

#endif // REPRODUTOR_H
