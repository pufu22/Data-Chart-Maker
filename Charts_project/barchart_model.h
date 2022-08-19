#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H
#include<bar_data.h>
#include<barcharttablemodel.h>
#include<qbarmodelmapper.h>
class BarChartModel
{
public:
    BarChartModel(BarChartTableModel *data);
    QChart *chart;
    void updateMapperLastColumn();
    void updateMapperLastRow();
    void salvaJsonBar();
protected:
    std::vector<std::vector<std::list<QBarSet>>> sets;
    QBarSeries *series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    QVBarModelMapper *mapper;
    QString title;
    int lastcolumn;
    int lastrow;
    friend class main;
};

#endif // BARCHART_MODEL_H
