#include "telaoptativa.h"
#include "ui_telaoptativa.h"

TelaOptativa::TelaOptativa(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaOptativa)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

TelaOptativa::~TelaOptativa()
{
    delete ui;
}

void TelaOptativa::on_pushButton_voltar_2_clicked()
{
    cout << "tela 0" << endl;
    ui->stackedWidget->setCurrentIndex(1);
}

void TelaOptativa::on_pushButton_voltar_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void TelaOptativa::on_pushButton_voltar_clicked()
{
    // Volta para a tela inicial
    emit voltarClicked();
}

