#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H

#include <comparisonChartData.h>
#include <QtCharts>
#include<QVector>
#include<QLineSeries>
#include<QAreaSeries>

class AreaChartData : public comparisonChartData {
public:
    AreaChartData();
    void pushPoint(int rowCount, int columnCount);   /*potrebbe overridare pushSets()*/
};

#endif // AREACHARTDATA_H
