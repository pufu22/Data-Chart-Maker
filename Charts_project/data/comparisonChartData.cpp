#include "comparisonChartData.h"

comparisonChartData::comparisonChartData(const QString& m_title, const QVector<QVector<qreal>>& m_sets, const QVector<QString>& m_names,
                                         const int& minValue, const int& maxValue)
                                        : ChartData(m_title), sets(m_sets),  names(m_names), yAxisMinValue(minValue), yAxisMaxValue(maxValue) {
    comparisonChartData::dataInit();
}

void comparisonChartData::dataInit() {
    data = sets;
}


QString comparisonChartData::getTitle()const{
    return title;
}

QVector<QVector<qreal>> comparisonChartData::getSets()const{
    return sets;
}

QVector<QString> comparisonChartData::getNames()const{
    return names;
}

int comparisonChartData::getYAxisMinValue()const{
    return yAxisMinValue;
}

int comparisonChartData::getYAxisMaxValue() const{
    return yAxisMaxValue;
}

void comparisonChartData::setTitle(QString t){
    title=t;
}

void comparisonChartData::setData(int x,int y,qreal val){
    sets[x][y]=val;
    data[x][y]=val;
}

void comparisonChartData::setYAxisMinValue(int min){
    yAxisMinValue=min;
}

void comparisonChartData::setYAxisMaxValue(int max){
    yAxisMaxValue=max;
}

void comparisonChartData::removeData(int pos){
    sets.removeAt(pos);
    data.removeAt(pos);
}

void comparisonChartData::removeGroup(int pos){
    names.remove(pos);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(pos);
        data[i].remove(pos);
    }
}

void comparisonChartData::pushData(int count){
    QVector<qreal> temp;
    temp.fill(0,count);
    sets.push_back(temp);
    data.push_back(temp);
}

void comparisonChartData::pushName(QString name){
    names.push_back(name);
}


/*Group = raggruppamento di dati che formano un' "entità" nel grafico (es. nel barchart i groups sarebbero i rettangoli dello stesso colore e
    nel linechart i groups sarebbero le linee).*/
void comparisonChartData::pushGroup(int pos){
    sets[pos].push_back(0);
    data[pos].push_back(0);
}

void comparisonChartData::setName(QString name,int pos){
    names[pos]=name;
}
