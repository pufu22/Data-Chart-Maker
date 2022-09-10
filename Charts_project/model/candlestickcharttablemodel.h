#ifndef CANDLESTICKCHARTTABLEMODEL_H
#define CANDLESTICKCHARTTABLEMODEL_H

#include<data/candlestickdata.h>
#include<inputdialog.h>
class CandleStickChartTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    CandleStickChartTableModel(CandleStickData* data=nullptr,QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int row, int count, const QModelIndex &parent= QModelIndex());
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    CandleStickData dati;

};

#endif // CANDLESTICKCHARTTABLEMODEL_H
