QT += testlib
QT -= gui
CONFIG += test
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LFLAGS += -fprofile-arcs -ftest-coverage

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_calc_tests.cpp  calculator.h \
    calculator.cpp \
    token.cpp

HEADERS += \
    token.h
