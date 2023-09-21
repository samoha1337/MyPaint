/****************************************************************************
** Meta object code from reading C++ file 'dialog_1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graf15/dialog_1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_1_t {
    QByteArrayData data[19];
    char stringdata0[332];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_1_t qt_meta_stringdata_Dialog_1 = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Dialog_1"
QT_MOC_LITERAL(1, 9, 12), // "ExportString"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "str"
QT_MOC_LITERAL(4, 27, 11), // "ExportStyle"
QT_MOC_LITERAL(5, 39, 16), // "style_value_line"
QT_MOC_LITERAL(6, 56, 17), // "style_value_brush"
QT_MOC_LITERAL(7, 74, 13), // "ExportSpinbox"
QT_MOC_LITERAL(8, 88, 10), // "spin_value"
QT_MOC_LITERAL(9, 99, 16), // "ExportColor_line"
QT_MOC_LITERAL(10, 116, 5), // "color"
QT_MOC_LITERAL(11, 122, 17), // "ExportColor_brush"
QT_MOC_LITERAL(12, 140, 26), // "on_pushButtonColor_clicked"
QT_MOC_LITERAL(13, 167, 24), // "on_pushButton_ok_clicked"
QT_MOC_LITERAL(14, 192, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(15, 221, 36), // "on_comboBoxStyle_currentIndex..."
QT_MOC_LITERAL(16, 258, 5), // "index"
QT_MOC_LITERAL(17, 264, 28), // "on_pushButtonColor_2_clicked"
QT_MOC_LITERAL(18, 293, 38) // "on_comboBoxStyle_2_currentInd..."

    },
    "Dialog_1\0ExportString\0\0str\0ExportStyle\0"
    "style_value_line\0style_value_brush\0"
    "ExportSpinbox\0spin_value\0ExportColor_line\0"
    "color\0ExportColor_brush\0"
    "on_pushButtonColor_clicked\0"
    "on_pushButton_ok_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_comboBoxStyle_currentIndexChanged\0"
    "index\0on_pushButtonColor_2_clicked\0"
    "on_comboBoxStyle_2_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       7,    1,   77,    2, 0x06 /* Public */,
       9,    1,   80,    2, 0x06 /* Public */,
      11,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    1,   89,    2, 0x08 /* Private */,
      17,    0,   92,    2, 0x08 /* Private */,
      18,    1,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QColor,   10,
    QMetaType::Void, QMetaType::QColor,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,

       0        // eod
};

void Dialog_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ExportString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->ExportStyle((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->ExportSpinbox((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ExportColor_line((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 4: _t->ExportColor_brush((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 5: _t->on_pushButtonColor_clicked(); break;
        case 6: _t->on_pushButton_ok_clicked(); break;
        case 7: _t->on_pushButton_cancel_clicked(); break;
        case 8: _t->on_comboBoxStyle_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_pushButtonColor_2_clicked(); break;
        case 10: _t->on_comboBoxStyle_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog_1::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_1::ExportString)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog_1::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_1::ExportStyle)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog_1::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_1::ExportSpinbox)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Dialog_1::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_1::ExportColor_line)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Dialog_1::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog_1::ExportColor_brush)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_1::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Dialog_1.data,
    qt_meta_data_Dialog_1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_1.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Dialog_1::ExportString(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog_1::ExportStyle(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog_1::ExportSpinbox(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dialog_1::ExportColor_line(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dialog_1::ExportColor_brush(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
