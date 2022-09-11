#include "piechartwidget.h"

piechartwidget::piechartwidget(QWidget *parent, const char *name, pie_data* data){
    lt = new QGridLayout(this);
    pietable = new QTableView;
    if(data==nullptr)
        pieModel = new piechartmodel();
    else
        pieModel = new piechartmodel(new Piecharttablemodel(this,data));
    pietable->setModel(pieModel->getTableModel());
    pieModel->getTableModel()->setParent(pietable);
    lt->addWidget(pietable);
    aggiungifetta=new QPushButton("&Aggiungi una fetta");
    lt->addWidget(aggiungifetta);
    connect(aggiungifetta,&QPushButton::released,this,&piechartwidget::aggiungifettaslot);
    rimuovifetta=new QPushButton("&Rimuovi una fetta");
    lt->addWidget(rimuovifetta);
    connect(rimuovifetta,&QPushButton::released,this,&piechartwidget::rimuovifettaslot);
    cambiaTitolo=new QPushButton("&Cambia Titolo");
    lt->addWidget(cambiaTitolo);
    connect(cambiaTitolo,&QPushButton::released,this,&piechartwidget::cambiaTitoloSlot);
    pietable->adjustSize();
    pietable->show();
    ingrandisci=new QPushButton("&Ingrandisci");
    connect(ingrandisci,&QPushButton::released,this,&piechartwidget::chartFocus);
    lt->addWidget(ingrandisci);
    chartview=new QChartView(pieModel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(lt);
}
void piechartwidget::aggiungifettaslot(){
    bool ok;
    ok = pieModel->getTableModel()->insertRows(pieModel->getTableModel()->rowCount(),1);
    if(ok)
        pieModel->updateInsertRow();
}

void piechartwidget::rimuovifettaslot(){
    bool ok;
    if(pieModel->getTableModel()->rowCount() > 1){
        int fetta=QInputDialog::getInt(this,tr("ELIMINA FETTA"),tr("Fetta:"),QLineEdit::Normal,1,pieModel->getTableModel()->rowCount(),1,&ok);
        if(ok)
            pieModel->getTableModel()->removeRow(fetta);
    }
}

void piechartwidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        pieModel->updateTitle(titolo);
    }

}

void piechartwidget::salvaJsonPie(){
    pieModel->salvaJson();
}

void piechartwidget::chartFocus(){
    ingrandisci->blockSignals(true);
    lt->removeWidget(chartview);
    PopupChart::chartFocus(chartview,this);
    ingrandisci->blockSignals(false);
    lt->addWidget(chartview);
}

