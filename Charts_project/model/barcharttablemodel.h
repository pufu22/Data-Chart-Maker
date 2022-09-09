#ifndef BARCHARTTABLEMODEL_H
#define BARCHARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <data/bar_data.h>
#include<QAbstractItemModel>
#include<vector>
#include<iostream>
#include<QInputDialog>
class BarChartTableModel:public QAbstractTableModel {
    Q_OBJECT
public:
    Bar_data* dati;
    //comparisonChartData* dati;

    BarChartTableModel(QObject *parent=0);
    BarChartTableModel(Bar_data* data,QObject* parent=0);
    //BarChartTableModel(comparisonChartData* data,QObject* parent=0);

    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row,  int count, const QModelIndex &parent=QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent=QModelIndex()) override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // BARCHARTTABLEMODEL_H
