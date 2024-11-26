TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        adresse.cpp \
        main.cpp \
        mainwindow.cpp \
        navigationssystem.cpp \
        ort.cpp \
        poi.cpp

HEADERS += \
    adresse.h \
    mainwindow.h \
    navigationssystem.h \
    ort.h \
    poi.h

FORMS += \
    mainwindow.ui
