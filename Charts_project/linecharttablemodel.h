#ifndef LINECHARTTABLEMODEL_H
#define LINECHARTTABLEMODEL_H

#include<QAbstractTableModel>
#include<linechartdata.h>
class LineChartTableModel:public QAbstractTableModel
{
    private:
        Q_OBJECT

public:
    LineChartTableModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);
    LineChartData dati;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool correctValue(const QModelIndex &index,const QVariant &value);
    int maxValue=0;
signals:
    changeRange(int maxValue);
};

#endif // LINECHARTTABLEMODEL_H
