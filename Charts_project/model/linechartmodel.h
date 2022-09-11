#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "chartModel.h"
#include<vector>
#include<string>
#include<model/linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<data/linechartdata.h>
class LineChartModel:public ChartModel
{

public:
    LineChartModel(LineChartTableModel *data);

    void updateInsertColumn() override;
    void updateRemoveColumn(int pos) override;
private:

    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;
    int getMax();
    int getMin();
public slots:
    void updateAxisY();
    void salvaJson() override;
private slots:
    void cambiaNome();
};

#endif // LINECHARTMODEL_H
