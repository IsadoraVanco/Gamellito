#ifndef TELANOVA_H
#define TELANOVA_H

#include <QWidget>

namespace Ui {
class TelaNova;
}

class TelaNova : public QWidget
{
    Q_OBJECT

public:
    explicit TelaNova(QWidget *parent = nullptr);
    ~TelaNova();

private slots:
    void on_pushButton_2_proximo_nova_2_clicked();

    void on_pushButton_2_proximo_nova_clicked();

    void on_pushButton_voltar_nova_clicked();

private:
    Ui::TelaNova *ui;

signals:
    void voltarClicked();
};

#endif // TELANOVA_H
