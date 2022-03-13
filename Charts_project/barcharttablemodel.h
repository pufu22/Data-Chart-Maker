#ifndef BARCHARTTABLEMODEL_H
#define BARCHARTTABLEMODEL_H

#include <QAbstractTableModel>
class BarChartTableModel:public QAbstractTableModel
{
    Q_OBJECT
public:
    BarChartTableModel(QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex())const override;
    int columnCount(const QModelIndex &parent = QModelIndex())const override;
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole)const override;
};

#endif // BARCHARTTABLEMODEL_H
