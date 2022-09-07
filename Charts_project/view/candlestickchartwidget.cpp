#include "candlestickchartwidget.h"

CandleStickChartWidget::CandleStickChartWidget(QWidget *parent)
    : QWidget{parent}
{
    lt=new QGridLayout(this);
    candleTable=new QTableView;
    candleTableModel=new CandleStickChartTableModel();
    candleModel=new CandleStickChartModel(candleTableModel);
    candleTable->setModel(candleTableModel);
    candleTableModel->setParent(candleTable);
    lt->addWidget(candleTable);
    candleTable->show();
    aggiungiSet=new QPushButton("Aggiungi set",this);
    connect(aggiungiSet,&QPushButton::released,this,&CandleStickChartWidget::aggiungiSetSlot);
    rimuoviSet=new QPushButton("Rimuovi set",this);
    connect(rimuoviSet,&QPushButton::released,this,&CandleStickChartWidget::rimuoviSetSlot);
    chartview=new QChartView(candleModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(aggiungiSet);
    lt->addWidget(rimuoviSet);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);

    connect(candleTableModel,&CandleStickChartTableModel::dataChanged,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::columnsRemoved,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::rowsRemoved,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::columnsInserted,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::rowsInserted,candleModel,&CandleStickChartModel::updateAxis);
}

void CandleStickChartWidget::aggiungiSetSlot(){

    bool ok=candleTableModel->insertRows(candleTableModel->rowCount(),1);
    if(ok)
        candleModel->updateMapper();

}
void CandleStickChartWidget::rimuoviSetSlot(){
    bool ok;
    if(candleModel->setsCount()>1){
        int set=QInputDialog::getInt(this,tr("ELIMINA SET"),tr("Set:"),QLineEdit::Normal,1,candleModel->setsCount(),1,&ok);
    if(ok)
        candleTableModel->removeRows(set-1,1);
        candleModel->updateRemoved(set-1);
    }

}
