#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include<vector>
#include<string>
#include<model/linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<data/linechartdata.h>
class LineChartModel:public QObject
{

public:
    QChart* getChart();
    LineChartModel(LineChartTableModel *data);

    void updateMapper(LineChartTableModel *data);
    void addLinea(LineChartTableModel *data,QString l);
    void salvaJsonFile();
private:
    QChart *chart;
    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;
    int getMax();
    int getMin();
public slots:
    void updateAxises();
    void axises(int maxValue);
    void updateAxisY();
};

#endif // LINECHARTMODEL_H
