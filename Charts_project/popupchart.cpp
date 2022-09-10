#include "popupchart.h"

PopupChart::PopupChart(QChartView* chart,QWidget *parent): QDialog(parent)
{
    lyt=new QVBoxLayout(this);
    chart=chart;
    lyt->addWidget(chart);
    //lyt->setSizeConstraint(QLayout::SetFixedSize);
    this->showMaximized();
    setLayout(lyt);
}

void PopupChart::chartFocus(QChartView* c,QWidget* parent){
    PopupChart* p=new PopupChart(c,parent);
    p->exec();
    p->deleteLater();
}
