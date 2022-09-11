#ifndef CANDLESTICKCHARTMODEL_H
#define CANDLESTICKCHARTMODEL_H

#include "chartModel.h"
#include <QObject>
#include<QtCharts>
#include<model/candlestickcharttablemodel.h>

class CandleStickChartModel:public ChartModel
{
public:
    CandleStickChartModel(CandleStickChartTableModel *data);

    void updateInsertRow() override;
    void updateRemoveRow(int pos) override;
private:
    QCandlestickSeries* candleSeries;
    QColor increasingColor;
    QColor decreasingColor;
    QBarCategoryAxis* axisX;
    QValueAxis* axisY;
    QHCandlestickModelMapper* mapper;
    QStringList categories;
    qreal getMax();
    qreal getMin();
public slots:
    void updateAxisY() override;
    void salvaJson() override;


};

#endif // CANDLESTICKCHARTMODEL_H
