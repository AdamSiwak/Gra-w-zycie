QT += testlib
QT += widgets
QT += gui\
      multimedia\
      charts

CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_gra_w_zycie_test.cpp \
    ../../dinosaur.cpp \
    ../../predator.cpp \
    ../../backgroundgui.cpp \
    ../../cave.cpp \
    ../../coordinates.cpp \
    ../../dinosaurGUI.cpp \
    ../../lake.cpp \
    ../../map.cpp \
    ../../objectgui.cpp \
    ../../prey.cpp \
    ../../sound.cpp \
    ../../timer.cpp \
    ../../tree.cpp \
    ../../cloud.cpp \
    ../../statistics_visitor.cpp \
    ../../chart.cpp

SUBDIRS += \
    ../../gra_w_zycie.pro

RESOURCES += \
    ../../images.qrc

DISTFILES += \
    ../../gra_w_zycie \
    ../../dinosaur.o \
    ../../dinosaurGUI.o \
    ../../main.o \
    ../../map.o \
    ../../moc_applicationwindow.o \
    ../../predator.o \
    ../../qrc_images.o \
    ../../gra_w_zycie.pro.user \
    ../../gra_w_zycie.pro.user.0fb9fc0 \
    ../../gra_w_zycie.pro.user.7e69003 \
    ../../Makefile \
    ../../README.md

HEADERS += \
    ../../backgroundgui.h \
    ../../cave.h \
    ../../coordinates.h \
    ../../dinosaur.h \
    ../../dinosaurGUI.h \
    ../../interact_visitor.h \
    ../../lake.h \
    ../../map_block.h \
    ../../map.h \
    ../../object.h \
    ../../objectgui.h \
    ../../predator.h \
    ../../prey.h \
    ../../sound.h \
    ../../statictics_visitor.h \
    ../../timer.cpp.autosave \
    ../../timer.h \
    ../../tree.h \
    ../../visitor.h \
    ../../chart.h
