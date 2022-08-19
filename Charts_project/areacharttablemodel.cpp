#include "areacharttablemodel.h"

AreaChartTableModel::AreaChartTableModel(AreaChartData *data,QObject * parent):QAbstractTableModel(parent)
{
    if(data==nullptr){

        dati=*(new AreaChartData());
    }
    else
        dati=*data;
}

int AreaChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati.getLines().size();
}

int AreaChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati.getLines().at(0).size();
}

QVariant AreaChartTableModel::data(const QModelIndex &index, int role) const
{


    if(role==Qt::DisplayRole){
        return dati.getLines()[index.row()][index.column()];
    }
    return QVariant();
}

bool AreaChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if(role==Qt::EditRole){
        dati.getLines()[index.row()][index.column()]=value.toInt();
        dati.setData(index.row(),index.column(),value.toInt());
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
        QVector<int> temp;
        temp.fill(0,columnCount());
        dati.getLines().push_back(temp);
    }
    endInsertRows();
    return true;
}

bool AreaChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent,column,column+1);

    for(int c=0;c<count;++c)
    {
        for(int i=0;i<rowCount();++i)
            dati.pushLine(i,i+1);
    }
    endInsertColumns();
return true;
}
