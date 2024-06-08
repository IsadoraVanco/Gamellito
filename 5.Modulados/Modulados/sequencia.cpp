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

// **** ÍNDICE ************************************************

void Sequencia::resetarIndice(){
    this->indiceAtual = 0;
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

// **** ITENS ************************************************

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

// **** MANIPULAÇÃO DE ITENS ************************************************

QJsonObject Sequencia::getItemNoIndexAtual(){
    return this->array->at(indiceAtual).toObject();
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
