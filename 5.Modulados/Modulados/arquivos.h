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

//Arquivos que serão utilizados
typedef struct{
    QString sequencia;
    QString respostas;
}structArquivos;

class Arquivos
{
public:
    // Construtor
    Arquivos();

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

    /* ************************************************************
     * ARQUIVOS JSON
     *************************************************************/

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

    /**
     * @brief Escreve um objeto JSON em um arquivo .json
     * @param objetoJson O Objeto JSON
     * @param pathArquivo O caminho do arquivo .json
     * @return True caso dê tudo certo, false para caso contrário
     */
    static bool escreverObjetoJson(QJsonObject objetoJson, QString pathArquivo);

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

private:

};

#endif // ARQUIVOS_H
