#include "candlestickcharttablemodel.h"

CandleStickChartTableModel::CandleStickChartTableModel(QObject* parent, CandleStickData* data) : ChartTableModel(parent, data),
                                                                                                 candleData(data) {}
int CandleStickChartTableModel::columnCount(const QModelIndex &parent)const {
    if (parent.isValid())
        return 0;
    else
        return 5;
}
bool CandleStickChartTableModel::insertRows(int row, int count, const QModelIndex &parent){
    qreal timestamp;
    qreal open;
    qreal high;
    qreal low;
    qreal close;
    bool ok;
    QStringList list = inputdialog::getStrings(nullptr,"candlestickchart",&ok);
    if (ok) {
        timestamp=list.at(0).toDouble();
        open=list.at(1).toDouble();
        high=list.at(2).toDouble();
        low=list.at(3).toDouble();
        close=list.at(4).toDouble();
    if(timestamp>candleData->getTimeStampAt(row-1)){
        beginInsertRows(parent,row,row);
            candleData->addData(timestamp,open,high,low,close);
        endInsertRows();
        return true;
    }
    }
        return false;
}

QVariant CandleStickChartTableModel::data(const QModelIndex &index, int role)const {
    if (role==Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return candleData->getTimeStampAt(index.row());
            break;
        case 1:
            return candleData->getOpenAt(index.row());
            break;
        case 2:
            return candleData->getHighAt(index.row());
            break;
        case 3:
            return candleData->getLowAt(index.row());
            break;
        case 4:
            return candleData->getCloseAt(index.row());
            break;
        }
    }
    else return QVariant();
}
Qt::ItemFlags CandleStickChartTableModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}
bool CandleStickChartTableModel::setData(const QModelIndex &index,const QVariant &value,int role){
    if(role==Qt::EditRole){
            switch (index.column()) {
            case 0:
                candleData->setData(index.row(), 0, value.toReal());
                break;
            case 1:
                if(value.toReal()<=candleData->getHighAt(index.row()) && value.toReal()>=candleData->getLowAt(index.row()))
                    candleData->setData(index.row(), 1, value.toReal());
                break;
            case 2:
                if(value.toReal()>=candleData->getLowAt(index.row()))
                    candleData->setData(index.row(), 2, value.toReal());
                break;
            case 3:
                if(value.toReal()<=candleData->getHighAt(index.row()))
                    candleData->setData(index.row(), 3, value.toReal());
                break;
            case 4:
                if(value.toReal()<=candleData->getHighAt(index.row()) && value.toReal()>=candleData->getLowAt(index.row()))
                    candleData->setData(index.row(), 4, value.toReal());
                break;
            }
            emit dataChanged(index,index);
            return true;
        }else
        return false;


}

QVariant CandleStickChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch(section){
        case 0:
            return QString("Timestamp");
            break;
        case 1:
            return QString("Open");
            break;
        case 2:
            return QString("High");
            break;
        case 3:
            return QString("Low");
            break;
        case 4:
            return QString("Close");
            break;
        }
    }
    else if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        return section+1;
    }
    return QVariant();
}


