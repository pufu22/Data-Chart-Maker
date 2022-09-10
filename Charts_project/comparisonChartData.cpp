#include "comparisonChartData.h"

comparisonChartData::comparisonChartData(const QString& m_title, const QVector<QVector<int>>& m_sets, const QVector<QString>& m_names,
                                         const QVector<QString>& m_categories, const int& minValue, const int& maxValue)
    :title(m_title), sets(m_sets),  names(m_names), categories(m_categories), yAxisMinValue(minValue), yAxisMaxValue(maxValue){}

QString comparisonChartData::getTitle()const{
    return title;
}

QVector<QVector<int>> comparisonChartData::getSets()const{
    return sets;
}

QVector<QString> comparisonChartData::getNames()const{
    return names;
}

QVector<QString> comparisonChartData::getCategories()const{
    return categories;
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

void comparisonChartData::setSets(int x,int y,int val){
    sets[x][y]=val;
}

void comparisonChartData::setYAxisMinValue(int min){
    yAxisMinValue=min;
}

void comparisonChartData::setYAxisMaxValue(int max){
    yAxisMaxValue=max;
}

void comparisonChartData::removeRow(int row){
    //categories.remove(row);
    sets.removeAt(row);

}

void comparisonChartData::removeColumn(int column){
    names.remove(column);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(column);
    }
}

void comparisonChartData::pushSets(int count){
    QVector<int> temp;
    temp.fill(0,count);
    sets.push_back(temp);
}

void comparisonChartData::pushName(QString name){
    names.push_back(name);
}

void comparisonChartData::pushCategory(QString catg){
    categories.push_back(catg);
}

/*Group = raggruppamento di dati che formano un' "entità" nel grafico (es. nel barchart i groups sarebbero i rettangoli dello stesso colore e
    nel linechart i groups sarebbero le linee).*/
void comparisonChartData::pushGroup(int pos){
    sets[pos].push_back(0);
}

void comparisonChartData::setName(QString name,int pos){
    names[pos]=name;
}
