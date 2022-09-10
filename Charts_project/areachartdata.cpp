#include "areachartdata.h"

AreaChartData::AreaChartData() : comparisonChartData("PlaceHolder", {{0,0},{1,12}}){}
AreaChartData::AreaChartData(QVector<QVector<int>> lines,QString title,QVector<QString>areanames):comparisonChartData(title,lines,areanames){}
void AreaChartData::pushPoint(int rowCount, int columnCount){
    QVector<int> temp;
    temp.push_back(rowCount);       //l'asse x che viene incrementata di 1 ogni volta.
    temp.insert(1, columnCount-1, 0); //i valori y delle linee che di default sono settate a 0.
    sets.push_back(temp);
}

void AreaChartData::removeAreaName(int l){
    names.remove(l);
}
void AreaChartData::addAreaName(QString l){
    names.push_back(l);
}

QString AreaChartData::getAreaName(int i)const{
    return names.at(i);
}
void AreaChartData::removeColumn(int column){
    names.remove(column-1);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(column);
    }
}
