#include "arquivos.h"

// Manipulação de diretório e arquivo
#include <QtCore>
#include <QFile>

// Escolha de arquivo
#include <QFileDialog>

// Caixa de diálogo
#include <QMessageBox>

// Para o JSON
#include <QJsonDocument>

// Para a manipulação de data e hora
#include <QDateTime>

/* ************************************************************
 * CONSTRUTOR
 *************************************************************/

Arquivos::Arquivos(QWidget *parent): QDialog(parent){}

/* ************************************************************
 * DESTRUTOR
 *************************************************************/

Arquivos::~Arquivos(){}

/* ************************************************************
 * AUXILIARES
 *************************************************************/

QString Arquivos::carregarDataAtual(){
    // Criar um objeto de data e hora
    QDateTime dataHora = QDateTime::currentDateTime();

    // Formata a data e hora
    QString dataHoraFormatada = dataHora.toString("dd/MM/yyyy HH:mm:ss");

    return dataHoraFormatada;
}

/* ************************************************************
 * PASTAS
 *************************************************************/

void Arquivos::criarPasta(QString nomePasta){

    // Verificar se a pasta já existe
    if(QDir(nomePasta).exists()){
        qDebug() << "[Arquivos][INFO] A pasta" << nomePasta << "já existe";

    }else{
        if(QDir().mkdir(nomePasta)){
            qDebug() << "[Arquivos][OK] Pasta" << nomePasta << "criada com sucesso.";
        }else{
            qDebug() << "[Arquivos][ERRO] Falha ao criar a pasta" << nomePasta;
        }
    }
}

/* ************************************************************
 * BACKUP DE VÍDEO
 *************************************************************/

QString Arquivos::selecionarVideo(){
    QString diretorioInicial = QDir::homePath();

    // Adiciona uma barra no final se não houver
    if (!diretorioInicial.endsWith(QDir::separator())) {
        diretorioInicial += QDir::separator();
    }

    QString caminhoArquivo = QFileDialog::getOpenFileName(this, tr("Selecione o video"), diretorioInicial, tr("MP4 (*.mp4);; MKV (*.mkv)"));

    return caminhoArquivo;
}

QString Arquivos::salvarVideoBackup(QString pasta){
    // Seleciona o vídeo
    QString caminhoArquivo = selecionarVideo();

    // Verifica se o arquivo foi escolhido e existe
    if(caminhoArquivo == "" || !arquivoExiste(caminhoArquivo)){
        return QString();
    }

    // Cria a pasta de backup geral
    criarPasta(pastas.backups);

    // Cria a pasta do perfil
    QString pastaPerfil = pastas.backups + '/' + pasta + '/';
    criarPasta(pastaPerfil);

    // Copia o nome do arquivo
    QFileInfo arquivo(caminhoArquivo);
    QString nomeArquivo = arquivo.fileName();

    // Monta o caminho completo de destino
    QString destinoCompleto = pastaPerfil + nomeArquivo;

    if(Arquivos::copiarArquivo(caminhoArquivo, destinoCompleto)) {
        QMessageBox::about(this, "Arquivo copiado", "Arquivo copiado para o backup!");
        qDebug() << "[Arquivos][OK] Arquivo copiado com sucesso:" << caminhoArquivo;
    }else{
        //QMessageBox::critical(this, "ERRO", "Erro ao copiar o arquivo para o backup. Por favor, tente novamente.");
        QMessageBox::about(this, "Arquivo duplicado", "O arquivo já está no backup");
        qDebug() << "[Arquivos][ERRO] Falha ao copiar o arquivo:" << caminhoArquivo;
    }

    return nomeArquivo;
}

/* ************************************************************
 * ARQUIVOS GERAIS
 *************************************************************/

bool Arquivos::arquivoExiste(QString pathArquivo){

    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    if(!arquivo.exists()){
        qDebug() << "[Arquivos][ERRO] O arquivo" << pathArquivo << "não existe!";
        return false;
    }

    qDebug() << "[Arquivos][OK] O arquivo" << pathArquivo << "existe!";
    return true;
}

