#ifndef TELAOPTATIVA_H
#define TELAOPTATIVA_H

#include <iostream>
#include <QWidget>

using namespace std;

namespace Ui {
class TelaOptativa;
}

class TelaOptativa : public QWidget
{
    Q_OBJECT

public:
    explicit TelaOptativa(QWidget *parent = nullptr);
    ~TelaOptativa();


private slots:
    void on_pushButton_voltar_2_clicked();

    void on_pushButton_voltar_3_clicked();

    void on_pushButton_voltar_clicked();

private:
    Ui::TelaOptativa *ui;

    // Configura os sinais
signals:

    void voltarClicked();
};

#endif // TELAOPTATIVA_H
