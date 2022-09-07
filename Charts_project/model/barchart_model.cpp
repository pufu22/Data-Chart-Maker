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

    for(int i=0;i<data->dati->getCategories().size();++i){
        QString qstr = data->dati->getCategories().at(i);

        categories<<qstr;

    }

    axisX=new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);
    axisY= new QValueAxis();
    int w=data->dati->getYAxisMinValue();
    int x=data->dati->getYAxisMaxValue();
    axisY->setRange(w,x);
    title=data->dati->getTitle();
    chart->setTitle(title);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series->setLabelsVisible(true);

}

void BarChartModel::updateMapperLastColumn()
{
    mapper->setLastBarSetColumn(++lastcolumn);
}
void BarChartModel::updateMapperLastRow(BarChartTableModel *data)
{

    mapper->setRowCount(++lastrow);
    categories<<data->dati->getCategories()[lastrow-1];
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
    mainObject.insert(QString::fromStdString("title"),title);
    mainObject.insert(QString::fromStdString("Type"),QString::fromStdString("barchart"));

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

