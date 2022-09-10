#ifndef COMPARISONCHARTDATA_H
#define COMPARISONCHARTDATA_H

#include "chartData.h"
#include<QVector>

class comparisonChartData:public ChartData{
protected:
    QString title;
    QVector<QVector<qreal>> sets;
    QVector<QString> names;
    int yAxisMinValue;
    int yAxisMaxValue;

    void dataInit() override final;
public:
    explicit comparisonChartData(const QString& m_title="titolo", const QVector<QVector<qreal>>& m_sets={{10}},
                                     const QVector<QString>& m_names={"insert name"}, const int& minValue=0, const int& maxValue=15);


    QString getTitle() const;
    QVector<QVector<qreal>> getSets() const;
    QVector<QString> getNames()const;
    int getYAxisMinValue() const;
    int getYAxisMaxValue() const;

    void setTitle(QString t);
    void setData(int x,int y,qreal val);  /*corrisponde al setData()*/
    void setYAxisMinValue(int min);
    void setYAxisMaxValue(int max);

    void removeData(int pos) override;
    virtual void removeGroup(int pos);

    virtual void pushData(int count);
        void pushName(QString name);
        void pushGroup(int pos);

    void pushSets(int pos);
    void setName(QString name,int pos);
};

#endif // COMPARISONCHARTDATA_H
