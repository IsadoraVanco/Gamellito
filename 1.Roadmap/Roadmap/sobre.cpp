#include "sobre.h"
#include "ui_sobre.h"

sobre::sobre(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sobre)
{
    ui->setupUi(this);
}

sobre::~sobre()
{
    delete ui;
}

void sobre::on_pushButton_sobreQt_clicked()
{
   // QMessageBox* message;
    //message->setStyleSheet(QString("QMessageBox{background-color: white;}"));
    //message->aboutQt(this, "Sobre o Qt");
    QMessageBox::aboutQt(this, "Sobre o Qt");
}

