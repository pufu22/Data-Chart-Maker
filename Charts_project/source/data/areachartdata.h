#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H

#include "comparisonChartData.h"

class AreaChartData : public comparisonChartData {
public:
    AreaChartData();
    AreaChartData(QVector<QVector<qreal>> lines, QString title, QVector<QString> areanames);

    void removeGroup(int pos) override;
    void pushData(int count) override;
    void pushGroup(int pos) override;
};

#endif // AREACHARTDATA_H
