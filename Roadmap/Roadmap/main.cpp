#include "mainwindow.h"
//#include "barrajanela.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle(QString("Gamellito"));
    //w.setStyleSheet("MainWindow::title {background-color: black; }");
   //w.setStyle(new BarraJanela);

    w.show();
    return a.exec();
}
