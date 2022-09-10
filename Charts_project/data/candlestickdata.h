#ifndef CANDLESTICKDATA_H
#define CANDLESTICKDATA_H
#include<data/chartData.h>
#include<QtCharts>
class CandleStickData:public ChartData
{
public:
    CandleStickData();
    CandleStickData(QVector<qreal> m_timestamp, QVector<qreal> m_open, QVector<qreal> m_close, QVector<qreal> m_high, QVector<qreal> m_low,
                        QString m_title);
    int getEntries()const;
    qreal getTimeStampAt(int pos)const;
    qreal getOpenAt(int pos)const;
    qreal getCloseAt(int pos)const;
    qreal getHighAt(int pos)const;
    qreal getLowAt(int pos)const;
    QString getTitle()const;
    void setTitle(QString t);
    void setData(int x,int y, qreal val) override;
    void removeData(int pos) override;
    void addData(qreal t,qreal o,qreal h,qreal l,qreal c);
private:
    QVector<qreal> timestamp;
    QVector<qreal> open;
    QVector<qreal>high;
    QVector<qreal>low;
    QVector<qreal>close;
    QString title;
    void dataInit() override;
};

#endif // CANDLESTICKDATA_H
