#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// Para texto
#include <QString>

// Para a lista da sequência
#include <QListWidget>
#include <QList>

// Para os botões
#include <QRadioButton>

// Para os campos de texto
#include <QTextEdit>

// Para monitorar eventos
#include <QEvent>

// Para controlar tempo
#include <QTimer>

#include "reprodutor.h"
#include "arquivos.h"
#include "senha.h"
#include "somambiente.h"
#include "perfil.h"
#include "video.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/* ************************************************************
 * DEFINIÇÕES
 *************************************************************/

// Páginas do programa (importante estar na ordem)
enum class Pagina{
    Ociosa,             // 0
    Inicial,            // 1
    Sobre,              // 2
    Configurar,         // 3
    ConfigurarPerfil,   // 4
    Video,              // 5
    Pergunta,           // 6
    AdicionarPergunta,  // 7
    EditarPergunta      // 8
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
     * CONFIGURAR TELAS
     *************************************************************/

    /**
     * @brief Configura todas as telas da aplicação
     */
    void configurarTelas();

    /**
     * @brief Configura a tela do menu inicial
     */
    void configurarElementosTelaMenu();

    /**
     * @brief Configura as tela de configuração
     */
    void configurarElementosTelaConfigurar();

    /**
     * @brief Configura a tela do reprodutor
     */
    void configurarElementosTelaReprodutor();

    /**
     * @brief Configura a tela ociosa
     */
    void configurarElementosTelaOciosa();

    /**
     * @brief Configura a tela de pergunta
     */
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
     * GERENCIAMENTO DE TELAS
     *************************************************************/

    /**
     * @brief Mostra uma tela definida do programa
     * @param tipo A tela que será mostrada
     */
    void mostrarTela(Pagina tipo);

    /**
     * @brief Configura e mostra a tela inicial
     */
    void mostrarTelaInicial();

    /**
     * @brief Mostra a tela ociosa
     */
    void mostrarTelaOciosa();

    /**
     * @brief Carrega a tela no indice atual da sequência
     */
    void carregarTelaAtual();

    /**
     * @brief Carrega a tela do próximo item da sequência
     */
    void mostrarProximaTela();

    /**
     * @brief Carrega a tela do item anterior da sequência
     */
    void mostrarTelaAnterior();

    /**
     * @brief Configura e carrega a tela de reprodutor
     * @param objetoAtual O objeto do indice atual da sequência
     */
    void configurarTelaVideo(QJsonObject objetoAtual);

    /**
     * @brief Configura e carrega a tela de pergunta
     * @param objetoAtual O objeto do indice atual da sequência
     */
    void configurarTelaPergunta(QJsonObject objetoAtual);

    /* ************************************************************
     * TEMPORIZADOR
     *************************************************************/

    /**
     * @brief Reconhece um evento de interação do usuário
     * @param obj Objeto que emite o evento
     * @param event O evento recebido
     * @return
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

    /**
     * @brief Configura o temporizador para a tela ociosa
     */
    void configurarTemporizador();

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

    /**
     * @brief Carrega todas as sequências dos perfis que estão no arquivo
     */
    void carregarSequencias();

    /**
     * @brief Remove um item da sequência que foi selecionado na lista
     */
    void removerItemSelecionado();

    /**
     * @brief Edita um item da sequência que foi selecionado na lista
     */
    void editarItemSelecionado();

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
     * @brief Salva a resposta escolhida em um arquivo
     */
    void salvarResposta();

    /**
     * @brief Atualiza o botão para confirmar ou não a resposta de uma pergunta
     */
    void atualizarBotaoConfirmar();

    /**
     * @brief Mostra qual a resposta correta da pergunta
     */
    void mostrarRespostaCorreta();

    /**
     * @brief Verifica qual opção foi selecionada
     * @param opcao1 O endereço do item 1
     * @param opcao2 O endereço do item 2
     * @param opcao3 O endereço do item 3
     * @param opcao4 O endereço do item 4
     * @return O número identificador da opção selecionada
     */
    int verificarRespostaSelecionada(QRadioButton *opcao1, QRadioButton *opcao2, QRadioButton *opcao3, QRadioButton *opcao4);

    /**
     * @brief Verifica se existe algum campo preenchido
     * @param pergunta O campo de pergunta
     * @param resposta1 O campo da resposta 1
     * @param resposta2 O campo da resposta 2
     * @param resposta3 O campo da resposta 3
     * @param resposta4 O campo da resposta 4
     * @return true caso exista algum preenchido, false para caso contrário
     */
    bool existeCamposPreenchidos(QTextEdit *pergunta, QTextEdit *resposta1, QTextEdit *resposta2, QTextEdit *resposta3, QTextEdit *resposta4);

    /**
     * @brief Verifica se existe algum campo vazio
     * @param pergunta O campo de pergunta
     * @param resposta1 O campo da resposta 1
     * @param resposta2 O campo da resposta 2
     * @param resposta3 O campo da resposta 3
     * @param resposta4 O campo da resposta 4
     * @return true caso exista algum, false para caso contrário
     */
    bool existemCamposVazios(QTextEdit *pergunta, QTextEdit *resposta1, QTextEdit *resposta2, QTextEdit *resposta3, QTextEdit *resposta4);

