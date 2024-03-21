/********************************************************************************
** Form generated from reading UI file 'sobre.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOBRE_H
#define UI_SOBRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_sobre
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_sobreQt;

    void setupUi(QDialog *sobre)
    {
        if (sobre->objectName().isEmpty())
            sobre->setObjectName(QString::fromUtf8("sobre"));
        sobre->resize(960, 540);
        sobre->setMinimumSize(QSize(960, 540));
        sobre->setMaximumSize(QSize(16777215, 16777215));
        sobre->setStyleSheet(QString::fromUtf8("background: qlineargradient(spread:pad, x1:0.605, y1:0.374591, x2:0.094, y2:0.125, stop:0 rgba(251, 254, 12, 255), stop:1 rgba(255, 116, 57, 255))"));
        gridLayout = new QGridLayout(sobre);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(370, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        label = new QLabel(sobre);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(320, 60));
        label->setMaximumSize(QSize(320, 60));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("text-align: center;\n"
"background: none;\n"
"color: black;"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(370, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        pushButton_sobreQt = new QPushButton(sobre);
        pushButton_sobreQt->setObjectName(QString::fromUtf8("pushButton_sobreQt"));
        pushButton_sobreQt->setMinimumSize(QSize(320, 60));
        pushButton_sobreQt->setMaximumSize(QSize(320, 60));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_sobreQt->setFont(font1);
        pushButton_sobreQt->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_sobreQt->setStyleSheet(QString::fromUtf8("background-color: #FF7439;\n"
"border-radius: 20px;\n"
"color: #fff;"));

        gridLayout->addWidget(pushButton_sobreQt, 1, 1, 1, 1);


        retranslateUi(sobre);

        QMetaObject::connectSlotsByName(sobre);
    } // setupUi

    void retranslateUi(QDialog *sobre)
    {
        sobre->setWindowTitle(QCoreApplication::translate("sobre", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("sobre", "VERS\303\203O DO SOFTWARE: 1.0.0\n"
"2024", nullptr));
        pushButton_sobreQt->setText(QCoreApplication::translate("sobre", "VERS\303\203O DA FERRAMENTA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sobre: public Ui_sobre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOBRE_H
