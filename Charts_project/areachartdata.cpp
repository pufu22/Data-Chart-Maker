#include "areachartdata.h"

/*AreaChartData::AreaChartData():lines({{0,0},{1,12},{2,12},{3,32}})
{
    title=QString::fromStdString("PlaceHolder");
}*/

AreaChartData::AreaChartData() : comparisonChartData("PlaceHolder", {{0,0},{1,12}}){}

/*QVector<QVector<int>> AreaChartData::getLines() const{
    return lines;
}*/

/*QString AreaChartData::getTitle()const{
    return  title;
}*/

/*void AreaChartData::pushLine(int pos,int coordinate){
    lines[pos].push_back(coordinate);
}*/

/*void AreaChartData::pushLine(int pos,int coordinate){
    sets[pos].push_back(coordinate);
}*/

/*void AreaChartData::setData(int x, int y, int value){
    lines[x][y]=value;
}*/

/*void AreaChartData::pushPoint(int count){
    QVector<int> temp;
    temp.fill(0,count);
    lines.push_back(temp);
}*/

void AreaChartData::pushPoint(int rowCount, int columnCount){
    QVector<int> temp;
    temp.push_back(rowCount);       //l'asse x che viene incrementata di 1 ogni volta.
    //temp.fill(0);
    temp.insert(1, columnCount-1, 0); //i valori y delle linee che di default sono settate a 0.
    sets.push_back(temp);
}

