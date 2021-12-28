#include<CreateChartWidget.h>
#include<QWidget>
CreateChartWidget::CreateChartWidget(QWidget *parent, const char *name):QWidget(parent){
     QHBoxLayout *lt = new QHBoxLayout(this);
     lt->setMargin(0);
     QLabel *label=new QLabel("Create a chart");
     lt->addWidget(label);
     lt->addSpacing(15);
     QPushButton *createbutton=new QPushButton("Create",this);
     lt->addWidget(createbutton);
}
