#ifndef CHARTMODEL_H
#define CHARTMODEL_H

#include "ChartTableModel.h"
#include <QObject>
#include <QtCharts>

class ChartModel : public QObject {
    Q_OBJECT
protected:
    ChartTableModel* tableModel;
    QChart* chart;
public:
    ChartModel(ChartTableModel* m_tableModel);

    QChart* getChart();
    virtual void updateInsertRow() {}
    virtual void updateInsertColumn() {}
    virtual void updateRemoveRow(int pos) {}
    virtual void updateRemoveColumn(int pos) {}
public slots:
    void updateTitle(QString title);
    virtual void updateAxisY() {}
    virtual void salvaJson() =0;
};

#endif // CHARTMODEL_H
