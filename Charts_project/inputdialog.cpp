#include "inputdialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QFormLayout>


inputdialog::inputdialog(QWidget *parent): QDialog(parent)
{
    QFormLayout *lytMain = new QFormLayout(this);

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

QStringList inputdialog::getStrings(QWidget *parent, bool *ok)
{
    inputdialog *dialog = new inputdialog(parent);

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
