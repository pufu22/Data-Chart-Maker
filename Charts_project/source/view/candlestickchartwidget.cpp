#include "candlestickchartwidget.h"

CandleStickChartWidget::CandleStickChartWidget(CandleStickData* data, QWidget *parent) : QWidget{parent} {
    lt = new QGridLayout(this);
    candleTable = new QTableView;
    if(data == nullptr)
        candleModel = new CandleStickChartModel();
    else
        candleModel = new CandleStickChartModel(new CandleStickChartTableModel(this,data));
    candleTable->setModel(candleModel->getTableModel());
    candleModel->getTableModel()->setParent(candleTable);
    lt->addWidget(candleTable);
    candleTable->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    candleTable->show();
    aggiungiSet=new QPushButton("Aggiungi set",this);
    connect(aggiungiSet,&QPushButton::released,this,&CandleStickChartWidget::aggiungiSetSlot);
    rimuoviSet=new QPushButton("Rimuovi set",this);
    connect(rimuoviSet,&QPushButton::released,this,&CandleStickChartWidget::rimuoviSetSlot);
    cambiaTitolo = new QPushButton("Cambia Titolo",this);
    connect(cambiaTitolo,&QPushButton::released,this,&CandleStickChartWidget::cambiaTitoloSlot);
    chartview=new QChartView(candleModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(aggiungiSet);
    lt->addWidget(rimuoviSet);
    lt->addWidget(cambiaTitolo);
    ingrandisci=new QPushButton("&Ingrandisci");
    lt->addWidget(ingrandisci);
    connect(ingrandisci,&QPushButton::released,this,&CandleStickChartWidget::chartFocus);
    lt->addWidget(chartview);

    lt->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(lt);

    connect(candleModel->getTableModel(),&ChartTableModel::dataChanged,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::columnsRemoved,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::rowsRemoved,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::columnsInserted,candleModel,&ChartModel::updateAxisY);
    connect(candleModel->getTableModel(),&ChartTableModel::rowsInserted,candleModel,&ChartModel::updateAxisY);
    connect(this,&CandleStickChartWidget::salvaJson,candleModel,&ChartModel::salvaJson);
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

void CandleStickChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        candleModel->updateTitle(titolo);
    }
}
void CandleStickChartWidget::chartFocus(){
    PopupChart::chartFocus(chartview,this);
    lt->addWidget(chartview);
}
