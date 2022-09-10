#ifndef PIECHARTMODEL_H
#define PIECHARTMODEL_H

#include "chartModel.h"
#include<vector>
#include<string>
#include<QtCharts>
#include<QString>
#include<QHPieModelMapper>
#include<model/piecharttablemodel.h>

class piechartmodel : public ChartModel {
private:
    QPieSeries* pieSeries;
    QString title;
    QVPieModelMapper* piemapper;
public:
    piechartmodel(Piecharttablemodel* data);

    void updateInsertRow() override;
public slots:
    void explodeSplice(bool state);
    void changeSlice();
    void salvaJson() override;
};

#endif // PIECHARTMODEL_H
