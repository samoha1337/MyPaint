#-------------------------------------------------
#
# Project created by QtCreator 2023-03-31T12:49:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graf3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arc.cpp \
    dialog_1.cpp \
    dialog_2.cpp \
    ellipse.cpp \
        main.cpp \
        mainwindow.cpp \
    polygon.cpp \
    polyline.cpp \
    tochka.cpp \
    color.cpp \
    pixel.cpp \
    my_widget.cpp \
    line.cpp \
    rect.cpp \
    mpen.cpp \
    mbrush.cpp \
    okno.cpp

HEADERS += \
    arc.h \
    dialog_1.h \
    dialog_2.h \
    ellipse.h \
        mainwindow.h \
    polygon.h \
    polyline.h \
    tochka.h \
    color.h \
    pixel.h \
    my_widget.h \
    line.h \
    rect.h \
    mpen.h \
    mbrush.h \
    okno.h

FORMS += \
    dialog_1.ui \
    dialog_2.ui \
        mainwindow.ui \
    okno.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
