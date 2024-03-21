/********************************************************************************
** Form generated from reading UI file 'telanova.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TELANOVA_H
#define UI_TELANOVA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TelaNova
{
public:
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QProgressBar *progressBar;
    QPushButton *pushButton_voltar_nova;
    QPushButton *pushButton_2_proximo_nova;
    QWidget *page_2;
    QPushButton *pushButton_2_proximo_nova_2;
    QListWidget *listWidget;

    void setupUi(QWidget *TelaNova)
    {
        if (TelaNova->objectName().isEmpty())
            TelaNova->setObjectName(QString::fromUtf8("TelaNova"));
        TelaNova->resize(725, 427);
        TelaNova->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 144, 32);"));
        label = new QLabel(TelaNova);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(290, 30, 141, 51));
        label->setAlignment(Qt::AlignCenter);
        stackedWidget = new QStackedWidget(TelaNova);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(40, 100, 591, 291));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        progressBar = new QProgressBar(page);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(150, 210, 251, 23));
        progressBar->setValue(24);
        pushButton_voltar_nova = new QPushButton(page);
        pushButton_voltar_nova->setObjectName(QString::fromUtf8("pushButton_voltar_nova"));
        pushButton_voltar_nova->setGeometry(QRect(60, 30, 90, 28));
        pushButton_2_proximo_nova = new QPushButton(page);
        pushButton_2_proximo_nova->setObjectName(QString::fromUtf8("pushButton_2_proximo_nova"));
        pushButton_2_proximo_nova->setGeometry(QRect(460, 30, 90, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pushButton_2_proximo_nova_2 = new QPushButton(page_2);
        pushButton_2_proximo_nova_2->setObjectName(QString::fromUtf8("pushButton_2_proximo_nova_2"));
        pushButton_2_proximo_nova_2->setGeometry(QRect(470, 30, 90, 28));
        listWidget = new QListWidget(page_2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(100, 30, 256, 192));
        stackedWidget->addWidget(page_2);

        retranslateUi(TelaNova);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TelaNova);
    } // setupUi

    void retranslateUi(QWidget *TelaNova)
    {
        TelaNova->setWindowTitle(QCoreApplication::translate("TelaNova", "Form", nullptr));
        label->setText(QCoreApplication::translate("TelaNova", "Tela nova ", nullptr));
        progressBar->setFormat(QString());
        pushButton_voltar_nova->setText(QCoreApplication::translate("TelaNova", "Inicio", nullptr));
        pushButton_2_proximo_nova->setText(QCoreApplication::translate("TelaNova", "Proximo", nullptr));
        pushButton_2_proximo_nova_2->setText(QCoreApplication::translate("TelaNova", "Proximo", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("TelaNova", "sdfsdfsd", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("TelaNova", "sdfsdfsd", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("TelaNova", "sdfsdfsdv", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("TelaNova", "bfbgbbgbgb", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class TelaNova: public Ui_TelaNova {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TELANOVA_H
