#include "perfil.h"

Perfil::Perfil(){
    this->sequencia = new Sequencia();
}


QString Perfil::capitalizarTexto(QString texto){
    return texto.left(1).toUpper() + texto.right(texto.length() - 1).toLower();
}

QString Perfil::pastaCapitalizada(){
    return capitalizarTexto(this->arquivos.pasta);
}
