#include "linechartdata.h"

LineChartData::LineChartData():lineseries({{0,0},{1,12},{2,0},{3,0}})
{

}

LineChartData::LineChartData(std::vector<std::vector<int> > series, std::string title):lineseries(series),title(title){}

LineChartData& LineChartData::operator =(const LineChartData& other){
    if (this == &other)
            return *this;
    this->lineseries=other.lineseries;
    this->title=other.title;
    return *this;
}
