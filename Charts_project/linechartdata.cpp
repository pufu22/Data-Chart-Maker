#include "linechartdata.h"

LineChartData::LineChartData():lineseries({{0,0},{1,12},{2,0},{3,0}}),nomeLinea({"po"})
{
    for(int i=0;i<lineseries.size();++i){
        for(int j=1;j<lineseries.at(0).size();j++)
            sortedYValues.push_back(lineseries[i][j]);
         std::sort(sortedYValues.begin(),sortedYValues.end());
    }
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

int LineChartData::getMaxValue()const{
    return sortedYValues.last();
}

int LineChartData::getMinValue()const{
    return sortedYValues.first();
}

void LineChartData::setTitle(QString t){
    title=t;
}

void LineChartData::setMaxValue(int max){
    maxValue=max;
}
void LineChartData::setMinValue(int min){
    minValue=min;
}


void LineChartData::addY(int y){
    sortedYValues.push_back(y);
    std::sort(sortedYValues.begin(),sortedYValues.end());
}

void LineChartData::removeY(int x,int y){
    sortedYValues.removeOne(lineseries[x][y]);
    std::sort(sortedYValues.begin(),sortedYValues.end());
}

QString LineChartData::getLineName(int i) const{
    return nomeLinea.at(i);
}

void LineChartData::addLineName(QString l){
    nomeLinea.push_back(l);
}

void LineChartData::removeLine(int column){
    for(int i=0;i<lineseries.size();++i)
    {
        lineseries[i].remove(column);
    }

}
void LineChartData::removePoints(int row){
    lineseries.remove(row);
}

void LineChartData::removeLineName(int l){
    nomeLinea.remove(l);
}
