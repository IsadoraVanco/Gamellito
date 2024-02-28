#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

// Classes das outras telas
#include "telaoptativa.h"
#include "telanova.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void moveInicio();

private:
    Ui::MainWindow *ui;

    // Novos objetos das classes
    TelaOptativa telaOptativa;
    TelaNova telaNova;
};
#endif // MAINWINDOW_H
