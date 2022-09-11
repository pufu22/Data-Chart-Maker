#ifndef LINECHARTTABLEMODEL_H
#define LINECHARTTABLEMODEL_H

#include "chartTableModel.h"
#include <source/data/linechartdata.h>
#include <QInputDialog>

class LineChartTableModel : public ChartTableModel {
    Q_OBJECT
private:
    LineChartData* lineData;
public:
    LineChartTableModel(QObject* parent=nullptr, LineChartData* data=new LineChartData());

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent=QModelIndex()) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role=Qt::EditRole) override;
};

#endif // LINECHARTTABLEMODEL_H
