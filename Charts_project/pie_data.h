#ifndef PIE_DATA_H
#define PIE_DATA_H

#include<vector>
#include<string>
#include<QJsonObject>
#include<QJsonArray>
#include<QString>
#include<QVector>
class pie_data
{
private:
    QVector<QString> etichette;
    QVector<int> valori;
    QString title;
public:
    pie_data();
    pie_data(QVector<int>s1,QVector<QString>s2,QString s3);
    pie_data& operator =(const pie_data& other);
    QVector<int> getValues()const;
    QVector<QString> getLabels()const;
    QString getTitle()const;
    void setLabel(int pos,QString l);
    void setValue(int pos,int v);
    void pushbackLabel(QString l);
    void pushbackValue(int v);
    void removeSlice(int pos);
};

#endif // PIE_DATA_H
