/**
 * @brief
 */
#ifndef USUARIO_H
#define USUARIO_H


// Para o nome dos arquivos
#include <QString>
// Para a sequência de vídeos e perguntas
#include <QJsonArray>

class Usuario
{
    // Nome do arquivo que armazena a sequência de vídeo e pergunta
    QString nomeArquivoSequencia;
    // Nome do arquivo que armazena as respostas das perguntas
    QString nomeArquivoRespostas;
    // O array com a sequencia de vídeos e perguntas
    QJsonArray arraySequencia;

public:
    // Métodos

    // Construtor
    Usuario();
};

#endif // USUARIO_H
