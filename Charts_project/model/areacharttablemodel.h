#ifndef AREACHARTTABLEMODEL_H
#define AREACHARTTABLEMODEL_H
#include<data/areachartdata.h>
#include "chartTableModel.h"
class AreaChartTableModel:public ChartTableModel
{
    Q_OBJECT
public:
    AreaChartTableModel(QObject* parent=nullptr, AreaChartData* data=new AreaChartData());
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex());
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const ;
private:
    AreaChartData* areaData;
};

#endif // AREACHARTTABLEMODEL_H