bool Arquivos::criarArquivo(QString pathArquivo){
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    // Caso haja erro ao criar o arquivo
    if(!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "[Arquivos][ERRO] Erro ao criar arquivo:" << pathArquivo;
        return false;
    }

    qDebug() << "[Arquivos][OK] Arquivo" << pathArquivo << "criado!";
    arquivo.close();

    return true;
}

bool Arquivos::inicializarArquivo(QString pathArquivo){

    // Se não existe, então cria!
    if(!arquivoExiste(pathArquivo)){
        return Arquivos::criarArquivo(pathArquivo);
    }

    return true;
}

bool Arquivos::copiarArquivo(QString fonte, QString destino){

    return QFile::copy(fonte, destino);
}

/* ************************************************************
 * ARQUIVOS JSON
 *************************************************************/

QString Arquivos::carregarPropriedadeJson(QString pathArquivo, QString propriedade){

    QJsonObject jsonObject = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    if (!jsonObject.contains(propriedade)) {
        qDebug() << "[Arquivos] A propriedade " + propriedade + " não foi encontrada no arquivo " + pathArquivo;
        return "";
    }

    return jsonObject[propriedade].toString();
}

void Arquivos::modificarPropriedade(QJsonObject &jsonObject, QString propriedade, QString novoValor){
    if (!jsonObject.contains(propriedade)){
        qDebug() << "[Arquivos] [ERRO] Objeto Json inválido. A propriedade não foi encontrada:" << propriedade;
        return;
    }

    jsonObject[propriedade] = novoValor;
}

// **** OBJETO ************************************************

QJsonObject Arquivos::carregarObjetoJson(QString pathArquivo){

    // Carrega o arquivo
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "[Arquivos] [ERRO] Erro ao abrir o arquivo Json:" << pathArquivo;
        return QJsonObject();
    }

    QByteArray valoresJson = arquivo.readAll();
    arquivo.close();

    QJsonParseError erro;
    QJsonDocument arquivoJson = QJsonDocument::fromJson(valoresJson, &erro);

    if (erro.error != QJsonParseError::NoError) {
        qDebug() << "[Arquivos] [ERRO] Erro ao ler arquivo Json:" << pathArquivo;
        return QJsonObject();
    }

    if (!arquivoJson.isObject()) {
        qDebug() << "[Arquivos] [ERRO] O arquivo não está em formato JSON:" << pathArquivo;
        return QJsonObject();
    }

    return arquivoJson.object();
}


bool Arquivos::escreverObjetoJson(QJsonObject &objetoJson, QString pathArquivo){
    // Cria um documento Json
    QJsonDocument docJson(objetoJson);

    // Converte o documento JSON para uma string
    //QString jsonString = docJson.toJson();

    // Escrevendo a string Json em um arquivo já existente
    QFile arquivoJson(pathArquivo);

    if(arquivoJson.open(QIODevice::WriteOnly | QIODevice::Text)){
        //QTextStream out(&arquivoJson);
        //out << jsonString;
        arquivoJson.write(docJson.toJson());
        arquivoJson.close();

        qDebug() << "[Arquivos] [OK] Arquivo JSON salvo com sucesso:" << pathArquivo;
        return true;
    }else{
        qDebug() << "[Arquivos] [ERRO] Erro ao abrir o arquivo JSON para escrita:" << pathArquivo;
        return false;
    }
}

QString Arquivos::retornarValorChaveObjeto(QJsonObject objetoJson, QString chave){

    // Verifica se o objeto possui uma chave chamada "tipo"
    if (objetoJson.contains(chave)) {

        // Acessa o valor da chave
        QString valor = objetoJson[chave].toString();

        qDebug() << "[Arquivos] [OK] O elemento atual possui a chave" << chave << "e possui valor" << valor;
        return valor;
    } else {
        qDebug() << "[Arquivos] [ERRO] O elemento atual não possui uma chave chamada" << chave;
        return QString();
    }
}

