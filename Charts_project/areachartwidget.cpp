#include "areachartwidget.h"

AreaChartWidget::AreaChartWidget(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    areaTable=new QTableView;
    areaTableModel=new AreaChartTableModel();
    areaModel=new AreaChartModel(areaTableModel);
    areaTable->setModel(areaTableModel);
    areaTableModel->setParent(areaTable);
    lt->addWidget(areaTable);
    areaTable->show();

    aggiungiLinea=new QPushButton("&Aggiungi una linea");
    lt->addWidget(aggiungiLinea);
    connect(aggiungiLinea,&QPushButton::released,this,&AreaChartWidget::aggiungiLineaSlot);

    aggiungiPunto=new QPushButton("&Aggiungi punto");
    lt->addWidget(aggiungiPunto);
    connect(aggiungiPunto,&QPushButton::released,this,&AreaChartWidget::aggiungiPuntoSlot);

    chartview=new QChartView(areaModel->chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);
}
void AreaChartWidget::aggiungiLineaSlot(){
    areaTableModel->insertColumns(areaTableModel->columnCount(),2);
    areaModel->updateMappers(areaTableModel);
}

void AreaChartWidget::aggiungiPuntoSlot(){
    areaTableModel->insertRows(areaTableModel->rowCount(),1);
}
