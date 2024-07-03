#ifndef ARQUIVOS_H
#define ARQUIVOS_H

// Caixas de diálogo
#include <QDialog>
#include <QInputDialog>

// Para a String
#include <QString>

// Manipulação de arquivos
#include <QFile>

// Para o JSON
#include <QJsonArray>


/* ************************************************************
 * DEFINIÇÕES
 *************************************************************/

#define ARQUIVO_CONFIGURACAO_GERAL "config.json"

// Arquivos que serão utilizados para cada perfil
typedef struct{
    QString sequencia;
    QString respostas;
    QString pasta;
}structArquivos;

// Pastas para organização dos arquivos
typedef struct{
    QString configuracoes;
    QString backups;
}structPastas;

class Arquivos : public QDialog
{
    Q_OBJECT

public:
    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    explicit Arquivos(QWidget *parent = nullptr);

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~Arquivos();

    /* ************************************************************
     * AUXILIARES
     *************************************************************/

    /**
     * @brief Retorna a data atual em texto
     * @return A data em texto
     */
    QString carregarDataAtual();

    /**
     * @brief Retira caracteres de um texto
     * @param texto O texto a ser analisado
     * @param caractere O caractere que vamos retirar
     * @return O texto convertido
     */
    QString retirarCaracteres(QString texto, QString caractere);

    /* ************************************************************
     * PASTAS
     *************************************************************/

    /**
     * @brief Cria uma pasta
     * @param nomePasta O nome da nova pasta em relação ao diretório
     * do programa
     */
    void criarPasta(QString nomePasta);

    /**
     * @brief Abre uma caixa de diálogo para selecionar uma pasta
     * do sistema
     * @return O caminho completo da pasta selecionada, ou nulo caso
     * não seja selecionado
     */
    QString selecionarPasta();

    /**
     * @brief Conserta um caminho caso não esteja no formato correto
     * @param caminho O caminho para consertar
     * @return O caminho correto
     */
    QString consertarCaminhoPasta(QString caminho);

    /* ************************************************************
     * BACKUP DE VÍDEO
     *************************************************************/

    /**
     * @brief Abre uma caixa de diálogo para selecionar um vídeo
     * dos arquivos locais
     * @return O caminho completo do arquivo selecionado, ou nulo
     * caso não seja selecionado
     */
    QString selecionarVideo();

    /**
     * @brief Salva um vídeo nas pastas de backup
     * @param pasta Nome da pasta onde o vídeo será guardado
     * @return O nome do arquivo salvo, ou nulo caso não salve
     */
    QString salvarVideoBackup(QString pasta);

    /* ************************************************************
     * ARQUIVOS GERAIS
     *************************************************************/

    /**
     * @brief Verifica se o arquivo existe
     * @arg pathArquivo O caminho completo do arquivo
     * @return true caso exista, false caso contrário
     */
    static bool arquivoExiste(QString pathArquivo);

    /**
     * @brief Abre um arquivo para escrita
     * @param pathArquivo O caminho completo do arquivo a ser aberto
     * @return O endereço do arquivo, ou nulo caso haja erro
     */
    QFile *abrirArquivoEscrita(QString pathArquivo);

    /**
     * @brief Fecha o arquivo aberto
     * @param arquivo O endereço do arquivo aberto
     */
    void fecharArquivo(QFile *arquivo);

    /**
     * @brief Cria um arquivo dado todo seu caminho
     * @param pathArquivo O caminho completo do arquivo
     * @return True caso a operação tenha sido concluída, false para caso contrário
     */
    bool criarArquivo(QString pathArquivo);

    /**
     * @brief Inicializa o arquivo caso ele não exista
     * @param pathArquivo O caminho completo do arquivo
     * @return True caso o arquivo foi inicializado corretamente, False
     * para caso contrário
     */
    bool inicializarArquivo(QString pathArquivo);

    /**
     * @brief Copia um arquivo para uma pasta de destino
     * @param fonte O caminho completo de arquivo fonte
     * @param destino O caminho completo do arquivo destino
     * @return true caso a operação tenha sucesso, false para caso contrário
     */
    bool copiarArquivo(QString fonte, QString destino);

    /* ************************************************************
     * ARQUIVO CSV
     *************************************************************/

    /**
     * @brief Gera uma planilha CSV com os dados do arquivo de respostas mencionado
     * @param nomePerfil Nome do perfil que será o nome do arquivo
     * @param nomeArquivoRespostas Nome do arquivo de respostas fonte
     * @param pastaDestino A pasta de destino do arquivo
     */
    void gerarCSV(QString nomePerfil, QString nomeArquivoRespostas, QString pastaDestino);

