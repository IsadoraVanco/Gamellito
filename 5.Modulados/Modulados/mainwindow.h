#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// Para o som ambiente
#include <QtMultimedia/QSound>

#include "arquivos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/* ************************************************************
 * DEFINIÇÕES
 *************************************************************/

// Páginas do programa
enum class Pagina{
    Inicial,    // 0
    Sobre,      // 1
    Configurar, // 2
    Video,      // 3
    Pergunta    // 4
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /* ************************************************************
     * SOM AMBIENTE DO MENU
     *************************************************************/

    /**
     * @brief Configura o som ambiente do menu
     * @param path O caminho relativo do arquivo
     */
    void configurarSomAmbiente(QString path);

    /**
     * @brief Liga o som ambiente e modifica o ícone do botão de som
     */
    void ligarSomAmbiente();

    /**
     * @brief Desliga o som ambiente e modifica o ícone do botão de som
     */
    void desligarSomAmbiente();

    /* ************************************************************
     * GERENCIAMENTO DE TELAS
     *************************************************************/

    /**
     * @brief Mostra uma tela definida do programa
     * @param tipo A tela que será mostrada
     */
    void mostrarTela(Pagina tipo);

    /**
     * @brief MainWindow Configura todas as telas dinamicamente
     */
    void configurarTelas();

    /* ************************************************************
     * GERENCIAMENTO DAS CONFIGURAÇÕES
     *************************************************************/

    /**
     * @brief Lê uma senha definida pelo usuário
     * @return A senha lida do usuário
     */
    QString lerSenha();

    /**
     * @brief Faz a configuração do arquivo geral de configurações do programa
     */
    void configurarArquivoGeral();

private:
    Ui::MainWindow *ui;

    // Nomes dos arquivos
    structArquivos paciente = {"spa.json", "rpa.json"};
    structArquivos responsavel = {"sre.json", "rre.json"};
    structArquivos profissional = {"spr.json", "rpr.json"};

    // Som ambiente
    QSound *somAmbiente;
    bool somAmbienteMutado = false;

};
#endif // MAINWINDOW_H
