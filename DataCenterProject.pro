QT += core
QT -= gui

CONFIG += c++11

TARGET = DataCenterProject
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    datacentercomponent.cpp \
    ethernetswitch.cpp \
    loadbalancer.cpp \
    datacenter.cpp \
    serverrack.cpp \
    server.cpp \
    router.cpp

HEADERS += \
    datacentercomponent.h \
    ethernetswitch.h \
    loadbalancer.h \
    datacenter.h \
    serverrack.h \
    server.h \
    router.h
