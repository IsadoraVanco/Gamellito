#ifndef BARRAJANELA_H
#define BARRAJANELA_H

#include <QApplication>
//#include <QMainWindow>
#include <QProxyStyle>
#include <QStyleOptionTitleBar>
#include <QPainter>

class BarraJanela : public QProxyStyle
{

public:
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = nullptr) const override;

};

#endif // BARRAJANELA_H
