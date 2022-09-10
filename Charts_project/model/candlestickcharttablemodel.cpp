#include "candlestickcharttablemodel.h"

CandleStickChartTableModel::CandleStickChartTableModel(CandleStickData* data,QObject* parent):QAbstractTableModel(parent)
{
    if(data==nullptr){
        dati=*(new CandleStickData());
    }
    else
        dati=*data;
}

int CandleStickChartTableModel::rowCount(const QModelIndex &parent)const {
    if (parent.isValid())
        return 0;
    else
        return dati.getEntries();
}
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
    if(timestamp>dati.getTimeStampAt(row-1)){
        beginInsertRows(parent,row,row);
            dati.addRow(timestamp,open,high,low,close);
        endInsertRows();
        return true;
    }
    }
        return false;
}
bool CandleStickChartTableModel::removeRows(int row, int count, const QModelIndex &parent){
    beginRemoveRows(parent,row,row);
        dati.removeRow(row);
    endRemoveRows();
}
QVariant CandleStickChartTableModel::data(const QModelIndex &index, int role)const {
    if (role==Qt::DisplayRole){
        switch (index.column()) {
        case 0:
            return dati.getTimeStampAt(index.row());
            break;
        case 1:
            return dati.getOpenAt(index.row());
            break;
        case 2:
            return dati.getHighAt(index.row());
            break;
        case 3:
            return dati.getLowAt(index.row());
            break;
        case 4:
            return dati.getCloseAt(index.row());
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
            dati.setTimeStampAt(index.row(),value.toReal());
            break;
        case 1:
            dati.setOpenAt(index.row(),value.toReal());
            break;
        case 2:
            dati.setHighAt(index.row(),value.toReal());
            break;
        case 3:
            dati.setLowAt(index.row(),value.toReal());
            break;
        case 4:
            dati.setCloseAt(index.row(),value.toReal());
            break;
        default:
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


