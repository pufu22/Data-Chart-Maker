#ifndef AREACHARTTABLEMODEL_H
#define AREACHARTTABLEMODEL_H
#include<data/areachartdata.h>
#include<QAbstractTableModel>
class AreaChartTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    AreaChartTableModel(AreaChartData* data=nullptr,QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumn(int column, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole);
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);
    AreaChartData* dati;
};

#endif // AREACHARTTABLEMODEL_H
