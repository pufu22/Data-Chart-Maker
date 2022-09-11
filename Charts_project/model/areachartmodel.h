#ifndef AREACHARTMODEL_H
#define AREACHARTMODEL_H
#include "chartModel.h"
#include<QChart>
#include<QVXYModelMapper>
#include<data/areachartdata.h>
#include<model/areacharttablemodel.h>
class AreaChartModel:public ChartModel
{
public:
    AreaChartModel(AreaChartTableModel* data);
    void updateInsertColumn() override;
    void updateRemoveColumn(int pos) override;

public slots:
    void updateAxisY();
    void salvaJson();
    void changeTitle(QString title);
private slots:
    void cambiaNome();
private:
    QVector<QVXYModelMapper*> linesmappers;
    QVector <QLineSeries*> series;
    QVector <QAreaSeries*> areaSeries;
    int getMin();
    int getMax();

};

#endif // AREACHARTMODEL_H
