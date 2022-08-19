#include "areachartmodel.h"
#include"stdio.h"
AreaChartModel::AreaChartModel(AreaChartTableModel* data)
{
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    linesmappers.push_back(new QVXYModelMapper);
    nLines=1;
    linesmappers[0]->setXColumn(0);
    linesmappers[0]->setYColumn(1);
    linesmappers[0]->setFirstRow(0);
    linesmappers[0]->setModel(data);
    series.push_back(new QLineSeries);
    linesmappers[0]->setSeries(series[0]);
    areaSeries.push_back(new QAreaSeries(series.at(0)));
    chart->addSeries(areaSeries.at(0));
    chart->createDefaultAxes();
    chart->setTitle(data->dati.getTitle());
}

void AreaChartModel::updateMappers(AreaChartTableModel* data)
{
    int temp=nLines++;
    series.push_back(new QLineSeries);
    linesmappers.push_back(new QVXYModelMapper);
    linesmappers[temp]->setXColumn(2*temp);
    linesmappers[temp]->setYColumn(2*temp+1);
    linesmappers[temp]->setFirstRow(0);
    linesmappers[temp]->setModel(data);
    linesmappers[temp]->setSeries(series[temp]);
    areaSeries.push_back(new QAreaSeries(series.at(temp),series.at(temp-1)));
    chart->addSeries(areaSeries.at(temp));
    chart->createDefaultAxes();

}
