#ifndef ARQUIVOS_H
#define ARQUIVOS_H

// Para a String
#include <QString>
#include <string>

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

class Arquivos
{
public:
    // Construtor
    Arquivos();

    /* ************************************************************
     * AUXILIARES
     *************************************************************/

    /**
     * @brief
     * @return
     */
    static QString carregarDataAtual();

    /* ************************************************************
     * PASTAS
     *************************************************************/

    /**
     * @brief
     * @param nomePasta
     */
    static void criarPasta(QString nomePasta);

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

    /**
     * @brief
     * @param objetoJson
     * @param chave
     * @return
     */
    static QString retornarValorChaveObjeto(QJsonObject objetoJson, QString chave);

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
     * @brief Preenche o arquivo de configurações iniciais
     * @param nomeArquivo
     * @param senha
     * @return True caso dê tudo certo, false para caso contrário
     */
    static bool preencherArquivoGeral(QString novaSenha, structArquivos paciente,
                         structArquivos responsavel, structArquivos profissional);

    // **** VISITAS ************************************************

    /**
     * @brief
     */
    static void aumentarVisitas();

    /**
     * @brief
     */
    static void aumentarReproducoes();

    /**
     * @brief
     */
    static void atualizarUltimoAcesso();

    // **** EXPORTAÇÃO ************************************************

    /**
     * @brief
     */
    static void atualizarUltimaExportacao();

    // **** SENHA ************************************************

    /**
     * @brief
     * @return
     */
    static QString carregarSenha();

    /**
     * @brief
     * @param novaSenha
     */
    static void alterarSenha(QString novaSenha);

    /* ************************************************************
     * ARQUIVO DE CONFIGURAÇÃO DE SEQUÊNCIA
     *************************************************************/

    /**
     * @brief
     * @param sequencia
     * @return
     */
    static int calcularId(QJsonArray sequencia);

    // **** VIDEO ************************************************

    /**
     * @brief
     * @param caminhoDestino
     * @param nomeArquivo
     * @return
     */
    static QJsonArray adicionarVideo(QString caminhoDestino, QString nomeArquivo);

    // **** PERGUNTA ************************************************

    /**
     * @brief
     * @param caminhoDestino
     * @param pergunta
     * @param opcao1
     * @param opcao2
     * @param opcao3
     * @param opcao4
     * @param correta
     * @return
     */
    static QJsonArray adicionarPergunta(QString caminhoDestino, QString pergunta, QString opcao1, QString opcao2, QString opcao3, QString opcao4, int correta);

    /**
     * @brief
     * @param array
     * @param objeto
     * @return
     */
    static int encontrarRespostaExistente(QJsonArray array, QJsonObject objeto);

    /**
     * @brief
     * @param objetoJson
     * @param caminhoDestino
     * @param selecionada
     */
    static void salvarResposta(QJsonObject objetoJson, QString caminhoDestino, int selecionada);

    // Nome das pastas (por enquanto, publico)
    structPastas pastas = {"configuracoes", "backups"};
private:

};

#endif // ARQUIVOS_H
