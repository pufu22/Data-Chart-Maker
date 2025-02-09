#include "chartModel.h"

ChartModel::ChartModel(ChartTableModel* m_tableModel) : tableModel(m_tableModel) {
    chart = new QChart;
    chart->setAnimationOptions(QChart::AllAnimations);
}

QChart* ChartModel::getChart() {
    return chart;
}

ChartTableModel* ChartModel::getTableModel() {
    return tableModel;
}

void ChartModel::updateTitle(QString title) {
    tableModel->getData()->setTitle(title);
    chart->setTitle(tableModel->getData()->getTitle());
}
