#ifndef BAR_DATA_H
#define BAR_DATA_H
#include <list>
#include <QtCharts>
#include<string>
#include<QVector>
#include<QString>
class Bar_data
{
protected:
    QVector<QVector<int>> sets;
    QString title;
    QVector<QString> barNames;
    QVector<QString> categories;
    int minValue;
    int maxValue;
    friend class BarChartModel;
    friend class BarChartTableModel;
public:
    Bar_data(QVector<QVector<int>> m_sets, QString m_title,  QVector<QString> m_categories,QVector<QString>m_names, int minValue,int maxValue);
    Bar_data();
    bool operator !();
    bool operator==(Bar_data d);
    Bar_data& operator =(const Bar_data& other);
    QString getTitle() const;
    QVector<QVector<int>> getSets() const;
    QVector<QString> getCategories() const;
    int getMinValue() const;
    int getMaxValue() const;
    QVector<QString> getBarNames()const;
    void setBarNames(int x,QString name);
    void setSets(int x,int y,int val);
    void removeRow(int row);
    void removeColumn(int column);
    void setCategories(int x,int y,QString cat);
    void setTitle(QString t);
    void setRange();
    void setMinValue(int min);
    void setMaxValue(int max);
    void pushSets(int pos);
    void pushCategory(QString cat);
    void pushBar(int pos);
    void pushBarName(QString name);
};

#endif // BAR_DATA_H
