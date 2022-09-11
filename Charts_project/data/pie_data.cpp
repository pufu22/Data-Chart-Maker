#include "pie_data.h"
#include<QVariantList>
pie_data::pie_data() : ChartData(), labels({"John", "Jude", "Eunbi"}), values({1, 32, 12}) { pie_data::dataInit(); }

pie_data::pie_data(QVector<qreal> m_values, QVector<QString> m_labels, QString m_title) : ChartData(m_title), labels(m_labels),
                                                                                             values(m_values) {
    pie_data::dataInit();
}

void pie_data::dataInit() {
    //QVector<qreal> temp;
    for(int i = 0; i < values.size(); i++){
        //temp.push_back(values[i]);
        data.push_back({values[i]});
    }
}


QVector<qreal> pie_data::getValues()const{
    return values;
}

QVector<QString> pie_data::getLabels()const{
    return labels;
}


void pie_data::setLabel(int pos,QString l){
    labels[pos]=l;
}

void pie_data::setData(int x,int y,qreal val){
    values[x]=val;
    data[x][y-1] = val;
}


void pie_data::pushLabel(QString l){
    labels.push_back(l);
}

void pie_data::pushValue(qreal val){
    values.push_back(val);
    data.push_back({val});
}

void pie_data::removeData(int pos){
    labels.remove(pos-1);
    values.remove(pos-1);
    data.remove(pos-1);
}
