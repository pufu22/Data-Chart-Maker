#include "areachartdata.h"

AreaChartData::AreaChartData() : comparisonChartData("PlaceHolder", {{0,0},{1,12}}){}

void AreaChartData::pushPoint(int rowCount, int columnCount){
    QVector<int> temp;
    temp.push_back(rowCount);       //l'asse x che viene incrementata di 1 ogni volta.
    temp.insert(1, columnCount-1, 0); //i valori y delle linee che di default sono settate a 0.
    sets.push_back(temp);
}

