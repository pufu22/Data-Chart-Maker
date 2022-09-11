#include "linechartdata.h"

LineChartData::LineChartData() : comparisonChartData("PlaceHolder", {{0,10},{1,2}}) {}

LineChartData::LineChartData(QVector<QVector<qreal>> series,QString m_title) : comparisonChartData(m_title, series){}

void LineChartData::removeGroup(int pos){
    names.remove(pos-1);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(pos);
        data[i].remove(pos);
    }
}

void LineChartData::pushData(int count){
    QVector<qreal> temp;
    temp.push_back(sets.size());    //l'asse x che viene incrementata di 1 ogni volta.
    temp.insert(1, count-1, 0);     //i valori y delle linee che di default sono settate a 0.
    sets.push_back(temp);
    data.push_back(temp);
}
