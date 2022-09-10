#ifndef PIECHARTTABLEMODEL_H
#define PIECHARTTABLEMODEL_H

#include <QAbstractTableModel>
#include <pie_data.h>
#include<inputdialog.h>
class Piecharttablemodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit Piecharttablemodel(pie_data* d=nullptr,QObject *parent = 0);
    // Header:


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // Fetch data dynamically:


    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());


    bool removeRows(int row,int count, const QModelIndex &parent=QModelIndex()) ;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    pie_data* dati;
private:
};

#endif // PIECHARTTABLEMODEL_H
