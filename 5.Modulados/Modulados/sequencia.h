#ifndef SEQUENCIA_H
#define SEQUENCIA_H

// Para armazenar a sequência
#include <QJsonArray>
#include <QJsonObject>

class Sequencia
{
public:
    Sequencia();

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
     * @brief Retorna o valor do item no index indicado na sequência
     * @param index O index do item na sequência
     * @return O valor do item
     */
    QString valorItem(int index);

private:
    // Marca qual o índice do elemento atual da sequência
    int indiceAtual = 0;

    QJsonArray *array;
};

#endif // SEQUENCIA_H
