#ifndef SELECTWINDOW_H
#define SELECTWINDOW_H
#include<QDialog>
#include<QLayout>
#include<QPushButton>
class selectWindow:public QDialog
{
    Q_OBJECT
public:
    selectWindow(QWidget* parent=0);
    ~selectWindow();

private:
    QLayout* lt;
    QPushButton* prima;
private signal:
    void creaLineChart();
};

#endif // SELECTWINDOW_H
