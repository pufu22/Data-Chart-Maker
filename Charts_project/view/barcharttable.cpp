#include "barcharttable.h"

barcharttable::barcharttable(Bar_data *data, QWidget *parent, const char *name):QWidget(parent)
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
    table=new QTableView;
    if(data==nullptr)
        barmodel=new BarChartTableModel();
    else
        barmodel=new BarChartTableModel(data);
    changeTitle=new QPushButton("&Cambia Titolo");
    connect(changeTitle,&QPushButton::released,this,&barcharttable::changetitle);

    m_model=new BarChartModel(barmodel);

    table->setModel(barmodel);
    barmodel->setParent(table);
    lt->addWidget(table);
    table->show();

    chartView = new QChartView(m_model->getChart());
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(1280, 480);
    QPushButton* ingrandisci=new QPushButton("&Ingrandisci");
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
    connect(barmodel,&BarChartTableModel::dataChanged,m_model,&BarChartModel::updateAxisY);
    connect(barmodel,&BarChartTableModel::columnsRemoved,m_model,&BarChartModel::updateAxisY);
    connect(barmodel,&BarChartTableModel::rowsRemoved,m_model,&BarChartModel::updateAxisY);

    connect(this,&barcharttable::riga,this,&barcharttable::adjustChart);
}

void barcharttable::setupModels(){
    //barchartmodel=new BarChartModel();
    barmodel=new BarChartTableModel();
    //barmodel->newData();
}

void barcharttable::aggiungiriga(){
    bool ok;
        ok=barmodel->insertRows(barmodel->rowCount(),1);
        if(ok)
            m_model->updateMapperLastRow(barmodel);

}

void barcharttable::aggiungicolonna(){
            bool ok;
            ok=barmodel->insertColumns(barmodel->columnCount(),1);
            if(ok)
            m_model->updateMapperLastColumn();

}

void barcharttable::removebars(){

    bool ok;
    int item;
    if(barmodel->columnCount()>1)
        item = QInputDialog::getInt(this, tr("Barre"),tr("Barra:"),1,1,barmodel->columnCount(),1, &ok);
        if (ok){
            barmodel->removeColumn(item-1);
            m_model->updateMapperRemoveColumn();
        }

}

void barcharttable::removeset(){
    bool ok;
    int item;
    if(barmodel->rowCount()>1)
        item = QInputDialog::getInt(this, tr("Barre"),tr("Barra:"),1,1,barmodel->rowCount(),1, &ok);
    if(ok){
        barmodel->removeRow(item-1);
        m_model->updateMapperRemoveRow(item-1);
    }

}

void barcharttable::salvaJsonBar(){
    m_model->salvaJsonBar();
}

void barcharttable::changetitle(){
    bool ok;
    QString title;
    title=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok)
        m_model->changeTitle(barmodel,title);
    chartView->resize(1280,480);
}
void barcharttable::chartFocus(){
PopupChart::chartFocus(chartView,this);
lt->addWidget(chartView);
emit riga();
}

void barcharttable::adjustChart(){
    chartView->resize(1280,480);
    //chartView->updatesEnabled();
    //chartView->updateGeometry();
}
