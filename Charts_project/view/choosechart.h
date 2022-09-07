#ifndef CHOOSECHART_H
#define CHOOSECHART_H

#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QVBoxLayout>

class ChooseChart : public QWidget{
    Q_OBJECT
private:
    QLabel* label;
    QPixmap pic;
    QPushButton* button;
public:
    explicit ChooseChart(const QString& name, const QString& imgPath, QWidget* parent = nullptr);
private slots:
    void creaChartSlot();
signals:
    void creaChartSignal(QString name);
};

#endif // CHOOSECHART_H
