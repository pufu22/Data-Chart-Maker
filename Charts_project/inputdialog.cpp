#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>


inputdialog::inputdialog(QString type,QWidget *parent): QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);
    if(type=="piechart")
    for (int i = 0; i < 2; ++i)
    {
        QLabel *tLabel;
        if(i==0)
             tLabel= new QLabel(QString("Etichetta").arg(i), this);
        else
            tLabel = new QLabel(QString("Valore").arg(i), this);
        QLineEdit *tLine = new QLineEdit(this);
        lytMain->addRow(tLabel, tLine);

        fields << tLine;
    }
    if(type=="candlestickchart")
        for(int i = 0; i<5; ++i){
            QLabel *tLabel;
            switch(i){
            case 0:tLabel=new QLabel(QString("Timestamp"),this);
                break;
            case 1:tLabel=new QLabel(QString("Open"),this);
                break;
            case 2:tLabel=new QLabel(QString("High"),this);
                break;
            case 3:tLabel=new QLabel(QString("Low"),this);
                break;
            case 4:tLabel=new QLabel(QString("Close"),this);
                break;
            }
            QLineEdit *tLine = new QLineEdit(this);
            lytMain->addRow(tLabel,tLine);
            fields<<tLine;
        }
    QDialogButtonBox *buttonBox = new QDialogButtonBox
            ( QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
              Qt::Horizontal, this );
    lytMain->addWidget(buttonBox);

    bool conn = connect(buttonBox, &QDialogButtonBox::accepted,
                   this, &inputdialog::accept);
    Q_ASSERT(conn);
    conn = connect(buttonBox, &QDialogButtonBox::rejected,
                   this, &inputdialog::reject);
    Q_ASSERT(conn);

    setLayout(lytMain);
}

QStringList inputdialog::getStrings(QWidget *parent,QString type, bool *ok)
{
    inputdialog *dialog = new inputdialog(type,parent);

    QStringList list;

    const int ret = dialog->exec();
    if (ok)
        *ok = !!ret;

    if (ret) {
        foreach (auto field, dialog->fields) {
            list << field->text();
        }
    }

    dialog->deleteLater();

    return list;
}
