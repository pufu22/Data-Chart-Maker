#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H

#include "chartModel.h"
#include "barcharttablemodel.h"

class BarChartModel : public ChartModel {
private:
    QBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QVBarModelMapper *mapper;

    int getMax();
    int getMin();
public:
    BarChartModel(BarChartTableModel *data = new BarChartTableModel());

    void updateInsertRow() override;
    void updateInsertColumn() override;
    void updateRemoveRow(int pos) override;
    void updateRemoveColumn(int pos) override;
private slots:
    void cambiaNome(int index, QtCharts::QBarSet* barset);
public slots:
    void updateAxisY() override;
    void salvaJson() override;
};

#endif // BARCHART_MODEL_H
