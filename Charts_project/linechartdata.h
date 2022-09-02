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
    int maxValue;
    int minValue;
    int secondMaxValue;
    int secondMinValue;
    QVector<int> sortedYValues;
public:
    LineChartData();
    LineChartData(QVector<QVector<int>> series,QString title);
    friend class LineChartTableModel;
    friend class LineChartModel;
    LineChartData& operator =(const LineChartData& other);
    QVector<QVector<int>> getLines() const;
    QString getTitle() const;
    int getMaxValue()const;
    int getsecondMaxValue()const;
    int getMinValue()const;
    int getsecondMinValue() const;
    void setTitle(QString t);
    void setData(int x, int y, int value);
    void pushPoint(int count);
    void pushLine(int pos,int coordinate);
    void setMaxValue(int max);
    void setMinValue(int min);
    void setSecondMaxValue(int smax);
    void setSecondMinValue(int smin);
    void addY(int y);
    void removeY(int x,int y);
};

#endif // LINECHARTDATA_H
