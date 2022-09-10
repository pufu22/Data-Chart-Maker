#ifndef CHARTDATA_H
#define CHARTDATA_H

#include <QVector>

class ChartData {
protected:
    QString title;
    QVector<QVector<qreal>> data;

    virtual void dataInit() =0;
public:
    ChartData(const QString& m_title = "Titolo");

    QString getTitle() const;
    QVector<QVector<qreal>> getData() const;

    void setTitle(QString t);
    virtual void setData(int x,int y, qreal val);

    virtual void removeData(int pos);    /*Elimina una riga dalle tabelle e non la singola cella.*/
};

#endif // CHARTDATA_H
