/****************************************************************************
** Meta object code from reading C++ file 'candlestickchartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Charts_project/source/view/candlestickchartwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'candlestickchartwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CandleStickChartWidget_t {
    QByteArrayData data[9];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CandleStickChartWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CandleStickChartWidget_t qt_meta_stringdata_CandleStickChartWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "CandleStickChartWidget"
QT_MOC_LITERAL(1, 23, 9), // "salvaJson"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 18), // "cambiaTitoloSignal"
QT_MOC_LITERAL(4, 53, 6), // "titolo"
QT_MOC_LITERAL(5, 60, 16), // "cambiaTitoloSlot"
QT_MOC_LITERAL(6, 77, 15), // "aggiungiSetSlot"
QT_MOC_LITERAL(7, 93, 14), // "rimuoviSetSlot"
QT_MOC_LITERAL(8, 108, 10) // "chartFocus"

    },
    "CandleStickChartWidget\0salvaJson\0\0"
    "cambiaTitoloSignal\0titolo\0cambiaTitoloSlot\0"
    "aggiungiSetSlot\0rimuoviSetSlot\0"
    "chartFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CandleStickChartWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CandleStickChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CandleStickChartWidget *_t = static_cast<CandleStickChartWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->salvaJson(); break;
        case 1: _t->cambiaTitoloSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->cambiaTitoloSlot(); break;
        case 3: _t->aggiungiSetSlot(); break;
        case 4: _t->rimuoviSetSlot(); break;
        case 5: _t->chartFocus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (CandleStickChartWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CandleStickChartWidget::salvaJson)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CandleStickChartWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CandleStickChartWidget::cambiaTitoloSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject CandleStickChartWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CandleStickChartWidget.data,
      qt_meta_data_CandleStickChartWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CandleStickChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CandleStickChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CandleStickChartWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CandleStickChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CandleStickChartWidget::salvaJson()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CandleStickChartWidget::cambiaTitoloSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
