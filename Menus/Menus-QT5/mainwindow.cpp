#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Elementos da tela inicial
    /*
     *  Ainda precisa trocar para um caminho relativo :P
     *  Utilizar quando a imagem estiver melhor >.< (tamanho minimo da label = 300)
    */
    QPixmap gamellito("/home/game/Área de Trabalho/Menus/Menus-QT5/assets/gamellito.png");
    //ui->label->setPixmap(gamellito.scaled(100, 100, Qt::KeepAspectRatio);

    // Som ambiente do menu
    inicializaSomAmbiente();

    //Conexões
    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));

    // Inicializa a primeira tela
    ui->stackedWidget->setCurrentIndex(0); // Tela inicial
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* ************************************************************
 * SOM AMBIENTE
 *************************************************************/

void MainWindow::inicializaSomAmbiente()
{
    som = new QSound("/home/game/Área de Trabalho/Roadmap/Roadmap/assets/funny-and-comical-melody-glide-synth-bass-and-trumpet-21398 (online-audio-converter.com).wav");
    som->setLoops(QSound::Infinite);
    ligaSomAmbiente();
}

void MainWindow::ligaSomAmbiente()
{
    ui->pushButton_som->setIcon(QIcon(":/icones/assets/som.png"));
    som->play();
    mutado = !mutado;
}

void MainWindow::desligaSomAmbiente()
{
    ui->pushButton_som->setIcon(QIcon(":/icones/assets/sem-som.png"));
    som->stop();
    mutado = !mutado;
}

/* ************************************************************
 * TELA INICIAL (0)
 *************************************************************/

void MainWindow::on_pushButton_som_clicked()
{
    if(mutado){
        ligaSomAmbiente();
    }else{
        desligaSomAmbiente();
    }
}

void MainWindow::on_pushButton_iniciar_clicked()
{
    // Vai para a tela "iniciar" e para o som ambiente
     ui->stackedWidget->setCurrentIndex(3);
     desligaSomAmbiente();
}

void MainWindow::on_pushButton_configurar_clicked()
{
    // Vai para a tela "configurar"
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_sobre_clicked()
{
    // Vai para a tela "sobre"
    ui->stackedWidget->setCurrentIndex(1);
}

/* ************************************************************
 * TELA SOBRE (1)
 *************************************************************/

void MainWindow::on_pushButton_versao_qt_clicked()
{
    // Abre um diálogo (barra do sistema tbm)
    QMessageBox::aboutQt(this, "Sobre o Qt");
}

void MainWindow::on_pushButton_voltar_sobre_clicked()
{
    // Volta para a tela inicial e retorna a música
     ui->stackedWidget->setCurrentIndex(0);
}

/* ************************************************************
 * TELA CONFIGURAR (2)
 *************************************************************/

void MainWindow::on_pushButton_voltar_configurar_clicked()
{
    // Volta para a tela inicial
     ui->stackedWidget->setCurrentIndex(0);
}

/* ************************************************************
 * TELA INICIAR (3)
 *************************************************************/

void MainWindow::on_pushButton_voltar_iniciar_clicked()
{
    // Volta para a tela inicial e liga o som ambiente
     ui->stackedWidget->setCurrentIndex(0);
     ligaSomAmbiente();
}


void MainWindow::on_pushButton_voltar_video_clicked()
{
    // Volta para o vídeo
     ui->stackedWidget->setCurrentIndex(0);
}

