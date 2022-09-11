#ifndef SELECTGRAPHIC_H
#define SELECTGRAPHIC_H

#include "choosechart.h"
#include <QMap>
#include <QWidget>

class SelectGraphic : public QWidget {
    Q_OBJECT

private:
    QMap<QString, QString> map;
    ChooseChart* chart;
public:
    explicit SelectGraphic(QWidget* parent = nullptr);
    QMap<QString, QString> getChartImages();
signals:
    void createChart(QString name);
};

#endif // SELECTGRAPHIC_H
