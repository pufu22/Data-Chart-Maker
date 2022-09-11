#ifndef BAR_DATA_H
#define BAR_DATA_H

#include "comparisonChartData.h"

class Bar_data : public comparisonChartData {
private:
    QVector<QString> categories;
public:
    Bar_data(QVector<QVector<qreal>> m_sets, QString m_title, QVector<QString> m_categories, QVector<QString>m_names, int minValue,int maxValue);
    Bar_data();

    QVector<QString> getCategories() const;

    void setCategories(QString catg, int x);

    void removeData(int pos) override;

    void pushCategory(QString catg);
};

#endif // BAR_DATA_H
//const QVector<QString>& m_categories={"insert label"}
