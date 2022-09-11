#include "linechartwidget.h"

LineChartWidget::LineChartWidget(LineChartData* data,QWidget *parent) : QWidget(parent) {
    lt = new QGridLayout(this);
    aggiungiriga = new QPushButton("&Aggiungi punto");
    aggiungilinea = new QPushButton("&Aggiungi una linea");
    togliLinea = new QPushButton("&Rimuovi linea");
    togliPunto = new QPushButton("Rimuovi Punti");
    cambiaTitolo=new QPushButton("Cambia Titolo");
    connect(aggiungilinea,&QPushButton::released,this,&LineChartWidget::aggiungilineaSlot);
    connect(aggiungiriga,&QPushButton::released,this,&LineChartWidget::aggiungipuntoSlot);
    connect(togliLinea,&QPushButton::released,this,&LineChartWidget::togliLineaSlot);
    connect(togliPunto,&QPushButton::released,this,&LineChartWidget::togliPuntoSlot);
    connect(cambiaTitolo,&QPushButton::released,this,&LineChartWidget::cambiaTitoloSlot);
    tableModel = new QTableView;
    if(data==nullptr)
        lineModel = new LineChartModel();
    else
        lineModel = new LineChartModel(new LineChartTableModel(this, data));

    tableModel->setModel(lineModel->getTableModel());
    lineModel->getTableModel()->setParent(tableModel);
    lt->addWidget(tableModel);

    tableModel->show();
    chartview = new QChartView(lineModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(aggiungiriga);
    lt->addWidget(aggiungilinea);
    lt->addWidget(togliLinea);
    lt->addWidget(togliPunto);
    lt->addWidget(cambiaTitolo);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(lt);
    connect(lineModel->getTableModel(),&ChartTableModel::dataChanged,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::rowsRemoved,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::columnsRemoved,lineModel,&ChartModel::updateAxisY);
}

void LineChartWidget::aggiungilineaSlot(){

    bool ok = lineModel->getTableModel()->insertColumns(lineModel->getTableModel()->columnCount(),1);
    if(ok){
        lineModel->updateInsertColumn();
        lineModel->updateAxisY();
    }
}

void LineChartWidget::togliLineaSlot(){
    bool ok;
    int linea;
    if(lineModel->getTableModel()->columnCount()-1>1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,lineModel->getTableModel()->columnCount()-1,1, &ok);
        if(ok){
            lineModel->getTableModel()->removeColumns(linea,1);
            lineModel->updateRemoveColumn(linea-1);
        }
    }
}

void LineChartWidget::aggiungipuntoSlot(){
    lineModel->getTableModel()->insertRows(lineModel->getTableModel()->rowCount(),1);
}

void LineChartWidget::togliPuntoSlot(){
    if(lineModel->getTableModel()->rowCount()>2)
        lineModel->getTableModel()->removeRows(lineModel->getTableModel()->rowCount()-1,1);
}

void LineChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        lineModel->updateTitle(titolo);
    }
}

void LineChartWidget::salvaJsonFile(){
    lineModel->salvaJson();
}
