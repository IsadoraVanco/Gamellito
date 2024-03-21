#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Passa o caminho da aplicação para o construtor
    MainWindow w(argv[0]);

    // Deixa a tela cheia
    //w.setWindowState(Qt::WindowFullScreen);
    // Some com a barra de título da janela
    //w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    w.show();
    return a.exec();
}
