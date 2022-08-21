#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H
#include <QtCharts>
#include<QVector>
#include<QLineSeries>
#include<QAreaSeries>
class AreaChartData
{
public:
    AreaChartData();
    QVector<QVector<int>> getLines() const;
    QString getTitle() const;
    void pushLine(int pos,int coordinate);
    void setData(int x,int y,int value);
    void pushPoint(int count);
private:
    QVector<QVector<int>> lines;
    QString title;
};

#endif // AREACHARTDATA_H
