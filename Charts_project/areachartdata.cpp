#include "areachartdata.h"

AreaChartData::AreaChartData():lines({{0,0},{1,12},{2,12},{3,32}})
{
    title=QString::fromStdString("PlaceHolder");
}

QVector<QVector<int>> AreaChartData::getLines() const{
    return lines;
}
QString AreaChartData::getTitle()const{
    return  title;
}

void AreaChartData::pushLine(int pos,int coordinate){
    lines[pos].push_back(coordinate);
}

void AreaChartData::setData(int x, int y, int value){
    lines[x][y]=value;
}

void AreaChartData::pushPoint(int count){
    QVector<int> temp;
    temp.fill(0,count);
    lines.push_back(temp);
}

