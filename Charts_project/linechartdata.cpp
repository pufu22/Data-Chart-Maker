#include "linechartdata.h"

LineChartData::LineChartData():lineseries({{0,0},{1,12},{2,0},{3,0}})
{

}

LineChartData::LineChartData(QVector<QVector<int>> series,QString title):lineseries(series),title(title){}

LineChartData& LineChartData::operator =(const LineChartData& other){
    if (this == &other)
            return *this;
    this->lineseries=other.lineseries;
    this->title=other.title;
    return *this;
}

QVector<QVector<int>> LineChartData::getLines()const{
    return lineseries;
}

QString LineChartData::getTitle() const{
    return title;
}

void LineChartData::setData(int x, int y, int value){
    lineseries[x][y]=value;
}
void LineChartData::pushPoint(int count){
    QVector<int> temp;
    temp.fill(0,count);
    lineseries.push_back(temp);
}
void LineChartData::pushLine(int pos,int coordinate){
    lineseries[pos].push_back(coordinate);
}