    // ***** ADICIONAR PERGUNTA *********************************************

    /**
     * @brief Mostra uma caixa de diálogo para confirmar a saída da nova pergunta
     * @return true caso confirme, false para caso contrário
     */
    bool mostrarConfirmarSairPergunta();

    /**
     * @brief Retira todo texto ou seleção feita no formulário de perguntas
     */
    void limparCamposPergunta();

    /**
     * @brief Adiciona uma pergunta na sequência do perfil selecionado
     * @return True caso o processo tenha sido concluído com sucesso,
     * false para caso contrário
     */
    bool salvarNovaPergunta();

    // ***** EDITAR PERGUNTA *********************************************

    /**
     * @brief Carrega a tela de edição de pergunta
     */
    void carregarEdicaoPergunta();

    /**
     * @brief Salva a pergunta editada
     * @return true caso salve, false para caso contrário
     */
    bool salvarPerguntaEditada();

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

    /**
     * @brief Inicia a sequência do perfil
     */
    void on_pushButton_iniciar_clicked();

    /**
     * @brief Manipula o som ambiente do menu
     */
    void on_pushButton_som_clicked();

    /**
     * @brief Mostra a tela de configurações
     */
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

    /**
     * @brief Volta para a tela inicial
     */
    void on_pushButton_inicio_reprodutor_clicked();

    /**
     * @brief Volta para a tela anterior
     */
    void on_pushButton_voltar_reprodutor_clicked();

    /**
     * @brief Passa para a próxima tela
     */
    void on_pushButton_proximo_reprodutor_clicked();

    // ***** PERGUNTA *********************************************

    /**
     * @brief Volta para a tela inicial
     */
    void on_pushButton_inicio_pergunta_clicked();

    /**
     * @brief Volta para a tela anterior
     */
    void on_pushButton_voltar_pergunta_clicked();

    /**
     * @brief Passa para a próxima tela
     */
    void on_pushButton_proximo_pergunta_clicked();

    /**
     * @brief Marca ou desmarca a opção 1 da pergunta
     */
    void on_radioButton_resposta1_clicked();

    /**
     * @brief Marca ou desmarca a opção 2 da pergunta
     */
    void on_radioButton_resposta2_clicked();

    /**
     * @brief Marca ou desmarca a opção 3 da pergunta
     */
    void on_radioButton_resposta3_clicked();

    /**
     * @brief Marca ou desmarca a opção 4 da pergunta
     */
    void on_radioButton_resposta4_clicked();

    // ***** ADICIONAR PERGUNTA *********************************************

    /**
     * @brief Volta para a tela inicial
     */
    void on_pushButton_inicio_adicionar_pergunta_clicked();

    /**
     * @brief Volta para a tela de configurações
     */
    void on_pushButton_voltar_adicionar_pergunta_clicked();

    /**
     * @brief Salva uma pergunta na sequência do perfil atual
     */
    void on_pushButton_salvar_pergunta_clicked();

    /**
     * @brief Marca ou desmarca a opção 1 da adição de pergunta
     */
    void on_radioButton_opcao1_clicked();

    /**
     * @brief Marca ou desmarca a opção 2 da adição de pergunta
     */
    void on_radioButton_opcao2_clicked();

    /**
     * @brief Marca ou desmarca a opção 3 da adição de pergunta
     */
    void on_radioButton_opcao3_clicked();

    /**
     * @brief Marca ou desmarca a opção 4 da adição de pergunta
     */
    void on_radioButton_opcao4_clicked();

    // ***** EDITAR PERGUNTA *********************************************

    /**
     * @brief Volta para a tela inicial
     */
    void on_pushButton_inicio_editar_pergunta_clicked();

    /**
     * @brief Volta para a tela de configurações
     */
    void on_pushButton_voltar_editar_pergunta_clicked();

    /**
     * @brief Salva uma pergunta editada na sequência do perfil atual
     */
    void on_pushButton_salvar_pergunta_editada_clicked();

    /**
     * @brief Marca ou desmarca a opção 1 da edição de pergunta
     */
    void on_radioButton_editar_opcao1_clicked();

    /**
     * @brief Marca ou desmarca a opção 2 da edição de pergunta
     */
    void on_radioButton_editar_opcao2_clicked();

    /**
     * @brief Marca ou desmarca a opção 3 da edição de pergunta
     */
    void on_radioButton_editar_opcao3_clicked();

    /**
     * @brief Marca ou desmarca a opção 4 da edição de pergunta
     */
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

    QTimer *contador;
    int tempoOcioso = 10 * 1000; // Em milissegundos
    bool ocioso = false;

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

    // Tela ociosa
    Video *videoOcioso;

    // ***** SOM AMBIENTE *********************************************

    SomAmbiente *somAmbiente = new SomAmbiente();

    // ***** BOTÕES *********************************************

    QRadioButton *ultimoApertado = nullptr;
    bool confirmarResposta = false;

};
#endif // MAINWINDOW_H
