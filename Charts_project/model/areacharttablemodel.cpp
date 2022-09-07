#include "areacharttablemodel.h"

AreaChartTableModel::AreaChartTableModel(AreaChartData *data,QObject * parent):QAbstractTableModel(parent)
{
    if(data==nullptr){

        dati=new AreaChartData();
    }
    else
        dati=data;
}

int AreaChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati->getSets().size();
}

int AreaChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati->getSets().at(0).size();
}

QVariant AreaChartTableModel::data(const QModelIndex &index, int role) const
{


    if(role==Qt::DisplayRole){
        return dati->getSets()[index.row()][index.column()];
    }
    return QVariant();
}

bool AreaChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if(role==Qt::EditRole){
        if(index.column()!=0){
            dati->setSets(index.row(),index.column(),value.toInt());
        }
        emit dataChanged(index,index);
        return true;
    }else
    return false;
}

Qt::ItemFlags AreaChartTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}

bool AreaChartTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row);
    for(int row =0;row<count;++row)
    {
        dati->pushPoint(rowCount(), columnCount());
    }
    endInsertRows();
    return true;
}

bool AreaChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
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
