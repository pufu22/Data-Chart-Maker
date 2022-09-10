#ifndef LINECHARTDATA_H
#define LINECHARTDATA_H

#include <comparisonChartData.h>
#include<vector>
#include<QPointF>
#include<string>
#include <QtCharts>
#include<QVector>
class LineChartData : public comparisonChartData {
protected:
    QVector<int> sortedYValues;
public:
    LineChartData();
    LineChartData(QVector<QVector<int>> series,QString title,QVector<QString>names);
    LineChartData& operator =(const LineChartData& other);
    QString getLineName(int i) const;    /*potrebbe essere un override di getNames(), forse*/
    void pushPoint(int rowCount, int columnCount);       /*metodo simile a pushSets()*/
    void addY(int y);
    void removeY(int x,int y);
    void removeLineName(int l);
    void addLineName(QString l);
    void removeColumn(int column);
};

#endif // LINECHARTDATA_H
