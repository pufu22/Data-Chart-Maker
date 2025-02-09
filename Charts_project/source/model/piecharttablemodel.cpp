#include "piecharttablemodel.h"

Piecharttablemodel::Piecharttablemodel(QObject *parent, pie_data* data) : ChartTableModel(parent, data), pieData(data) {}


int Piecharttablemodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    else
        return 2;

}

bool Piecharttablemodel::insertRows(int row, int count, const QModelIndex &parent) {
    bool ok;
    QStringList list = inputdialog::getStrings(nullptr, "piechart", &ok);
    if (!pieData->getLabels().contains(list.at(0))) {
        if(ok){
            beginInsertRows(parent, row, row + count - 1);
                pieData->pushLabel(list.at(0));
                pieData->pushValue(list.at(1).toInt());
            endInsertRows();
            return true;
        }
        return false;
    }
    else
        QMessageBox::warning(nullptr,"Attenzione!","Label già presente.",QMessageBox::Ok);
    return false;
}

bool Piecharttablemodel::removeRows(int row,  int count, const QModelIndex &parent) {
    beginRemoveRows(parent,row-1,row+count-2);
        pieData->removeData(row);
    endRemoveRows();
    return true;
}

QVariant Piecharttablemodel::data(const QModelIndex &index, int role) const {
    if (role==Qt::DisplayRole) {
        if(index.column()==0)
            return pieData->getLabels().at(index.row());
        else
            return pieData->getValues().at(index.row());
    }
    return QVariant();
}

bool Piecharttablemodel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (data(index, role) != value) {
        if(index.column()==0)
            if (!pieData->getLabels().contains(value.toString()))
                pieData->setLabel(index.row(),value.toString());
            else {
                QMessageBox::warning(nullptr,"Attenzione!","Label già presente.",QMessageBox::Ok);
                return false;
            }
        else
            pieData->setData(index.row(), index.column(), value.toUInt());
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags Piecharttablemodel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
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
