#include "sequencia.h"

Sequencia::Sequencia(){
    array = new QJsonArray();
}

bool Sequencia::estaVazia(){
    return array->isEmpty();
}

int Sequencia::tamanho(){
    return this->array->size();
}

QString Sequencia::valorItem(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(objeto["tipo"] == "video"){
        return objeto["caminho"].toString();

    }else if(objeto["tipo"] == "pergunta"){
        return objeto["pergunta"].toString();
    }

    return QString();
}
