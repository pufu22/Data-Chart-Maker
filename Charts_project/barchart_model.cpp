#include "barchart_model.h"
#include <bar_data.h>
#include<QStringList>
#include<QString>
#include<iostream>
#include<string>
#include<QVBarModelMapper>
BarChartModel::BarChartModel(BarChartTableModel *data)
{
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

    for(auto it=data->dati.categories.begin();it!=data->dati.categories.end();++it){
        QString qstr = QString::fromStdString(*it);
        categories<<qstr;

    }
    axisX=new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY= new QValueAxis();
    int w=data->dati.range[0];
    int x=data->dati.range[1];
    axisY->setRange(w,x);
    title=QString::fromStdString(data->dati.title);
    chart->setTitle(title);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
};


void BarChartModel::updateMapperLastColumn()
{
    mapper->setLastBarSetColumn(++lastcolumn);
}
void BarChartModel::updateMapperLastRow()
{
    mapper->setRowCount(++lastrow);
    categories<<QString(lastrow);
    axisX->append(categories);
}

void BarChartModel::salvaJsonBar(){
    QJsonObject mainObject;
    mainObject.insert(QString::fromStdString("title"),title);
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("barchart"));

}
