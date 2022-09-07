#ifndef COMPARISONCHARTDATA_H
#define COMPARISONCHARTDATA_H

#include<QVector>

class comparisonChartData {
protected:
    QString title;
    QVector<QVector<int>> sets;
    QVector<QString> names;
    QVector<QString> categories;
    int yAxisMinValue;
    int yAxisMaxValue;
public:
    explicit comparisonChartData(const QString& m_title="insert title", const QVector<QVector<int>>& m_sets={{10}}, const QVector<QString>& m_names={"insert name"}, const QVector<QString>& m_categories={"insert label"}, const int& minValue=0, const int& maxValue=15);

    QString getTitle() const;
    QVector<QVector<int>> getSets() const;
    QVector<QString> getNames()const;
    QVector<QString> getCategories() const;
    int getYAxisMinValue() const;
    int getYAxisMaxValue() const;

    void setTitle(QString t);
    void setSets(int x,int y,int val);  /*corrisponde al setData()*/
    void setYAxisMinValue(int min);
    void setYAxisMaxValue(int max);

    void removeRow(int row);
    void removeColumn(int column);

    void pushSets(int pos);
    void pushName(QString name);
    void pushCategory(QString catg);
    void pushGroup(int pos);
};

#endif // COMPARISONCHARTDATA_H
