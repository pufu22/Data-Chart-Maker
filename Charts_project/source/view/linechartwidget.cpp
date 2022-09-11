#include "linechartwidget.h"

LineChartWidget::LineChartWidget(LineChartData* data,QWidget *parent, const char *name) : QWidget(parent)
{
    lt = new QGridLayout(this);
    aggiungiriga = new QPushButton("&Aggiungi punto");
    aggiungilinea = new QPushButton("&Aggiungi una linea");
    togliLinea = new QPushButton("&Rimuovi linea");
    togliPunto = new QPushButton("Rimuovi Punti");
    connect(aggiungilinea,&QPushButton::released,this,&LineChartWidget::aggiungilineaslot);
    connect(aggiungiriga,&QPushButton::released,this,&LineChartWidget::aggiungipunto);
    connect(togliLinea,&QPushButton::released,this,&LineChartWidget::togliLineaSlot);
    connect(togliPunto,&QPushButton::released,this,&LineChartWidget::togliPuntoSlot);
    tableModel = new QTableView;
    if(data==nullptr)
        lineModel = new LineChartModel();
    else
        lineModel = new LineChartModel(new LineChartTableModel(this, data));

    tableModel->setModel(lineModel->getTableModel());
    //lineModel->getTableModel()->setParent(tableModel);           in teoria non serve
    lt->addWidget(tableModel);

    tableModel->show();
    chartview = new QChartView(lineModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(aggiungiriga);
    lt->addWidget(aggiungilinea);
    lt->addWidget(togliLinea);
    lt->addWidget(togliPunto);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(lt);
    lineModel->getTableModel()->setHeaderData(0, Qt::Horizontal, "Stock ID", Qt::DisplayRole);
    connect(nullptr,&MainWindow::salvaConNomeSignal,this,&LineChartWidget::salvaJsonFile);
    connect(lineModel->getTableModel(),&ChartTableModel::dataChanged,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::rowsInserted,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::rowsRemoved,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::columnsInserted,lineModel,&ChartModel::updateAxisY);
    connect(lineModel->getTableModel(),&ChartTableModel::columnsRemoved,lineModel,&ChartModel::updateAxisY);
}

void LineChartWidget::aggiungilineaslot(){

    bool ok = lineModel->getTableModel()->insertColumns(lineModel->getTableModel()->columnCount(),1);
    if(ok){
        lineModel->updateInsertColumn();
        lineModel->updateAxisY();
    }
}

void LineChartWidget::aggiungipunto(){
    lineModel->getTableModel()->insertRows(lineModel->getTableModel()->rowCount(),1);
}

void LineChartWidget::togliLineaSlot(){
    bool ok;
    int linea;
    if(lineModel->getTableModel()->columnCount()-1 > 1){
        linea=QInputDialog::getInt(this, tr("Linea"),tr("Linea:"),1,1,lineModel->getTableModel()->columnCount()-1,1, &ok);
        if(ok) {
            lineModel->getTableModel()->removeColumns(linea, 1);
            lineModel->updateRemoveColumn(linea-1);
        }
    }
}

void LineChartWidget::togliPuntoSlot(){
            bool ok;
            int row;
            if(lineModel->getTableModel()->rowCount()>1){
                row=QInputDialog::getInt(this, tr("Punti"),tr("Punti"),1,1,lineModel->getTableModel()->rowCount(),1, &ok);
                if (ok){
                    lineModel->getTableModel()->removeRows(row-1,1);
                }
            }
}

void LineChartWidget::salvaJsonFile(){
    lineModel->salvaJson();
}
