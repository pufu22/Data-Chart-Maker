#ifndef LINECHARTDATA_H
#define LINECHARTDATA_H

#include<vector>
#include<QPointF>
#include<string>
class LineChartData
{
protected:
    std::vector<std::vector<int>> lineseries;
    std::string title;
public:
    LineChartData();
    friend class LineChartTableModel;
    friend class LineChartModel;
};

#endif // LINECHARTDATA_H
