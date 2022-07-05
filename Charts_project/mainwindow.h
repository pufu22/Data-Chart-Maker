#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CreateChartWidget.h>
#include<QChartView>
#include<QChart>
#include<QMenu>
#include<linechartwidget.h>
#include<selectwindow.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createMenus();
    void createActions();
    void creaPieChartFromFile(const QJsonObject &json);
private:
    //CreateChartWidget createchart;
    QMenu* fileMenu;
    QMenu* openMenu;
    QAction* newAct;
    QAction* openAct;
    selectWindow* selezionaTipo;
private slots:
    void nuovoGrafico();
    bool apriFile();
public slots:
    void creaBarChart();
    void creaLineChart();

};
#endif // MAINWINDOW_H
