QT += testlib
QT += widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_gra_w_zycie_test.cpp \
    ../../dinosaur.cpp \
    ../../predator.cpp \
    ../../dinosaurGUI.cpp
