#ifndef BARCHARTTABLEMODEL_H
#define BARCHARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <bar_data.h>
#include<QAbstractItemModel>
#include<vector>
#include<iostream>
#include<QInputDialog>
class BarChartTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    BarChartTableModel(QObject *parent=0);
    BarChartTableModel(Bar_data* data,QObject* parent=0);
    //BarChartTableModel(comparisonChartData* data,QObject* parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumn(int column, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count,const QModelIndex &parent = QModelIndex());
    bool removeColumn(int column, const QModelIndex &parent=QModelIndex());
    bool removeRow(int row,  const QModelIndex &parent=QModelIndex());
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole);
    Bar_data* dati;
    //comparisonChartData* dati;
    void newData();
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);
signals:
    void minMaxChanged(int min,int max);
};

#endif // BARCHARTTABLEMODEL_H