    /* ************************************************************
     * ARQUIVOS JSON
     *************************************************************/

    static QString carregarPropriedadeJson(QString pathArquivo, QString propriedade);

    void modificarPropriedade(QJsonObject &jsonObject, QString propriedade, QString novoValor);

    // **** OBJETO ************************************************

    /**
     * @brief Carrega um objeto json armazenado em um arquivo
     * @param pathArquivo O caminho do arquivo
     */
    static QJsonObject carregarObjetoJson(QString pathArquivo);

    /**
     * @brief Escreve um objeto JSON em um arquivo .json
     * @param objetoJson O Objeto JSON
     * @param pathArquivo O caminho do arquivo .json
     * @return True caso dê tudo certo, false para caso contrário
     */
    static bool escreverObjetoJson(QJsonObject &objetoJson, QString pathArquivo);

    // **** ARRAY ************************************************

    /**
     * @brief Converte o arquivo JSON para um Array de JSON
     * @param pathArquivoJson O caminho completo do arquivo
     * @return O array de JSON
     */
    QJsonArray converterJsonParaArray(QString pathArquivoJson);

    /**
     * @brief Escreve os objetos JSON do array no arquivo .json
     * @param pathArquivoJson O caminho completo do arquivo .json
     * @param arrayJson O array de objetos JSON
     */
    void escreverArrayJson(QString pathArquivoJson, QJsonArray arrayJson);

    /* ************************************************************
     * ARQUIVO DE CONFIGURAÇÃO GERAL
     *************************************************************/

    /**
     * @brief Cria o arquivo de configuração geral
     * @param novaSenha A nova senha válida
     * @return true caso tudo tenha sido concluído com sucesso, false para caso contrário
     */
    bool criarArquivoGeral(QString novaSenha);

    // **** VISITAS ************************************************

    /**
     * @brief Aumenta o número de visitas no arquivo
     */
    void aumentarVisitas();

    /**
     * Aumenta o número de reproduções no arquivo
     */
    void aumentarReproducoes();

    /**
     * Atualiza o ultimo acesso ao programa
     */
    void atualizarUltimoAcesso();

    // **** EXPORTAÇÃO ************************************************

    /**
     * @brief Atualiza a ultima exportação no arquivo
     */
    void atualizarUltimaExportacao();

    // **** SENHA ************************************************
    
    /**
     * @brief Carrega a senha que está no arquivo
     */
    static QString carregarSenha();

    /**
     * @brief Altera a senha no arquivo
     * @param novaSenha A nova senha a ser escrita no arquivo
     */
    static void alterarSenha(QString novaSenha);

    /* ************************************************************
     * ARQUIVO DE CONFIGURAÇÃO DE SEQUÊNCIA
     *************************************************************/

    /**
     * @brief Carrega uma sequência de um um arquivo Json e o retorna
     * @param nomeArquivo O nome do arquivo que a sequência está armazenada
     * @return A sequência carregada
     */
    QJsonArray carregarSequenciaDoArquivo(QString nomeArquivo);

    /**
     * @brief Salva uma sequência em um arquivo Json
     * @param sequencia A sequência a ser salva
     * @param nomeArquivo O nome do arquivo que será salvo
     */
    void salvarSequenciaNoArquivo(QJsonArray sequencia, QString nomeArquivo);

    // **** VIDEO ************************************************

    /**
     * @brief Adiciona um vídeo no arquivo de sequência
     * @param caminhoDestino O caminho do arquivo
     * @param nomeArquivo O nome do arquivo de sequência
     */
    QJsonArray adicionarVideo(QString caminhoDestino, QString nomeArquivo);

    // **** PERGUNTA ************************************************

    /**
     * @brief Verifica se as respostas do objeto json são iguais às do array
     * @param array O array de sequência
     * @param obejto O objeto json
     */
    int encontrarRespostaExistente(QJsonArray array, QJsonObject objeto);

    /**
     * @brief Salva a resposta no arquivo
     * @param objetoJson O objeto que representa a pergunta respondida
     * @param respondida O número da resposta respondida
     * @param nomeArquivo O nome do arquivo que será escrito a resposta
     */
    void salvarResposta(QJsonObject objetoJson, int selecionada, QString nomeArquivo);

    /**
     * @brief Limpa as respostas armazenadas de um perfil
     * @param nomeArquivoRespostas Nome do arquivo que contém as respostas
     */
    void limparRespostas(QString nomeArquivoRespostas);

    // Nome das pastas (por enquanto, publico)
    structPastas pastas = {"configuracoes", "backups"};
private:

};

#endif // ARQUIVOS_H
