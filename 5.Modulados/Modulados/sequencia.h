#ifndef SEQUENCIA_H
#define SEQUENCIA_H

// Para armazenar a sequência
#include <QJsonArray>
#include <QJsonObject>

// Para configurar arquivos
#include "arquivos.h"

class Sequencia
{
public:
    // **** CONSTRUTOR ************************************************

    Sequencia();

    // **** BÁSICOS ************************************************

    /**
     * @brief Verifica se uma sequência está vazia.
     * @return true caso esteja vazia, false para caso contrário.
     */
    bool estaVazia();

    /**
     * @brief Verifica o tamanho da sequência
     * @return O tamanho da sequência
     */
    int tamanho();

    /**
     * @brief Retorna o array da sequência
     * @return Um QJsonArray
     */
    QJsonArray getSequencia();

    // **** ÍNDICE ************************************************

    /**
     * @brief Modifica o índice atual para o início
     */
    void resetarIndice();

    /**
     * @brief Calcula o próximo indice da sequencia e indica se ainda está dentro
     * do limite
     * @return true caso ainda esteja dentro do limite do indice, false para caso
     * contrário
     */
    bool proximoIndice();

    /**
     * @brief Calcula o indice anterior da sequencia e indica se ainda está dentro
     * do limite
     * @return true caso ainda esteja dentro do limite do indice, false para caso
     * contrário
     */
    bool indiceAnterior();

    /**
     * @brief Calcula um Id para o novo item da lista
     * @return O novo Id
     */
    int calcularNovoId();

    // **** MANIPULAÇÃO DE ITENS ************************************************

    /**
     * @brief Carrega a sequência armazenada no arquivo
     * @param nomeArquivo O nome do arquivo que está a sequência
     */
    void carregarDoArquivo(QString nomeArquivo);

    /**
     * @brief Retorna o valor da chave de um objeto Json
     * @param objetoJson O objeto Json
     * @param chave A chave a ser buscada
     * @return O valor da chave do objeto Json
     */
    static QString valorChave(QJsonObject objetoJson, QString chave);

    /**
     * @brief Retorna o valor da chave do item no index atual
     * @param chave A chave a ser buscada
     * @return O valor da chave no item
     */
    QString valorChaveNoIndexAtual(QString chave);

    /**
     * @brief Retorna o valor do item no index indicado na sequência
     * @param index O index do item na sequência
     * @return O valor do item
     */
    QString valorItem(int index);

    /**
     * @brief Retorna o valor do item no index atual
     * @return O valor do item
     */
    QString valorItemNoIndexAtual();

    /**
     * @brief Retorna o tipo do item no indice atual da sequência
     * @return O tipo do item
     */
    QString tipoItemNoIndexAtual();

    /**
     * @brief Retorna o item no indice atual da sequência
     * @return Um QJsonObject
     */
    QJsonObject getItemNoIndexAtual();

    /**
     * @brief Adiciona um vídeo na sequência
     * @param nomeArquivo O nome do arquivo de vídeo que será adicionado
     */
    void adicionarVideo(QString nomeArquivo);

    /**
     * @brief Adiciona uma pergunta na sequência
     * @param pergunta A pergunta
     * @param opcao1 Uma opção de resposta
     * @param opcao2 Uma opção de resposta
     * @param opcao3 Uma opção de resposta
     * @param opcao4 Uma opção de resposta
     * @param correta Número da resposta correta
     */
    void adicionarPergunta(QString pergunta, QString opcao1, QString opcao2, QString opcao3, QString opcao4, int correta);

private:
    // Marca qual o índice do elemento atual da sequência
    int indiceAtual = 0;

    QJsonArray *array;

    // Configurar
    Arquivos *arquivos = new Arquivos();
};

#endif // SEQUENCIA_H
