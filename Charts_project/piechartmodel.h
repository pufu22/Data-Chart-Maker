#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include<vector>
#include<string>
#include<QtCharts>
#include<QString>
#include<QHPieModelMapper>
#include<piecharttablemodel.h>
class piechartmodel:public QObject
{
public:
    QChart* chart;
    piechartmodel(Piecharttablemodel* data);
protected:
    QPieSeries* pieSeries;
    QString* title;
    QVPieModelMapper* piemapper;

};

#endif // PIECHARTMODEL_H
