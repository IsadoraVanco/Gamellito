/**
 * Versão 3 (ReprodutorMenu):
 * O menu de stacked widgets, que salva o caminho dos videos.
 * Responsável por manipular as telas
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

// Para o video
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QAudio>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtMultimedia/QtMultimedia>
#include <QtCore>
#include <QtGui>
#include <QGraphicsVideoItem>

// Para o áudio
#include <QtMultimedia/QSound>

// Para a manipulação de perfis
#include "usuario.h"

// Para a manipulação de arquivos
#include "arquivos.h"

/* ************************************************************
 * DEFINIÇÕES
 *************************************************************/

// Armazena os nomes de todos arquivos
#define ARQUIVO_CONFIGURACAO_GERAL "configs.json"

// Páginas do programa
enum class Pagina{
    Inicial,    // 0
    Sobre,      // 1
    Configurar, // 2
    Video,      // 3
    Pergunta    // 4
};

// Deve ser adicionado na stacked widgets de "Configurar"
#define PAGINA_ADICIONAR_PERGUNTA 5

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
     * SOM AMBIENTE DO MENU
     *************************************************************/

    /**
     * @brief Configura o som ambiente do menu e o inicializa
     */
    void inicializarSomAmbiente();

    /**
     * @brief Liga o som ambiente e modifica o ícone do botão de som
     */
    void ligarSomAmbiente();

    /**
     * @brief Desliga o som ambiente e modifica o ícone do botão de som
     */
    void desligarSomAmbiente();

    /* ************************************************************
     * SEQUÊNCIA DE VÍDEO E PERGUNTA
     *************************************************************/

    /**
     * @brief Mostra uma tela definida do programa
     * @param tipo A tela que será mostrada
     */
    void mostrarTela(Pagina tipo);

    /**
     * @brief Carrega a sequência de vídeos e perguntas em uma estrutura
     */
    void carregarSequencia();

    /**
     * @brief Atualizar a página para o próximo item da sequência
     */
    void proximoDaSequencia();

    /**
     * @brief Atualizar a página para o item anterior da sequência
     */
    void anteriorDaSequencia();

    /* ************************************************************
     * TELA INICIAL (0)
     *************************************************************/

    /**
     * @brief Volta para o a tela do menu e liga o som ambiente
     */
    void voltarInicio();

    /**
     * @brief Manipula o som ambiente do menu
     */
    void on_pushButton_som_clicked();

    /**
     * @brief Mainwindow::iniciarSequencia
     */
    //void Mainwindow::iniciarSequencia();

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

    // trocar para eventos

    void on_pushButton_video_tocar_clicked();

    void on_pushButton_video_parar_clicked();

    void on_pushButton_video_proximo_clicked();

    /* ************************************************************
     * TELA QUESTIONARIO (4)
     *************************************************************/

    /**
     * @brief Configura a página do questionário
     */
    void configurarPergunta();

    /**
     * @brief Volta para o início da aplicação
     */
    void on_pushButton_voltar_iniciar_clicked();

    /**
     * @brief Volta para o vídeo anterior
     */
    void on_pushButton_voltar_video_clicked();

    /**
     * @brief Seleciona a opção A do questionário
     */
    void on_radioButton_opcao1_clicked();

    /* ************************************************************
     * TELA ADICIONAR PERGUNTA (5)
     *************************************************************/

    /**
     * @brief Mostra a tela de "Adicionar Pergunta"
     */
    void mostrarTelaAdicionarPergunta();

private:
    // O UI do programa
    Ui::MainWindow *ui;

    // Página atual
    Pagina paginaAtual {Pagina::Inicial};

    // Sequência de vídeo e pergunta

    // Reprodutor
    QMediaPlayer *player;

    // Widget de vídeo
    QVideoWidget *videoWidget;

    QGraphicsVideoItem* videoItem;
    QGraphicsScene* scene;


    // Som ambiente
    //QMediaPlayer *som_ambiente;
    QSound *som;
    bool mutado = false;

};
#endif // MAINWINDOW_H
