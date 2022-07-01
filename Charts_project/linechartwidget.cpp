#include "linechartwidget.h"

LineChartWidget::LineChartWidget(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    aggiungiriga=new QPushButton("&Aggiungi punto");
    aggiungicolonna=new QPushButton("&Aggiungi colonna");
    aggiungilinea=new QPushButton("&Aggiungi una linea");
    connect(aggiungilinea,&QPushButton::released,this,&LineChartWidget::aggiungilineaslot);
    connect(aggiungiriga,&QPushButton::released,this,&LineChartWidget::aggiungipunto);
    table=new QTableView;
    linecharttablemodel=new LineChartTableModel();

    linechartmodel=new LineChartModel(linecharttablemodel);
    connect(linecharttablemodel,&LineChartTableModel::changeRange,linechartmodel,&LineChartModel::axises);
    table->setModel(linecharttablemodel);
     linecharttablemodel->setParent(table);
     lt->addWidget(table);

     table->show();
     chartview=new QChartView(linechartmodel->chart);
     chartview->setRenderHint(QPainter::Antialiasing);
     chartview->setMinimumSize(1280,480);
     lt->addWidget(aggiungiriga);
     lt->addWidget(aggiungicolonna);
     lt->addWidget(aggiungilinea);
     lt->addWidget(chartview);
     lt->setSizeConstraint(QLayout::SetFixedSize);
     setLayout(lt);
     linecharttablemodel->setHeaderData(0, Qt::Horizontal, "Stock ID", Qt::DisplayRole);

}

void LineChartWidget::aggiungilineaslot(){
    linecharttablemodel->insertColumns(linecharttablemodel->columnCount(),2);
    linechartmodel->updateMapper(linecharttablemodel);
    linechartmodel->updateAxises();
}

void LineChartWidget::aggiungipunto(){
    linecharttablemodel->insertRows(linecharttablemodel->rowCount(),1);
    linechartmodel->updateMapper(linecharttablemodel);
    linechartmodel->updateAxises();
}
