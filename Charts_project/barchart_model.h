#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H
#include<bar_data.h>

class BarChartModel
{
public:
    BarChartModel(Bar_data data);
    QChart *chart;
protected:
    std::vector<std::vector<std::list<QBarSet>>> sets;
    QBarSeries series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;

    friend class main;
};

#endif // BARCHART_MODEL_H
