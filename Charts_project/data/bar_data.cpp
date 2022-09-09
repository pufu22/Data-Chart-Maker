#include "bar_data.h"
#include<string>

Bar_data::Bar_data(QVector<QVector<qreal>> m_sets, QString m_title, QVector<QString> m_categories, QVector<QString> m_names, int minValue,
                   int maxValue)
    : comparisonChartData(m_title, m_sets, m_names, minValue, maxValue){categories = m_categories;}

Bar_data::Bar_data() : comparisonChartData(){categories = {"insert label"};}

QVector<QString> Bar_data::getCategories()const{
    return categories;
}

void Bar_data::setCategories(QString catg, int x){
    categories[x]=catg;
}

void Bar_data::removeData(int pos) {
    categories.remove(pos);
    sets.removeAt(pos);
    data.remove(pos);
}

void Bar_data::pushCategory(QString catg){
    categories.push_back(catg);
}
