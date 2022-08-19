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
    LineChartData(std::vector<std::vector<int>> series,std::string title);
    friend class LineChartTableModel;
    friend class LineChartModel;
    LineChartData& operator =(const LineChartData& other);
};

#endif // LINECHARTDATA_H
