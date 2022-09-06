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
    QVector<QString> nomeLinea;
    QString title;
    int maxValue;
    int minValue;
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
    int getMinValue()const;
    QString getLineName(int i) const;
    void setTitle(QString t);
    void setData(int x, int y, int value);
    void pushPoint(int count);
    void pushLine(int pos,int coordinate);
    void setMaxValue(int max);
    void setMinValue(int min);
    void addY(int y);
    void removeY(int x,int y);
    void addLineName(QString l);
    void removeLineName(int l);
    void removeLine(int column);
    void removePoints(int row);
};

#endif // LINECHARTDATA_H
