#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include<vector>
#include<string>
#include<QtCharts>
#include<QString>
#include<QHPieModelMapper>
#include<model/piecharttablemodel.h>

class piechartmodel:public QObject
{
public:
    QChart* getChart();
    ~piechartmodel();
    Piecharttablemodel* dati;
    piechartmodel(Piecharttablemodel* data);
    void connectInsertedSlice();
    int sliceCount();
    void salvaJsonPie();
    void changeTitle(Piecharttablemodel *data,QString t);
protected:
    QChart* chart;
    QPieSeries* pieSeries;
    QString title;
    QVPieModelMapper* piemapper;
public slots:
    void explodeSplice(bool state);
    void changeSlice();


};

#endif // PIECHARTMODEL_H
