#ifndef CANDLESTICKCHARTMODEL_H
#define CANDLESTICKCHARTMODEL_H

#include <QObject>
#include<QtCharts>
#include<model/candlestickcharttablemodel.h>

class CandleStickChartModel:public QObject
{
public:
    CandleStickChartModel(CandleStickChartTableModel *data);
    QChart* chart;
    int setsCount();
    void updateMapper();

private:

    QCandlestickSeries* candleSeries;
    QColor increasingColor;
    QColor decreasingColor;
    QVector<QCandlestickSet*> candleSets;
    QBarCategoryAxis* axisX;
    QValueAxis* axisY;
    QHCandlestickModelMapper* mapper;
    QStringList categories;
    qreal getMax();
    qreal getMin();
public slots:
    void updateAxis();


};

#endif // CANDLESTICKCHARTMODEL_H
