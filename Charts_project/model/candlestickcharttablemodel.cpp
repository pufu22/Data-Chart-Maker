#include "candlestickcharttablemodel.h"

CandleStickChartTableModel::CandleStickChartTableModel(QObject* parent, CandleStickData* data) : ChartTableModel(parent, data),
                                                                                                 candleData(data) {}

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
        if(timestamp>candleData->getTimeStampAt(row-1)) {
            beginInsertRows(parent,row,row);
                candleData->addData(timestamp,open,high,low,close);
            endInsertRows();
            return true;
        }
    }
    return false;
}

Qt::ItemFlags CandleStickChartTableModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}

QVariant CandleStickChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
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
