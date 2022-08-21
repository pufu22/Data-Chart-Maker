#include "pie_data.h"
#include<QVariantList>
pie_data::pie_data():etichette({"John","Jude","Eunbi"}),title("Persone che occupano gli stock di holo"),valori({1,32,12})
{

}

pie_data::pie_data(QVector<int> s1, QVector<QString> s2, QString s3):etichette(s2),title(s3),valori(s1){}

pie_data& pie_data::operator =(const pie_data& other)
{
    if (this == &other)
            return *this;
    this->etichette=other.etichette;
    this->valori=other.valori;
    this->title=other.title;
    return *this;
}

QVector<int> pie_data::getValues()const{
    return valori;
}

QVector<QString> pie_data::getLabels()const{
    return etichette;
}

QString pie_data::getTitle()const{
    return title;
}

void pie_data::setLabel(int pos,QString l){
    etichette[pos]=l;
}

void pie_data::setValue(int pos,int v){
    valori[pos]=v;
}

void pie_data::pushbackLabel(QString l){
    etichette.push_back(l);
}

void pie_data::pushbackValue(int v){
    valori.push_back(v);
}

void pie_data::removeSlice(int pos){
    etichette.remove(pos-1);
    valori.remove(pos-1);
}
