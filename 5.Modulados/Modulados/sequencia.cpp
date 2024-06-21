#include "sequencia.h"


// **** CONSTRUTOR ************************************************

Sequencia::Sequencia(){
    array = new QJsonArray();
}

// **** BÁSICOS ************************************************

bool Sequencia::estaVazia(){
    return array->isEmpty();
}

int Sequencia::tamanho(){
    return this->array->size();
}

QJsonArray Sequencia::getSequencia(){
    return *this->array;
}

QJsonObject Sequencia::getItem(int index){
    if(index < 0 || index >= this->array->size()){
        return QJsonObject();
    }

    return this->array->at(index).toObject();
}

QJsonObject Sequencia::getItemNoIndexAtual(){
    return getItem(indiceAtual);
}

QString Sequencia::valorChave(QJsonObject objetoJson, QString chave){

    // Verifica se o objeto possui uma chave chamada "tipo"
    if(objetoJson.contains(chave)) {

        // Acessa o valor da chave
        QString valor = objetoJson[chave].toString();

        qDebug() << "[Sequencia][OK] O elemento possui a chave" << chave << "e possui valor" << valor;
        return valor;
    } else {
        qDebug() << "[Sequencia][ERRO] O elemento não possui uma chave chamada" << chave;
        return QString();
    }
}

