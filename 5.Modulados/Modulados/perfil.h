#ifndef PERFIL_H
#define PERFIL_H

#include <QString>

#include "sequencia.h"
#include "arquivos.h"

// Perfis disponíveis
enum class TipoPerfil{
    Paciente,       // 0
    Responsavel,    // 1
    Profissional    // 2
};

class Perfil{
public:

    /* ************************************************************
     * CONSTRUTOR
     *************************************************************/

    Perfil();

    /* ************************************************************
     * DESTRUTOR
     *************************************************************/

    ~Perfil();

    /* ************************************************************
     * CONFIGURAÇÕES
     *************************************************************/

    /**
     * @brief Carrega as sequências que estão no arquivo
     */
    void carregarSequencia();

    // Nome do perfil
    QString nome;
    // A estrutura de arquivos do perfil
    structArquivos arquivos;
    // A sequência de perguntas e vídeos do perfil
    Sequencia *sequencia;

private:

};

#endif // PERFIL_H
