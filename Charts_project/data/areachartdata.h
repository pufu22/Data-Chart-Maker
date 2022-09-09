#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H

#include <data/comparisonChartData.h>
#include <QtCharts>
#include<QVector>
#include<QLineSeries>
#include<QAreaSeries>

class AreaChartData : public comparisonChartData {
public:
    AreaChartData();

    void pushData(int count) override;
};

#endif // AREACHARTDATA_H
