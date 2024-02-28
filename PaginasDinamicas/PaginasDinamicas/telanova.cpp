#include "telanova.h"
#include "ui_telanova.h"

TelaNova::TelaNova(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaNova)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);
}

TelaNova::~TelaNova()
{
    delete ui;
}

void TelaNova::on_pushButton_2_proximo_nova_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void TelaNova::on_pushButton_2_proximo_nova_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void TelaNova::on_pushButton_voltar_nova_clicked()
{
    // Volta para a tela inicial
    emit voltarClicked();
}

