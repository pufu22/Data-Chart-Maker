#ifndef COMPARISONCHARTDATA_H
#define COMPARISONCHARTDATA_H

#include "chartData.h"

class comparisonChartData : public ChartData{
protected:
    QVector<QVector<qreal>> sets;
    QVector<QString> names;

    void dataInit() override final;
public:
    explicit comparisonChartData(const QString& m_title="titolo", const QVector<QVector<qreal>>& m_sets={{10}},
                                 const QVector<QString>& m_names={"insert name"});

    QVector<QVector<qreal>> getSets() const;
    QVector<QString> getNames()const;

    void setData(int x,int y, qreal val) override;
    void setName(QString name,int pos);

    void removeData(int pos) override;
    virtual void removeGroup(int pos);

    virtual void pushData(int count);
    void pushName(QString name);
    virtual void pushGroup(int pos);        /*Group = raggruppamento di dati che formano un' "entità" nel grafico (es. nel barchart i groups sarebbero
                                              i rettangoli dello stesso colore e nel linechart i groups sarebbero le linee).*/
};

#endif // COMPARISONCHARTDATA_H
