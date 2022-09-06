#include "candlestickchartmodel.h"
#include<iostream>
CandleStickChartModel::CandleStickChartModel(CandleStickChartTableModel* data)
{
    chart=new QChart();
    chart->setAnimationOptions(QChart::AllAnimations);
    candleSeries=new QCandlestickSeries;
    candleSeries->setIncreasingColor(QColor(Qt::green));
    candleSeries->setDecreasingColor(QColor(Qt::red));


    mapper=new QHCandlestickModelMapper;
    mapper->setFirstSetRow(0);
    mapper->setLastSetRow(2);
    mapper->setTimestampColumn(0);
    mapper->setOpenColumn(1);
    mapper->setHighColumn(2);
    mapper->setLowColumn(3);
    mapper->setCloseColumn(4);

    mapper->setModel(data);
    mapper->setSeries(candleSeries);
    for(int i=0;i<candleSeries->sets().size();++i){
        categories << QDateTime::fromMSecsSinceEpoch(candleSeries->sets().at(i)->timestamp()).toString("dd");
    }
    chart->addSeries(candleSeries);
    chart->createDefaultAxes();
    candleSeries->setName("Acme Ltd");
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(axisY->max() * 1.01);
        axisY->setMin(axisY->min() * 0.99);
    chart->setTitle("Acme Ltd Historical Data (July 2015)");
    connect(candleSeries,&QCandlestickSeries::candlestickSetsAdded,this,&CandleStickChartModel::updateAxis);
    connect(candleSeries,&QCandlestickSeries::candlestickSetsRemoved,this,&CandleStickChartModel::updateAxis);
}

int CandleStickChartModel::setsCount(){
    return candleSeries->sets().size();
}

void CandleStickChartModel::updateMapper(){
    mapper->setLastSetRow(mapper->lastSetRow()+1);
    categories<<QDateTime::fromMSecsSinceEpoch(candleSeries->sets().at(mapper->lastSetRow()-1)->timestamp()).toString("dd");
    chart->createDefaultAxes();
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
    axisY = qobject_cast<QValueAxis *>(chart->axes(Qt::Vertical).at(0));
        axisY->setMax(getMax() * 1.01);
        axisY->setMin(getMin() * 0.99);
}

void CandleStickChartModel::updateAxis(){
    chart->createDefaultAxes();
    axisX = qobject_cast<QBarCategoryAxis *>(chart->axes(Qt::Horizontal).at(0));
    axisX->setCategories(categories);
        axisY->setMax(getMax()*1.01);
        axisY->setMin(getMin()*0.99);
}

qreal CandleStickChartModel::getMax(){
    qreal max=0;
    for(int i=0;i<candleSeries->sets().size();++i){
        if(candleSeries->sets().at(i)->high()>max)
            max=candleSeries->sets().at(i)->high();
    }
    return max;
}

qreal CandleStickChartModel::getMin(){
    qreal min=10000000;
    for(int i=0;i<candleSeries->sets().size();++i){
        if(candleSeries->sets().at(i)->low()<min)
            min=candleSeries->sets().at(i)->low();
    }
    return min;
}
