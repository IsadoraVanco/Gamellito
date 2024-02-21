#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Colocar audio de inicio depois
    ui->pushButton_som->setIcon(QIcon(":/icones/som.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_som_clicked()
{
    if(estaMutado){
        estaMutado = false;
        ui->pushButton_som->setIcon(QIcon(":/icones/som.png"));
        //on_actionsom_triggered();
        //Player->setMuted(false); Qt < 6
        //Audio->setMuted(false); // Qt 6
    }else{
        estaMutado = true;
        ui->pushButton_som->setIcon(QIcon(":/icones/sem-som.png"));
        //Player->setMuted(true); Qt < 6
        //Audio->setMuted(true);  // Qt 6
    }
}

void MainWindow::on_pushButton_sobre_clicked()
{
    // Criando uma instancia
    ui_sobre = new sobre(this);
    ui_sobre->show();
}

