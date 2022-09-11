#include "areacharttablemodel.h"

AreaChartTableModel::AreaChartTableModel(QObject* parent, AreaChartData* data) : ChartTableModel(parent, data), areaData(data) {}

bool AreaChartTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row);
        for(int i =0;i<count;++i)
            areaData->pushData(columnCount());
    endInsertRows();
    return true;
}

bool AreaChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    bool ok;
    QString areaName=QInputDialog::getText(nullptr,tr("Area"),tr("Nome area:"),QLineEdit::Normal,tr(""),&ok);
    if(ok&&areaName.trimmed()!=""){
        areaData->pushName(areaName);
        beginInsertColumns(parent,column,column);
        for(int c=0;c<count;++c) {
            for(int i=0;i<rowCount();++i)
                areaData->pushGroup(i);
        }
        endInsertColumns();
        return true;
    }
    return false;
}

bool AreaChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column+count-1);
        areaData->removeGroup(column);
    endRemoveColumns();
    return true;
}

bool AreaChartTableModel::setData(const QModelIndex &index,const QVariant &value,int role) {
    if(role==Qt::EditRole){
        if(index.column()!=0){
            if(index.column()!=1){
                if(value.toInt() >= chartData->getData().at(index.row()).at(index.column()-1))
                    chartData->setData(index.row(),index.column(),value.toInt());
                else
                    QMessageBox::warning(nullptr,"Attenzione!","Il punto deve essere maggiore di quello precedente.",QMessageBox::Ok);
            }
            else
                chartData->setData(index.row(),index.column(),value.toInt());
        }
        emit dataChanged(index,index);
        return true;
    }
    else
        return false;
}

Qt::ItemFlags AreaChartTableModel::flags(const QModelIndex &index) const {
    if(index.column()!=0)
        return QAbstractTableModel::flags(index)
                |Qt::ItemIsEditable;
    else
        return QAbstractTableModel::flags(index)
                |Qt::NoItemFlags;
}

QVariant AreaChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section==0)
            return QString("X");
        else
            return areaData->getNames().at(section-1);
    }
    return QVariant();
}

bool AreaChartTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role){
    if(role == Qt::EditRole && orientation == Qt::Horizontal)
        areaData->setName(value.toString(), section);
    return true;
}
