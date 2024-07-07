#include "arquivos.h"

// Manipulação de diretório e arquivo
#include <QtCore>

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

QString Arquivos::retirarCaracteres(QString texto, QString caractere){
    texto.remove(caractere);
    return texto;
}

/* ************************************************************
 * PASTAS
 *************************************************************/

void Arquivos::criarPasta(QString nomePasta){
    if(QDir(nomePasta).exists()){
        qDebug() << "[Arquivos][INFO] A pasta existe:" << nomePasta;

    }else{
        if(!QDir().mkdir(nomePasta)){
            qDebug() << "[Arquivos][ERRO] Falha ao criar a pasta:" << nomePasta;
        }
    }
}

QString Arquivos::selecionarPasta(){
    QString pastaSelecionada = QFileDialog::getExistingDirectory(nullptr, "Selecione uma pasta", "");

    return pastaSelecionada;
}

QString Arquivos::consertarCaminhoPasta(QString caminho){
    // Adiciona uma barra no final se não houver
    if(!caminho.endsWith(QDir::separator())){
        caminho += QDir::separator();
    }

    return caminho;
}

/* ************************************************************
 * BACKUP DE VÍDEO
 *************************************************************/

QString Arquivos::selecionarVideo(){
    QString diretorioInicial = consertarCaminhoPasta(QDir::homePath());

    QString caminhoArquivo = QFileDialog::getOpenFileName(this, tr("Selecione o video"), diretorioInicial, tr("MP4 (*.mp4);; MKV (*.mkv)"));

    return caminhoArquivo;
}

