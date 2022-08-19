#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include<vector>
#include<string>
#include<linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<linechartdata.h>
class LineChartModel:public QObject
{

public:
    LineChartModel(LineChartTableModel *data);
    QChart *chart;
    void updateMapper(LineChartTableModel *data);
    void updateAxises();
    void salvaJsonFile();
protected:
    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;
public slots:
    void axises(int maxValue);
};

#endif // LINECHARTMODEL_H
