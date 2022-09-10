#ifndef CANDLESTICKCHARTMODEL_H
#define CANDLESTICKCHARTMODEL_H

#include <QObject>
#include<QtCharts>
#include<model/candlestickcharttablemodel.h>

class CandleStickChartModel:public QObject
{
public:
    CandleStickChartModel(CandleStickChartTableModel *data);

    int setsCount();
    void updateMapper();
    QChart* getChart();
private:
    CandleStickChartTableModel* dati;
    QChart* chart;
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
    void updateRemoved(int row);
    void salvaJson();
    void cambiaTitolo(CandleStickChartTableModel* data,QString t);


};

#endif // CANDLESTICKCHARTMODEL_H
