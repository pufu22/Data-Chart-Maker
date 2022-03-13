#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreateChartWidget.h>
#include<QChartView>
#include<QChart>
#include<QMenu>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();

private:
    //CreateChartWidget createchart;
    QMenu* fileMenu;
    QMenu* editMenu;

};
#endif // MAINWINDOW_H
