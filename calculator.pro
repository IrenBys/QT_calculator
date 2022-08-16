QT += core gui widgets

CONFIG += c++11

TARGET = calculator
CONFIG += console

CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
        calc.cpp \
        main.cpp

HEADERS += \
    calc.h
