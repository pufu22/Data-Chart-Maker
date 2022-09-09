#include "barcharttablemodel.h"

BarChartTableModel::BarChartTableModel(QObject *parent):QAbstractTableModel(parent)
{
    dati=new Bar_data();
}
BarChartTableModel::BarChartTableModel(Bar_data *data,/*comparisonChartData* data,*/ QObject *parent):QAbstractTableModel(parent)
{
    dati=data;
}
int BarChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return dati->getSets().size();
}

int BarChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return dati->getSets().at(0).size();
}

QVariant BarChartTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return dati->getSets()[index.row()][index.column()];

        return QVariant();

}

bool BarChartTableModel::setData(const QModelIndex &index,const QVariant &value,int role)
{
    if(role==Qt::EditRole){
            dati->setData(index.row(),index.column(),value.toInt());
        emit dataChanged(index,index);
        return true;
    }
    else
        return false;
}

Qt::ItemFlags BarChartTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}


bool BarChartTableModel::insertRows(int row, int count, const QModelIndex &)
{

    beginInsertRows(QModelIndex(),row,row);
        for(int r = 0;r<count;++r)
        {
            dati->pushData(columnCount());
        }

    endInsertRows();
        return true;

}

bool BarChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent,column,column);
    for(int c=0;c<count;++c)
    {
        for(int i=0;i<rowCount();++i)
            dati->pushGroup(i);
    }

    endInsertColumns();

        return true;

}

bool BarChartTableModel::removeRows(int row, int count, const QModelIndex &parent){
    beginRemoveRows(parent,row,row);
    dati->removeData(row);
    endRemoveRows();
    return true;
}

bool BarChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column);
    dati->removeGroup(column);
    endRemoveColumns();
    return true;
}


QVariant BarChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {
        return dati->getCategories()[section];
    }
    else if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        return dati->getNames()[section];
    }
    return QVariant();
}

