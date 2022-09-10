#ifndef CHARTTABLEMODEL_H
#define CHARTTABLEMODEL_H

#include <data/chartData.h>
#include <QAbstractTableModel>

class ChartTableModel : public QAbstractTableModel {
protected:
    ChartData* chartData;
public:
    ChartTableModel(QObject* parent=nullptr, ChartData* m_data=nullptr);

    ChartData* getData() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    bool removeRows(int row,  int count, const QModelIndex &parent=QModelIndex()) override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
};

#endif // CHARTTABLEMODEL_H
