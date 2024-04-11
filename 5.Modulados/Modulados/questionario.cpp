#include "questionario.h"
#include "ui_questionario.h"

Questionario::Questionario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Questionario)
{
    ui->setupUi(this);
}

Questionario::~Questionario()
{
    delete ui;
}
