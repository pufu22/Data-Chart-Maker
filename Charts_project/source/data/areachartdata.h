#ifndef AREACHARTDATA_H
#define AREACHARTDATA_H

#include "comparisonChartData.h"

class AreaChartData : public comparisonChartData {
public:
    AreaChartData();

    void removeGroup(int pos) override;
    void pushData(int count) override;
};

#endif // AREACHARTDATA_H
