#include "areachartwidget.h"

AreaChartWidget::AreaChartWidget(QWidget *parent, const char *name) : QWidget(parent)
{
    lt = new QGridLayout(this);
    areaTable = new QTableView;
    areaModel = new AreaChartModel();
    areaTable->setModel(areaModel->getTableModel());
    //areaModel->getTableModel()->setParent(areaTable);          non serve in teoria
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

    connect(areaModel->getTableModel(),&ChartTableModel::dataChanged,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::columnsInserted,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::columnsRemoved,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::rowsInserted,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::rowsRemoved,areaModel,&ChartModel::updateAxisY);
}
void AreaChartWidget::aggiungiLineaSlot(){
    areaModel->getTableModel()->insertColumns(areaModel->getTableModel()->columnCount(),1);
    areaModel->updateInsertColumn();
}

void AreaChartWidget::aggiungiPuntoSlot(){
    areaModel->getTableModel()->insertRows(areaModel->getTableModel()->rowCount(),1);
}
