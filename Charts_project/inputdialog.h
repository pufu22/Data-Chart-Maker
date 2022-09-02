#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
class inputdialog:public QDialog
{
    Q_OBJECT
public:
    inputdialog(QWidget *parent = nullptr);
    static QStringList getStrings(QWidget *parent, bool *ok = nullptr);
private:
    QList<QLineEdit*> fields;
};

#endif // INPUTDIALOG_H
