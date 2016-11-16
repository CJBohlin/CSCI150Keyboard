/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../keyboard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Keyboard_t {
    QByteArrayData data[18];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Keyboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Keyboard_t qt_meta_stringdata_Keyboard = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Keyboard"
QT_MOC_LITERAL(1, 9, 17), // "specialKeyClicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "key"
QT_MOC_LITERAL(4, 32, 10), // "keyClicked"
QT_MOC_LITERAL(5, 43, 4), // "text"
QT_MOC_LITERAL(6, 48, 12), // "showKeyboard"
QT_MOC_LITERAL(7, 61, 7), // "globalX"
QT_MOC_LITERAL(8, 69, 7), // "globalY"
QT_MOC_LITERAL(9, 77, 6), // "themes"
QT_MOC_LITERAL(10, 84, 13), // "QApplication&"
QT_MOC_LITERAL(11, 98, 3), // "app"
QT_MOC_LITERAL(12, 102, 6), // "border"
QT_MOC_LITERAL(13, 109, 8), // "QString&"
QT_MOC_LITERAL(14, 118, 5), // "color"
QT_MOC_LITERAL(15, 124, 12), // "hideKeyboard"
QT_MOC_LITERAL(16, 137, 15), // "keyboardVisible"
QT_MOC_LITERAL(17, 153, 13) // "buttonClicked"

    },
    "Keyboard\0specialKeyClicked\0\0key\0"
    "keyClicked\0text\0showKeyboard\0globalX\0"
    "globalY\0themes\0QApplication&\0app\0"
    "border\0QString&\0color\0hideKeyboard\0"
    "keyboardVisible\0buttonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Keyboard[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   55,    2, 0x0a /* Public */,
       9,    3,   60,    2, 0x0a /* Public */,
      15,    0,   67,    2, 0x0a /* Public */,
      16,    0,   68,    2, 0x0a /* Public */,
      17,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, 0x80000000 | 13,   11,   12,   14,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Keyboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Keyboard *_t = static_cast<Keyboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->specialKeyClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->keyClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->showKeyboard((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->themes((*reinterpret_cast< QApplication(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->hideKeyboard(); break;
        case 5: { bool _r = _t->keyboardVisible();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->buttonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Keyboard::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Keyboard::specialKeyClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Keyboard::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Keyboard::keyClicked)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Keyboard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Keyboard.data,
      qt_meta_data_Keyboard,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Keyboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Keyboard::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Keyboard.stringdata0))
        return static_cast<void*>(const_cast< Keyboard*>(this));
    return QWidget::qt_metacast(_clname);
}

int Keyboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Keyboard::specialKeyClicked(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Keyboard::keyClicked(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
