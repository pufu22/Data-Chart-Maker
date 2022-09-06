#ifndef AREACHARTMODEL_H
#define AREACHARTMODEL_H
#include<QChart>
#include<QVXYModelMapper>
#include<areachartdata.h>
#include<model/areacharttablemodel.h>
class AreaChartModel
{
public:
    AreaChartModel(AreaChartTableModel* data);
    QChart* getChart();
    void updateMappers(AreaChartTableModel* data);
private:
    QChart *chart;
    QVector<QVXYModelMapper*> linesmappers;
    QVector <QLineSeries*> series;
    QVector <QAreaSeries*> areaSeries;
    int nLines;
};

#endif // AREACHARTMODEL_H
