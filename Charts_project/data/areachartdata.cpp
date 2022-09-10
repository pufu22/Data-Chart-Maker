#include "areachartdata.h"

AreaChartData::AreaChartData() : comparisonChartData("PlaceHolder", {{0,0},{1,12}}){}
AreaChartData::AreaChartData(QVector<QVector<qreal>> lines,QString title,QVector<QString>areanames):comparisonChartData(title,lines,areanames){}
void AreaChartData::removeGroup(int pos){
    names.remove(pos-1);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(pos);
    }
}
