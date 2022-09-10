#ifndef PIE_DATA_H
#define PIE_DATA_H

#include "chartData.h"
#include<vector>
#include<string>
#include<QJsonObject>
#include<QJsonArray>
#include<QString>
#include<QVector>
class pie_data:public ChartData
{
private:
    QVector<QString> labels;
    QVector<qreal> values;
    QString title;
    void dataInit() override;
public:
    pie_data();
    pie_data(QVector<qreal> m_values, QVector<QString> m_labels, QString m_title);
    pie_data& operator =(const pie_data& other);
    QVector<qreal> getValues()const;
    QVector<QString> getLabels()const;

    QString getTitle()const;
    void setLabel(int pos,QString l);
    void setData(int x, int y, qreal val) override;
    void setTitle(QString t);
    void pushLabel(QString l);
    void pushValue(qreal val);
    void removeData(int pos) override   ;
};

#endif // PIE_DATA_H
