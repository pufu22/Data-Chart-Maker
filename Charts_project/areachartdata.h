#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H
#include <comparisonChartData.h>
#include <QtCharts>
#include<QVector>
#include<QLineSeries>
#include<QAreaSeries>
class AreaChartData : public comparisonChartData
{
public:
    AreaChartData();
    /*QVector<QVector<int>> getLines() const;
    QString getTitle() const;*/
    //void pushLine(int pos,int coordinate);
    //void setData(int x,int y,int value);
    void pushPoint(int rowCount, int columnCount);   /*potrebbe overridare pushSets()*/
private:
    /*QVector<QVector<int>> lines;
    QString title;*/
};

#endif // AREACHARTDATA_H
