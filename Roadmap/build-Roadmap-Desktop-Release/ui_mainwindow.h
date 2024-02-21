/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_iniciar;
    QPushButton *pushButton_configurar;
    QPushButton *pushButton_sobre;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QPushButton *pushButton_som;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 540);
        MainWindow->setMinimumSize(QSize(960, 540));
        MainWindow->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.605, y1:0.374591, x2:0.094, y2:0.125, stop:0 rgba(251, 254, 12, 255), stop:1 rgba(255, 116, 57, 255))"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(60);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_iniciar = new QPushButton(centralwidget);
        pushButton_iniciar->setObjectName(QString::fromUtf8("pushButton_iniciar"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_iniciar->sizePolicy().hasHeightForWidth());
        pushButton_iniciar->setSizePolicy(sizePolicy);
        pushButton_iniciar->setMinimumSize(QSize(320, 60));
        pushButton_iniciar->setMaximumSize(QSize(320, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pushButton_iniciar->setFont(font);
        pushButton_iniciar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_iniciar->setStyleSheet(QString::fromUtf8("background-color: #FF7439;\n"
"border-radius: 20px;\n"
"color: #fff;"));
        pushButton_iniciar->setFlat(false);

        verticalLayout->addWidget(pushButton_iniciar);

        pushButton_configurar = new QPushButton(centralwidget);
        pushButton_configurar->setObjectName(QString::fromUtf8("pushButton_configurar"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_configurar->sizePolicy().hasHeightForWidth());
        pushButton_configurar->setSizePolicy(sizePolicy1);
        pushButton_configurar->setMinimumSize(QSize(320, 60));
        pushButton_configurar->setMaximumSize(QSize(320, 60));
        pushButton_configurar->setSizeIncrement(QSize(0, 2));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_configurar->setFont(font1);
        pushButton_configurar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_configurar->setStyleSheet(QString::fromUtf8("background-color: #FF7439;\n"
"border-radius: 20px;\n"
"color: #fff;"));

        verticalLayout->addWidget(pushButton_configurar);

        pushButton_sobre = new QPushButton(centralwidget);
        pushButton_sobre->setObjectName(QString::fromUtf8("pushButton_sobre"));
        pushButton_sobre->setMinimumSize(QSize(320, 60));
        pushButton_sobre->setMaximumSize(QSize(320, 60));
        pushButton_sobre->setFont(font1);
        pushButton_sobre->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sobre->setStyleSheet(QString::fromUtf8("background-color: #FF7439;\n"
"border-radius: 20px;\n"
"color: #fff;"));

        verticalLayout->addWidget(pushButton_sobre);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagens/gamellito.png")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 1, 3, 1, 1);

        pushButton_som = new QPushButton(centralwidget);
        pushButton_som->setObjectName(QString::fromUtf8("pushButton_som"));
        pushButton_som->setMinimumSize(QSize(30, 30));
        pushButton_som->setMaximumSize(QSize(40, 40));
        pushButton_som->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_som->setStyleSheet(QString::fromUtf8("border: none;\n"
"border-radius: 10px;\n"
"background-color: #FF7439;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icones/assets/som.png"), QSize(), QIcon::Normal, QIcon::On);
        icon.addFile(QString::fromUtf8(":/icones/assets/som.png"), QSize(), QIcon::Active, QIcon::On);
        pushButton_som->setIcon(icon);

        gridLayout->addWidget(pushButton_som, 3, 0, 1, 1, Qt::AlignBottom);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_iniciar->setText(QCoreApplication::translate("MainWindow", "INICIAR", nullptr));
        pushButton_configurar->setText(QCoreApplication::translate("MainWindow", "CONFIGURAR", nullptr));
        pushButton_sobre->setText(QCoreApplication::translate("MainWindow", "SOBRE", nullptr));
        label->setText(QString());
        pushButton_som->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
