#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// Para a lista da sequência
#include <QListWidget>

// Para os botões
#include <QRadioButton>

#include "reprodutor.h"
#include "arquivos.h"
#include "senha.h"
#include "somambiente.h"
#include "perfil.h"

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
    ConfigurarPerfil, // 3
    Video,      // 4
    Pergunta,   // 5
    AdicionarPergunta,   //6
    EditarPergunta      // 7
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

    void configurarTelas();

    /* ************************************************************
     * ICONES
     *************************************************************/

    /**
     * @brief Atualiza o ícone do botão de som do menu
     */
    void atualizarIconeSom();

    /* ************************************************************
     * GERENCIAMENTO DAS CONFIGURAÇÕES
     *************************************************************/

    // ***** GERAL *********************************************

    /**
     * @brief Configura o arquivo de configurações gerais
     */
    void configurarArquivoGeral();

    // ***** SEQUÊNCIAS *********************************************

    void carregarSequencias();

    /**
     * @brief Mostra uma caixa de diálogo para confirmar a exclusão
     * de um item da sequência.
     * @return true caso confirme, false para caso contrárioS
     */
    bool mostrarConfirmarRemoverItem();

    // ***** TELAS *********************************************

    void carregarTelaAtual();

    void mostrarProximaTela();

    void mostrarTelaAnterior();

    void configurarTelaVideo(QJsonObject objetoAtual);

    void configurarTelaPergunta(QJsonObject objetoAtual);

    // ***** ADICIONAR PERGUNTA *********************************************

    bool mostrarConfirmarSairPergunta();

    /**
     * @brief Retira todo texto ou seleção feita no formulário de perguntas
     */
    void limparCamposPergunta();

    /**
     * @brief Verifica se existem campos que não foram preenchidos no fomulário
     * @return True caso exista algum campo vazio, false para caso contrário
     */
    bool existemCamposVazios();

    /**
     * @brief Verifica se todos os campos foram preenchidos no formulário
     * @return True caso todos estejam preenchidos, false para caso contrário
     */
    bool todosCamposPreenchidos();

    /**
     * @brief Adiciona uma pergunta na sequência do perfil selecionado
     * @return True caso o processo tenha sido concluído com sucesso,
     * false para caso contrário
     */
    bool salvarNovaPergunta();

    // ***** EDITAR PERGUNTA *********************************************

    void carregarEdicaoPergunta();

    bool salvarPerguntaEditada();

    bool todosCamposPreenchidosEditada();

    bool existemCamposVaziosEditada();

    // ***** PERGUNTA *********************************************

    /**
     * @brief Verifica qual resposta foi selecionada
     * @return O número da resposta selecionada
     */
    int verificarRespostaSelecionada();

    /**
     * @brief Salva a resposta escolhida em um arquivo
     */
    void salvarResposta();

    // ***** PERFIS *********************************************

    /**
     * @brief Configura as propriedades de cada perfil existente no sistema.
     */
    void configurarPerfis();

    void removerItemSelecionado();

    void editarItemSelecionado();

    /**
     * @brief Atualiza a lista do perfil atual no widget de seleção.
     */
    void carregarListaPerfilAtual();

    /**
     * @brief Modifica o usuário selecionado para a exibição da sequência.
     * @param nomePerfil O texto do perfil selecionado no widget.
     */
    void selecionarPerfil(QString nomePerfil);

    /**
     * @brief Adiciona os perfis existentes no widget de seleção de usuário.
     */
    void adicionarPerfisParaSelecao();

    /* ************************************************************
     * BOTÕES E AÇÕES
     *************************************************************/

    // ***** INICIAR *********************************************

    void on_pushButton_iniciar_clicked();

    /**
     * @brief Mostra a página de "sobre o programa"
     */
    void on_pushButton_sobre_clicked();

    /**
     * @brief Manipula o som ambiente do menu
     */
    void on_pushButton_som_clicked();

    void on_pushButton_configurar_clicked();

    // ***** SOBRE *********************************************

    /**
     * @brief Volta para o início do menu
     */
    void on_pushButton_voltar_sobre_clicked();

    // ***** CONFIGURAR *********************************************

    /**
     * @brief Altera a página para a de Configurar Perfil
     */
    void on_pushButton_configurar_perfil_clicked();

    // ***** CONFIGURAR PERFIL *********************************************

    /**
     * @brief Volta para o início do menu
     */
    void on_pushButton_voltar_configurar_clicked();

    /**
     * @brief Altera a senha de acesso às configurações
     */
    void on_pushButton_alterar_senha_clicked();

    /**
     * @brief Adiciona um vídeo na sequência selecionada
     */
    void on_pushButton_adicionar_video_clicked();

    /**
     * @brief Adiciona uma pergunta na sequência selecionada
     */
    void on_pushButton_adicionar_pergunta_clicked();

    /**
     * @brief Salva um vídeo nas pastas de backup do perfil selecionado
     */
    void on_pushButton_salvar_video_clicked();

    /**
     * @brief Edita um item da sequência selecionada
     */
    void on_pushButton_editarItem_clicked();

    /**
     * @brief Remove um item da sequência selecionada
     */
    void on_pushButton_removerItem_clicked();

    // ***** REPRODUTOR *********************************************

    void on_pushButton_inicio_reprodutor_clicked();

    void on_pushButton_voltar_reprodutor_clicked();

    void on_pushButton_proximo_reprodutor_clicked();

    // ***** PERGUNTA *********************************************

    void on_pushButton_pergunta_inicio_clicked();

    void on_pushButton_voltar_pergunta_clicked();

    void on_pushButton_proximo_pergunta_clicked();

    void on_radioButton_resposta1_clicked();

    void on_radioButton_resposta2_clicked();

    void on_radioButton_resposta3_clicked();

    void on_radioButton_resposta4_clicked();

    // ***** ADICIONAR PERGUNTA *********************************************

    void on_pushButton_inicial_adicionar_pergunta_clicked();

    void on_pushButton_voltar_adicionar_pergunta_clicked();

    void on_pushButton_salvar_pergunta_clicked();

    void on_radioButton_opcao1_clicked();

    void on_radioButton_opcao2_clicked();

    void on_radioButton_opcao3_clicked();

    void on_radioButton_opcao4_clicked();

    // ***** EDITAR PERGUNTA *********************************************

    void on_pushButton_inicial_editar_pergunta_clicked();

    void on_pushButton_voltar_editar_pergunta_clicked();

    void on_pushButton_salvar_pergunta_editada_clicked();

    void on_radioButton_editar_opcao1_clicked();

    void on_radioButton_editar_opcao2_clicked();

    void on_radioButton_editar_opcao3_clicked();

    void on_radioButton_editar_opcao4_clicked();

