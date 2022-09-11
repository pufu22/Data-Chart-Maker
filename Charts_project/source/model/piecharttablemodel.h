#ifndef PIECHARTTABLEMODEL_H
#define PIECHARTTABLEMODEL_H

#include "chartTableModel.h"
#include <source/data/pie_data.h>
#include <source/dialog/inputdialog.h>
#include <QMessageBox>

class Piecharttablemodel : public ChartTableModel {
    Q_OBJECT
private:
    pie_data* pieData;
public:
    explicit Piecharttablemodel(QObject *parent=nullptr, pie_data* data=new pie_data());

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row,  int count, const QModelIndex &parent=QModelIndex()) override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // PIECHARTTABLEMODEL_H
