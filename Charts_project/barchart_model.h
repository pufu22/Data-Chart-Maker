#ifndef BARCHART_MODEL_H
#define BARCHART_MODEL_H
#include<bar_data.h>

class BarChartModel
{
public:
    BarChartModel(Bar_data data);
protected:
    QBarSeries series;
    QStringList categories;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
};

#endif // BARCHART_MODEL_H
