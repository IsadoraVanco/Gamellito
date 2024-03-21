/**
 * Manipulando arquivos necessários: JSON e TXT
 */
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

// Para a String
#include <QString>

// Para o JSON
#include <QJsonArray>


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
    static void escreverJson(QString pathArquivoJson, QJsonArray arrayJson);

};

#endif // ARQUIVOS_H
