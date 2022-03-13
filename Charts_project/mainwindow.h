#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreateChartWidget.h>
#include<QChartView>
#include<QChart>
#include<QMenu>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();

private:
    //CreateChartWidget createchart;
    Ui::MainWindow *ui;
    QMenu* fileMenu;


};
#endif // MAINWINDOW_H
