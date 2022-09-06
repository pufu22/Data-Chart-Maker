#include "selectwindow.h"

selectWindow::selectWindow(QWidget* parent)
{
    lt=new QGridLayout(this);
    prima=new QPushButton("&Barchart");
    lt->addWidget(prima);
    connect(prima,&QPushButton::released,this,&selectWindow::creaBarChart);
    seconda=new QPushButton("&Linechart");
    lt->addWidget(seconda);
    connect(seconda,&QPushButton::released,this,&selectWindow::creaLineChart);
    terza=new QPushButton("&Pie chart");
    lt->addWidget(terza);
    connect(terza,&QPushButton::released,this,&selectWindow::creaPieChart);
    quarta=new QPushButton("&Area chart");
    lt->addWidget(quarta);
    connect(quarta,&QPushButton::released,this,&selectWindow::creaAreaChart);

}
selectWindow::~selectWindow()
{}

void selectWindow::creaBarChart(){
    emit creaBarChartSignal();
    this->destroy();
}

void selectWindow::creaLineChart(){
    emit creaLineChartSignal();
    this->destroy();
}

void selectWindow::creaAreaChart(){
    emit creaAreaChartSignal();
    this->destroy();
}

void selectWindow::creaPieChart(){
    emit creaPieChartSignal();
    this->destroy();
}
