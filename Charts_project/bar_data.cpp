#include "bar_data.h"
#include<string>
//Bar_data::Bar_data(QVector<QVector<int>> m_sets, QString m_title, QVector<QString> m_categories, QVector<QString> m_names, int minValue, int maxValue):sets(m_sets),title(m_title),
//    categories(m_categories),barNames(m_names){};

Bar_data::Bar_data(QVector<QVector<int>> m_sets, QString m_title, QVector<QString> m_categories, QVector<QString> m_names, int minValue, int maxValue):comparisonChartData(m_title, m_sets, m_names, m_categories, minValue, maxValue){}

//Bar_data::Bar_data():sets({{3},{1}}),title("riempi"),categories({"w ","e"}),barNames({"blu"}),minValue(0),maxValue(15){};

Bar_data::Bar_data():comparisonChartData(){}

Bar_data& Bar_data::operator =(const Bar_data& other){
    if (this == &other)
            return *this;
    this->categories=other.categories;
    this->sets=other.sets;
    this->title=other.title;
    return *this;
}

/*QString Bar_data::getTitle()const{
    return title;
}
QVector<QString>Bar_data::getCategories()const{
    return categories;
}
QVector<QVector<int>> Bar_data::getSets()const{
    return sets;
}
QVector<QString>Bar_data::getBarNames()const{
    return barNames;
}
int Bar_data::getMinValue()const{
    return minValue;
}

int Bar_data::getMaxValue() const{
    return maxValue;
}

void Bar_data::setSets(int x,int y,int val){
    sets[x][y]=val;
}*/

void Bar_data::setCategories(int x,int y,QString cat){
    categories[x]=cat;
}

void Bar_data::setBarNames(int x,QString name){
    //barNames[x]=name;
    names[x]=name;
}

/*void Bar_data::setTitle(QString t){
    title=t;
}*/

/*void Bar_data::pushSets(int count){
    QVector<int> temp;
    temp.fill(0,count);
    sets.push_back(temp);
}*/

/*void Bar_data::pushCategory(QString cat){
    categories.push_back(cat);
}*/

/*void Bar_data::pushBar(int pos){
    sets[pos].push_back(0);
}*/

/*void Bar_data::pushBarName(QString name){
    barNames.push_back(name);
}*/

void Bar_data::removeRow(int row){
    categories.remove(row);
    sets.removeAt(row);
}

/*void Bar_data::removeColumn(int column){
    //barNames.remove(column);
    names.remove(column);
    for(int i=0;i<sets.size();++i){
        sets[i].remove(column);
    }
}*/



/*void Bar_data::setMinValue(int min){
    minValue=min;
}

void Bar_data::setMaxValue(int max){
    maxValue=max;
}*/
