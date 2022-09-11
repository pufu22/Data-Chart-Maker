/****************************************************************************
** Meta object code from reading C++ file 'piechartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Charts_project/source/view/piechartwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piechartwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_piechartwidget_t {
    QByteArrayData data[9];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_piechartwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_piechartwidget_t qt_meta_stringdata_piechartwidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "piechartwidget"
QT_MOC_LITERAL(1, 15, 18), // "cambiaTitoloSignal"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 6), // "titolo"
QT_MOC_LITERAL(4, 42, 17), // "aggiungifettaslot"
QT_MOC_LITERAL(5, 60, 16), // "rimuovifettaslot"
QT_MOC_LITERAL(6, 77, 16), // "cambiaTitoloSlot"
QT_MOC_LITERAL(7, 94, 10), // "chartFocus"
QT_MOC_LITERAL(8, 105, 12) // "salvaJsonPie"

    },
    "piechartwidget\0cambiaTitoloSignal\0\0"
    "titolo\0aggiungifettaslot\0rimuovifettaslot\0"
    "cambiaTitoloSlot\0chartFocus\0salvaJsonPie"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_piechartwidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    0,   50,    2, 0x0a /* Public */,
       8,    0,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void piechartwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        piechartwidget *_t = static_cast<piechartwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cambiaTitoloSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->aggiungifettaslot(); break;
        case 2: _t->rimuovifettaslot(); break;
        case 3: _t->cambiaTitoloSlot(); break;
        case 4: _t->chartFocus(); break;
        case 5: _t->salvaJsonPie(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (piechartwidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&piechartwidget::cambiaTitoloSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject piechartwidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_piechartwidget.data,
      qt_meta_data_piechartwidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *piechartwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *piechartwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_piechartwidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int piechartwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void piechartwidget::cambiaTitoloSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
