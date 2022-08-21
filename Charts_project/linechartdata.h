#ifndef LINECHARTDATA_H
#define LINECHARTDATA_H

#include<vector>
#include<QPointF>
#include<string>
#include <QtCharts>
#include<QVector>
class LineChartData
{
protected:
    QVector<QVector<int>> lineseries;
    QString title;
public:
    LineChartData();
    LineChartData(QVector<QVector<int>> series,QString title);
    friend class LineChartTableModel;
    friend class LineChartModel;
    LineChartData& operator =(const LineChartData& other);
    QVector<QVector<int>> getLines() const;
    QString getTitle() const;
    void setData(int x, int y, int value);
    void pushPoint(int count);
    void pushLine(int pos,int coordinate);
};

#endif // LINECHARTDATA_H
