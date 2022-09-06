#include "piechartwidget.h"


piechartwidget::piechartwidget(QWidget *parent, const char *name,pie_data* d){
    lt=new QGridLayout(this);
    pietable=new QTableView;
    if(d==nullptr)
        pietablemodel=new Piecharttablemodel();
        else
        pietablemodel=new Piecharttablemodel(this,d);
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
    chartview=new QChartView(piemodel->chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(lt);
    connect(nullptr,&MainWindow::salvaConNomeSignal,this,&piechartwidget::salvaJsonPie);
}
void piechartwidget::aggiungifettaslot(){
    QString etichetta;
    int valore;
    bool ok;
    QStringList list = inputdialog::getStrings(this, "piechart",&ok);
    if (ok) {
        etichetta=list.at(0);
        valore=list.at(1).toInt();
        pietablemodel->insertRows(pietablemodel->rowCount(),1,etichetta,valore);
        piemodel->connectInsertedSlice();
    }
}

void piechartwidget::rimuovifettaslot(){
    bool ok;
    if(piemodel->sliceCount()>1){
        int fetta=QInputDialog::getInt(this,tr("ELIMINA FETTA"),tr("Fetta:"),QLineEdit::Normal,1,piemodel->sliceCount(),1,&ok);
        if(ok)
            pietablemodel->removeRow(fetta);
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

