#ifndef QUESTIONARIO_H
#define QUESTIONARIO_H

#include <QWidget>

namespace Ui {
class Questionario;
}

class Questionario : public QWidget
{
    Q_OBJECT

public:
    explicit Questionario(QWidget *parent = nullptr);
    ~Questionario();

private:
    Ui::Questionario *ui;
};

#endif // QUESTIONARIO_H
