#ifndef CANDLESTICKDATA_H
#define CANDLESTICKDATA_H

#include<QtCharts>
class CandleStickData
{
public:
    CandleStickData();
    int getEntries()const;
    QVector<qreal> getTimeStamps()const;
    QVector<qreal> getOpens()const;
    QVector<qreal> getHighs()const;
    QVector<qreal> getLows()const;
    QVector<qreal> getCloses()const;
    qreal getTimeStampAt(int pos)const;
    qreal getOpenAt(int pos)const;
    qreal getCloseAt(int pos)const;
    qreal getHighAt(int pos)const;
    qreal getLowAt(int pos)const;
    QString getTitle()const;
    void setTimeStampAt(int pos,qreal v);
    void setOpenAt(int pos,qreal v);
    void setCloseAt(int pos,qreal v);
    void setHighAt(int pos,qreal v);
    void setLowAt(int pos,qreal v);
    void removeRow(int row);
    void addRow(qreal t,qreal o,qreal h,qreal l,qreal c);
private:
    QVector<qreal> timestamp;
    QVector<qreal> open;
    QVector<qreal>high;
    QVector<qreal>low;
    QVector<qreal>close;
    QString title;
};

#endif // CANDLESTICKDATA_H
