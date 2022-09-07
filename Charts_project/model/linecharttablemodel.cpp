#include "linecharttablemodel.h"

LineChartTableModel::LineChartTableModel(LineChartData* data,QObject *parent):QAbstractTableModel(parent)
{
    if(data==nullptr)
        dati=new LineChartData();
    else
        dati=data;
}

int LineChartTableModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        //return dati->getLines().size();
        return dati->getSets().size();
}

int LineChartTableModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    else
        //return dati->getLines().at(0).size();
        return dati->getSets().at(0).size();
}

QVariant LineChartTableModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole){
        //return dati->getLines()[index.row()][index.column()];
        return dati->getSets()[index.row()][index.column()];
    }


        return QVariant();
}

/*bool LineChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role==Qt::EditRole&&correctValue(index,value)){
        if(index.column()%2==1)
            dati->removeY(index.row(),index.column());
        //dati->setData(index.row(),index.column(),value.toInt());
        dati->setSets(index.row(),index.column(),value.toInt());
        emit dataChanged(index,index);
        if(index.column()%2!=0){
            int v=value.toInt();
            if(v<dati->getYAxisMinValue()||v>dati->getYAxisMaxValue()){
                dati->addY(v);
                emit minMaxChanged(dati->getYAxisMinValue(),dati->getYAxisMaxValue());
            }
            else
                dati->addY(v);
        }
        emit   updateAxis();
        return true;
    }
    else
        return false;
}*/

bool LineChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role==Qt::EditRole){
        if(index.column()!=0){
            dati->removeY(index.row(),index.column());
            dati->setSets(index.row(),index.column(),value.toInt());
        }
        emit dataChanged(index,index);

        /*Il codice all'interno dell'if potrebbe non funzionare dato che dipendeva precedentemente da
            funzioni che sono state ghostate (commentate/eliminate).*/
        if(index.column()!=0){
            int v=value.toInt();
            if(v<dati->getYAxisMinValue()||v>dati->getYAxisMaxValue()){
                dati->addY(v);
                emit minMaxChanged(dati->getYAxisMinValue(),dati->getYAxisMaxValue());
            }
            else
                dati->addY(v);
        }
        emit   updateAxis();
        return true;
    }
    else
        return false;
}

/*bool LineChartTableModel::correctValue(const QModelIndex &index,const QVariant &value)
{
    int temp=index.row()-1;
    int temp2=index.row()+1;
    bool correctness=true;
    if(index.column()%2==0){
            while(temp>-1){
                if(value<=dati->getSets()[temp][index.column()])
                    correctness=false;
                temp=temp-1;
            }
            while(temp2<dati->getSets().size()){
                if(value>=dati->getSets()[temp2][index.column()])
                    correctness=false;
                temp2=temp2+1;
            }
    }
    return correctness;
}*/

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
        dati->pushPoint(rowCount(), columnCount());
        //dati->pushSets(columnCount());
    }
    endInsertRows();
    return true;
}

/*bool LineChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent,column,column+1);
    for(int c=0;c<count;++c)
    {
        for(int i=0;i<rowCount();++i)
            dati->pushLine(i,i+1);
    }
    endInsertColumns();
    return true;
}*/

bool LineChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
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

bool LineChartTableModel::removeRows(int row, int count, const QModelIndex &parent){
    beginRemoveRows(parent,row,row);
        //dati->removePoints(row);
        dati->removeRow(row);
    endRemoveRows();
    return true;
}

/*bool LineChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column+count-1);
        //dati->removeLine(column+1);
        //dati->removeLine(column);
        dati->removeColumn(column+1);
        dati->removeColumn(column);
    dati->removeLineName(column);
    endRemoveColumns();
    return true;
}*/

bool LineChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column+count-1);
        dati->removeColumn(column);
        //dati->removeLineName(column);
    endRemoveColumns();
    return true;
}

QVariant LineChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section==0)
            return QString("X");
        else
            return QString("Y");
    }
    return QVariant();
}

