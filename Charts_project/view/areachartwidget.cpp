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

    chartview=new QChartView(areaModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);

    connect(areaTableModel,&AreaChartTableModel::dataChanged,areaModel,&AreaChartModel::updateAxisY);
    connect(areaTableModel,&AreaChartTableModel::columnsInserted,areaModel,&AreaChartModel::updateAxisY);
    connect(areaTableModel,&AreaChartTableModel::columnsRemoved,areaModel,&AreaChartModel::updateAxisY);
    connect(areaTableModel,&AreaChartTableModel::rowsInserted,areaModel,&AreaChartModel::updateAxisY);
    connect(areaTableModel,&AreaChartTableModel::rowsRemoved,areaModel,&AreaChartModel::updateAxisY);
}
void AreaChartWidget::aggiungiLineaSlot(){
    //areaTableModel->insertColumns(areaTableModel->columnCount(),2);
    areaTableModel->insertColumns(areaTableModel->columnCount(),1);
    areaModel->updateInsertColumn();
}

void AreaChartWidget::aggiungiPuntoSlot(){
    areaTableModel->insertRows(areaTableModel->rowCount(),1);
}
