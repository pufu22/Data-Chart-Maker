/****************************************************************************
** Meta object code from reading C++ file 'linechartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Charts_project/source/view/linechartwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'linechartwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LineChartWidget_t {
    QByteArrayData data[12];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LineChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LineChartWidget_t qt_meta_stringdata_LineChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LineChartWidget"
QT_MOC_LITERAL(1, 16, 5), // "linea"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "cambiaTitoloSignal"
QT_MOC_LITERAL(4, 42, 6), // "titolo"
QT_MOC_LITERAL(5, 49, 17), // "aggiungilineaSlot"
QT_MOC_LITERAL(6, 67, 17), // "aggiungipuntoSlot"
QT_MOC_LITERAL(7, 85, 14), // "togliLineaSlot"
QT_MOC_LITERAL(8, 100, 14), // "togliPuntoSlot"
QT_MOC_LITERAL(9, 115, 16), // "cambiaTitoloSlot"
QT_MOC_LITERAL(10, 132, 13), // "salvaJsonFile"
QT_MOC_LITERAL(11, 146, 10) // "chartFocus"

    },
    "LineChartWidget\0linea\0\0cambiaTitoloSignal\0"
    "titolo\0aggiungilineaSlot\0aggiungipuntoSlot\0"
    "togliLineaSlot\0togliPuntoSlot\0"
    "cambiaTitoloSlot\0salvaJsonFile\0"
    "chartFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LineChartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   63,    2, 0x08 /* Private */,
       6,    0,   64,    2, 0x08 /* Private */,
       7,    0,   65,    2, 0x08 /* Private */,
       8,    0,   66,    2, 0x08 /* Private */,
       9,    0,   67,    2, 0x08 /* Private */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LineChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LineChartWidget *_t = static_cast<LineChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->linea(); break;
        case 1: _t->cambiaTitoloSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->aggiungilineaSlot(); break;
        case 3: _t->aggiungipuntoSlot(); break;
        case 4: _t->togliLineaSlot(); break;
        case 5: _t->togliPuntoSlot(); break;
        case 6: _t->cambiaTitoloSlot(); break;
        case 7: _t->salvaJsonFile(); break;
        case 8: _t->chartFocus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (LineChartWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineChartWidget::linea)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LineChartWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LineChartWidget::cambiaTitoloSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LineChartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LineChartWidget.data,
      qt_meta_data_LineChartWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LineChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LineChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LineChartWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LineChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void LineChartWidget::linea()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LineChartWidget::cambiaTitoloSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
