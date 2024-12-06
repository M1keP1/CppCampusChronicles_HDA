/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GUI_NavBase/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "addRadioButton",
    "",
    "GPS",
    "gps",
    "label",
    "on_pushButton_new_clicked",
    "on_pushButton_show_clicked",
    "on_pushButton_calc_clicked",
    "on_pushButton_change_clicked",
    "on_pushButton_save_clicked",
    "on_pushButton_exit_clicked",
    "onInfoButtonClicked",
    "onRadioButtonClicked",
    "checked",
    "on_pushButton_Del_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[6];
    char stringdata6[26];
    char stringdata7[27];
    char stringdata8[27];
    char stringdata9[29];
    char stringdata10[27];
    char stringdata11[27];
    char stringdata12[20];
    char stringdata13[21];
    char stringdata14[8];
    char stringdata15[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "addRadioButton"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 3),  // "GPS"
        QT_MOC_LITERAL(31, 3),  // "gps"
        QT_MOC_LITERAL(35, 5),  // "label"
        QT_MOC_LITERAL(41, 25),  // "on_pushButton_new_clicked"
        QT_MOC_LITERAL(67, 26),  // "on_pushButton_show_clicked"
        QT_MOC_LITERAL(94, 26),  // "on_pushButton_calc_clicked"
        QT_MOC_LITERAL(121, 28),  // "on_pushButton_change_clicked"
        QT_MOC_LITERAL(150, 26),  // "on_pushButton_save_clicked"
        QT_MOC_LITERAL(177, 26),  // "on_pushButton_exit_clicked"
        QT_MOC_LITERAL(204, 19),  // "onInfoButtonClicked"
        QT_MOC_LITERAL(224, 20),  // "onRadioButtonClicked"
        QT_MOC_LITERAL(245, 7),  // "checked"
        QT_MOC_LITERAL(253, 25)   // "on_pushButton_Del_clicked"
    },
    "MainWindow",
    "addRadioButton",
    "",
    "GPS",
    "gps",
    "label",
    "on_pushButton_new_clicked",
    "on_pushButton_show_clicked",
    "on_pushButton_calc_clicked",
    "on_pushButton_change_clicked",
    "on_pushButton_save_clicked",
    "on_pushButton_exit_clicked",
    "onInfoButtonClicked",
    "onRadioButtonClicked",
    "checked",
    "on_pushButton_Del_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x08,    1 /* Private */,
       6,    0,   79,    2, 0x08,    4 /* Private */,
       7,    0,   80,    2, 0x08,    5 /* Private */,
       8,    0,   81,    2, 0x08,    6 /* Private */,
       9,    0,   82,    2, 0x08,    7 /* Private */,
      10,    0,   83,    2, 0x08,    8 /* Private */,
      11,    0,   84,    2, 0x08,    9 /* Private */,
      12,    0,   85,    2, 0x08,   10 /* Private */,
      13,    1,   86,    2, 0x08,   11 /* Private */,
      15,    0,   89,    2, 0x08,   13 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'addRadioButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<GPS, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_new_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_show_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_calc_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_change_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onInfoButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRadioButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_Del_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addRadioButton((*reinterpret_cast< std::add_pointer_t<GPS>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->on_pushButton_new_clicked(); break;
        case 2: _t->on_pushButton_show_clicked(); break;
        case 3: _t->on_pushButton_calc_clicked(); break;
        case 4: _t->on_pushButton_change_clicked(); break;
        case 5: _t->on_pushButton_save_clicked(); break;
        case 6: _t->on_pushButton_exit_clicked(); break;
        case 7: _t->onInfoButtonClicked(); break;
        case 8: _t->onRadioButtonClicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->on_pushButton_Del_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
