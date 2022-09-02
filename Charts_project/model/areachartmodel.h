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
    QChart *chart;
    void updateMappers(AreaChartTableModel* data);
private:
    QVector<QVXYModelMapper*> linesmappers;
    QVector <QLineSeries*> series;
    QVector <QAreaSeries*> areaSeries;
    int nLines;
};

#endif // AREACHARTMODEL_H
