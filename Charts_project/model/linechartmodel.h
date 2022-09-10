#ifndef LINECHARTMODEL_H
#define LINECHARTMODEL_H

#include "chartModel.h"
#include<vector>
#include<string>
#include<model/linecharttablemodel.h>
#include<QtCharts>
#include<QVXYModelMapper>
#include<data/linechartdata.h>

class LineChartModel : public ChartModel {
private:
    int nLines;
    QVector<QLineSeries*> series;
    QString title;
    QVector<QVXYModelMapper*> mapper;

    int getMax();
    int getMin();
public:
    LineChartModel(LineChartTableModel *data);

    void updateInsertColumn() override;
    void updateRemoveColumn(int pos) override;
private slots:
    void cambiaNome();
public slots:
    void updateAxisY() override;
    void salvaJson() override;
};

#endif // LINECHARTMODEL_H
