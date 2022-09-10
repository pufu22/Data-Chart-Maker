#ifndef LINECHARTDATA_H
#define LINECHARTDATA_H

#include <data/comparisonChartData.h>
#include<vector>
#include<QPointF>
#include<string>
#include <QtCharts>
#include<QVector>

class LineChartData : public comparisonChartData {
public:
    LineChartData();
    LineChartData(QVector<QVector<qreal>> series,QString title);

    void removeGroup(int pos) override;
    void pushData(int count);

};

#endif // LINECHARTDATA_H
