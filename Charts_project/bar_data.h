#ifndef BAR_DATA_H
#define BAR_DATA_H

#include <comparisonChartData.h>
#include <list>
#include <QtCharts>
#include<string>
#include<QVector>
#include<QString>

class Bar_data : public comparisonChartData {
public:
    Bar_data(QVector<QVector<int>> m_sets, QString m_title, QVector<QString> m_categories,QVector<QString>m_names);
    Bar_data();
    bool operator !();
    bool operator==(Bar_data d);
    Bar_data& operator =(const Bar_data& other);
    void setBarNames(int x,QString name);
    void removeRow(int row);   /*Metodo overridato*/
    void setCategories(int x,QString cat);
    void setRange();
};

#endif // BAR_DATA_H
