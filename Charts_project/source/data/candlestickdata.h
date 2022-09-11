#ifndef CANDLESTICKDATA_H
#define CANDLESTICKDATA_H

#include "chartData.h"

class CandleStickData : public ChartData {
private:
    QVector<qreal> timestamp;
    QVector<qreal> open;
    QVector<qreal>high;
    QVector<qreal>low;
    QVector<qreal>close;

    void dataInit() override;
public:
    CandleStickData();
    CandleStickData(QVector<qreal> m_timestamp, QVector<qreal> m_open, QVector<qreal> m_close, QVector<qreal> m_high, QVector<qreal> m_low,
                    QString m_title);

    qreal getTimeStampAt(int pos)const;
    qreal getOpenAt(int pos)const;
    qreal getCloseAt(int pos)const;
    qreal getHighAt(int pos)const;
    qreal getLowAt(int pos)const;

    void setData(int x,int y, qreal val) override;

    void addData(qreal t,qreal o,qreal h,qreal l,qreal c);

    void removeData(int pos) override;
};

#endif // CANDLESTICKDATA_H
