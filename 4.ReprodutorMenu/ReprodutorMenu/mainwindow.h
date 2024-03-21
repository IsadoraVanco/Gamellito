/**
 * Versão 3 (ReprodutorMenu):
 * O menu de stacked widgets, que salva o caminho dos videos
 */
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
#include <QtCore>
#include <QtGui>

// Para o áudio
#include <QtMultimedia/QSound>

// Para a manipulação de arquivos
#include "arquivos.h"

#define ARQUIVO_CONFIGURACAO "config.json"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

// Passa o caminho de onde foi chamado a aplicação pelo argv
public:
    MainWindow(char* arg, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

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

    /* ************************************************************
     * TELA INICIAL (0)
     *************************************************************/

    /**
     * @brief Manipula o som do menu
     */
    void on_pushButton_som_clicked();

    /**
     * @brief Inicia a sequência de vídeos e perguntas
     */
    void on_pushButton_iniciar_clicked();

    /**
     * @brief Vai para a página de configurações da sequência
     * de vídeos e perguntas
     */
    void on_pushButton_configurar_clicked();

    /**
     * @brief Vai para a página de informações do software
     */
    void on_pushButton_sobre_clicked();

    /**
     * @brief Volta para o início da aplicação
     */
    void voltarInicio();

    /* ************************************************************
     * TELA SOBRE (1)
     *************************************************************/

    /**
     * @brief Mostra a versão do Qt utilizada
     */
    void on_pushButton_versao_qt_clicked();

    /**
     * @brief Volta para o início da aplicação
     */
    void on_pushButton_voltar_sobre_clicked();

    /* ************************************************************
     * TELA CONFIGURAR (2)
     *************************************************************/

    /**
     * @brief Volta para a tela inicial
     */
    void on_pushButton_voltar_configurar_clicked();

    /**
     * @brief Adiciona um video na lista de configurações
     */
    void on_pushButton_adicionar_video_clicked();

    /**
     * @brief Adiciona uma pergunta na lista de configurações
     */
    void on_pushButton_adicionar_pergunta_clicked();

    /* ************************************************************
     * TELA REPRODUTOR (3)
     *************************************************************/

    void iniciaVideo();

    void on_pushButton_video_tocar_clicked();

    void on_pushButton_video_parar_clicked();

    void on_pushButton_video_proximo_clicked();

    /* ************************************************************
     * TELA QUESTIONARIO (4)
     *************************************************************/

    /**
     * @brief Volta para o início da aplicação
     */
    void on_pushButton_voltar_iniciar_clicked();

    /**
     * @brief Volta para o vídeo anterior
     */
    void on_pushButton_voltar_video_clicked();

    /* ************************************************************
     * TELA ADICIONAR PERGUNTA (5)
     *************************************************************/

private:
    Ui::MainWindow *ui;

    // O caminho recebido em argc argv
    char *caminho;

    // Reprodutor
    QMediaPlayer *player;
    QVideoWidget *video;
    QMediaPlaylist *playlist;
    QMediaPlayer::State estadoVideo;

    // Som ambiente
    QMediaPlayer *som_ambiente;
    QSound *som;
    bool mutado = false;

};
#endif // MAINWINDOW_H
