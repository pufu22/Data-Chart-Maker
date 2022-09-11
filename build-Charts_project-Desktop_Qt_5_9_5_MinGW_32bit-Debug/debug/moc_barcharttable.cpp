/****************************************************************************
** Meta object code from reading C++ file 'barcharttable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Charts_project/source/view/barcharttable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'barcharttable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_barcharttable_t {
    QByteArrayData data[12];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_barcharttable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_barcharttable_t qt_meta_stringdata_barcharttable = {
    {
QT_MOC_LITERAL(0, 0, 13), // "barcharttable"
QT_MOC_LITERAL(1, 14, 4), // "riga"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 18), // "cambiaTitoloSignal"
QT_MOC_LITERAL(4, 39, 6), // "titolo"
QT_MOC_LITERAL(5, 46, 12), // "aggiungiriga"
QT_MOC_LITERAL(6, 59, 15), // "aggiungicolonna"
QT_MOC_LITERAL(7, 75, 10), // "removebars"
QT_MOC_LITERAL(8, 86, 9), // "removeset"
QT_MOC_LITERAL(9, 96, 11), // "changetitle"
QT_MOC_LITERAL(10, 108, 12), // "salvaJsonBar"
QT_MOC_LITERAL(11, 121, 10) // "chartFocus"

    },
    "barcharttable\0riga\0\0cambiaTitoloSignal\0"
    "titolo\0aggiungiriga\0aggiungicolonna\0"
    "removebars\0removeset\0changetitle\0"
    "salvaJsonBar\0chartFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_barcharttable[] = {

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

void barcharttable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        barcharttable *_t = static_cast<barcharttable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->riga(); break;
        case 1: _t->cambiaTitoloSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->aggiungiriga(); break;
        case 3: _t->aggiungicolonna(); break;
        case 4: _t->removebars(); break;
        case 5: _t->removeset(); break;
        case 6: _t->changetitle(); break;
        case 7: _t->salvaJsonBar(); break;
        case 8: _t->chartFocus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (barcharttable::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&barcharttable::riga)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (barcharttable::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&barcharttable::cambiaTitoloSignal)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject barcharttable::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_barcharttable.data,
      qt_meta_data_barcharttable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *barcharttable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *barcharttable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_barcharttable.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int barcharttable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void barcharttable::riga()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void barcharttable::cambiaTitoloSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
