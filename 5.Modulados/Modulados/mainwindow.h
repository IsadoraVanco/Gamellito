#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

// Para a lista da sequência
#include <QListWidget>
#include <QList>

// Para os botões
#include <QRadioButton>

// Para os campos de texto
#include <QTextEdit>

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

// Páginas do programa (importante estar na ordem)
enum class Pagina{
    Inicial,            // 0
    Sobre,              // 1
    Configurar,         // 2
    ConfigurarPerfil,   // 3
    Video,              // 4
    Pergunta,           // 5
    AdicionarPergunta,  // 6
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

    /* ************************************************************
     * CONFIGURAR TELAS
     *************************************************************/

    void configurarTelas();

    void configurarElementosTelaMenu();

    void configurarElementosTelaConfigurar();

    void configurarElementosTelaReprodutor();

    void configurarElementosTelaPergunta();

    /* ************************************************************
     * ICONES
     *************************************************************/

    /**
     * @brief Atualiza o ícone do botão de som do menu
     */
    void atualizarIconeSom();

    /**
     * @brief Adiciona os icones de voltar à página inicial
     */
    void adicionarIconesPaginaInicial();

    /**
     * @brief Adiciona os icones de voltar à página anterior
     */
    void adicionarIconesVoltar();

    /**
     * @brief Adiciona os ícones de avançar para a próxima página
     */
    void adicionarIconesProximo();

    /* ************************************************************
     * GERENCIAMENTO DAS CONFIGURAÇÕES
     *************************************************************/

    // ***** GERAL *********************************************

    /**
     * @brief Configura o arquivo de configurações gerais
     */
    void configurarArquivoGeral();

    /**
     * @brief Mostra uma caixa de diálogo para confirmar uma ação
     * @param titulo O título da caixa
     * @param texto O texto da caixa
     * @return true caso seja confirmado, false para caso contrário
     */
    bool mostrarConfirmar(QString titulo, QString texto);

    // ***** SEQUÊNCIAS *********************************************

    void carregarSequencias();

    void removerItemSelecionado();

    void editarItemSelecionado();

    // ***** TELAS *********************************************

    void carregarTelaAtual();

    void mostrarProximaTela();

    void mostrarTelaAnterior();

    void configurarTelaVideo(QJsonObject objetoAtual);

    void configurarTelaPergunta(QJsonObject objetoAtual);

    // ***** CONFIGURAR PERFIL *********************************************

    /**
     * @brief Gera os relatórios com respostas dos perfis
     */
    void gerarRelatorios();

    // ***** PERGUNTA *********************************************

    /**
     * @brief Desmarca a opção do botão
     * @param btn O endereço do botão que será alterado
     */
    void desmarcarOpcao(QRadioButton *btn);

    /**
     * @brief Limpa o campo de texto
     * @param campo O endereço do campo de texto
     */
    void limparTexto(QTextEdit *campo);

    /**
     * @brief Verifica qual resposta foi selecionada
     * @return O número da resposta selecionada
     */
    int verificarRespostaSelecionada();

    /**
     * @brief Salva a resposta escolhida em um arquivo
     */
    void salvarResposta();

    void atualizarBotaoConfirmar();

    void mostrarRespostaCorreta();

    // ***** ADICIONAR PERGUNTA *********************************************

    bool mostrarConfirmarSairPergunta();

    /**
     * @brief Retira todo texto ou seleção feita no formulário de perguntas
     */
    void limparCamposPergunta();

    /**
     * @brief Verifica se todos os campos foram preenchidos no formulário
     * @return True caso todos estejam preenchidos, false para caso contrário
     */
    bool todosCamposPreenchidos();

    /**
     * @brief Verifica se existem campos que não foram preenchidos no fomulário
     * @return True caso exista algum campo vazio, false para caso contrário
     */
    bool existemCamposVazios();

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

    // ***** PERFIS *********************************************

    /**
     * @brief Configura as propriedades de cada perfil existente no sistema.
     */
    void configurarPerfis();

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
     * @brief Manipula o som ambiente do menu
     */
    void on_pushButton_som_clicked();

    void on_pushButton_configurar_clicked();

    // ***** SOBRE *********************************************

    /**
     * @brief Mostra a versão do Qt utilizada no programa
     */
    void on_pushButton_versao_qt_clicked();

    // ***** CONFIGURAR *********************************************

    /**
     * @brief Altera a senha de acesso às configurações
     */
    void on_pushButton_alterar_senha_clicked();

    /**
     * @brief Salva um vídeo nas pastas de backup do perfil selecionado
     */
    void on_pushButton_salvar_video_clicked();

    // ***** CONFIGURAR PERFIL *********************************************

    /**
     * @brief Adiciona um vídeo na sequência selecionada
     */
    void on_pushButton_adicionar_video_clicked();

    /**
     * @brief Adiciona uma pergunta na sequência selecionada
     */
    void on_pushButton_adicionar_pergunta_clicked();

    /**
     * @brief Edita um item da sequência selecionada
     */
    void on_pushButton_editarItem_clicked();

    /**
     * @brief Remove um item da sequência selecionada
     */
    void on_pushButton_removerItem_clicked();

    /**
     * @brief Move um item da lista para cima
     */
    void on_pushButton_mover_cima_clicked();

    /**
     * @brief Move um item da lista para baixo
     */
    void on_pushButton_mover_baixo_clicked();

    /**
     * @brief Limpa uma sequência de perfil
     */
    void on_pushButton_limpar_sequencia_clicked();

    /**
     * @brief Limpa as respostas de um perfil
     */
    void on_pushButton_limpar_respostas_clicked();

    // ***** REPRODUTOR *********************************************

    void on_pushButton_inicio_reprodutor_clicked();

    void on_pushButton_voltar_reprodutor_clicked();

    void on_pushButton_proximo_reprodutor_clicked();

    // ***** PERGUNTA *********************************************

    void on_pushButton_inicio_pergunta_clicked();

    void on_pushButton_voltar_pergunta_clicked();

    void on_pushButton_proximo_pergunta_clicked();

    void on_radioButton_resposta1_clicked();

    void on_radioButton_resposta2_clicked();

    void on_radioButton_resposta3_clicked();

    void on_radioButton_resposta4_clicked();

    // ***** ADICIONAR PERGUNTA *********************************************

    void on_pushButton_inicio_adicionar_pergunta_clicked();

    void on_pushButton_voltar_adicionar_pergunta_clicked();

    void on_pushButton_salvar_pergunta_clicked();

    void on_radioButton_opcao1_clicked();

    void on_radioButton_opcao2_clicked();

    void on_radioButton_opcao3_clicked();

    void on_radioButton_opcao4_clicked();

    // ***** EDITAR PERGUNTA *********************************************

    void on_pushButton_inicio_editar_pergunta_clicked();

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

    // Gerenciador das senhas
    Senha *senha = new Senha(this);

    // Gerenciador dos arquivos
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
    bool confirmarResposta = false;

};
#endif // MAINWINDOW_H
