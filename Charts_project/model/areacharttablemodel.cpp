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
            dati->setData(index.row(),index.column(),value.toInt());
        }
        emit dataChanged(index,index);
        return true;
    }else
    return false;
}

Qt::ItemFlags AreaChartTableModel::flags(const QModelIndex &index) const
{
    if(index.column()!=0)
        return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
    else return Qt::NoItemFlags;
}

bool AreaChartTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row);
    for(int row =0;row<count;++row)
    {
        dati->pushData(columnCount());
    }
    endInsertRows();
    return true;
}

bool AreaChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    bool ok;
    QString areaName=QInputDialog::getText(nullptr,tr("Area"),tr("Nome area:"),QLineEdit::Normal,tr(""),&ok);
    if(ok&&areaName.trimmed()!=""){
        dati->pushName(areaName);
        beginInsertColumns(parent,column,column);
        for(int c=0;c<count;++c)
        {
            for(int i=0;i<rowCount();++i)
                dati->pushGroup(i);
        }
        endInsertColumns();
        return true;
        }
    return false;
}

bool AreaChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column+count-1);
        dati->removeGroup(column);
    endRemoveColumns();
}

bool AreaChartTableModel::removeRows(int row, int count, const QModelIndex &parent){
    beginRemoveRows(parent,row,row);
    dati->removeData(row);
    endRemoveRows();
}
QVariant AreaChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section==0)
            return QString("X");
        else
            return dati->getNames().at(section-1);

    }
    return QVariant();
}

bool AreaChartTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role){
    if(role == Qt::EditRole && orientation == Qt::Horizontal){
       dati->setName(value.toString(),section);
    }
}