private:

    /* ************************************************************
     * CONSTANTES E ATRIBUTOS
     *************************************************************/

    // ***** CONFIGURAÇÕES *********************************************

    // Senha para as configurações
    Senha *senha = new Senha(this);

    Arquivos *arquivos = new Arquivos(this);

    // ***** SEQUÊNCIA *********************************************

    // Marca qual o perfil atual da sequência
    TipoPerfil perfilAtual = TipoPerfil::Paciente;

    // Sequências de vídeos e perguntas
    Perfil *paciente = new Perfil();
    Perfil *responsavel = new Perfil();
    Perfil *profissional = new Perfil();

    // Mapeamento entre o nome do Perfil e o próprio perfil
    std::map<TipoPerfil, Perfil*> perfis = {
        {TipoPerfil::Paciente, paciente},
        {TipoPerfil::Responsavel, responsavel},
        {TipoPerfil::Profissional, profissional}
    };

    // ***** INTERFACE *********************************************

    // A interface da janela
    Ui::MainWindow *ui;

    // O reprodutor de vídeo
    Reprodutor *reprodutor;

    // ***** SOM AMBIENTE *********************************************

    SomAmbiente *somAmbiente = new SomAmbiente();

    // ***** BOTÕES *********************************************

    QRadioButton *ultimoApertado = nullptr;

};
#endif // MAINWINDOW_H
