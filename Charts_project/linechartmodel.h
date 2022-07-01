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
protected:
    int nLines;
    std::vector<QLineSeries*> series;
    std::string title;
    std::vector<QVXYModelMapper*> mapper;
public slots:
    void axises(int maxValue);
};

#endif // LINECHARTMODEL_H
