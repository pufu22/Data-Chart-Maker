#include "linecharttablemodel.h"

LineChartTableModel::LineChartTableModel(QObject* parent, LineChartData* data) : ChartTableModel(parent, data), lineData(data) {}

bool LineChartTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent,row,row);
    for(int i =0;i<count;++i)
        lineData->pushData(columnCount());
    endInsertRows();
    return true;
}

bool LineChartTableModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    bool ok;
    QString nomeLinea = QInputDialog::getText(nullptr, tr("Titolo"), tr("Titolo:"), QLineEdit::Normal, tr(""), &ok);
    if(ok && nomeLinea.trimmed()!=""){
        beginInsertColumns(parent,column,column);
        for(int c=0;c<count;++c)
            for(int i=0;i<rowCount();++i)
                lineData->pushGroup(i);
        lineData->pushName(nomeLinea);
        endInsertColumns();
        return true;
    }
    return false;
}

bool LineChartTableModel::removeColumns(int column, int count, const QModelIndex &parent){
    beginRemoveColumns(parent,column,column+count-1);
        lineData->removeGroup(column);
    endRemoveColumns();
    return true;
}

Qt::ItemFlags LineChartTableModel::flags(const QModelIndex &index) const {
    if(index.column()!=0)
        return QAbstractTableModel::flags(index)
                |Qt::ItemIsEditable;
    else
        return QAbstractTableModel::flags(index)
                |Qt::NoItemFlags;
}

QVariant LineChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section==0)
            return QString("X");
        else
            return lineData->getNames().at(section-1);
    }
    return QVariant();
}

bool LineChartTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if(role == Qt::EditRole && orientation == Qt::Horizontal)
       lineData->setName(value.toString(), section);
    return true;
}

