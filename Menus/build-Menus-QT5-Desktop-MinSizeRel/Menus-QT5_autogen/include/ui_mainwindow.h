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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *inicio;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_som;
    QLabel *label;
    QSpacerItem *horizontalSpacer_inicial_2;
    QSpacerItem *horizontalSpacer_inicial_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_iniciar;
    QPushButton *pushButton_configurar;
    QPushButton *pushButton_sobre;
    QPushButton *pushButton_sair;
    QSpacerItem *verticalSpacer_inicial;
    QSpacerItem *horizontalSpacer_inicial;
    QSpacerItem *verticalSpacer_inicial_2;
    QWidget *sobre;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_sobre;
    QPushButton *pushButton_versao_qt;
    QSpacerItem *verticalSpacer_sobre_2;
    QSpacerItem *horizontalSpacer_sobre;
    QSpacerItem *horizontalSpacer_sobre_2;
    QLabel *label_versao_soft;
    QPushButton *pushButton_voltar_sobre;
    QWidget *configurar;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_voltar_configurar;
    QSpacerItem *horizontalSpacer_configurar;
    QPushButton *pushButton_adicionar_video;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_adicionar_pergunta;
    QSpacerItem *horizontalSpacer_configurar_2;
    QSpacerItem *horizontalSpacer_configurar_3;
    QSpacerItem *verticalSpacer_configurar;
    QSpacerItem *verticalSpacer_configurar_2;
    QWidget *iniciar;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_voltar_video;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QPushButton *pushButton_voltar_iniciar;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_5;
    QRadioButton *radioButton_opcao2;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *radioButton_opcao3;
    QRadioButton *radioButton_opcao4;
    QRadioButton *radioButton_opcao1;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_pergunta;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.605, y1:0.374591, x2:0.094, y2:0.125, stop:0 rgba(251, 254, 12, 255), stop:1 rgba(255, 116, 57, 255))"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(800, 600));
        inicio = new QWidget();
        inicio->setObjectName(QString::fromUtf8("inicio"));
        gridLayout_2 = new QGridLayout(inicio);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_som = new QPushButton(inicio);
        pushButton_som->setObjectName(QString::fromUtf8("pushButton_som"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_som->sizePolicy().hasHeightForWidth());
        pushButton_som->setSizePolicy(sizePolicy);
        pushButton_som->setMinimumSize(QSize(40, 40));
        pushButton_som->setMaximumSize(QSize(40, 40));
        pushButton_som->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_som->setLayoutDirection(Qt::LeftToRight);
        pushButton_som->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 15px;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_2->addWidget(pushButton_som, 3, 1, 1, 1, Qt::AlignBottom);

        label = new QLabel(inicio);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(241, 0));
        label->setMaximumSize(QSize(241, 332));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagens/assets/gamellito.png")));
        label->setScaledContents(true);

        gridLayout_2->addWidget(label, 2, 7, 1, 1, Qt::AlignVCenter);

        horizontalSpacer_inicial_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_inicial_2, 2, 8, 1, 1);

        horizontalSpacer_inicial_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_inicial_3, 2, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(60);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton_iniciar = new QPushButton(inicio);
        pushButton_iniciar->setObjectName(QString::fromUtf8("pushButton_iniciar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_iniciar->sizePolicy().hasHeightForWidth());
        pushButton_iniciar->setSizePolicy(sizePolicy2);
        pushButton_iniciar->setMinimumSize(QSize(320, 60));
        pushButton_iniciar->setMaximumSize(QSize(320, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        pushButton_iniciar->setFont(font);
        pushButton_iniciar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_iniciar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));
        pushButton_iniciar->setFlat(false);

        verticalLayout->addWidget(pushButton_iniciar);

        pushButton_configurar = new QPushButton(inicio);
        pushButton_configurar->setObjectName(QString::fromUtf8("pushButton_configurar"));
        sizePolicy2.setHeightForWidth(pushButton_configurar->sizePolicy().hasHeightForWidth());
        pushButton_configurar->setSizePolicy(sizePolicy2);
        pushButton_configurar->setMinimumSize(QSize(320, 60));
        pushButton_configurar->setMaximumSize(QSize(320, 60));
        pushButton_configurar->setSizeIncrement(QSize(0, 2));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_configurar->setFont(font1);
        pushButton_configurar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_configurar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border: none;\n"
"	border-radius: 20px;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));

        verticalLayout->addWidget(pushButton_configurar);

        pushButton_sobre = new QPushButton(inicio);
        pushButton_sobre->setObjectName(QString::fromUtf8("pushButton_sobre"));
        sizePolicy2.setHeightForWidth(pushButton_sobre->sizePolicy().hasHeightForWidth());
        pushButton_sobre->setSizePolicy(sizePolicy2);
        pushButton_sobre->setMinimumSize(QSize(320, 60));
        pushButton_sobre->setMaximumSize(QSize(320, 60));
        pushButton_sobre->setFont(font1);
        pushButton_sobre->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sobre->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));

        verticalLayout->addWidget(pushButton_sobre);

        pushButton_sair = new QPushButton(inicio);
        pushButton_sair->setObjectName(QString::fromUtf8("pushButton_sair"));
        sizePolicy2.setHeightForWidth(pushButton_sair->sizePolicy().hasHeightForWidth());
        pushButton_sair->setSizePolicy(sizePolicy2);
        pushButton_sair->setMinimumSize(QSize(320, 60));
        pushButton_sair->setMaximumSize(QSize(320, 60));
        pushButton_sair->setFont(font1);
        pushButton_sair->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sair->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));

        verticalLayout->addWidget(pushButton_sair);


        gridLayout_2->addLayout(verticalLayout, 2, 2, 1, 1);

        verticalSpacer_inicial = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_inicial, 3, 2, 1, 1);

        horizontalSpacer_inicial = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_inicial, 2, 1, 1, 1);

        verticalSpacer_inicial_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_inicial_2, 0, 2, 1, 1);

        stackedWidget->addWidget(inicio);
        sobre = new QWidget();
        sobre->setObjectName(QString::fromUtf8("sobre"));
        gridLayout_3 = new QGridLayout(sobre);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_sobre = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_sobre, 0, 2, 1, 1);

        pushButton_versao_qt = new QPushButton(sobre);
        pushButton_versao_qt->setObjectName(QString::fromUtf8("pushButton_versao_qt"));
        pushButton_versao_qt->setMinimumSize(QSize(320, 60));
        pushButton_versao_qt->setFont(font1);
        pushButton_versao_qt->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_versao_qt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_3->addWidget(pushButton_versao_qt, 1, 2, 1, 1, Qt::AlignHCenter);

        verticalSpacer_sobre_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_3->addItem(verticalSpacer_sobre_2, 2, 2, 1, 1);

        horizontalSpacer_sobre = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_sobre, 1, 1, 1, 1);

        horizontalSpacer_sobre_2 = new QSpacerItem(350, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_sobre_2, 1, 3, 1, 1);

        label_versao_soft = new QLabel(sobre);
        label_versao_soft->setObjectName(QString::fromUtf8("label_versao_soft"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_versao_soft->sizePolicy().hasHeightForWidth());
        label_versao_soft->setSizePolicy(sizePolicy3);
        label_versao_soft->setMinimumSize(QSize(250, 60));
        label_versao_soft->setMaximumSize(QSize(250, 60));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_versao_soft->setFont(font2);
        label_versao_soft->setStyleSheet(QString::fromUtf8("background-color: none;"));

        gridLayout_3->addWidget(label_versao_soft, 2, 1, 1, 1);

        pushButton_voltar_sobre = new QPushButton(sobre);
        pushButton_voltar_sobre->setObjectName(QString::fromUtf8("pushButton_voltar_sobre"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy4.setHorizontalStretch(100);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_voltar_sobre->sizePolicy().hasHeightForWidth());
        pushButton_voltar_sobre->setSizePolicy(sizePolicy4);
        pushButton_voltar_sobre->setMinimumSize(QSize(120, 60));
        pushButton_voltar_sobre->setMaximumSize(QSize(120, 60));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_voltar_sobre->setFont(font3);
        pushButton_voltar_sobre->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_voltar_sobre->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_3->addWidget(pushButton_voltar_sobre, 0, 1, 1, 1, Qt::AlignTop);

        stackedWidget->addWidget(sobre);
        configurar = new QWidget();
        configurar->setObjectName(QString::fromUtf8("configurar"));
        gridLayout_4 = new QGridLayout(configurar);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_voltar_configurar = new QPushButton(configurar);
        pushButton_voltar_configurar->setObjectName(QString::fromUtf8("pushButton_voltar_configurar"));
        sizePolicy2.setHeightForWidth(pushButton_voltar_configurar->sizePolicy().hasHeightForWidth());
        pushButton_voltar_configurar->setSizePolicy(sizePolicy2);
        pushButton_voltar_configurar->setMinimumSize(QSize(120, 60));
        pushButton_voltar_configurar->setMaximumSize(QSize(120, 60));
        pushButton_voltar_configurar->setFont(font3);
        pushButton_voltar_configurar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_voltar_configurar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_4->addWidget(pushButton_voltar_configurar, 0, 0, 1, 1);

        horizontalSpacer_configurar = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_configurar, 3, 4, 1, 1);

        pushButton_adicionar_video = new QPushButton(configurar);
        pushButton_adicionar_video->setObjectName(QString::fromUtf8("pushButton_adicionar_video"));
        sizePolicy4.setHeightForWidth(pushButton_adicionar_video->sizePolicy().hasHeightForWidth());
        pushButton_adicionar_video->setSizePolicy(sizePolicy4);
        pushButton_adicionar_video->setMinimumSize(QSize(250, 60));
        pushButton_adicionar_video->setMaximumSize(QSize(250, 60));
        pushButton_adicionar_video->setFont(font3);
        pushButton_adicionar_video->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_adicionar_video->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_4->addWidget(pushButton_adicionar_video, 3, 1, 1, 1);

        scrollArea = new QScrollArea(configurar);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 203, 16);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 528, 356));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 1, 1, 1, 3);

        pushButton_adicionar_pergunta = new QPushButton(configurar);
        pushButton_adicionar_pergunta->setObjectName(QString::fromUtf8("pushButton_adicionar_pergunta"));
        sizePolicy4.setHeightForWidth(pushButton_adicionar_pergunta->sizePolicy().hasHeightForWidth());
        pushButton_adicionar_pergunta->setSizePolicy(sizePolicy4);
        pushButton_adicionar_pergunta->setMinimumSize(QSize(250, 60));
        pushButton_adicionar_pergunta->setMaximumSize(QSize(250, 60));
        pushButton_adicionar_pergunta->setFont(font3);
        pushButton_adicionar_pergunta->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_adicionar_pergunta->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_4->addWidget(pushButton_adicionar_pergunta, 3, 3, 1, 1);

        horizontalSpacer_configurar_2 = new QSpacerItem(120, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_configurar_2, 3, 0, 1, 1);

        horizontalSpacer_configurar_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_configurar_3, 3, 2, 1, 1);

        verticalSpacer_configurar = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_configurar, 2, 1, 1, 1);

        verticalSpacer_configurar_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_4->addItem(verticalSpacer_configurar_2, 4, 1, 1, 1);

        stackedWidget->addWidget(configurar);
        iniciar = new QWidget();
        iniciar->setObjectName(QString::fromUtf8("iniciar"));
        gridLayout_6 = new QGridLayout(iniciar);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_2, 2, 2, 1, 1);

        pushButton_voltar_video = new QPushButton(iniciar);
        pushButton_voltar_video->setObjectName(QString::fromUtf8("pushButton_voltar_video"));
        sizePolicy2.setHeightForWidth(pushButton_voltar_video->sizePolicy().hasHeightForWidth());
        pushButton_voltar_video->setSizePolicy(sizePolicy2);
        pushButton_voltar_video->setMinimumSize(QSize(250, 60));
        pushButton_voltar_video->setMaximumSize(QSize(250, 60));
        pushButton_voltar_video->setFont(font3);
        pushButton_voltar_video->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_voltar_video->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_6->addWidget(pushButton_voltar_video, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer, 4, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_4, 0, 2, 1, 1);

        pushButton_voltar_iniciar = new QPushButton(iniciar);
        pushButton_voltar_iniciar->setObjectName(QString::fromUtf8("pushButton_voltar_iniciar"));
        sizePolicy2.setHeightForWidth(pushButton_voltar_iniciar->sizePolicy().hasHeightForWidth());
        pushButton_voltar_iniciar->setSizePolicy(sizePolicy2);
        pushButton_voltar_iniciar->setMinimumSize(QSize(250, 60));
        pushButton_voltar_iniciar->setMaximumSize(QSize(250, 60));
        pushButton_voltar_iniciar->setFont(font3);
        pushButton_voltar_iniciar->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_voltar_iniciar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #FF7439;\n"
