#-------------------------------------------------
#
# Project created by QtCreator 2017-11-24T23:54:32
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gra_w_zycie
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
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
        main.cpp \
    predator.cpp \
    dinosaur.cpp \
    map.cpp \
    sound.cpp \
    backgroundgui.cpp \
    objectgui.cpp \
    prey.cpp \
    dinosaurGUI.cpp \
    coordinates.cpp \
    cave.cpp \
    lake.cpp \
    tree.cpp \
    timer.cpp \
    cloud.cpp \
    statistics_visitor.cpp

HEADERS += \
    predator.h \
    dinosaurGUI.h \
    dinosaur.h \
    visitor.h \
    statictics_visitor.h \
    map.h \
    map_block.h \
    object.h \
    sound.h \
    interact_visitor.h \
    backgroundgui.h \
    objectgui.h\
    prey.h \
    coordinates.h \
    cave.h \
    lake.h \
    tree.h \
    timer.h \
    cloud.h

FORMS += \
        applicationwindow.ui

DISTFILES +=

RESOURCES += \
images.qrc
