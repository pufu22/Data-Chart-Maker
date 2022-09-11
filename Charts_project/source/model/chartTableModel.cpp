#include "chartTableModel.h"

ChartTableModel::ChartTableModel(QObject* parent, ChartData* m_data) : QAbstractTableModel(parent), chartData(m_data) {}

ChartData* ChartTableModel::getData() const {
    return chartData;
}

int ChartTableModel::rowCount(const QModelIndex& parent) const {
    if(parent.isValid())
        return 0;
    else
        return chartData->getData().size();
}

int ChartTableModel::columnCount(const QModelIndex& parent) const {
    if(parent.isValid())
        return 0;
    else
        return chartData->getData().at(0).size();
}

bool ChartTableModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent,row,row);
        chartData->removeData(row);
    endRemoveRows();
    return true;
}

QVariant ChartTableModel::data(const QModelIndex &index, int role) const {
    if(role==Qt::DisplayRole)
        return chartData->getData().at(index.row()).at(index.column());
    return QVariant();
}

bool ChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role==Qt::EditRole){
        if(index.column()!=0){
            chartData->setData(index.row(),index.column(),value.toInt());
        }
        emit dataChanged(index,index);
        return true;
    }
    else
        return false;
}
