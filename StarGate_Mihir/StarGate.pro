TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        raumfahrtunternehmen.cpp \
        raumflug.cpp \
        raumgleiter.cpp

HEADERS += \
    raumfahrtunternehmen.h \
    raumflug.h \
    raumgleiter.h
