#include "areachartwidget.h"

AreaChartWidget::AreaChartWidget(AreaChartData* data, QWidget *parent) : QWidget(parent)
{
    lt = new QGridLayout(this);
    areaTable = new QTableView;
    if(data==nullptr)
        areaModel = new AreaChartModel();
    else
        areaModel = new AreaChartModel(new AreaChartTableModel(this,data));
    areaTable->setModel(areaModel->getTableModel());
    areaModel->getTableModel()->setParent(areaTable);
    lt->addWidget(areaTable);
    areaTable->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    areaTable->show();

    aggiungiLinea=new QPushButton("&Aggiungi una linea");
    lt->addWidget(aggiungiLinea);
    connect(aggiungiLinea,&QPushButton::released,this,&AreaChartWidget::aggiungiLineaSlot);

    aggiungiPunto=new QPushButton("&Aggiungi punto");
    lt->addWidget(aggiungiPunto);
    connect(aggiungiPunto,&QPushButton::released,this,&AreaChartWidget::aggiungiPuntoSlot);

    rimuoviLinea=new QPushButton("&Rimuovi una linea");
    lt->addWidget(rimuoviLinea);
    connect(rimuoviLinea,&QPushButton::released,this,&AreaChartWidget::rimuoviLineaSlot);

    rimuoviPunto=new QPushButton("&Rimuovi punto");
    lt->addWidget(rimuoviPunto);
    connect(rimuoviPunto,&QPushButton::released,this,&AreaChartWidget::rimuoviPuntoSlot);

    cambiaTitolo=new QPushButton("&Cambia titolo");
    lt->addWidget(cambiaTitolo);
    connect(cambiaTitolo,&QPushButton::released,this,&AreaChartWidget::cambiaTitoloSlot);

    ingrandisci=new QPushButton("&Ingrandisci");
    lt->addWidget(ingrandisci);
    connect(ingrandisci,&QPushButton::released,this,&AreaChartWidget::chartFocus);

    chartview=new QChartView(areaModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(lt);

    connect(areaModel->getTableModel(),&ChartTableModel::dataChanged,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::columnsInserted,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::columnsRemoved,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::rowsInserted,areaModel,&ChartModel::updateAxisY);
    connect(areaModel->getTableModel(),&ChartTableModel::rowsRemoved,areaModel,&ChartModel::updateAxisY);
    connect(this,&AreaChartWidget::cambiaTitoloSignal,areaModel,&ChartModel::updateTitle);
}

void AreaChartWidget::aggiungiLineaSlot(){
    bool ok =areaModel->getTableModel()->insertColumns(areaModel->getTableModel()->columnCount(),1);
    if(ok){
        areaModel->updateInsertColumn();
        areaModel->updateAxisY();
    }
}

void AreaChartWidget::aggiungiPuntoSlot(){
    areaModel->getTableModel()->insertRows(areaModel->getTableModel()->rowCount(),1);
}

void AreaChartWidget::rimuoviLineaSlot(){
    bool ok;
    int linea;
    if(areaModel->getTableModel()->columnCount()-1>1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,areaModel->getTableModel()->columnCount()-1,1, &ok);
        if(ok){
            areaModel->getTableModel()->removeColumns(linea,1);
            areaModel->updateRemoveColumn(linea-1);
        }
    }
}

void AreaChartWidget::rimuoviPuntoSlot(){

    if(areaModel->getTableModel()->rowCount()>2){
            areaModel->getTableModel()->removeRows(areaModel->getTableModel()->rowCount()-1,1);
    }
}
void AreaChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        emit AreaChartWidget::cambiaTitoloSignal(titolo);
        //areaModel->changeTitle(titolo);
    }
}
void AreaChartWidget::salvaJson(){
    areaModel->salvaJson();
}

void AreaChartWidget::chartFocus(){
    PopupChart::chartFocus(chartview,this);
    lt->addWidget(chartview);
}
