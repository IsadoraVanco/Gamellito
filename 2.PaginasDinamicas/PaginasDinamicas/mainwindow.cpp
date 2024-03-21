#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Adicionando dinamicamente novas telas na Stacked Widgets
    //ui->stackedWidget->addWidget(&telaNova);

    // Alternativo => especifica em qual index vai colocar as telas
    // Tome cuidado com os indexs!
    ui->stackedWidget->insertWidget(1, &telaOptativa);
    ui->stackedWidget->insertWidget(1, &telaNova);

    // Indica em qual tela irá iniciar
    ui->stackedWidget->setCurrentIndex(0);

    // Faz as conexões entre sinais e slots
    connect(&telaOptativa, SIGNAL(voltarClicked()), this, SLOT(moveInicio()));
    connect(&telaNova, SIGNAL(voltarClicked()), this, SLOT(moveInicio()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()    // vai para telaOptativa
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::moveInicio()
{
    ui->stackedWidget->setCurrentIndex(0);
}

