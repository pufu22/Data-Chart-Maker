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
