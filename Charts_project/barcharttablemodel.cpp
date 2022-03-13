#include "barcharttablemodel.h"

BarChartTableModel::BarChartTableModel(QObject *parent):QAbstractTableModel(parent)
{
}

int BarChartTableModel::rowCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

int BarChartTableModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 3;
}

QVariant BarChartTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
           return QString("Row%1, Column%2")
                       .arg(index.row() + 1)
                       .arg(index.column() +1);

        return QVariant();

}
