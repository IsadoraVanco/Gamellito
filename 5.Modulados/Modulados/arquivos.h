#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <QDialog>
#include <QInputDialog>

// Para a String
#include <QString>

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

namespace Ui {
class Senha;
}

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

    static QString carregarDataAtual();

    /* ************************************************************
     * PASTAS
     *************************************************************/

    static void criarPasta(QString nomePasta);

    /* ************************************************************
     * BACKUP DE VÍDEO
     *************************************************************/

    /**
     * @brief Abre uma caixa de diálogo para selecionar um vídeo
     * dos arquivos locais
     * @return O nome do arquivo escolhido
     */
    QString selecionarVideo();

    /**
     * @brief Salva um vídeo nas pastas de backup
     * @param pasta Nome da pasta final
     * @return O nome do arquivo salvo
     */
    QString salvarVideoBackup(QString pasta);

    /* ************************************************************
     * ARQUIVOS GERAIS
     *************************************************************/

    /**
     * @brief Verifica se o arquivo de existe, se não, exibe uma mensagem de erro
     * @arg pathArquivo O caminho completo do arquivo
     * @return True caso exista, False caso contrário
     */
    static bool arquivoExiste(QString pathArquivo);

    /**
     * @brief Cria um arquivo dado todo seu caminho
     * @param pathArquivo O caminho completo do arquivo
     * @return True caso a operação tenha sido concluída, false para caso contrário
     */
    static bool criarArquivo(QString pathArquivo);

    /**
     * @brief Inicializa o arquivo caso ele não exista
     * @param pathArquivo O caminho completo do arquivo
     * @return True caso o arquivo foi inicializado corretamente, False
     * para caso contrário
     */
    static bool inicializarArquivo(QString pathArquivo);

    /**
     * @brief
     * @param fonte
     * @param destino
     * @return
     */
    static bool copiarArquivo(QString fonte, QString destino);

    /* ************************************************************
     * ARQUIVOS JSON
     *************************************************************/

    /**
     * @brief
     * @param pathArquivo
     * @param propriedade
     * @return
     */
    static QString carregarPropriedadeJson(QString pathArquivo, QString propriedade);

    /**
     * @brief
     * @param jsonObject
     * @param propriedade
     * @param novoValor
     */
    static void modificarPropriedade(QJsonObject &jsonObject, QString propriedade, QString novoValor);

    // **** OBJETO ************************************************

    /**
     * @brief
     * @param pathArquivo
     * @return
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
    static QJsonArray converterJsonParaArray(QString pathArquivoJson);

    /**
     * @brief Escreve os objetos JSON do array no arquivo .json
     * @param pathArquivoJson O caminho completo do arquivo .json
     * @param arrayJson O array de objetos JSON
     */
    static void escreverArrayJson(QString pathArquivoJson, QJsonArray arrayJson);

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


    static void aumentarVisitas();

    static void aumentarReproducoes();

    static void atualizarUltimoAcesso();

    // **** EXPORTAÇÃO ************************************************

    static void atualizarUltimaExportacao();

    // **** SENHA ************************************************

    static QString carregarSenha();

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


    static QJsonArray adicionarVideo(QString caminhoDestino, QString nomeArquivo);

    // **** PERGUNTA ************************************************

    int encontrarRespostaExistente(QJsonArray array, QJsonObject objeto);

    void salvarResposta(QJsonObject objetoJson, int selecionada, QString nomeArquivo);

    // Nome das pastas (por enquanto, publico)
    structPastas pastas = {"configuracoes", "backups"};
private:

};

#endif // ARQUIVOS_H
