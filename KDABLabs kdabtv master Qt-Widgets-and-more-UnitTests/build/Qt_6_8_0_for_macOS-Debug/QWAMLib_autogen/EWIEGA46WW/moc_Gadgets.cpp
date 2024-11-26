/****************************************************************************
** Meta object code from reading C++ file 'Gadgets.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Gadgets.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Gadgets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSMyGadgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMyGadgetENDCLASS = QtMocHelpers::stringData(
    "MyGadget",
    "MyEnum",
    "Foo",
    "Bar",
    "Baz"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMyGadgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       4,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    3,   19,

 // enum data: key, value
       2, uint(MyGadget::Foo),
       3, uint(MyGadget::Bar),
       4, uint(MyGadget::Baz),

       0        // eod
};

Q_CONSTINIT const QMetaObject MyGadget::staticMetaObject = { {
    nullptr,
    qt_meta_stringdata_CLASSMyGadgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMyGadgetENDCLASS,
    nullptr,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMyGadgetENDCLASS_t,
        // enum 'MyEnum'
        QtPrivate::TypeAndForceComplete<MyGadget::MyEnum, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyGadget, std::true_type>
    >,
    nullptr
} };

QT_WARNING_POP
