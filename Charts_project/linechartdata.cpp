#include "linechartdata.h"

LineChartData::LineChartData() : comparisonChartData() {
    sets={{0,10},{1,2}};
    for(int i=0;i<sets.size();++i){
        for(int j=1;j<sets.at(0).size();j++)
            sortedYValues.push_back(sets[i][j]);
         std::sort(sortedYValues.begin(),sortedYValues.end());
    }
}

LineChartData::LineChartData(QVector<QVector<int>> series,QString m_title) : comparisonChartData(m_title, series){}

LineChartData& LineChartData::operator =(const LineChartData& other){
    if (this == &other)
        return *this;
    sets=other.sets;
    title=other.title;
    return *this;
}

void LineChartData::pushPoint(int rowCount, int columnCount){
    QVector<int> temp;
    temp.push_back(rowCount);       //l'asse x che viene incrementata di 1 ogni volta.
    temp.insert(1, columnCount-1, 0); //i valori y delle linee che di default sono settate a 0.
    sets.push_back(temp);
}

void LineChartData::addY(int y){
    sortedYValues.push_back(y);
    std::sort(sortedYValues.begin(),sortedYValues.end());
    setYAxisMinValue(sortedYValues.first());
    setYAxisMaxValue(sortedYValues.last());
}

void LineChartData::removeY(int x,int y){
    sortedYValues.removeOne(sets[x][y]);
    std::sort(sortedYValues.begin(),sortedYValues.end());  /*non ha senso ordinarlo.*/
    if (sortedYValues.count()>1){
        setYAxisMinValue(sortedYValues.first());
        setYAxisMaxValue(sortedYValues.last());
    }
    else{
        setYAxisMinValue(0);
        setYAxisMaxValue(15);
    }
}

QString LineChartData::getLineName(int i) const{
    return names.at(i);
}

void LineChartData::removeLineName(int l){
    names.remove(l);
}
