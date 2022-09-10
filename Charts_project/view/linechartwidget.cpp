#include "linechartwidget.h"

LineChartWidget::LineChartWidget(LineChartData* data,QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    aggiungiriga=new QPushButton("&Aggiungi punto");
    aggiungilinea=new QPushButton("&Aggiungi una linea");
    togliLinea=new QPushButton("&Rimuovi linea");
    togliPunto=new QPushButton("Rimuovi Punti");
    connect(aggiungilinea,&QPushButton::released,this,&LineChartWidget::aggiungilineaslot);
    connect(aggiungiriga,&QPushButton::released,this,&LineChartWidget::aggiungipunto);
    connect(togliLinea,&QPushButton::released,this,&LineChartWidget::togliLineaSlot);
    connect(togliPunto,&QPushButton::released,this,&LineChartWidget::togliPuntoSlot);
    table=new QTableView;
    if(data==nullptr)
        linecharttablemodel=new LineChartTableModel();
    else
        linecharttablemodel=new LineChartTableModel(this, data);
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
     lt->addWidget(chartview);
     lt->setSizeConstraint(QLayout::SetFixedSize);
     setLayout(lt);
     linecharttablemodel->setHeaderData(0, Qt::Horizontal, "Stock ID", Qt::DisplayRole);
     connect(nullptr,&MainWindow::salvaConNomeSignal,this,&LineChartWidget::salvaJsonFile);
     connect(linecharttablemodel,&LineChartTableModel::dataChanged,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::rowsInserted,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::rowsRemoved,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::columnsInserted,linechartmodel,&LineChartModel::updateAxisY);
     connect(linecharttablemodel,&LineChartTableModel::columnsRemoved,linechartmodel,&LineChartModel::updateAxisY);
}

void LineChartWidget::aggiungilineaslot(){

    bool ok = linecharttablemodel->insertColumns(linecharttablemodel->columnCount(),1);
    if(ok){
        linechartmodel->updateInsertColumn();
        linechartmodel->updateAxisY();
    }
}

void LineChartWidget::aggiungipunto(){
    linecharttablemodel->insertRows(linecharttablemodel->rowCount(),1);
}

void LineChartWidget::togliLineaSlot(){
    bool ok;
    int linea;
    if(linecharttablemodel->columnCount()-1 > 1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,linecharttablemodel->columnCount()-1,1, &ok);
        if(ok) {
            linecharttablemodel->removeColumns(linea, 1);
            linechartmodel->updateRemoveColumn(linea-1);
        }
    }
}

void LineChartWidget::togliPuntoSlot(){
            bool ok;
            int row;
            if(linecharttablemodel->rowCount()>1){
                row=QInputDialog::getInt(this, tr("Punti"),tr("Punti"),1,1,linecharttablemodel->rowCount(),1, &ok);
                if (ok){
                    linecharttablemodel->removeRows(row-1,1);
                }
            }
}

void LineChartWidget::salvaJsonFile(){
    linechartmodel->salvaJson();
}
