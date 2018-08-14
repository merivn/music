/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_network_t {
    QByteArrayData data[11];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_network_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_network_t qt_meta_stringdata_network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "network"
QT_MOC_LITERAL(1, 8, 17), // "sig_reqSongStatus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 10), // "ItemResult"
QT_MOC_LITERAL(4, 38, 12), // "SearchStatus"
QT_MOC_LITERAL(5, 51, 18), // "sig_reqSongStatus2"
QT_MOC_LITERAL(6, 70, 12), // "sig_setBgpix"
QT_MOC_LITERAL(7, 83, 6), // "author"
QT_MOC_LITERAL(8, 90, 10), // "sig_seturl"
QT_MOC_LITERAL(9, 101, 17), // "dolrcworkfinished"
QT_MOC_LITERAL(10, 119, 10) // "striderror"

    },
    "network\0sig_reqSongStatus\0\0ItemResult\0"
    "SearchStatus\0sig_reqSongStatus2\0"
    "sig_setBgpix\0author\0sig_seturl\0"
    "dolrcworkfinished\0striderror"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    2,   49,    2, 0x06 /* Public */,
       6,    2,   54,    2, 0x06 /* Public */,
       8,    1,   59,    2, 0x06 /* Public */,
       9,    2,   62,    2, 0x06 /* Public */,
      10,    0,   67,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,    2,    7,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QByteArray, QMetaType::QString,    2,    2,
    QMetaType::Void,

       0        // eod
};

void network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        network *_t = static_cast<network *>(_o);
        switch (_id) {
        case 0: _t->sig_reqSongStatus((*reinterpret_cast< const ItemResult(*)>(_a[1])),(*reinterpret_cast< SearchStatus(*)>(_a[2]))); break;
        case 1: _t->sig_reqSongStatus2((*reinterpret_cast< const ItemResult(*)>(_a[1])),(*reinterpret_cast< SearchStatus(*)>(_a[2]))); break;
        case 2: _t->sig_setBgpix((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->sig_seturl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->dolrcworkfinished((*reinterpret_cast< const QByteArray(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 5: _t->striderror(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (network::*_t)(const ItemResult & , SearchStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::sig_reqSongStatus)) {
                *result = 0;
            }
        }
        {
            typedef void (network::*_t)(const ItemResult & , SearchStatus );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::sig_reqSongStatus2)) {
                *result = 1;
            }
        }
        {
            typedef void (network::*_t)(const QStringList & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::sig_setBgpix)) {
                *result = 2;
            }
        }
        {
            typedef void (network::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::sig_seturl)) {
                *result = 3;
            }
        }
        {
            typedef void (network::*_t)(const QByteArray & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::dolrcworkfinished)) {
                *result = 4;
            }
        }
        {
            typedef void (network::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&network::striderror)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject network::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network.data,
      qt_meta_data_network,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *network::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_network.stringdata))
        return static_cast<void*>(const_cast< network*>(this));
    return QObject::qt_metacast(_clname);
}

int network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void network::sig_reqSongStatus(const ItemResult & _t1, SearchStatus _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void network::sig_reqSongStatus2(const ItemResult & _t1, SearchStatus _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void network::sig_setBgpix(const QStringList & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void network::sig_seturl(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void network::dolrcworkfinished(const QByteArray & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void network::striderror()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
