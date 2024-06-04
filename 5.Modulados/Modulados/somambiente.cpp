#include "somambiente.h"

SomAmbiente::SomAmbiente(){}

bool SomAmbiente::configurar(QString nomeArquivo){

    QDir dir = QDir::current();
    // O arquivo de som deve estar na pasta de assets!
    QString caminho = dir.filePath("assets/sons/" + nomeArquivo);

    if(!QFile::exists(caminho)){
        qDebug() << "[Som][Erro] Arquivo de som não encontrado:" << caminho;
        som = nullptr;
        return false;
    }

    som = new QSound(QString(caminho));
    som->setLoops(QSound::Infinite);

    qDebug() << "[Som][OK] Som configurado:" << nomeArquivo;
    return true;
}

void SomAmbiente::ligar(){
    if(som){
        som->play();
        mutado = false;
    }
}

void SomAmbiente::desligar(){
    if(som){
        som->stop();
        mutado = true;
    }
}

bool SomAmbiente::estaMutado(){
    return mutado == true;
}
