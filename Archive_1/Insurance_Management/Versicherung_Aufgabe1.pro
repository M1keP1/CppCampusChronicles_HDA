TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        kfzschein.cpp \
        lvschein.cpp \
        main.cpp \
        versicherer.cpp \
        vschein.cpp

HEADERS += \
    kfzschein.h \
    lvschein.h \
    versicherer.h \
    vschein.h
