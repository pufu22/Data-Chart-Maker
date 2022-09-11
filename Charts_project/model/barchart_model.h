#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H

#include "chartModel.h"
#include<data/bar_data.h>
#include<model/barcharttablemodel.h>
#include<qbarmodelmapper.h>
#include<QString>
class BarChartModel:public ChartModel
{
public:
    BarChartModel(BarChartTableModel *data);
    void updateInsertColumn() override;
    void updateInsertRow() override;
    void updateRemoveRow(int pos) override;
    void updateRemoveColumn(int pos) override;
private:
    QBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QVBarModelMapper *mapper;
    int getMax();
    int getMin();
private slots:
    void cambiaNome(int index,QtCharts::QBarSet* barset);
public slots:
    void updateAxisY() override;
    void salvaJson() override;
};

#endif // BARCHART_MODEL_H

