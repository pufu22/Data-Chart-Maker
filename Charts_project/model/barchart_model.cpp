#include "barchart_model.h"
#include <data/bar_data.h>
#include<QStringList>
#include<QString>
#include<iostream>
#include<string>
#include<QVBarModelMapper>
BarChartModel::BarChartModel(BarChartTableModel *data)
{
    dati=data;
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    series=new QBarSeries;
    mapper=new QVBarModelMapper();

    mapper->setFirstBarSetColumn(0);
    lastcolumn=data->columnCount();
    mapper->setLastBarSetColumn(lastcolumn);
    lastrow=data->rowCount();
    mapper->setFirstRow(0);
    mapper->setRowCount(lastrow);
    mapper->setSeries(series);
    mapper->setModel(data);
    chart->addSeries(series);

    for(int i=0;i<data->rowCount();++i){

        QString qstr = data->headerData(i,Qt::Vertical,Qt::DisplayRole).toString();
        categories<<qstr;

    }

    axisX=new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY= new QValueAxis();
    axisY->setRange(getMin(),getMax());
    title=data->dati->getTitle();
    chart->setTitle(title);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setLabelsVisible(true);
    connect(series,&QBarSeries::doubleClicked,this,&BarChartModel::cambiaNome);
}

void BarChartModel::updateMapperLastColumn()
{
    mapper->setLastBarSetColumn(++lastcolumn);
}
void BarChartModel::updateMapperLastRow(BarChartTableModel *data)
{

    mapper->setRowCount(++lastrow);
    categories<<data->headerData(lastrow-1,Qt::Vertical,Qt::DisplayRole).toString();
    axisX->append(categories);

}

void BarChartModel::updateMapperRemoveColumn(){
    mapper->setLastBarSetColumn(--lastcolumn);
}

void BarChartModel::updateMapperRemoveRow(int pos){
    mapper->setRowCount(--lastrow);
    categories.removeAt(pos);
    axisX->clear();
    axisX->append(categories);
}

void BarChartModel::salvaJsonBar(){
    QJsonObject mainObject;
    QJsonObject secondaryObject;
    mainObject.insert(QString::fromStdString("title"),chart->title());
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("barchart"));
    QJsonArray c;
    QJsonArray v;
    QList<QBarSet*>temp=series->barSets();
    for(int j=0;j<temp.at(0)->count();++j)
    {
        for(int i=0;i<temp.count();++i)
        {
            if(j>0)
                c.pop_front();
            else
                v.append(temp.at(i)->label());
            c.append(temp.at(i)->at(j));
        }
        secondaryObject.insert(categories.at(j),c);

    }



    mainObject.insert(QString::fromStdString("bars"),secondaryObject);
    mainObject.insert(QString::fromStdString("names"),v);

    QJsonDocument document;
    document.setObject( mainObject );
    bool ok;
    QString nomeFile=QInputDialog::getText(nullptr,tr("Salva con nome:"),tr("Nome file:"),QLineEdit::Normal,QDir::home().dirName(),&ok);

    QFile file( "../Charts_project/graficisalvati/"+nomeFile+".json");
    if(file.open( QIODevice::WriteOnly))
    {
        file.write(document.toJson());
               //return false;
    }
    else
            qWarning("Couldn't open save file.");
}

void BarChartModel::updateAxisY(){
    axisY->setRange(getMin(),getMax()+1);
}

void BarChartModel::changeTitle(BarChartTableModel *data,QString t){
    data->dati->setTitle(t);
    chart->setTitle(data->dati->getTitle());
}

QChart* BarChartModel::getChart(){
    return chart;
}
int BarChartModel::getMax(){
    int max=series->barSets().at(0)->at(0);
for(int i=0;i<series->barSets().size();++i)
    for(int j=0;j<series->barSets().at(i)->count();++j){
        qreal t=series->barSets().at(i)->at(j);
        if(t>max)
            max=t;
    }
    return max;
}

int BarChartModel::getMin(){
    int min=0;
    for(int i=0;i<series->barSets().size();++i)
        for(int j=0;j<series->barSets().at(i)->count();++j){
            qreal t=series->barSets().at(i)->at(j);
            if(t<min)
                min=t;
        }
        return min;
}

void BarChartModel::cambiaNome(int index,QBarSet *barset){
    QStringList name;
    name<<"Bar name";
    name<<"Set name";
    bool ok;
    QString scelta=QInputDialog::getItem(nullptr, tr("QInputDialog::getItem()"),
                                         tr("Scegli:"), name, 0, false, &ok);
    if(ok && !scelta.isEmpty())
        if(scelta.compare("Bar name")==0)
        for(int i=0;i<series->barSets().count();++i){
        QBarSet* barSet=series->barSets().at(i);
        if(barset==barSet){
            bool ok2;
            QString nome=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok2);
            if(ok2 && nome.trimmed()!=""){
                dati->setHeaderData(i,Qt::Horizontal,nome,Qt::EditRole);
            }
            chart->legend()->update();
        }
        }
        else{
            bool ok3;
            QString nomeset=QInputDialog::getText(nullptr,tr("Nome"),tr("Nome:"),QLineEdit::Normal,tr(""),&ok3);
            if(ok3 && nomeset.trimmed()!="")
                dati->setHeaderData(index,Qt::Vertical,nomeset,Qt::EditRole);
                categories.replace(index,nomeset);
                axisX->replace(axisX->at(index),nomeset);
        }


}
