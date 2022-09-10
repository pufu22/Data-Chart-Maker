#include "areachartwidget.h"

AreaChartWidget::AreaChartWidget(QWidget *parent, const char *name,AreaChartData* data):QWidget(parent)
{
    lt=new QGridLayout(this);
    areaTable=new QTableView;
    if(data==nullptr)
        areaTableModel=new AreaChartTableModel();
    else
        areaTableModel=new AreaChartTableModel(data);
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

    rimuoviLinea=new QPushButton("&Rimuovi una linea");
    lt->addWidget(rimuoviLinea);
    connect(rimuoviLinea,&QPushButton::released,this,&AreaChartWidget::rimuoviLineaSlot);

    rimuoviPunto=new QPushButton("&Rimuovi punto");
    lt->addWidget(rimuoviPunto);
    connect(rimuoviPunto,&QPushButton::released,this,&AreaChartWidget::rimuoviPuntoSlot);

    cambiaTitolo=new QPushButton("&Cambia titolo");
    lt->addWidget(cambiaTitolo);
    connect(cambiaTitolo,&QPushButton::released,this,&AreaChartWidget::cambiaTitoloSlot);

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

        bool ok =areaTableModel->insertColumns(areaTableModel->columnCount(),1);
        if(ok){
            areaModel->updateMappers();
            areaModel->updateAxisY();
        }

}

void AreaChartWidget::aggiungiPuntoSlot(){
    areaTableModel->insertRows(areaTableModel->rowCount(),1);
}

void AreaChartWidget::rimuoviLineaSlot(){
    bool ok;
    int linea;
    if(areaTableModel->columnCount()-1>1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,areaTableModel->columnCount()-1,1, &ok);
        if(ok){
            areaTableModel->removeColumns(linea,1);
            areaModel->updateRemoved(linea-1);
        }
    }
}

void AreaChartWidget::rimuoviPuntoSlot(){

    if(areaTableModel->rowCount()>2){
            areaTableModel->removeRows(areaTableModel->rowCount()-1,1);
    }
}
void AreaChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        areaModel->changeTitle(titolo);
    }
}
void AreaChartWidget::salvaJson(){
    areaModel->salvaJson();
}
