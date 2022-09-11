#ifndef CANDLESTICKCHARTTABLEMODEL_H
#define CANDLESTICKCHARTTABLEMODEL_H

#include "chartTableModel.h"
#include <source/data/candlestickdata.h>
#include <source/dialog/inputdialog.h>
#include <QMessageBox>

class CandleStickChartTableModel : public ChartTableModel {
    Q_OBJECT
private:
    CandleStickData* candleData;
public:
    CandleStickChartTableModel(QObject* parent=0, CandleStickData* data=new CandleStickData());

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // CANDLESTICKCHARTTABLEMODEL_H
