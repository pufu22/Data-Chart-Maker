#ifndef AREACHARTTABLEMODEL_H
#define AREACHARTTABLEMODEL_H
#include<data/areachartdata.h>
#include<QAbstractTableModel>
class AreaChartTableModel:public QAbstractTableModel {
    Q_OBJECT
private:
    AreaChartData* dati;
public:
    AreaChartTableModel(AreaChartData* data=nullptr,QObject *parent=0);

    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
    bool setData(const QModelIndex &index,const QVariant &value,int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};

#endif // AREACHARTTABLEMODEL_H
