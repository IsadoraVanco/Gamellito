#ifndef REPRODUTOR_H
#define REPRODUTOR_H

#include <QWidget>

// Para o video
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudio>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QtMultimedia>
#include <QGraphicsVideoItem>

// Para diretório
#include <QtCore>
#include <QtGui>

namespace Ui {
class Reprodutor;
}

class Reprodutor : public QWidget
{
    Q_OBJECT

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
     * AUXILIAR
     *************************************************************/

    /**
     * @brief Converte um tempo em texto
     * @param tempo O tempo em milissegundos
     * @return O texto convertido no formato adequado
     */
    QString converterTempoEmTexto(qint64 tempo);

    /* ************************************************************
     * WIDGETS
     *************************************************************/

    /**
     * @brief Altera o estado do botão de reprodução
     * @param status O status emitido
     */
    void alterarEstado(QMediaPlayer::MediaStatus status);

    /**
     * @brief Altera a duração máxima do vídeo nos widgets
     * @param duracao A duração em milissegundos
     */
    void alterarDuracaoMaxima(int64_t duracao);

    /**
     * @brief Altera o widget que marca o tempo atual do vídeo
     * @param tempo O tempo atual em milissegundos
     */
    void alterarWidgetTempo(int64_t tempo);

    /* ************************************************************
     * REPRODUÇÃO DO VÍDEO
     *************************************************************/

    /**
     * @brief Altera o tempo atual do vídeo de acordo com a posição do widget
     * @param posicao A posição do tempo no widget
     */
    void alterarTempoVideo(int posicao);

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

    /* ************************************************************
     * SOM DO VÍDEO
     *************************************************************/

    /**
     * @brief Muta o som
     */
    void mutarSom();

    /**
     * @brief Reproduz o som
     */
    void reproduzirSom();

    /**
     * @brief Altera o volume do som
     * @param valor O novo valor
     */
    void alterarVolume(int valor);

private slots:

    /* ************************************************************
     * AÇÕES
     *************************************************************/

    // ***** VIDEO **************************************************

    /**
     * @brief Realiza a ação ao clicar no botão de play/pause
     */
    void on_pushButton_video_tocar_clicked();

    /**
     * @brief Realiza a ação de voltar o video
     */
    void on_pushButton_voltarVideo_clicked();

    /**
     * @brief Realiza a ação de adiantar o video
     */
    void on_pushButton_passarVideo_clicked();

    // ***** SOM **************************************************

    /**
     * @brief Realiza a ação ao clicar no botão de volume
     */
    void on_pushButton_volume_clicked();

private:

    /* ************************************************************
     * CONSTANTES E ATRIBUTOS
     *************************************************************/

    Ui::Reprodutor *ui;

    // Reprodutor
    QMediaPlayer *player;
    bool videoParado = true;

    // Volume
    bool somMutado = true;

    // Widget de vídeo
    QVideoWidget *videoWidget;
    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;

    // Widget de tempo (em milissegundos)
    int periodoTempo = 50; // Representa o periodo entre um ponto e outro do slider
    int tempoAcao = 5000;   // Representa o tempo para a ação de voltar e adiantar
};

#endif // REPRODUTOR_H
