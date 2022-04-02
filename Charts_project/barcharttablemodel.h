#ifndef BARCHARTTABLEMODEL_H
#define BARCHARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <bar_data.h>
#include<QAbstractItemModel>
#include<vector>
#include<iostream>
class BarChartTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    BarChartTableModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumn(int column, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    Bar_data dati;
    void newData();
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);

};

#endif // BARCHARTTABLEMODEL_H
