#include "linecharttablemodel.h"

LineChartTableModel::LineChartTableModel(LineChartData* data,QObject *parent):QAbstractTableModel(parent)
{
    if(data==nullptr)
        dati=*(new LineChartData());
    else
        dati=*data;
}

int LineChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati.lineseries.size();
}

int LineChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        return dati.lineseries.at(0).size();
}

QVariant LineChartTableModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole)
        return dati.lineseries[index.row()][index.column()];

        return QVariant();
}

bool LineChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role==Qt::EditRole&&correctValue(index,value)){
        if(value.toInt()>maxValue)
            maxValue=value.toInt();
        dati.lineseries[index.row()][index.column()]=value.toInt();
        emit dataChanged(index,index);
        emit changeRange(maxValue);
        return true;
    }
    else
        return false;
}


bool LineChartTableModel::correctValue(const QModelIndex &index,const QVariant &value)
{
    int temp=index.row()-1;
    int temp2=index.row()+1;
    bool correctness=true;
    if(index.column()%2==0){
            while(temp>-1){
                if(value<=dati.lineseries[temp][index.column()])
                    correctness=false;
                temp=temp-1;
            }
            while(temp2<dati.lineseries.size()){
                if(value>=dati.lineseries[temp2][index.column()])
                    correctness=false;
                temp2=temp2+1;
            }
    }
    return correctness;


}
Qt::ItemFlags LineChartTableModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}

bool LineChartTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row);
    for(int row =0;row<count;++row)
    {
        std::vector<int> temp;
        temp.resize(columnCount());
        std::fill(temp.begin(),temp.end(),0);
        dati.lineseries.push_back(temp);
    }
    endInsertRows();
    return true;
}

bool LineChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent,column,column+1);
    for(int c=0;c<count;++c)
    {
        for(int i=0;i<rowCount();++i)
            dati.lineseries[i].push_back(i+1);
    }
    endInsertColumns();
    return true;
}

QVariant LineChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section%2==0)
            return QString("X");
        else
            return QString("Y");
    }
    return QVariant();
}

