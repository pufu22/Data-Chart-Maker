#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>

class inputdialog : public QDialog {
    Q_OBJECT
private:
    QList<QLineEdit*> fields;
public:
    inputdialog(QString type,QWidget *parent = nullptr);
    static QStringList getStrings(QWidget *parent,QString type, bool *ok = nullptr);
};

#endif // INPUTDIALOG_H
