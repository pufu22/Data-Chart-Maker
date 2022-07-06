#include "barcharttablemodel.h"

BarChartTableModel::BarChartTableModel(QObject *parent):QAbstractTableModel(parent)
{
    dati=*(new Bar_data());
}
BarChartTableModel::BarChartTableModel(Bar_data *data, QObject *parent):QAbstractTableModel(parent)
{
    dati=*data;
}
int BarChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;

    return dati.sets.size();
}

int BarChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    return dati.sets.at(0).size();
}

QVariant BarChartTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
           return dati.sets[index.row()][index.column()];

        return QVariant();

}

bool BarChartTableModel::setData(const QModelIndex &index,const QVariant &value,int role)
{
    if(role==Qt::EditRole){
            dati.sets[index.row()][index.column()]=value.toInt();
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
    for(int row = 0;row<count;++row)
    {
        std::vector<int> temp;
        temp.resize(columnCount());
        std::fill(temp.begin(),temp.end(),1);
        dati.sets.push_back(temp);
        dati.categories.push_back("2");
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
            dati.sets[i].push_back(i+1);
        dati.categories.push_back("e");
    }
    endInsertColumns();
    return true;

}
