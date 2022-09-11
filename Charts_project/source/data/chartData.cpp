#include "chartData.h"

ChartData::ChartData(const QString& m_title) : title(m_title) {};

QString ChartData::getTitle() const {
    return title;
}

QVector<QVector<qreal>> ChartData::getData() const {
    return data;
}

void ChartData::setTitle(QString t) {
    title = t;
}

void ChartData::setData(int x,int y, qreal val) {
    data[x][y] = val;
}

void ChartData::removeData(int pos) {
    data.remove(pos);
}
