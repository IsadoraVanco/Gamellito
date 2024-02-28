/********************************************************************************
** Form generated from reading UI file 'telaoptativa.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELAOPTATIVA_H
#define UI_TELAOPTATIVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaOptativa
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page;
    QCheckBox *checkBox;
    QPushButton *pushButton_voltar;
    QPushButton *pushButton_voltar_2;
    QWidget *page_2;
    QToolButton *toolButton;
    QPushButton *pushButton_voltar_3;
    QLabel *label;

    void setupUi(QWidget *TelaOptativa)
    {
        if (TelaOptativa->objectName().isEmpty())
            TelaOptativa->setObjectName(QString::fromUtf8("TelaOptativa"));
        TelaOptativa->resize(768, 414);
        TelaOptativa->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 244, 83);"));
        stackedWidget = new QStackedWidget(TelaOptativa);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(80, 70, 551, 271));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        checkBox = new QCheckBox(page);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(200, 90, 87, 21));
        pushButton_voltar = new QPushButton(page);
        pushButton_voltar->setObjectName(QString::fromUtf8("pushButton_voltar"));
        pushButton_voltar->setGeometry(QRect(10, 210, 111, 41));
        pushButton_voltar_2 = new QPushButton(page);
        pushButton_voltar_2->setObjectName(QString::fromUtf8("pushButton_voltar_2"));
        pushButton_voltar_2->setGeometry(QRect(420, 220, 111, 41));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        toolButton = new QToolButton(page_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(120, 70, 24, 26));
        pushButton_voltar_3 = new QPushButton(page_2);
        pushButton_voltar_3->setObjectName(QString::fromUtf8("pushButton_voltar_3"));
        pushButton_voltar_3->setGeometry(QRect(420, 220, 90, 28));
        stackedWidget->addWidget(page_2);
        label = new QLabel(TelaOptativa);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(280, 20, 151, 41));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(TelaOptativa);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TelaOptativa);
    } // setupUi

    void retranslateUi(QWidget *TelaOptativa)
    {
        TelaOptativa->setWindowTitle(QCoreApplication::translate("TelaOptativa", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("TelaOptativa", "CheckBox", nullptr));
        pushButton_voltar->setText(QCoreApplication::translate("TelaOptativa", "Ir para o inicio", nullptr));
        pushButton_voltar_2->setText(QCoreApplication::translate("TelaOptativa", "Proximo", nullptr));
        toolButton->setText(QCoreApplication::translate("TelaOptativa", "...", nullptr));
        pushButton_voltar_3->setText(QCoreApplication::translate("TelaOptativa", "proximo", nullptr));
        label->setText(QCoreApplication::translate("TelaOptativa", "Tela Optativa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TelaOptativa: public Ui_TelaOptativa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELAOPTATIVA_H