QString Arquivos::salvarVideoBackup(QString pasta){
    // Seleciona o vídeo
    QString caminhoArquivo = selecionarVideo();

    // Verifica se o arquivo foi escolhido e existe
    if(caminhoArquivo.isEmpty() || !arquivoExiste(caminhoArquivo)){
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

    if(copiarArquivo(caminhoArquivo, destinoCompleto)){
        QMessageBox::about(this, "Arquivo copiado", "Arquivo copiado para o backup!");
        qDebug() << "[Arquivos][OK] Arquivo copiado com sucesso:" << caminhoArquivo;
    }else{
//        QMessageBox::critical(this, "ERRO", "Erro ao copiar o arquivo para o backup. Por favor, tente novamente.");
//        QMessageBox::about(this, "Arquivo duplicado", "O arquivo já está no backup");
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
        qDebug() << "[Arquivos][ERRO] O arquivo NÃO existe:" << pathArquivo;
        return false;
    }

    return true;
}

QFile *Arquivos::abrirArquivoEscrita(QString pathArquivo){
    QFile *arquivo = new QFile(QDir::current().absoluteFilePath(pathArquivo));

    if(arquivo->open(QIODevice::WriteOnly | QIODevice::Text)){
        return arquivo;
    }else{
        qDebug() << "[Arquivos][ERRO] Falha ao abrir arquivo para escrita:" << pathArquivo;
        return nullptr;
    }
}

void Arquivos::fecharArquivo(QFile *arquivo){
    arquivo->close();
    delete arquivo;
}

bool Arquivos::criarArquivo(QString pathArquivo){
    QFile *arquivo = abrirArquivoEscrita(pathArquivo);

    // Caso haja erro ao criar o arquivo
    if(!arquivo){
        qDebug() << "[Arquivos][ERRO] Erro ao criar arquivo:" << pathArquivo;
        return false;
    }

    // Fecha o arquivo
    fecharArquivo(arquivo);

    qDebug() << "[Arquivos][OK] Arquivo criado:" << pathArquivo;
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
 * ARQUIVO CSV
 *************************************************************/

void Arquivos::gerarCSV(QString nomePerfil, QString nomeArquivoRespostas, QString pastaDestino){

    // Importa o array do arquivo de sequência
    QString caminhoCompletoRespostas = pastas.configuracoes + '/' + nomeArquivoRespostas;
    QJsonArray respostas = converterJsonParaArray(caminhoCompletoRespostas);

    if(respostas.isEmpty()){
        return;
    }

    // Cria um novo arquivo
    QString nomeArquivo = "relatorio" + nomePerfil + ".csv";
    QString caminhoDestino = pastaDestino + "/" + nomeArquivo;
    QFile *arquivoCSV = abrirArquivoEscrita(caminhoDestino);

    if(arquivoCSV == nullptr){
        qDebug() << "[Arquivos][ERRO] Falha ao gerar relatório" << nomeArquivo;
        return;
    }

    // Abre o arquivo de configurações
    QJsonObject configuracoes = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Informações importantes
    QTextStream out(arquivoCSV);
    out << "Perfil: ;" << nomePerfil << "\n";
    out << "Data da exportacao: ;" << carregarDataAtual() << "\n";
    out << "Numero de acessos ao programa: ;" << configuracoes["numeroAcessos"].toInt() << "\n";
    out << "Numero de acessos a sequencia: ;" << configuracoes["numeroReproducoes"].toInt() << "\n\n";

    // Coloca os cabeçalhos
    out << "Pergunta; Resposta1; Quantidade respondida1; "
           "Resposta2; Quantidade respondida2; "
           "Resposta3; Quantidade respondida3; "
           "Resposta4; Quantidade respondida4; Correta\n";

    // Percorre as respostas
    for(int i = 0; i < respostas.size(); i++){
        QJsonObject item = respostas.at(i).toObject();

        // Transforma o texto
        QString texto = retirarCaracteres(item["pergunta"].toString(), "\n");
        texto = retirarCaracteres(texto, ";");
        out << texto << ";";

        texto = retirarCaracteres(item["resposta1"].toString(), "\n");
        texto = retirarCaracteres(texto, ";");
        out << texto << ";";

        out << item["qtd1"].toInt() << ";";

        texto = retirarCaracteres(item["resposta2"].toString(), "\n");
        texto = retirarCaracteres(texto, ";");
        out << texto << ";";

        out << item["qtd2"].toInt() << ";";

        texto = retirarCaracteres(item["resposta3"].toString(), "\n");
        texto = retirarCaracteres(texto, ";");
        out << texto << ";";

        out << item["qtd3"].toInt() << ";";

        texto = retirarCaracteres(item["resposta4"].toString(), "\n");
        texto = retirarCaracteres(texto, ";");
        out << texto << ";";

        out << item["qtd4"].toInt() << ";";
        out << item["correta"].toInt() << "\n";
    }

    // Fecha o arquivo
    fecharArquivo(arquivoCSV);

    qDebug() << "[Arquivos][OK] Relatório gerado:" << nomeArquivo;
}

/* ************************************************************
 * ARQUIVO JSON
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

        qDebug() << "[Arquivos][OK] Arquivo JSON salvo com sucesso:" << pathArquivo;
        return true;
    }else{
        qDebug() << "[Arquivos][ERRO] Erro ao abrir o arquivo JSON para escrita:" << pathArquivo;
        return false;
    }
}

// **** ARRAY ************************************************

QJsonArray Arquivos::converterJsonParaArray(QString pathArquivoJson){

    QFile arquivo(QDir::current().absoluteFilePath(pathArquivoJson));

    // Caso haja erro para abrir o arquivo
    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "[Arquivos][ERRO] Falha ao abrir arquivo JSON para converter para Array:" << pathArquivoJson;
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

bool Arquivos::criarArquivoGeral(QString novaSenha){
    QJsonObject novoObjeto;

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
        qDebug() << "[Arquivos][ERRO] Falha ao atualizar a data da última exportação";
    }
}

// **** SENHA ************************************************

QString Arquivos::carregarSenha(){
    // Carrega a senha do arquivo
    QString senhaArquivo = carregarPropriedadeJson(ARQUIVO_CONFIGURACAO_GERAL, "senha");

    return senhaArquivo;
}

void Arquivos::alterarSenha(QString novaSenha){
    // Carrega o JSON do arquivo
    QJsonObject objetoJson = carregarObjetoJson(ARQUIVO_CONFIGURACAO_GERAL);

    // Modifica a propriedade
    objetoJson["senha"] = novaSenha;

    // Salva o Json modificado de volta no arquivo
    if(escreverObjetoJson(objetoJson, ARQUIVO_CONFIGURACAO_GERAL)) {
        qDebug() << "[Arquivos][OK] Senha atualizada";
    } else {
        qDebug() << "[Arquivos][ERRO] Falha ao atualizar a senha";
    }
}

/* ************************************************************
 * ARQUIVO DE CONFIGURAÇÃO DE SEQUÊNCIA
 *************************************************************/

void Arquivos::salvarSequenciaNoArquivo(QJsonArray sequencia, QString nomeArquivo){

    //Cria as pastas para salvar o arquivo
    criarPasta(pastas.configuracoes);

    // Cria um documento JSON a partir do array JSON
    QJsonDocument doc(sequencia);

    // Converte o documento JSON em uma string
    QString strJson(doc.toJson(QJsonDocument::Compact));

    // Cria um objeto QFile com o nome do arquivo
    QString pathArquivo = pastas.configuracoes + '/' + nomeArquivo;
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

QJsonArray Arquivos::carregarSequenciaDoArquivo(QString nomeArquivo){

    QString pathArquivo = this->pastas.configuracoes + '/' + nomeArquivo;

    QFile arquivo(QDir::current().absoluteFilePath(pathArquivo));

    // Caso haja erro para abrir o arquivo
    if (!arquivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "[Arquivos][ERRO] Falha ao abrir arquivo JSON para conversão para Array:" << pathArquivo;
        return QJsonArray();
    }

    // Lê o arquivo
    QTextStream input(&arquivo);
    QString textoJson = input.readAll();

    arquivo.close();

    // Converte a string em um documento JSON
    QJsonDocument doc = QJsonDocument::fromJson(textoJson.toUtf8());

    // Converte o documento JSON em um array JSON
    QJsonArray array = doc.array();

    return array;
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

//        qDebug() << "valor " + QString::number(valor);

        // O objeto do array não pode ser modificado diretamente,
        // por isso, retira o item e o reinsere modificado

        sequenciaRespostas.removeAt(indice);
        sequenciaRespostas.insert(indice, objeto);
    }

    // Salva a sequencia novamente
    escreverArrayJson(caminho, sequenciaRespostas);

    qDebug() << "[Arquivos][OK] A resposta foi salva no arquivo";
}

void Arquivos::limparRespostas(QString nomeArquivoRespostas){

    // Carrega as respostas do perfil
    QString caminhoCompletoRespostas = pastas.configuracoes + '/' + nomeArquivoRespostas;
    QJsonArray respostas = converterJsonParaArray(caminhoCompletoRespostas);

    if(!respostas.isEmpty()){
        QMessageBox::about(this, "Respostas apagadas", "As respostas deste perfil foram apagadas com sucesso. A partir de agora, as respostas estão novamente sendo computadas.");
    }

    // Cria um arquivo vazio
    criarArquivo(caminhoCompletoRespostas);
}
