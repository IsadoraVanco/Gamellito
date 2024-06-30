#include "perfil.h"


/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Perfil::Perfil(){
    this->sequencia = new Sequencia();
}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Perfil::~Perfil(){
    delete sequencia;
}

/* ************************************************************
 * CONFIGURAÇÕES
 *************************************************************/

void Perfil::carregarSequencia(){

    if(this->arquivos.sequencia.isEmpty()){
        qDebug() << "[Perfil][ERRO] O arquivo de sequência ainda não foi definido";
        return;
    }

    this->sequencia->carregarDoArquivo(this->arquivos.sequencia);
}