// **** ARRAY ************************************************

QJsonArray Arquivos::converterJsonParaArray(QString pathArquivoJson){

    QFile arquivo(QDir::current().absoluteFilePath(pathArquivoJson));

    // Caso haja erro para abrir o arquivo
    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "[Arquivos] [ERRO] Falha ao abrir arquivo JSON para conversão para Array:" << pathArquivoJson;
        return QJsonArray();
    }

    // Lê o arquivo
    QTextStream input(&arquivo);
    QString textoJson = input.readAll();

    arquivo.close();

    // Converte a string em um documento JSON
    QJsonDocument doc = QJsonDocument::fromJson(textoJson.toUtf8());

    // Converte o documento JSON em um array JSON
    QJsonArray arrayJson = doc.array();

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
        qDebug() << "[Arquivos] [ERRO] Erro ao abrir arquivo JSON:" << pathArquivoJson;
        return;
    }

    // Escreve a string no arquivo
    QTextStream saida(&arquivo);
    saida << strJson;

    arquivo.close();

    qDebug() << "[Arquivos] [OK] Array JSON salvo em:" << pathArquivoJson;
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

    // Refere-se ao número de vezes que o programa foi aberto
    novoObjeto["numeroAcessos"] = 1; // acessando agora :)
    // Refere-se ao número de vezes que o botão de "iniciar" foi apertado
    novoObjeto["numeroReproducoes"] = 0;
    novoObjeto["ultimoAcesso"] = carregarDataAtual();

    novoObjeto["ultimaExportacao"] = "";

    novoObjeto["senha"] = novaSenha;

    return escreverObjetoJson(novoObjeto, QString(ARQUIVO_CONFIGURACAO_GERAL));
}

// **** VISITAS ************************************************

void Arquivos::aumentarVisitas(){

    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Carrega o valor da propriedade
    int visitas = objetoJson["numeroAcessos"].toInt();

    visitas++;
    qDebug() << "[Arquivos] [INFO] Visitas aumentadas:" << visitas;

    // Modifica a propriedade
    objetoJson["numeroAcessos"] = visitas;

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos] [OK] Número de visitas atualizado";
    } else {
        qDebug() << "[Arquivos] [ERRO] Falha ao atualizar o número de visitas";
    }
}

void Arquivos::aumentarReproducoes(){
    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Carrega o valor da propriedade
    int reproducoes = objetoJson["numeroReproducoes"].toInt();

    reproducoes++;
    qDebug() << "[Arquivos] [INFO] Reproduções aumentadas:" << reproducoes;

    // Modifica a propriedade
    objetoJson["numeroReproducoes"] = reproducoes;

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos] [OK] Número de reproduções atualizado";
    } else {
        qDebug() << "[Arquivos] [ERRO] Falha ao atualizar o número de reproduções";
    }
}

void Arquivos::atualizarUltimoAcesso(){
    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Modifica a propriedade
    objetoJson["ultimoAcesso"] = carregarDataAtual();

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos] [OK] Último acesso atualizado";
    } else {
        qDebug() << "[Arquivos] [ERRO] Falha ao atualizar o último acesso";
    }
}

// **** EXPORTAÇÃO ************************************************

void Arquivos::atualizarUltimaExportacao(){
    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Modifica a propriedade
    objetoJson["ultimaExportacao"] = carregarDataAtual();

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos] [OK] Data da última exportação atualizado";
    } else {
        qDebug() << "[Arquivos] [ERRO] Falha ao atualizar a data da última exportação";
    }
}

// **** SENHA ************************************************

QString Arquivos::carregarSenha(){
    // Carrega a senha do arquivo
    QString senhaArquivo = Arquivos::carregarPropriedadeJson(ARQUIVO_CONFIGURACAO_GERAL, "senha");

    return senhaArquivo;
}

void Arquivos::alterarSenha(QString novaSenha){
    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Modifica a propriedade
    objetoJson["senha"] = novaSenha;

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos] [OK] Senha atualizada";
    } else {
        qDebug() << "[Arquivos] [ERRO] Falha ao atualizar a senha";
    }
}

