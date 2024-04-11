#include "arquivos.h"

// Manipulação de diretório e arquivo
#include <QtCore>
#include <QFile>

// Caixas de diálogo
#include <QMessageBox>
#include <QInputDialog>

// Para o JSON
#include <QJsonDocument>

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

bool Arquivos::criarArquivo(QString pathArquivo){
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    // Caso haja erro ao criar o arquivo
    if(!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }

    qDebug() << "Arquivo criado!";
    arquivo.close();

    return true;
}

bool Arquivos::inicializarArquivo(QString pathArquivo){

    // Se não existe, então cria!
    if(!arquivoExiste(pathArquivo)){
        bool resultado = Arquivos::criarArquivo(pathArquivo);

        return resultado;
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

void Arquivos::escreverArrayJson(QString pathArquivoJson, QJsonArray arrayJson){
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

bool Arquivos::escreverObjetoJson(QJsonObject objetoJson, QString pathArquivo){
    QJsonDocument doc(objetoJson);

    // Convertendo o documento JSON para uma string
    QString jsonString = doc.toJson();

    // Escrevendo a string JSON em um arquivo
    QFile outputFile(pathArquivo);

    if(outputFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&outputFile);
        out << jsonString;
        outputFile.close();

        qDebug() << "Arquivo JSON salvo com sucesso.";
        return true;
    }else{
        qDebug() << "Erro ao abrir o arquivo JSON para escrita.";
        return false;
    }
}

/* ************************************************************
 * ARQUIVO DE CONFIGURAÇÃO GERAL
 *************************************************************/

bool Arquivos::preencherArquivoGeral(QString novaSenha, structArquivos paciente,
                                     structArquivos responsavel, structArquivos profissional){
    QJsonObject novoObjeto;

    novoObjeto["sequenciaPaciente"] = QString(paciente.sequencia);
    novoObjeto["respostasPaciente"] = QString(paciente.respostas);

    novoObjeto["sequenciaResponsavel"] = QString(responsavel.sequencia);
    novoObjeto["respostasResponsavel"] = QString(responsavel.respostas);

    novoObjeto["sequenciaProfissional"] = QString(profissional.sequencia);
    novoObjeto["respostasProfissional"] = QString(profissional.respostas);

    novoObjeto["numeroAcessos"] = 1; // acessando agora :)
    novoObjeto["senha"] = novaSenha;

    return escreverObjetoJson(novoObjeto, QString(ARQUIVO_CONFIGURACAO_GERAL));
}


