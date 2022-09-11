#include "barcharttable.h"

barcharttable::barcharttable(Bar_data *data, QWidget *parent) : QWidget(parent)
{
    lt=new QGridLayout(this);

    aggiungi_riga=new QPushButton("&Aggiungi riga");
    connect(aggiungi_riga,&QPushButton::released,this,&barcharttable::aggiungiriga);
    aggiungi_colonna=new QPushButton("&Aggiungi colonna");
    connect(aggiungi_colonna,&QPushButton::released,this,&barcharttable::aggiungicolonna);

    removeBars=new QPushButton("&Rimuovi barre");
    connect(removeBars,&QPushButton::released,this,&barcharttable::removebars);
    removeSet=new QPushButton("&Rimuovi set di barre");
    connect(removeSet,&QPushButton::released,this,&barcharttable::removeset);
    barTable = new QTableView;
    if(data==nullptr)
        barModel = new BarChartModel();
    else
        barModel = new BarChartModel(new BarChartTableModel(this, data));
    changeTitle=new QPushButton("&Cambia Titolo");
    connect(changeTitle,&QPushButton::released,this,&barcharttable::changetitle);

    barTable->setModel(barModel->getTableModel());
    barModel->getTableModel()->setParent(barTable);
    lt->addWidget(barTable);
    barTable->show();

    chartView = new QChartView(barModel->getChart());
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1280, 480);

    ingrandisci=new QPushButton("&Ingrandisci");
    connect(ingrandisci,&QPushButton::released,this,&barcharttable::chartFocus);
    lt->addWidget(aggiungi_riga);
    lt->addWidget(aggiungi_colonna);
    lt->addWidget(removeBars);
    lt->addWidget(removeSet);
    lt->addWidget(changeTitle);
    lt->addWidget(ingrandisci);
    lt->addWidget(chartView);
    lt->setSizeConstraint(QLayout::SetMinimumSize);
    setLayout(lt);
    connect(barModel->getTableModel(),&ChartTableModel::dataChanged,barModel,&ChartModel::updateAxisY);
    connect(barModel->getTableModel(),&ChartTableModel::columnsRemoved,barModel,&ChartModel::updateAxisY);
    connect(barModel->getTableModel(),&ChartTableModel::rowsRemoved,barModel,&ChartModel::updateAxisY);
}

void barcharttable::aggiungiriga(){
    bool ok = barModel->getTableModel()->insertRows(barModel->getTableModel()->rowCount(),1);
    if(ok){
        barModel->updateInsertRow();
    }

}

void barcharttable::aggiungicolonna(){
        bool ok = barModel->getTableModel()->insertColumns(barModel->getTableModel()->columnCount(),1);
        if(ok){
            barModel->updateInsertColumn();
        }
}

void barcharttable::removebars(){
    bool ok = false;
    int item;
    if(barModel->getTableModel()->columnCount()>1)
        item = QInputDialog::getInt(this, tr("Barre"),tr("Barra:"),1,1,barModel->getTableModel()->columnCount(),1, &ok);
    if (ok){
        barModel->getTableModel()->removeColumn(item-1);
        barModel->updateRemoveColumn(barModel->getTableModel()->columnCount());
    }
}

void barcharttable::removeset(){
    bool ok = false;
    int item;
    if(barModel->getTableModel()->rowCount()>1)
        item = QInputDialog::getInt(this, tr("Barre"),tr("Barra:"),1,1,barModel->getTableModel()->rowCount(),1, &ok);
    if(ok){
        barModel->getTableModel()->removeRow(item-1);
        barModel->updateRemoveRow(item-1);
    }

}

void barcharttable::salvaJsonBar(){
    barModel->salvaJson();
}

void barcharttable::changetitle(){
    bool ok;
    QString title;
    title=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok)
        barModel->updateTitle(title);
}

void barcharttable::chartFocus(){
    PopupChart::chartFocus(chartView,this);
    lt->addWidget(chartView);
}
