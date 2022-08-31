#include<CreateChartWidget.h>
#include<QWidget>
#include<selectchartwidget.h>
#include<iostream>
#include<QDialog>
using namespace std;
CreateChartWidget::CreateChartWidget(QWidget *parent, const char *name):QWidget(parent){
     QHBoxLayout *lt = new QHBoxLayout(this);
     lt->setMargin(0);
     //QLabel *label=new QLabel("Create a chart");
     //lt->addWidget(label);
     //lt->addSpacing(15);
     QPushButton *createbutton=new QPushButton("&Create",this);
     connect(createbutton,&QPushButton::released,this,&CreateChartWidget::apri_crea);
     lt->addWidget(createbutton);
}

void CreateChartWidget::apri_crea(){

    QDialog* about=new QDialog(0,0);
    about->show();
    /*selectchartwidget* select=new selectchartwidget(this,"select");
    select->setVisible(true);*/
    cout<<"ciao";
}
