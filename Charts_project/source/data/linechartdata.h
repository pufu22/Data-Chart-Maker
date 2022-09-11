#ifndef LINECHARTDATA_H
#define LINECHARTDATA_H

#include "comparisonChartData.h"

class LineChartData : public comparisonChartData {
public:
    LineChartData();
    LineChartData(QVector<QVector<qreal>> series, QString title, QVector<QString> names);

    void removeGroup(int pos) override;
    void pushData(int count) override;
};

#endif // LINECHARTDATA_H
