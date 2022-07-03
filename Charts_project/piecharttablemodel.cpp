#include "piecharttablemodel.h"

Piecharttablemodel::Piecharttablemodel(QObject *parent)
    : QAbstractTableModel(parent)
{
    dati=*(new pie_data());
}




int Piecharttablemodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return dati.etichette.size();

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
            //overhead nel convertire std::string a QString ma non c'è altra soluzione visto che QVariant non ha costruttori con std::string
            return QString::fromStdString(dati.etichette.at(index.row()));
        else
            return dati.valori.at(index.row());
    }



    return QVariant();
}

bool Piecharttablemodel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        if(index.column()==0)
            dati.etichette.at(index.row())=value.toString().toStdString();
        else
            dati.valori.at(index.row())=value.toInt();
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
    dati.etichette.push_back(" ");
    dati.valori.push_back(0);
    endInsertRows();
}



