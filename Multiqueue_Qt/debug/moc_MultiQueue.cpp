/****************************************************************************
** Meta object code from reading C++ file 'MultiQueue.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Code/MultiQueue.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultiQueue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata__Enter__t {
    QByteArrayData data[6];
    char stringdata[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata__Enter__t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata__Enter__t qt_meta_stringdata__Enter_ = {
    {
QT_MOC_LITERAL(0, 0, 7), // "_Enter_"
QT_MOC_LITERAL(1, 8, 7), // "sendMsg"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "msg"
QT_MOC_LITERAL(4, 21, 8), // "sendTime"
QT_MOC_LITERAL(5, 30, 1) // "t"

    },
    "_Enter_\0sendMsg\0\0msg\0sendTime\0t"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data__Enter_[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       4,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void _Enter_::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        _Enter_ *_t = static_cast<_Enter_ *>(_o);
        switch (_id) {
        case 0: _t->sendMsg((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (_Enter_::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&_Enter_::sendMsg)) {
                *result = 0;
            }
        }
        {
            typedef void (_Enter_::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&_Enter_::sendTime)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject _Enter_::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata__Enter_.data,
      qt_meta_data__Enter_,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *_Enter_::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *_Enter_::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata__Enter_.stringdata))
        return static_cast<void*>(const_cast< _Enter_*>(this));
    return QThread::qt_metacast(_clname);
}

int _Enter_::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void _Enter_::sendMsg(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void _Enter_::sendTime(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
