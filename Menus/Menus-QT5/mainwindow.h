#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// Para os icones
#include <QIcon>
// Para as imagens
#include <QPixmap>
// Para o stackedwidgets
#include <QtWidgets>
// Para o vídeo
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudio>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QtMultimedia>
// Para o áudio
#include <QtMultimedia/QSound>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /* ************************************************************
     * TELA INICIAL (0)
     *************************************************************/

    void on_pushButton_som_clicked();

    void on_pushButton_iniciar_clicked();

    void on_pushButton_configurar_clicked();

    void on_pushButton_sobre_clicked();

    /* ************************************************************
     * TELA SOBRE (1)
     *************************************************************/

    void on_pushButton_versao_qt_clicked();

    void on_pushButton_voltar_sobre_clicked();

    /* ************************************************************
     * TELA CONFIGURAR (2)
     *************************************************************/

    void on_pushButton_voltar_configurar_clicked();

    /* ************************************************************
     * TELA INICIAR (3)
     *************************************************************/

    void on_pushButton_voltar_iniciar_clicked();

    void on_pushButton_voltar_video_clicked();

    /* ************************************************************
     * SOM AMBIENTE
     *************************************************************/

    /**
     * @brief Inicializa o som ambiente do menu
     */
    void inicializaSomAmbiente();

    /**
     * @brief Liga o som ambiente e modifica o ícone do botão de som
     */
    void ligaSomAmbiente();

    /**
     * @brief Desliga o som ambiente e modifica o ícone do botão de som
     */
    void desligaSomAmbiente();

private:
    Ui::MainWindow *ui;

    QMediaPlayer *som_ambiente;
    QSound *som;
    bool mutado = false;

};
#endif // MAINWINDOW_H
