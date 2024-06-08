#ifndef SEQUENCIA_H
#define SEQUENCIA_H

// Para armazenar a sequência
#include <QJsonArray>
#include <QJsonObject>

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
     * @brief Calcula um Id para o novo item da lista
     * @return O novo Id
     */
    int calcularNovoId();

    // **** ITENS ************************************************

    /**
     * @brief Retorna o valor do item no index indicado na sequência
     * @param index O index do item na sequência
     * @return O valor do item
     */
    QString valorItem(int index);

    // **** MANIPULAÇÃO DE ITENS ************************************************

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
};

#endif // SEQUENCIA_H
