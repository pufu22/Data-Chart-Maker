#ifndef AREACHARTTABLEMODEL_H
#define AREACHARTTABLEMODEL_H

#include "chartTableModel.h"
#include <source/data/areachartdata.h>
#include <QInputDialog>
#include <QMessageBox>

class AreaChartTableModel : public ChartTableModel {
    Q_OBJECT
private:
    AreaChartData* areaData;
public:
    AreaChartTableModel(QObject* parent=nullptr, AreaChartData* data=new AreaChartData());

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent=QModelIndex()) override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole) override;
};

#endif // AREACHARTTABLEMODEL_H
