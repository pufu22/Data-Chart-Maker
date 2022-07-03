#include "piechartwidget.h"

piechartwidget::piechartwidget(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    pietable=new QTableView;
    pietablemodel=new Piecharttablemodel();
    piemodel=new piechartmodel(pietablemodel);
    pietable->setModel(pietablemodel);
    pietablemodel->setParent(pietable);
    lt->addWidget(pietable);
    aggiungifetta=new QPushButton("&Aggiungi una fetta");
    lt->addWidget(aggiungifetta);
    connect(aggiungifetta,&QPushButton::released,this,&piechartwidget::aggiungifettaslot);
    pietable->show();
    chartview=new QChartView(piemodel->chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(lt);
}

void piechartwidget::aggiungifettaslot(){
pietablemodel->insertRows(pietablemodel->rowCount(),1);
bool ok;
QStringList list = inputdialog::getStrings(this, &ok);
if (ok) {

}
}
