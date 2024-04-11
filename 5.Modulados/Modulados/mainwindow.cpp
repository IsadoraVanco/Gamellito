#include "mainwindow.h"
#include "./ui_mainwindow.h"


// Para debugar
#include <QDebug>

// Para manipular diretorios
#include <QtCore>

// Caixas de diálogo
#include <QMessageBox>
#include <QInputDialog>

// Construtor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Conexões
    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));
    //connect(ui->pushButton_sobre, SIGNAL(clicked()), this, SLOT(mostrarTela(Pagina::Sobre)));

    // Adiciona a imagem do menu
    QPixmap gamellito("assets/gamellito.png");
    ui->label_imagemMenu->setPixmap(gamellito);

    // Configura o som ambiente
    configurarSomAmbiente("assets/sons/som-ambiente.wav");
    ligarSomAmbiente();

    // Inicializa a primeira tela
    configurarTelas();
    mostrarTela(Pagina::Inicial); // Tela inicial

    // Verifica os arquivos de configurações
    configurarArquivoGeral();
}

// Destrutor
MainWindow::~MainWindow()
{
    delete ui;
}

/* ************************************************************
 * SOM AMBIENTE DO MENU
 *************************************************************/

void MainWindow::configurarSomAmbiente(QString path)
{
    // O arquivo de som deve estar na pasta de assets!
    QDir dir = QDir::current();
    QString caminho = dir.filePath("assets/sons/som-ambiente.wav");
    somAmbiente = new QSound(QString(caminho));
    somAmbiente->setLoops(QSound::Infinite);

    qDebug() << caminho;
}

void MainWindow::ligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/icones/som/com-som-preto.png"));
    somAmbiente->play();
    somAmbienteMutado = false;
}

void MainWindow::desligarSomAmbiente()
{
    // O arquivo de icone deve estar na pasta de assets!
    ui->pushButton_som->setIcon(QIcon("assets/icones/som/sem-som-preto.png"));
    somAmbiente->stop();
    somAmbienteMutado = true;
}

/* ************************************************************
 * GERENCIAMENTO DE TELAS
 *************************************************************/

void MainWindow::mostrarTela(Pagina tipo){
    // Converte o enum para int e carrega a página
    ui->stackedWidget->setCurrentIndex(static_cast<int>(tipo));
}

void MainWindow::configurarTelas(){

    // Inicio e Sobre já estão configuradas!

    // Adiciona as outras
    //ui->stackedWidget->insertWidget(Pagina::Configurar, widget);

}

/* ************************************************************
 * GERENCIAMENTO DAS CONFIGURAÇÕES
 *************************************************************/

QString MainWindow::lerSenha(){
    int numMinimo = 4;
    QString input = QInputDialog::getText(nullptr, "Definição de senha", "Olá profissional! Vamos definir sua senha? Ela será necessária para as configurações do programa e para a troca de usuário");

    while(input.length() < numMinimo){ // número mínimo de dígitos
        input = QInputDialog::getText(nullptr, "Definição de senha", QString("Senha muito curta! Utilize no mínimo %1 caracteres quaisquer").arg(numMinimo));
    }

    QMessageBox::about(this, "Senha cadastrada", "Sua senha foi cadastrada com sucesso! Não a esqueça e não conte para ninguém :)");
    return input;
}

void MainWindow::configurarArquivoGeral(){
    if(!Arquivos::arquivoExiste(ARQUIVO_CONFIGURACAO_GERAL)){
        // Cria um arquivo
        if(!Arquivos::criarArquivo(QString(ARQUIVO_CONFIGURACAO_GERAL))){
            QMessageBox::critical(this, "ERRO", "Não foi possível criar um arquivo de configuração, por favor, entre em contato com o suporte");
            this->close();
            return;
        }

        // Lê uma nova senha
        QString senha = lerSenha();

        // Preenche com as configs
        if(!Arquivos::preencherArquivoGeral(senha, paciente, responsavel, profissional)){
            QMessageBox::critical(this, "ERRO", "Não foi possível preencher o arquivo de configurações iniciais. Por favor, entre em contato com o suporte");
            this->close();
            return;
        }

        QMessageBox::about(this, "Pronto :)", "Os arquivos de configuração inicial do programa foram criados. Aproveite o software! :)");
    }else{
        // Aumenta o número de "visitas"

    }
}
