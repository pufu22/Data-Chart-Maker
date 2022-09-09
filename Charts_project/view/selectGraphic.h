#ifndef SELECTGRAPHIC_H
#define SELECTGRAPHIC_H

#include <view/choosechart.h>
#include <QMap>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QGridLayout>

class SelectGraphic : public QWidget {
    Q_OBJECT

private:
    QMap<QString, QString> map;   //togliere il puntatore
    ChooseChart* chart;
public:
    explicit SelectGraphic(QWidget* parent = nullptr);
    QMap<QString, QString> getChartImages();  //togliere il puntatore
signals:
    void createChart(QString name);
};

#endif // SELECTGRAPHIC_H
