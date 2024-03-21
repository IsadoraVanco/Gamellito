#include "arquivos.h"

// Para arquivos
#include <QFile>
#include <QTextStream>
#include <QDir>

// Para o JSON
#include <QJsonDocument>
#include <QJsonObject>

// Para debugar
//#include <QApplication>

Arquivos::Arquivos()
{

}

bool Arquivos::arquivoExiste(QString pathArquivo){

    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    if(!arquivo.exists()){
        qDebug() << "Erro: O arquivo " + pathArquivo + " não foi encontrado!";
        return false;
    }

    qDebug() << "O arquivo " + pathArquivo + " existe!";
    return true;
}

bool Arquivos::inicializarArquivo(QString pathArquivo){

    // Se não existe, então cria!
    if(!arquivoExiste(pathArquivo)){
        QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

        // Caso haja erro ao criar o arquivo
        if(!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
            return false;
        }

        qDebug() << "Arquivo de configuração criado!";
        arquivo.close();
    }

    return true;
}

/* ************************************************************
 * ARQUIVOS JSON
 *************************************************************/

QJsonArray Arquivos::converterJsonParaArray(QString pathArquivoJson){

    QJsonArray arrayJson;

    // Abre o arquivo para leitura
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivoJson));

    // Caso haja erro para abrir o arquivo
    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        // Oq vai retornar?
        return arrayJson;
    }

    // Lê o arquivo
    QTextStream in(&arquivo);
    QString textoJson = in.readAll();
    arquivo.close();

    // Converte a string em um documento JSON
    QJsonDocument doc = QJsonDocument::fromJson(textoJson.toUtf8());

    // Converte o documento JSON em um array JSON
    arrayJson = doc.array();

    return arrayJson;
}

void Arquivos::escreverJson(QString pathArquivoJson, QJsonArray arrayJson){
    // Cria um documento JSON a partir do array JSON
    QJsonDocument doc(arrayJson);

    // Converte o documento JSON em uma string
    QString strJson(doc.toJson(QJsonDocument::Compact));

    // Cria um objeto QFile com o nome do arquivo
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivoJson));

    // Abre o arquivo para escrita
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "Erro ao escrever JSON";
        return;
    }

    // Escreve a string no arquivo
    QTextStream out(&arquivo);
    out << strJson;

    arquivo.close();

    qDebug() << "Arquivo JSON salvo";
}
