#include "piechartwidget.h"

piechartwidget::piechartwidget(QWidget *parent, const char *name):QWidget(parent)
{
    lt=new QGridLayout(this);
    pietable=new QTableView;
    pietablemodel=new Piecharttablemodel();
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
    pietable->show();
    chartview=new QChartView(piemodel->chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    QPushButton* ingrandisci=new QPushButton;
    ingrandisci->setIcon(QIcon(":/icone/ingrandisci"));
    lt->addWidget(ingrandisci);
    setLayout(lt);
}
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
    pietable->show();
    chartview=new QChartView(piemodel->chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(1280,480);
    lt->addWidget(chartview);
    lt->setSizeConstraint(QLayout::SetFixedSize);
    QPushButton* ingrandisci=new QPushButton;
    ingrandisci->setIcon(QIcon(":/icone/ingrandisci"));
    lt->addWidget(ingrandisci);
    setLayout(lt);
}
void piechartwidget::aggiungifettaslot(){
    std::string etichetta;
    int valore;
    bool ok;
    QStringList list = inputdialog::getStrings(this, &ok);
    if (ok) {
        etichetta=list.at(0).toStdString();
        valore=list.at(1).toInt();
        pietablemodel->insertRows(pietablemodel->rowCount(),1,etichetta,valore);
        piemodel->connectInsertedSlice();
    }
}

void piechartwidget::rimuovifettaslot(){
    bool ok;
    int fetta=QInputDialog::getInt(this,tr("ELIMINA FETTA"),tr("Fetta:"),QLineEdit::Normal,1,piemodel->sliceCount(),1,&ok);
    pietablemodel->removeRow(fetta);
}
