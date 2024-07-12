#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // Define um icone para o executavel
    QIcon icon("assets/icones/aplicacao/app.png");
    a.setWindowIcon(icon);
    w.setWindowIcon(icon);

    // Deixa a tela cheia
    w.setWindowState(Qt::WindowFullScreen);
    // Some com a barra de título da janela
    w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    w.show();
    return a.exec();
}
