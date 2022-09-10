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
    AreaChartData(QVector<QVector<int>> lines,QString title,QVector<QString>areanames);
    void pushPoint(int rowCount, int columnCount);   /*potrebbe overridare pushSets()*/
    void removeAreaName(int l);
    void addAreaName(QString l);
    QString getAreaName(int i)const;
    void removeColumn(int column);
};

#endif // AREACHARTDATA_H
