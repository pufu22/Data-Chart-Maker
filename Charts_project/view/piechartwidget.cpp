#include "piechartwidget.h"


piechartwidget::piechartwidget(QWidget *parent, const char *name,pie_data* d){
    lt=new QGridLayout(this);
    pietable=new QTableView;
    if(d==nullptr)
        pietablemodel=new Piecharttablemodel();
        else
        pietablemodel=new Piecharttablemodel(d);
    piemodel=new piechartmodel(pietablemodel);

    pietable->setModel(pietablemodel);
    pietablemodel->setParent(pietable);
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
    //ingrandisci->setIcon(QIcon(":/icone/ingrandisci"));
    connect(ingrandisci,&QPushButton::released,this,&piechartwidget::chartFocus);
    lt->addWidget(ingrandisci);
    chartview=new QChartView(piemodel->getChart());
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(lt);
}
void piechartwidget::aggiungifettaslot(){

        bool ok;
        ok=pietablemodel->insertRows(pietablemodel->rowCount(),1);
        if(ok)
            piemodel->connectInsertedSlice();
}

piechartwidget::~piechartwidget(){
delete(piemodel);
}
void piechartwidget::rimuovifettaslot(){
    bool ok;
    if(piemodel->sliceCount()>1){
        int fetta=QInputDialog::getInt(this,tr("ELIMINA FETTA"),tr("Fetta:"),QLineEdit::Normal,1,piemodel->sliceCount(),1,&ok);
        if(ok)
            pietablemodel->removeRows(fetta-1,1);
    }
}

void piechartwidget::cambiaTitoloSlot(){
    bool ok;
    QString titolo=QInputDialog::getText(this,tr("Titolo"),tr("Titolo:"),QLineEdit::Normal,tr(""),&ok);
    if(ok && titolo.trimmed()!=""){
        piemodel->changeTitle(pietablemodel,titolo);
    }

}

void piechartwidget::salvaJsonPie(){
    piemodel->salvaJsonPie();
}

void piechartwidget::chartFocus(){
    ingrandisci->blockSignals(true);
    lt->removeWidget(chartview);
    PopupChart::chartFocus(chartview,this);
    ingrandisci->blockSignals(false);
    lt->addWidget(chartview);
}

