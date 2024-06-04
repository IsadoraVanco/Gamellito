#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// Para a lista da sequência
#include <QListWidget>

#include "reprodutor.h"
#include "arquivos.h"
#include "senha.h"
#include "somambiente.h"

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
    Pergunta,   // 4
    AdicionarPergunta   //5
};

// Perfis disponíveis
enum class Perfil{
    Paciente,       // 0
    Responsavel,    // 1
    Profissional    // 2
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    MainWindow(QWidget *parent = nullptr);

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~MainWindow();

private slots:

    /* ************************************************************
     * GERENCIAMENTO DE TELAS
     *************************************************************/

    /**
     * @brief Mostra uma tela definida do programa
     * @param tipo A tela que será mostrada
     */
    void mostrarTela(Pagina tipo);

    /**
     * @brief Configura todas as telas dinamicamente
     */
    void configurarTelas();

    /* ************************************************************
     * ICONES
     *************************************************************/

    void atualizarIconeSom();

    /* ************************************************************
     * BOTÕES E AÇÕES
     *************************************************************/

    // ***** INICIAR *********************************************

    /**
     * @brief
     */
    void on_pushButton_iniciar_clicked();

    /**
     * @brief
     */
    void on_pushButton_sobre_clicked();

    /**
     * @brief
     */
    void on_pushButton_som_clicked();

    /**
     * @brief
     */
    void on_pushButton_configurar_clicked();

    // ***** SOBRE *********************************************

    /**
     * @brief
     */
    void on_pushButton_voltar_sobre_clicked();

    // ***** CONFIGURAR *********************************************

    /**
     * @brief
     */
    void on_pushButton_voltar_configurar_clicked();

    /**
     * @brief
     */
    void on_pushButton_alterar_senha_clicked();

    /**
     * @brief
     */
    void on_pushButton_adicionar_video_clicked();

    /**
     * @brief
     */
    void on_pushButton_adicionar_pergunta_clicked();

    /**
     * @brief
     */
    void on_pushButton_salvar_video_clicked();

    // ***** REPRODUTOR *********************************************

    /**
     * @brief
     */
    void on_pushButton_inicio_reprodutor_clicked();

    /**
     * @brief
     */
    void on_pushButton_voltar_reprodutor_clicked();

    /**
     * @brief
     */
    void on_pushButton_proximo_reprodutor_clicked();

    // ***** PERGUNTA *********************************************

    /**
     * @brief
     */
    void on_pushButton_pergunta_inicio_clicked();

    /**
     * @brief
     */
    void on_pushButton_voltar_pergunta_clicked();

    /**
     * @brief
     */
    void on_pushButton_proximo_pergunta_clicked();

    // ***** ADICIONAR PERGUNTA *********************************************

    /**
     * @brief
     */
    void on_pushButton_inicial_adicionar_pergunta_clicked();

    /**
     * @brief
     */
    void on_pushButton_voltar_adicionar_pergunta_clicked();

    /**
     * @brief
     */
    void on_pushButton_salvar_pergunta_clicked();

    /* ************************************************************
     * GERENCIAMENTO DAS CONFIGURAÇÕES
     *************************************************************/

    // ***** GERAL *********************************************

    /**
     * @brief
     */
    void criarArquivoGeral();

    /**
     * @brief Faz a configuração do arquivo geral de configurações do programa
     */
    void configurarArquivoGeral();

    // ***** SEQUÊNCIAS *********************************************

    /**
     * @brief
     */
    bool criarArquivoSequencia();

    /**
     * @brief
     * @param sequencia
     * @return
     */
    bool ehSequenciaVazia(QJsonArray sequencia);

    /**
     * @brief
     * @return
     */
    bool configurarSequenciaAtual();

    /**
     * @brief
     */
    void carregarSequencias();

    /**
     * @brief
     * @return
     */
    bool mostrarConfirmarRemoverItem();

    // ***** TELAS *********************************************

    /**
     * @brief
     */
    void carregarTelaAtual();

    /**
     * @brief
     */
    void mostrarProximaTela();

    /**
     * @brief
     */
    void mostrarTelaAnterior();

    /**
     * @brief
     */
    void configurarTelaVideo(QJsonObject objetoAtual);

    /**
     * @brief
     * @param objetoAtual
     */
    void configurarTelaPergunta(QJsonObject objetoAtual);

    // ***** ADICIONAR PERGUNTA *********************************************

    /**
     * @brief
     * @return
     */
    bool mostrarConfirmarSairPergunta();

    /**
     * @brief
     */
    void limparCamposPergunta();

    /**
     * @brief
     * @return
     */
    bool verificarCamposVazios();

    /**
     * @brief
     * @return
     */
    bool verificarCamposPreenchidos();

    /**
     * @brief
     * @return
     */
    bool salvarPergunta();

    // ***** PERGUNTA *********************************************

    /**
     * @brief
     * @return
     */
    int verificarRespostaSelecionada();

    /**
     * @brief
     */
    bool criarArquivoRespostas();

    /**
     * @brief
     */
    void salvarResposta();

    // ***** VIDEO *********************************************

    /**
     * @brief
     * @return
     */
    QString selecionarVideo();

    /**
     * @brief
     * @return
     */
    QString salvarVideoBackup();

    // ***** PERFIS *********************************************

    /**
     * @brief
     * @param texto
     * @return
     */
    QString capitalizarTexto(QString texto);

    /**
     * @brief
     */
    void removerItemSelecionado();

    /**
     * @brief
     */
    void editarItemSelecionado() ;

    /**
     * @brief
     */
    void carregarListaPerfil();

    /**
     * @brief
     * @param perfil
     */
    void selecionarPerfil(QString perfil);

    /**
     * @brief
     */
    void configurarPerfis();

    void on_pushButton_editarItem_clicked();

    void on_pushButton_removerItem_clicked();

private:

    /* ************************************************************
     * CONSTANTES E ATRIBUTOS
     *************************************************************/

    // ***** CONFIGURAÇÕES *********************************************

    // Mapeamento entre os perfis e os arquivos/pasta
    std::map<Perfil, structArquivos> arquivos = {
        {Perfil::Paciente, {"spa.json", "rpa.json", "paciente"}},
        {Perfil::Responsavel, {"sre.json", "rre.json", "responsavel"}},
        {Perfil::Profissional, {"spr.json", "rpr.json", "profissional"}}
    };

    // Nome das pastas que serão utilizadas
    structPastas pastas = {"configuracoes", "backups"};

    // Senha para as configurações
    Senha *senha = new Senha(this);

    // ***** SEQUÊNCIA *********************************************

    // Marca qual o perfil atual da sequência
    Perfil perfilAtual = Perfil::Paciente;

    // Marca qual o índice do elemento atual da sequência
    int indiceAtual = 0;

    // Sequências de vídeos e perguntas
    QJsonArray paciente;
    QJsonArray responsavel;
    QJsonArray profissional;

    // Mapeamento entre os perfis e sequências
    std::map<Perfil, QJsonArray> sequencias = {
        {Perfil::Paciente, paciente},
        {Perfil::Responsavel, responsavel},
        {Perfil::Profissional, profissional}
    };

    // ***** INTERFACE *********************************************

    // A interface da janela
    Ui::MainWindow *ui;

    // O reprodutor de vídeo
    Reprodutor *reprodutor;

    // ***** SOM AMBIENTE *********************************************

    SomAmbiente *somAmbiente = new SomAmbiente();

};
#endif // MAINWINDOW_H
