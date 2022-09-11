#include "candlestickdata.h"

CandleStickData::CandleStickData() : ChartData()
{
    timestamp = {1435708800000,1435795200000};
    open = {126.90,126.69};
    close = {126.60,126.69};
    high = {126.94,126.69};
    low = {125.99,126.69};
    CandleStickData::dataInit();
}

CandleStickData::CandleStickData(QVector<qreal> m_timestamp, QVector<qreal> m_open, QVector<qreal> m_close, QVector<qreal> m_high,
                                 QVector<qreal> m_low, QString m_title)
                                : ChartData(m_title), timestamp(m_timestamp), open(m_open), high(m_high), low(m_low), close(m_close) {
    CandleStickData::dataInit();
}

void CandleStickData::dataInit() {
    QVector<qreal> temp;
    for(int i = 0; i < timestamp.size(); i++){
        temp.push_back(timestamp[i]);
        temp.push_back(open[i]);
        temp.push_back(high[i]);
        temp.push_back(low[i]);
        temp.push_back(close[i]);
        data.push_back(temp);
        temp.clear();
    }
}

qreal CandleStickData::getTimeStampAt(int pos) const {
    return timestamp.at(pos);
}

qreal CandleStickData::getOpenAt(int pos) const {
    return open.at(pos);
}

qreal CandleStickData::getCloseAt(int pos) const {
    return close.at(pos);
}

qreal CandleStickData::getHighAt(int pos) const {
    return high.at(pos);
}

qreal CandleStickData::getLowAt(int pos) const {
    return low.at(pos);
}

void CandleStickData::setData(int x,int y, qreal val) {
    switch (y) {
    case 0: timestamp.replace(x, val);
            break;
    case 1: open.replace(x, val);
            break;
    case 2: high.replace(x, val);
            break;
    case 3: low.replace(x, val);
            break;
    case 4: close.replace(x, val);
            break;
    }
    data[x][y] = val;
}

void CandleStickData::addData(qreal t, qreal o, qreal h, qreal l, qreal c){
    timestamp.push_back(t);
    open.push_back(o);
    close.push_back(c);
    high.push_back(h);
    low.push_back(l);
    data.push_back({timestamp.last(), open.last(), high.last(), low.last(), close.last()});
}

void CandleStickData::removeData(int pos) {
    timestamp.removeAt(pos);
    open.removeAt(pos);
    close.removeAt(pos);
    high.removeAt(pos);
    low.removeAt(pos);
    data.remove(pos);
}
