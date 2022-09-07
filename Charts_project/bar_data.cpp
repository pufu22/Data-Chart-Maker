#include "bar_data.h"
#include<string>

Bar_data::Bar_data(QVector<QVector<int>> m_sets, QString m_title, QVector<QString> m_categories, QVector<QString> m_names, int minValue,
                   int maxValue)
    : comparisonChartData(m_title, m_sets, m_names, m_categories, minValue, maxValue){}

Bar_data::Bar_data():comparisonChartData(){}

Bar_data& Bar_data::operator =(const Bar_data& other){
    if (this == &other)
            return *this;
    this->categories=other.categories;
    this->sets=other.sets;
    this->title=other.title;
    return *this;
}

void Bar_data::setCategories(int x,int y,QString cat){
    categories[x]=cat;
}

void Bar_data::setBarNames(int x,QString name){
    names[x]=name;
}

void Bar_data::removeRow(int row){
    categories.remove(row);
    sets.removeAt(row);
}