/* ************************************************************
 * ARQUIVO DE CONFIGURAÇÃO DE SEQUÊNCIA
 *************************************************************/

void Arquivos::salvarSequenciaNoArquivo(QJsonArray sequencia, QString pasta, QString nomeArquivo){

    //Cria as pastas para salvar o arquivo
    criarPasta(pastas.configuracoes);

    QString caminho = pastas.configuracoes + '/' + pasta;
    criarPasta(caminho);

    // Cria um documento JSON a partir do array JSON
    QJsonDocument doc(sequencia);

    // Converte o documento JSON em uma string
    QString strJson(doc.toJson(QJsonDocument::Compact));

    // Cria um objeto QFile com o nome do arquivo
    QString pathArquivo = caminho + '/' + nomeArquivo;
    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    // Abre o arquivo para escrita
    if (!arquivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug() << "[Arquivos][ERRO] Erro ao salvar sequência em:" << pathArquivo;
        return;
    }

    // Escreve a string no arquivo
    QTextStream saida(&arquivo);
    saida << strJson;

    arquivo.close();

    qDebug() << "[Arquivos][OK] Sequência salva em:" << pathArquivo;
}

// **** PERGUNTA ************************************************

int Arquivos::encontrarRespostaExistente(QJsonArray respostas, QJsonObject pergunta){
    // Percorre o array procurando um objeto que seja igual
    for(int i = 0; i < respostas.size(); i++){

        QJsonObject item = respostas.at(i).toObject();

        if(item["pergunta"] == pergunta["pergunta"] &&
           item["resposta1"] == pergunta["opcao1"] &&
           item["resposta2"] == pergunta["opcao2"] &&
           item["resposta3"] == pergunta["opcao3"] &&
           item["resposta4"] == pergunta["opcao4"]){
            qDebug() << "[Arquivos][INFO] A pergunta já foi respondida em" << i;
            return i;
        }
    }

    return -1;
}

void Arquivos::salvarResposta(QJsonObject objetoPergunta, int selecionada, QString nomeArquivo){

    //Cria as pastas para salvar o arquivo
    criarPasta(pastas.configuracoes);

    QString caminho = pastas.configuracoes + '/' + nomeArquivo;

    if(!arquivoExiste(caminho)){
        criarArquivo(caminho);
    }

    // Carrega a sequencia do arquivo
    QJsonArray sequenciaRespostas = converterJsonParaArray(caminho);

    int indice = encontrarRespostaExistente(sequenciaRespostas, objetoPergunta);

    if(indice < 0){
        // Cria um novo e adiciona
        QJsonObject novaResposta;

        novaResposta["pergunta"] = objetoPergunta["pergunta"];
        novaResposta["correta"] = objetoPergunta["correta"];

        for(int i = 1; i <= 4; i++){
           QString resposta = "resposta" + QString::number(i);
           QString opcao = "opcao" + QString::number(i);
           QString qtd = "qtd" + QString::number(i);

           novaResposta[resposta] = objetoPergunta[opcao];

           if(i == selecionada){
                novaResposta[qtd] = 1;
           }else{
               novaResposta[qtd] = 0;
           }
        }

        sequenciaRespostas.append(novaResposta);
    }else{
        // Atualiza a quantidade que foi respondida
        QString qtd = "qtd" + QString::number(selecionada);

        QJsonObject objeto = sequenciaRespostas.at(indice).toObject();

        int valor = objeto[qtd].toInt();
        objeto[qtd] = valor + 1;

        qDebug() << "valor " + QString::number(valor);

        // O objeto do array não pode ser modificado diretamente,
        // por isso, retira o item e o reinsere modificado

        sequenciaRespostas.removeAt(indice);
        sequenciaRespostas.insert(indice, objeto);
    }

    // Salva a sequencia novamente
    escreverArrayJson(caminho, sequenciaRespostas);

    qDebug() << "[Arquivos][OK] A resposta foi salva no arquivo";
}
