#include "linechartmodel.h"

LineChartModel::LineChartModel(LineChartTableModel * data)
{
    chart=new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
    series.push_back(new QLineSeries);
    nLines=1;
    mapper.push_back(new QVXYModelMapper());
    mapper[0]->setXColumn(0);
    mapper[0]->setYColumn(1);
    mapper[0]->setSeries(series[0]);
    mapper[0]->setModel(data);
    chart->addSeries(series[0]);
    chart->createDefaultAxes();
    chart->setTitle("line chart");

}

void LineChartModel::updateMapper(LineChartTableModel * data){
    int temp=nLines++;
    series.push_back(new QLineSeries);
    mapper.push_back(new QVXYModelMapper());
    mapper[temp]->setXColumn(2*temp);
    mapper[temp]->setYColumn(2*temp+1);
    mapper[temp]->setSeries(series[temp]);
    mapper[temp]->setModel(data);
    chart->addSeries(series[temp]);
}

void LineChartModel::updateAxises(){
    chart->createDefaultAxes();
}

void LineChartModel::axises(int maxValue){
    this->updateAxises();
    chart->axisY()->setRange(0,maxValue);

}
