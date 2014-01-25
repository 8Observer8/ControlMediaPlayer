QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UControlMediaPlayer
TEMPLATE = app

DESTDIR = ../bin

SOURCES += main.cpp\
        UControlMediaPlayer.cpp \
    UWindowControlMediaPlayer.cpp

HEADERS  += UControlMediaPlayer.h \
    UWindowControlMediaPlayer.h

RESOURCES += \
    resource.qrc
