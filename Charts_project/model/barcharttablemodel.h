#ifndef BARCHARTTABLEMODEL_H
#define BARCHARTTABLEMODEL_H

#include "chartTableModel.h"
#include <data/bar_data.h>
#include<QAbstractItemModel>
#include<vector>
#include<QInputDialog>
class BarChartTableModel:public ChartTableModel
{
    Q_OBJECT
private:
    Bar_data* barData;
public:
    BarChartTableModel(QObject* parent=nullptr, Bar_data* data=new Bar_data());
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent=QModelIndex()) override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole) override;
};

#endif // BARCHARTTABLEMODEL_H
