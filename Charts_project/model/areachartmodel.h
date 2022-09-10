#ifndef AREACHARTMODEL_H
#define AREACHARTMODEL_H

#include "chartModel.h"
#include <QChart>
#include <QVXYModelMapper>
#include <data/areachartdata.h>
#include <model/areacharttablemodel.h>

class AreaChartModel : public ChartModel {
private:
    QVector<QVXYModelMapper*> linesmappers;
    QVector <QLineSeries*> series;
    QVector <QAreaSeries*> areaSeries;

    int getMin();
    int getMax();
public:
    AreaChartModel(AreaChartTableModel* data);

    void updateInsertColumn() override;
    void updateRemoveColumn(int pos) override;
private slots:
    void cambiaNome();
public slots:
    void updateAxisY() override;
    void salvaJson() override;
};

#endif // AREACHARTMODEL_H