"	border-radius: 20px;\n"
"	border: none;\n"
"	color: #fff;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #c8592d;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: #c8592d;\n"
"}"));

        gridLayout_6->addWidget(pushButton_voltar_iniciar, 5, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_3, 6, 2, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        radioButton_opcao2 = new QRadioButton(iniciar);
        radioButton_opcao2->setObjectName(QString::fromUtf8("radioButton_opcao2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(radioButton_opcao2->sizePolicy().hasHeightForWidth());
        radioButton_opcao2->setSizePolicy(sizePolicy5);
        radioButton_opcao2->setMinimumSize(QSize(250, 60));
        radioButton_opcao2->setBaseSize(QSize(10, 0));
        radioButton_opcao2->setFont(font2);
        radioButton_opcao2->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_opcao2->setTabletTracking(true);
        radioButton_opcao2->setFocusPolicy(Qt::TabFocus);
        radioButton_opcao2->setAcceptDrops(true);
        radioButton_opcao2->setLayoutDirection(Qt::LeftToRight);
        radioButton_opcao2->setAutoFillBackground(false);
        radioButton_opcao2->setStyleSheet(QString::fromUtf8("background-color: #9ED125;\n"
"border-radius: 5px;"));
        radioButton_opcao2->setInputMethodHints(Qt::ImhNone);
        radioButton_opcao2->setIconSize(QSize(40, 40));
        radioButton_opcao2->setCheckable(true);

        gridLayout_5->addWidget(radioButton_opcao2, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(30, 5, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 2, 1, 1, 1);

        radioButton_opcao3 = new QRadioButton(iniciar);
        radioButton_opcao3->setObjectName(QString::fromUtf8("radioButton_opcao3"));
        sizePolicy5.setHeightForWidth(radioButton_opcao3->sizePolicy().hasHeightForWidth());
        radioButton_opcao3->setSizePolicy(sizePolicy5);
        radioButton_opcao3->setMinimumSize(QSize(320, 60));
        radioButton_opcao3->setBaseSize(QSize(10, 0));
        radioButton_opcao3->setFont(font2);
        radioButton_opcao3->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_opcao3->setTabletTracking(true);
        radioButton_opcao3->setFocusPolicy(Qt::TabFocus);
        radioButton_opcao3->setAcceptDrops(true);
        radioButton_opcao3->setLayoutDirection(Qt::LeftToRight);
        radioButton_opcao3->setAutoFillBackground(false);
        radioButton_opcao3->setStyleSheet(QString::fromUtf8("background-color: #9ED125;\n"
"border-radius: 5px;"));
        radioButton_opcao3->setInputMethodHints(Qt::ImhNone);
        radioButton_opcao3->setIconSize(QSize(40, 40));
        radioButton_opcao3->setCheckable(true);

        gridLayout_5->addWidget(radioButton_opcao3, 2, 0, 1, 1);

        radioButton_opcao4 = new QRadioButton(iniciar);
        radioButton_opcao4->setObjectName(QString::fromUtf8("radioButton_opcao4"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(radioButton_opcao4->sizePolicy().hasHeightForWidth());
        radioButton_opcao4->setSizePolicy(sizePolicy6);
        radioButton_opcao4->setMinimumSize(QSize(320, 60));
        radioButton_opcao4->setBaseSize(QSize(10, 0));
        radioButton_opcao4->setFont(font2);
        radioButton_opcao4->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_opcao4->setTabletTracking(true);
        radioButton_opcao4->setFocusPolicy(Qt::TabFocus);
        radioButton_opcao4->setAcceptDrops(true);
        radioButton_opcao4->setLayoutDirection(Qt::LeftToRight);
        radioButton_opcao4->setAutoFillBackground(false);
        radioButton_opcao4->setStyleSheet(QString::fromUtf8("background-color: #9ED125;\n"
"border-radius: 5px;"));
        radioButton_opcao4->setInputMethodHints(Qt::ImhNone);
        radioButton_opcao4->setIconSize(QSize(40, 40));
        radioButton_opcao4->setCheckable(true);

        gridLayout_5->addWidget(radioButton_opcao4, 2, 2, 1, 1);

        radioButton_opcao1 = new QRadioButton(iniciar);
        radioButton_opcao1->setObjectName(QString::fromUtf8("radioButton_opcao1"));
        sizePolicy5.setHeightForWidth(radioButton_opcao1->sizePolicy().hasHeightForWidth());
        radioButton_opcao1->setSizePolicy(sizePolicy5);
        radioButton_opcao1->setMinimumSize(QSize(250, 60));
        radioButton_opcao1->setBaseSize(QSize(10, 0));
        radioButton_opcao1->setFont(font2);
        radioButton_opcao1->setCursor(QCursor(Qt::PointingHandCursor));
        radioButton_opcao1->setTabletTracking(true);
        radioButton_opcao1->setFocusPolicy(Qt::TabFocus);
        radioButton_opcao1->setAcceptDrops(true);
        radioButton_opcao1->setLayoutDirection(Qt::LeftToRight);
        radioButton_opcao1->setAutoFillBackground(false);
        radioButton_opcao1->setStyleSheet(QString::fromUtf8("background-color: #9ED125;\n"
"border-radius: 5px;"));
        radioButton_opcao1->setInputMethodHints(Qt::ImhNone);
        radioButton_opcao1->setIconSize(QSize(40, 40));
        radioButton_opcao1->setCheckable(true);

        gridLayout_5->addWidget(radioButton_opcao1, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(5, 30, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout_5->addItem(verticalSpacer_5, 1, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 3, 2, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 5, 5, 1, 1);

        scrollArea_2 = new QScrollArea(iniciar);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 688, 161));
        label_pergunta = new QLabel(scrollAreaWidgetContents_2);
        label_pergunta->setObjectName(QString::fromUtf8("label_pergunta"));
        label_pergunta->setGeometry(QRect(10, 10, 531, 171));
        sizePolicy5.setHeightForWidth(label_pergunta->sizePolicy().hasHeightForWidth());
        label_pergunta->setSizePolicy(sizePolicy5);
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setWeight(75);
        label_pergunta->setFont(font4);
        label_pergunta->setStyleSheet(QString::fromUtf8("background-color: none;"));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_6->addWidget(scrollArea_2, 1, 2, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        stackedWidget->addWidget(iniciar);

        gridLayout->addWidget(stackedWidget, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_som->setText(QString());
        label->setText(QString());
        pushButton_iniciar->setText(QCoreApplication::translate("MainWindow", "INICIAR", nullptr));
        pushButton_configurar->setText(QCoreApplication::translate("MainWindow", "CONFIGURAR", nullptr));
        pushButton_sobre->setText(QCoreApplication::translate("MainWindow", "SOBRE", nullptr));
        pushButton_sair->setText(QCoreApplication::translate("MainWindow", "SAIR", nullptr));
        pushButton_versao_qt->setText(QCoreApplication::translate("MainWindow", "VERS\303\203O DA FERRAMENTA", nullptr));
        label_versao_soft->setText(QCoreApplication::translate("MainWindow", "VERS\303\203O DO SOFTWARE: 1.0.0\n"
"2024", nullptr));
        pushButton_voltar_sobre->setText(QCoreApplication::translate("MainWindow", "VOLTAR", nullptr));
        pushButton_voltar_configurar->setText(QCoreApplication::translate("MainWindow", "VOLTAR", nullptr));
        pushButton_adicionar_video->setText(QCoreApplication::translate("MainWindow", "ADICIONAR V\303\215DEO", nullptr));
        pushButton_adicionar_pergunta->setText(QCoreApplication::translate("MainWindow", "ADICIONAR PERGUNTA", nullptr));
        pushButton_voltar_video->setText(QCoreApplication::translate("MainWindow", "VOLTAR PARA O V\303\215DEO", nullptr));
        pushButton_voltar_iniciar->setText(QCoreApplication::translate("MainWindow", "IR PARA O MENU", nullptr));
        radioButton_opcao2->setText(QCoreApplication::translate("MainWindow", "Op\303\247ao 2", nullptr));
        radioButton_opcao3->setText(QCoreApplication::translate("MainWindow", "Op\303\247ao 3", nullptr));
        radioButton_opcao4->setText(QCoreApplication::translate("MainWindow", "Op\303\247ao 4", nullptr));
        radioButton_opcao1->setText(QCoreApplication::translate("MainWindow", "Op\303\247ao 1", nullptr));
        label_pergunta->setText(QCoreApplication::translate("MainWindow", "A pergunta estar\303\241 escrita aqui...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
