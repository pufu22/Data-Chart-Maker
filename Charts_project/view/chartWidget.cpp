#include "chartWidget.h"

ChartWidget::ChartWidget(QWidget *parent) : QWidget{parent} {
    /*this->setTableView();
    buttons = this->setArrayPushButton();
    this->setChartView();*/

    lt=new QGridLayout(this);
    lt->addWidget(table);
    table->show();

    for(auto i = buttons->begin(); i < buttons->end(); i++){
        lt->addWidget(*i);
    }

    lt->addWidget(chartView);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);
}
