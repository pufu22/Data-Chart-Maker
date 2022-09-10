#include "candlestickchartwidget.h"

CandleStickChartWidget::CandleStickChartWidget(QWidget *parent,CandleStickData* d)
    : QWidget{parent}
{
    lt=new QGridLayout(this);
    candleTable=new QTableView;
    if(d)
    candleTableModel=new CandleStickChartTableModel(d);
        else
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
    cambiaTitolo=new QPushButton("Cambia Titolo",this);
    connect(cambiaTitolo,&QPushButton::released,this,&CandleStickChartWidget::cambiaTitoloSlot);
    chartview=new QChartView(candleModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(aggiungiSet);
    lt->addWidget(rimuoviSet);
    lt->addWidget(cambiaTitolo);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(lt);

    connect(candleTableModel,&CandleStickChartTableModel::dataChanged,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::columnsRemoved,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::rowsRemoved,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::columnsInserted,candleModel,&CandleStickChartModel::updateAxis);
    connect(candleTableModel,&CandleStickChartTableModel::rowsInserted,candleModel,&CandleStickChartModel::updateAxis);
    connect(this,&CandleStickChartWidget::salvaJson,candleModel,&CandleStickChartModel::salvaJson);
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

void CandleStickChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        candleModel->cambiaTitolo(candleTableModel,titolo);
    }
}
