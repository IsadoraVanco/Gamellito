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

    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    explicit Reprodutor(QWidget *parent = nullptr);

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~Reprodutor();

    /* ************************************************************
     * REPRODUÇÃO DO VÍDEO
     *************************************************************/

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
     * @param caminhoVideo
     */
    void configurarVideo(QString caminhoVideo);

private slots:

    /* ************************************************************
     * AÇÕES
     *************************************************************/

    /**
     * @brief
     */
    void on_pushButton_video_tocar_clicked();

private:

    /* ************************************************************
     * CONSTANTES E ATRIBUTOS
     *************************************************************/

    Ui::Reprodutor *ui;

    // Reprodutor
    QMediaPlayer *player;
    bool videoParado = true;

    // Widget de vídeo
    QVideoWidget *videoWidget;

    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;
};

#endif // REPRODUTOR_H
