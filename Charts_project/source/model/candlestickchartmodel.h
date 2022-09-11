#ifndef CANDLESTICKCHARTMODEL_H
#define CANDLESTICKCHARTMODEL_H

#include "chartModel.h"
#include "candlestickcharttablemodel.h"

class CandleStickChartModel : public ChartModel {
private:
    QCandlestickSeries* candleSeries;
    QVector<QCandlestickSet*> candleSets;
    QBarCategoryAxis* axisX;
    QValueAxis* axisY;
    QHCandlestickModelMapper* mapper;
    QStringList categories;
    QColor increasingColor;
    QColor decreasingColor;

    qreal getMax();
    qreal getMin();
public:
    CandleStickChartModel(CandleStickChartTableModel *data = new CandleStickChartTableModel());

    void updateInsertRow() override;
    void updateRemoveRow(int pos) override;
public slots:
    void updateAxisY() override;
    void salvaJson() override;
};

#endif // CANDLESTICKCHARTMODEL_H

