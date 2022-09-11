#include "candlestickchartwidget.h"

CandleStickChartWidget::CandleStickChartWidget(QWidget *parent) : QWidget{parent} {
    lt = new QGridLayout(this);
    candleTable = new QTableView;
    candleModel = new CandleStickChartModel();
    candleTable->setModel(candleModel->getTableModel());
    //candleModel->getTableModel()->setParent(candleTable);            in teoria non serve
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

    connect(candleModel->getTableModel(),&ChartTableModel::dataChanged,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::columnsRemoved,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::rowsRemoved,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::columnsInserted,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::rowsInserted,candleModel,&ChartModel::updateAxisY);
}

void CandleStickChartWidget::aggiungiSetSlot(){

    bool ok=candleModel->getTableModel()->insertRows(candleModel->getTableModel()->rowCount(),1);
    if(ok)
        candleModel->updateInsertRow();

}
void CandleStickChartWidget::rimuoviSetSlot(){
    bool ok;
    if(candleModel->getTableModel()->rowCount() > 1){
        int set=QInputDialog::getInt(this,tr("ELIMINA SET"),tr("Set:"),QLineEdit::Normal,1,candleModel->getTableModel()->rowCount(),1,&ok);
        if(ok)
            candleModel->getTableModel()->removeRows(set-1,1);
        candleModel->updateRemoveRow(set-1);
    }

}
