#include "comparisonChartData.h"

comparisonChartData::comparisonChartData(const QString& m_title, const QVector<QVector<qreal>>& m_sets, const QVector<QString>& m_names)
                                        : ChartData(m_title), sets(m_sets),  names(m_names) {
    comparisonChartData::dataInit();
}

void comparisonChartData::dataInit() {
    data = sets;
}

QVector<QVector<qreal>> comparisonChartData::getSets()const{
    return sets;
}

QVector<QString> comparisonChartData::getNames()const{
    return names;
}

void comparisonChartData::setData(int x,int y, qreal val) {
    sets[x][y] = val;
    data[x][y] = val;
}

void comparisonChartData::setName(QString name, int pos){
    names[pos]=name;
}

void comparisonChartData::removeData(int pos) {
    sets.remove(pos);
    data.remove(pos);
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

void comparisonChartData::pushGroup(int pos){
    sets[pos].push_back(0);
    data[pos].push_back(0);
}
