/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "handleBackFromStartButton"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 17), // "handleStartButton"
QT_MOC_LITERAL(4, 56, 17), // "handleStatsButton"
QT_MOC_LITERAL(5, 74, 17), // "handlestatsSelect"
QT_MOC_LITERAL(6, 92, 25), // "handleBackFromStatsButton"
QT_MOC_LITERAL(7, 118, 17), // "handleBacktoStats"
QT_MOC_LITERAL(8, 136, 20), // "handleSettingsButton"
QT_MOC_LITERAL(9, 157, 16), // "handleQuitButton"
QT_MOC_LITERAL(10, 174, 16), // "handleSaveButton"
QT_MOC_LITERAL(11, 191, 18), // "handleCancelButton"
QT_MOC_LITERAL(12, 210, 17), // "handleMusicButton"
QT_MOC_LITERAL(13, 228, 23), // "handleExecuteGameButton"
QT_MOC_LITERAL(14, 252, 22), // "handleBackToListButton"
QT_MOC_LITERAL(15, 275, 8), // "redValue"
QT_MOC_LITERAL(16, 284, 10), // "greenValue"
QT_MOC_LITERAL(17, 295, 9), // "blueValue"
QT_MOC_LITERAL(18, 305, 12), // "readGameInfo"
QT_MOC_LITERAL(19, 318, 18), // "handleGameSelected"
QT_MOC_LITERAL(20, 337, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(21, 354, 4) // "item"

    },
    "MainWindow\0handleBackFromStartButton\0"
    "\0handleStartButton\0handleStatsButton\0"
    "handlestatsSelect\0handleBackFromStatsButton\0"
    "handleBacktoStats\0handleSettingsButton\0"
    "handleQuitButton\0handleSaveButton\0"
    "handleCancelButton\0handleMusicButton\0"
    "handleExecuteGameButton\0handleBackToListButton\0"
    "redValue\0greenValue\0blueValue\0"
    "readGameInfo\0handleGameSelected\0"
    "QListWidgetItem*\0item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    1,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleBackFromStartButton(); break;
        case 1: _t->handleStartButton(); break;
        case 2: _t->handleStatsButton(); break;
        case 3: _t->handlestatsSelect(); break;
        case 4: _t->handleBackFromStatsButton(); break;
        case 5: _t->handleBacktoStats(); break;
        case 6: _t->handleSettingsButton(); break;
        case 7: _t->handleQuitButton(); break;
        case 8: _t->handleSaveButton(); break;
        case 9: _t->handleCancelButton(); break;
        case 10: _t->handleMusicButton(); break;
        case 11: _t->handleExecuteGameButton(); break;
        case 12: _t->handleBackToListButton(); break;
        case 13: _t->redValue(); break;
        case 14: _t->greenValue(); break;
        case 15: _t->blueValue(); break;
        case 16: _t->readGameInfo(); break;
        case 17: _t->handleGameSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
