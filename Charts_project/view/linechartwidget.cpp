#include "linechartwidget.h"

LineChartWidget::LineChartWidget(LineChartData* data,QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    aggiungiriga=new QPushButton("&Aggiungi punto");
    aggiungilinea=new QPushButton("&Aggiungi una linea");
    togliLinea=new QPushButton("&Rimuovi linea");
    togliPunto=new QPushButton("Rimuovi Punti");
    cambiaTitolo=new QPushButton("Cambia Titolo");
    connect(aggiungilinea,&QPushButton::released,this,&LineChartWidget::aggiungilineaslot);
    connect(aggiungiriga,&QPushButton::released,this,&LineChartWidget::aggiungipunto);
    connect(togliLinea,&QPushButton::released,this,&LineChartWidget::togliLineaSlot);
    connect(togliPunto,&QPushButton::released,this,&LineChartWidget::togliPuntoSlot);
    connect(cambiaTitolo,&QPushButton::released,this,&LineChartWidget::cambiaTitoloSlot);
    table=new QTableView;
    if(data==nullptr)
        linecharttablemodel=new LineChartTableModel();
    else
        linecharttablemodel=new LineChartTableModel(data);
    linechartmodel=new LineChartModel(linecharttablemodel);

    table->setModel(linecharttablemodel);
     linecharttablemodel->setParent(table);
     lt->addWidget(table);

     table->show();
     chartview=new QChartView(linechartmodel->getChart());
     chartview->setRenderHint(QPainter::Antialiasing);
     chartview->setMinimumSize(1280,480);
     lt->addWidget(aggiungiriga);
     lt->addWidget(aggiungilinea);
     lt->addWidget(togliLinea);
     lt->addWidget(togliPunto);
     lt->addWidget(cambiaTitolo);
     lt->addWidget(chartview);
     lt->setSizeConstraint(QLayout::SetFixedSize);
     setLayout(lt);
     //linecharttablemodel->setHeaderData(0, Qt::Horizontal, "Stock ID", Qt::DisplayRole);
     connect(nullptr,&MainWindow::salvaConNomeSignal,this,&LineChartWidget::salvaJsonFile);
     connect(linecharttablemodel,&LineChartTableModel::dataChanged,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::rowsInserted,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::rowsRemoved,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::columnsInserted,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::columnsRemoved,linechartmodel,&LineChartModel::updateAxisY);
}

void LineChartWidget::aggiungilineaslot(){

    bool ok;
    QString nomeLinea=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && nomeLinea.trimmed()!=""){
        linechartmodel->addLinea(linecharttablemodel,nomeLinea);
        //linecharttablemodel->insertColumns(linecharttablemodel->columnCount(),2);
        linecharttablemodel->insertColumns(linecharttablemodel->columnCount(),1);
        linechartmodel->updateMapper(linecharttablemodel);
        linechartmodel->updateAxisY();
    }
}

void LineChartWidget::aggiungipunto(){
    linecharttablemodel->insertRows(linecharttablemodel->rowCount(),1);
    linechartmodel->updateAxises();
}

void LineChartWidget::togliLineaSlot(){
    bool ok;
    int linea;
    if(linecharttablemodel->columnCount()-1>1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,linecharttablemodel->columnCount()-1,1, &ok);
        if(ok){
            linecharttablemodel->removeColumns(linea,1);
            linechartmodel->updateRemoved(linea-1);
        }
    }
}

void LineChartWidget::togliPuntoSlot(){

            if(linecharttablemodel->rowCount()>2){

                    linecharttablemodel->removeRows(linecharttablemodel->rowCount()-1,1);

            }
}

void LineChartWidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        linechartmodel->cambiaTitolo(linecharttablemodel,titolo);
    }
}
void LineChartWidget::salvaJsonFile(){
    linechartmodel->salvaJsonFile();
}
