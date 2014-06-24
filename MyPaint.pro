#-------------------------------------------------
#
# Project created by QtCreator 2014-06-24T16:36:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG(debug, debug|release) {
    unix:DESTDIR = ../debug/unix
    unix:OBJECTS_DIR = ../debug/unix/objects
    unix:MOC_DIR = ../debug/unix/moc
    unix:RCC_DIR = ../debug/unix/moc
    unix:TARGET = MyPaintProd
    win32:DESTDIR = ../debug/win32
    win32:OBJECTS_DIR = ../debug/win32/objects
    win32:MOC_DIR = ../debug/win32/moc
    win32:RCC_DIR = ../debug/win32/moc
    win32:TARGET = MyPaintProd

    DEFINES = DEBUG
}
else {
    unix:DESTDIR = ../release/unix
    unix:OBJECTS_DIR = ../release/unix/objects
    unix:MOC_DIR = ../release/unix/moc
    unix:RCC_DIR = ../release/unix/moc
    unix:TARGET = MyPaintPro
    win32:DESTDIR = ../release/win32
    win32:OBJECTS_DIR = ../release/win32/objects
    win32:MOC_DIR = ../release/win32/moc
    win32:RCC_DIR = ../release/win32/moc
    win32:TARGET = MyPaintPro
}

SOURCES += main.cpp\
        MainWindow.cpp

HEADERS  += MainWindow.h

FORMS    += MainWindow.ui
