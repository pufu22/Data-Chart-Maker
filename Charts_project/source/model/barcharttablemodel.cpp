#include "barcharttablemodel.h"

BarChartTableModel::BarChartTableModel(QObject* parent, Bar_data* data) : ChartTableModel(parent, data), barData(data) {}

bool BarChartTableModel::insertRows(int row, int count, const QModelIndex &) {
    bool ok;
    QString cat=QInputDialog::getText(nullptr,tr("Aggiungi categoria"),tr("Categoria:"),QLineEdit::Normal,tr(" "),&ok);
    if(!barData->getCategories().contains(cat)) {
        if(ok && cat.trimmed()!=""){
            beginInsertRows(QModelIndex(),row,row);
                for(int r=0; r<count; ++r)
                {
                        barData->pushData(columnCount());
                        barData->pushCategory(cat);

                }
            endInsertRows();
            return true;
        }
        return false;
    }
    else
        QMessageBox::warning(nullptr,"Attenzione!","Categoria già esistente",QMessageBox::Ok);
    return false;
}

bool BarChartTableModel::insertColumns(int column, int count, const QModelIndex &parent) {
    bool ok;
    QString set=QInputDialog::getText(nullptr,tr("Aggiungi nome barra"),tr("Barra:"),QLineEdit::Normal,tr(" "),&ok);
    if(ok && set.trimmed()!= ""){
    beginInsertColumns(parent,column,column);
        for(int c=0;c<count;++c)
        {
            for(int i=0;i<rowCount();++i)
                barData->pushGroup(i);
            barData->pushName(set);
        }

        endInsertColumns();

            return true;
    }
    return false;
}

bool BarChartTableModel::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent,column,column);
        barData->removeGroup(column);
    endRemoveColumns();
    return true;
}

bool BarChartTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(role==Qt::EditRole){
        chartData->setData(index.row(),index.column(),value.toInt());
        emit dataChanged(index,index);
        return true;
    }
    else
        return false;
}

Qt::ItemFlags BarChartTableModel::flags(const QModelIndex &index) const {
    return QAbstractTableModel::flags(index)
            |Qt::ItemIsEditable;
}

QVariant BarChartTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Vertical)
        return barData->getCategories().at(section);
    else if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        return barData->getNames().at(section);
    return QVariant();
}

bool BarChartTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role) {
    if(role == Qt::EditRole && orientation == Qt::Vertical)
       barData->setCategories(value.toString(), section);
    if(role == Qt::EditRole && orientation == Qt::Horizontal)
        barData->setName(value.toString(), section);
    return true;
}
