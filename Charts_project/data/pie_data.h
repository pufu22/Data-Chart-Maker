#ifndef PIE_DATA_H
#define PIE_DATA_H

#include "chartData.h"
#include <vector>
#include <string>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QVector>
class pie_data : public ChartData {
private:
    QVector<QString> labels;
    QVector<qreal> values;

    void dataInit() override;
public:
    pie_data();
    pie_data(QVector<qreal> m_values, QVector<QString> m_labels, QString m_title);

    QVector<qreal> getValues()const;
    QVector<QString> getLabels()const;

    void setLabel(int pos, QString l);
    void setData(int x, int y, qreal val) override;

    void removeData(int pos) override;

    void pushLabel(QString l);
    void pushValue(qreal v);
};

#endif // PIE_DATA_H
