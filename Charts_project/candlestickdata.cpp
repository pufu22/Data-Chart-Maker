#include "candlestickdata.h"

CandleStickData::CandleStickData():timestamp({1435708800000,1435795200000}),open({126.90,126.69}),high({126.94,126.69}),low({125.99,126.69}),close({126.60,126.69})
{

}

int CandleStickData::getEntries()const{
    return timestamp.size();
}
QVector<qreal> CandleStickData::getTimeStamps()const{
    return timestamp;
}
QVector<qreal> CandleStickData::getOpens()const{
    return open;
}
QVector<qreal> CandleStickData::getHighs()const{
    return high;
}
QVector<qreal> CandleStickData::getLows()const{
    return low;
}
QVector<qreal> CandleStickData::getCloses()const{
    return close;
}
qreal CandleStickData::getTimeStampAt(int pos)const{
    return timestamp.at(pos);
}
qreal CandleStickData::getOpenAt(int pos)const{
    return open.at(pos);
}
qreal CandleStickData::getCloseAt(int pos)const{
    return close.at(pos);
}
qreal CandleStickData::getHighAt(int pos)const{
    return high.at(pos);
}
qreal CandleStickData::getLowAt(int pos)const{
    return low.at(pos);
}
QString CandleStickData::getTitle()const{
    return title;
}

void CandleStickData::setTimeStampAt(int pos,qreal v){
    timestamp.replace(pos,v);
}
void CandleStickData::setOpenAt(int pos,qreal v){
    open.replace(pos,v);
}
void CandleStickData::setCloseAt(int pos,qreal v){
    close.replace(pos,v);
}
void CandleStickData::setHighAt(int pos,qreal v){
    high.replace(pos,v);
}
void CandleStickData::setLowAt(int pos,qreal v){
    low.replace(pos,v);
}
void CandleStickData::removeRow(int row){
    timestamp.removeAt(row);
    open.removeAt(row);
    close.removeAt(row);
    high.removeAt(row);
    low.removeAt(row);
}
void CandleStickData::addRow(qreal t,qreal o, qreal h,qreal l,qreal c){
    timestamp.push_back(t);
    open.push_back(o);
    close.push_back(c);
    high.push_back(h);
    low.push_back(l);
}

