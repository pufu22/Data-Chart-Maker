#include "barcharttablemodel.h"

BarChartTableModel::BarChartTableModel(QObject* parent, Bar_data* data) : ChartTableModel(parent, data),
                                                                                                        barData(data) {}

bool BarChartTableModel::insertRows(int row, int count, const QModelIndex &) {

    beginInsertRows(QModelIndex(),row,row);
        for(int r = 0;r<count;++r)
            barData->pushData(columnCount());
    endInsertRows();
    return true;
}

bool BarChartTableModel::insertColumns(int column, int count, const QModelIndex &parent) {
    beginInsertColumns(parent,column,column);
        for(int c=0;c<count;++c)
            for(int i=0;i<rowCount();++i)
                barData->pushGroup(i);
    endInsertColumns();
    return true;
}

bool BarChartTableModel::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent,column,column);
        barData->removeGroup(column);
    endRemoveColumns();
    return true;
}

Qt::ItemFlags BarChartTableModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}

QVariant BarChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Vertical)
        return barData->getCategories().at(section);
    else if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        return barData->getNames().at(section);
    return QVariant();
}

bool BarChartTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if(role == Qt::EditRole && orientation == Qt::Vertical)
       barData->setCategories(value.toString(), section);
    if(role == Qt::EditRole && orientation == Qt::Horizontal)
        barData->setName(value.toString(), section);
    return true;
}
