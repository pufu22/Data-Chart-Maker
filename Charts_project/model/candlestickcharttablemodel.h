#ifndef CANDLESTICKCHARTTABLEMODEL_H
#define CANDLESTICKCHARTTABLEMODEL_H
#include<model/charttablemodel.h>
#include<data/candlestickdata.h>
#include<inputdialog.h>
class CandleStickChartTableModel:public ChartTableModel
{
    Q_OBJECT
public:
    CandleStickChartTableModel(QObject* parent=0, CandleStickData* data=new CandleStickData());
    int columnCount(const QModelIndex &parent)const;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    //bool removeRows(int row, int count, const QModelIndex &parent= QModelIndex());
    Qt::ItemFlags flags(const QModelIndex &index) const ;
    bool setData(const QModelIndex &index,const QVariant &value,int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role)const override;
private:
    CandleStickData* candleData;

};

#endif // CANDLESTICKCHARTTABLEMODEL_H
