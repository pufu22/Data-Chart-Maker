#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include<vector>
#include<string>
#include<model/linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<linechartdata.h>
class LineChartModel:public QObject
{

public:
    LineChartModel(LineChartTableModel *data);
    QChart *chart;
    void updateMapper(LineChartTableModel *data);
    void addLinea(LineChartTableModel *data,QString l);
    void salvaJsonFile();
protected:
    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;

public slots:
    void updateAxises();
    void axises(int maxValue);
    void updateAxisY(int min,int max);
};

#endif // LINECHARTMODEL_H
