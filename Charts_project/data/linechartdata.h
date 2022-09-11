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
    LineChartData(QVector<QVector<qreal>> series,QString title,QVector<QString>names);

    void pushData(int count);       /*metodo simile a pushSets()*/
    void removeGroup(int pos) override;
};

#endif // LINECHARTDATA_H
