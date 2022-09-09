#include "piecharttablemodel.h"

Piecharttablemodel::Piecharttablemodel(QObject *parent,pie_data* d)
    : QAbstractTableModel(parent)
{
    if(d==0)
        dati=*(new pie_data());
    else
        dati=*d;
}



int Piecharttablemodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return dati.getLabels().size();

}

int Piecharttablemodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return 2;

}





QVariant Piecharttablemodel::data(const QModelIndex &index, int role) const
{
    if (role==Qt::DisplayRole){
        if(index.column()==0)

            return dati.getLabels().at(index.row());
        else
            return dati.getValues().at(index.row());
    }



    return QVariant();
}

bool Piecharttablemodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if(index.column()==0)
            dati.setLabel(index.row(),value.toString());
        else
            dati.setData(index.row(), index.column(), value.toInt());
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags Piecharttablemodel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}
bool Piecharttablemodel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    //dati.pushLabel(eti);
    //dati.pushValue(val);
    endInsertRows();
    return true;
}

bool Piecharttablemodel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent,row-1,row-1);
    dati.removeData(row);
    endRemoveRows();
    return true;
}

QVariant Piecharttablemodel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if(section%2==0)
            return QString("Etichetta");
        else
            return QString("Valore");
    }
    else if(role == Qt::DisplayRole && orientation == Qt::Vertical){
        return section+1;
    }
    return QVariant();
}
