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

    connect(candleTableModel,&CandleStickChartTableModel::dataChanged,candleModel,&CandleStickChartModel::updateAxisY);
    connect(candleTableModel,&CandleStickChartTableModel::columnsRemoved,candleModel,&CandleStickChartModel::updateAxisY);
    connect(candleTableModel,&CandleStickChartTableModel::rowsRemoved,candleModel,&CandleStickChartModel::updateAxisY);
    connect(candleTableModel,&CandleStickChartTableModel::columnsInserted,candleModel,&CandleStickChartModel::updateAxisY);
    connect(candleTableModel,&CandleStickChartTableModel::rowsInserted,candleModel,&CandleStickChartModel::updateAxisY);
}

void CandleStickChartWidget::aggiungiSetSlot(){

    bool ok=candleTableModel->insertRows(candleTableModel->rowCount(),1);
    if(ok)
        candleModel->updateInsertRow();

}
void CandleStickChartWidget::rimuoviSetSlot(){
    bool ok;
    if(candleTableModel->rowCount() > 1){
        int set=QInputDialog::getInt(this,tr("ELIMINA SET"),tr("Set:"),QLineEdit::Normal,1,candleTableModel->rowCount(),1,&ok);
        if(ok)
            candleTableModel->removeRows(set-1,1);
        candleModel->updateRemoveRow(set-1);
    }

}