QString Sequencia::valorChaveNoIndexAtual(QString chave){

    QJsonObject objeto = getItem(indiceAtual);

    return valorChave(objeto, chave);
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

QString Sequencia::valorItemNoIndexAtual(){
    return valorItem(indiceAtual);
}

TipoItem Sequencia::tipoItem(int index){

    if(index < 0 || index >= this->array->size()){
        return TipoItem::Indefinido;
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(objeto["tipo"] == "video"){
        return TipoItem::Video;

    }else if(objeto["tipo"] == "pergunta"){
        return TipoItem::Pergunta;
    }

    return TipoItem::Indefinido;
}

TipoItem Sequencia::tipoItemNoIndexAtual(){
    return tipoItem(indiceAtual);
}

// **** ÍNDICE ************************************************

void Sequencia::resetarIndice(){
    this->indiceAtual = 0;
}

bool Sequencia::proximoIndice(){

    if(this->indiceAtual + 1 >= this->array->size()){
        this->resetarIndice();
        return false;
    }

    this->indiceAtual++;
    return true;
}

bool Sequencia::indiceAnterior(){

    if(this->indiceAtual - 1 < 0){
        this->resetarIndice();
        return false;
    }

    this->indiceAtual--;
    return true;
}

int Sequencia::calcularNovoId(){
    int id = 0;

    // Percorre o array e encontra o maior id
    for(const QJsonValue valor : *this->array){

        // Verifica se o valor é um objeto
        if(valor.isObject()){

            // Converte o valor para um objeto
            QJsonObject objeto = valor.toObject();

            // Verifica se o objeto possui a chave "id"
            if(objeto.contains("id")){
                int idAtual = objeto["id"].toInt();

                // Atualiza o valor de id se o id atual for maior
                if (idAtual > id) {
                    id = idAtual;
                }
            }
        }
    }

    // Retorna um id maior para o novo
    return id + 1;
}

// **** MANIPULAÇÃO DE ITENS ************************************************

void Sequencia::carregarDoArquivo(QString nomeArquivo){

    *this->array = arquivos->carregarSequenciaDoArquivo(nomeArquivo);
}

void Sequencia::adicionarVideo(QString nomeArquivo){

    // Calcula o id para o novo item
    int id = this->calcularNovoId();

    // Cria um novo objeto JSON para o vídeo
    QJsonObject novoVideo;

    novoVideo["id"] = id;
    novoVideo["tipo"] = "video";
    novoVideo["caminho"] = nomeArquivo;

    // Adiciona o novo video no fim do array
    this->array->append(novoVideo);

    qDebug() << "[Sequência][OK] Video adicionado na sequencia";
}

void Sequencia::editarVideo(int index, QString nomeArquivo){

    QJsonObject objeto = this->array->at(index).toObject();

    if(!objeto.contains("caminho")){
        qDebug() << "[Sequência][ERRO] Vídeo NÃO pode ser editado na sequência";
        return;
    }

    // Edita o objeto
    objeto["caminho"] = nomeArquivo;

    // Atualiza a sequência
    (*this->array)[index] = objeto;

    qDebug() << "[Sequência][OK] Vídeo editado na sequência:" << nomeArquivo;
}

void Sequencia::adicionarPergunta(QString pergunta, QString opcao1, QString opcao2, QString opcao3, QString opcao4, int correta){

    // Calcula o id para o novo item
    int id = this->calcularNovoId();

    // Cria um novo objeto JSON para a pergunta
    QJsonObject novaPergunta;

    novaPergunta["id"] = id;
    novaPergunta["tipo"] = "pergunta";
    novaPergunta["pergunta"] = pergunta;
    novaPergunta["opcao1"] = opcao1;
    novaPergunta["opcao2"] = opcao2;
    novaPergunta["opcao3"] = opcao3;
    novaPergunta["opcao4"] = opcao4;
    novaPergunta["correta"] = correta;

    // Adiciona o novo video no fim do array
    this->array->append(novaPergunta);

    qDebug() << "[Sequência][OK] Pergunta adicionada na sequencia";
}

void Sequencia::editarPergunta(int index, QString pergunta, QString opcao1, QString opcao2, QString opcao3, QString opcao4, int correta){
    if(!ehPergunta(index)){
        return;
    }

    QJsonObject objeto = this->array->at(index).toObject();

    objeto["pergunta"] = pergunta;
    objeto["opcao1"] = opcao1;
    objeto["opcao2"] = opcao2;
    objeto["opcao3"] = opcao3;
    objeto["opcao4"] = opcao4;
    objeto["correta"] = correta;

    // Adiciona o item editado no mesmo índice
    (*this->array)[index] = objeto;
}

void Sequencia::removerItem(int index){
    if(index < 0 || index >= this->array->size()){
        return;
    }

    // Remove o item do array
    this->array->removeAt(index);

    qDebug() << "[Sequência][OK] O item foi removido da sequência";
}

// **** CONSULTA DE ITENS ************************************************

bool Sequencia::ehPergunta(int index){
    if(index < 0 || index >= this->array->size()){
        return false;
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(objeto["tipo"] != "pergunta"){
        qDebug() << "[Sequência][INFO] O item no index " << index << "NÃO é uma pergunta";
        return false;
    }

    return true;
}

QString Sequencia::getPergunta(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return QString();
    }

    return objeto["pergunta"].toString();
}

QString Sequencia::getPerguntaNoIndiceAtual(){
    return getPergunta(indiceAtual);
}

QString Sequencia::getOpcao1(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return QString();
    }

    return objeto["opcao1"].toString();
}

QString Sequencia::getOpcao1NoIndiceAtual(){
    return getOpcao1(indiceAtual);
}

QString Sequencia::getOpcao2(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return QString();
    }

    return objeto["opcao2"].toString();
}

QString Sequencia::getOpcao2NoIndiceAtual(){
    return getOpcao2(indiceAtual);
}

QString Sequencia::getOpcao3(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return QString();
    }

    return objeto["opcao3"].toString();
}

QString Sequencia::getOpcao3NoIndiceAtual(){
    return getOpcao3(indiceAtual);
}

QString Sequencia::getOpcao4(int index){
    if(index < 0 || index >= this->array->size()){
        return QString();
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return QString();
    }

    return objeto["opcao4"].toString();
}

QString Sequencia::getOpcao4NoIndiceAtual(){
    return getOpcao4(indiceAtual);
}

int Sequencia::getRespostaCorreta(int index){
    if(index < 0 || index >= this->array->size()){
        return -1;
    }

    QJsonObject objeto = this->array->at(index).toObject();

    if(!ehPergunta(index)){
        return -1;
    }

    return objeto["correta"].toInt();
}

int Sequencia::getRespostaCorretaNoIndiceAtual(){
    return getRespostaCorreta(indiceAtual);
}
