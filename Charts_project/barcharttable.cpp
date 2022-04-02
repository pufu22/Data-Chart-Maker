#include "barcharttable.h"

barcharttable::barcharttable(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);

    aggiungi_riga=new QPushButton("&Aggiungi riga");
    connect(aggiungi_riga,&QPushButton::released,this,&barcharttable::aggiungiriga);
    aggiungi_colonna=new QPushButton("&Aggiungi colonna");
    connect(aggiungi_colonna,&QPushButton::released,this,&barcharttable::aggiungicolonna);

    table=new QTableView;
    barmodel=new BarChartTableModel();
    m_model=new BarChartModel(barmodel);
    table->setModel(barmodel);
    barmodel->setParent(table);
    lt->addWidget(table);
    table->show();

    QChartView *chartView = new QChartView(m_model->chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1280, 480);

    lt->addWidget(aggiungi_riga);
    lt->addWidget(aggiungi_colonna);
    lt->addWidget(chartView);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);

}

void barcharttable::setupModels(){
    //barchartmodel=new BarChartModel();
    barmodel=new BarChartTableModel();
    //barmodel->newData();
}

void barcharttable::aggiungiriga(){
    barmodel->insertRows(barmodel->rowCount(),1);
    m_model->updateMapperLastRow();
}

void barcharttable::aggiungicolonna(){
    barmodel->insertColumns(barmodel->columnCount(),1);
    m_model->updateMapperLastColumn();
}

