#ifndef SEQUENCIA_H
#define SEQUENCIA_H

// Para armazenar a sequência
#include <QJsonArray>
#include <QJsonObject>

// Para configurar arquivos
#include "arquivos.h"

// Tipos de itens
enum class TipoItem{
    Indefinido, // 0
    Pergunta,   // 1
    Video       // 2
};

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

    /**
     * @brief Retorna o item de um index da sequência
     * @param index Valor do index
     * @return O item
     */
    QJsonObject getItem(int index);

    /**
     * @brief Retorna o item no indice atual da sequência
     * @return Um QJsonObject
     */
    QJsonObject getItemNoIndexAtual();

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
    TipoItem tipoItemNoIndexAtual();

    /**
     * @brief Retorna o tipo do item no index indicado na sequência
     * @param index O index do item na sequência
     * @return O valor do item
     */
    TipoItem tipoItem(int index);

    /**
     * @brief Calcula um Id para o novo item da lista
     * @return O novo Id
     */
    int calcularNovoId();

    // **** ÍNDICE ************************************************

    /**
     * @brief Verifica se um índice é válido para o array
     * @param index O index a ser analisado
     * @return true caso seja válido, false para caso contrário
     */
    bool ehIndiceValido(int index);

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
     * @brief Altera a posição de um elemento
     * @param index O index atual
     * @param novoIndex O novo index do elemento
     */
    void alterarIndice(int index, int novoIndex);

    // **** MANIPULAÇÃO DE ITENS ************************************************

    /**
     * @brief Limpa toda a sequência
     */
    void limpar();

    /**
     * @brief Carrega a sequência armazenada no arquivo
     * @param nomeArquivo O nome do arquivo que está a sequência
     */
    void carregarDoArquivo(QString nomeArquivo);

    /**
     * @brief Adiciona um vídeo na sequência
     * @param nomeArquivo O nome do arquivo de vídeo que será adicionado
     */
    void adicionarVideo(QString nomeArquivo);

    /**
     * @brief Edita um item de vídeo da sequência
     * @param index O index onde está o item
     * @param nomeArquivo O nome do arquivo atualizado
     */
    void editarVideo(int index, QString nomeArquivo);

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

    /**
     * @brief Edita uma pergunta que está no index
     * @param index O index do item na sequência
     * @param pergunta A pergunta a ser editada
     * @param opcao1 Opção que será editada
     * @param opcao2 Opção que será editada
     * @param opcao3 Opção que será editada
     * @param opcao4 Opção que será editada
     * @param correta O número da opção correta
     */
    void editarPergunta(int index, QString pergunta, QString opcao1, QString opcao2, QString opcao3, QString opcao4, int correta);

    /**
     * @brief Remove um item da sequência
     * @param index O index do item a ser removido
     */
    void removerItem(int index);

    // **** CONSULTA DE ITENS ************************************************

    /**
     * @brief Verifica se um item no index indicado é uma pergunta
     * @param index O index do item
     * @return True caso seja uma pergunta, false para caso contrário
     */
    bool ehPergunta(int index);

    /**
     * @brief Retorna a pergunta caso o item do index seja uma pergunta.
     * @param index O index do item
     * @return A pergunta
     */
    QString getPergunta(int index);

    /**
     * @brief Retorna a pergunta do item no indice atual
     * @return A pergunta
     */
    QString getPerguntaNoIndiceAtual();

    /**
     * @brief Retorna a primeira opção da resposta caso o item no index seja uma pergunta
     * @param index O index do item
     * @return A opção
     */
    QString getOpcao1(int index);

    /**
     * @brief Retorna a primeira opção da resposta no item no índice atual
     * @return A opção
     */
    QString getOpcao1NoIndiceAtual();

    /**
     * @brief Retorna a segunda opção da resposta caso o item no index seja uma pergunta
     * @param index O index do item
     * @return A opção
     */
    QString getOpcao2(int index);

    /**
     * @brief Retorna a segunda opção da resposta no item no índice atual
     * @return A opção
     */
    QString getOpcao2NoIndiceAtual();

    /**
     * @brief Retorna a terceira opção da resposta caso o item no index seja uma pergunta
     * @param index O index do item
     * @return A opção
     */
    QString getOpcao3(int index);

    /**
     * @brief Retorna a terceira opção da resposta no item no índice atual
     * @return A opção
     */
    QString getOpcao3NoIndiceAtual();

    /**
     * @brief Retorna a quarta opção da resposta caso o item no index seja uma pergunta
     * @param index O index do item
     * @return A opção
     */
    QString getOpcao4(int index);

    /**
     * @brief Retorna a quarta opção da resposta no item no índice atual
     * @return A opção
     */
    QString getOpcao4NoIndiceAtual();

    /**
     * @brief O número que representa a opção correta da pergunta no index
     * @param index O index do item
     * @return O número da opção correta
     */
    int getRespostaCorreta(int index);

    /**
     * @brief Retorna o número da resposta correta de um item no indice atual
     * @return O número da resposta correta
     */
    int getRespostaCorretaNoIndiceAtual();

private:
    // Marca qual o índice do elemento atual da sequência
    int indiceAtual = 0;

    QJsonArray *array;

    // Configurar
    Arquivos *arquivos = new Arquivos();
};

#endif // SEQUENCIA_H
