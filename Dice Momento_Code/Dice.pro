QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dice
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    randomnumbergenerator.cpp \
    randomnumbergeneratormemento.cpp \
    randomnumbercaretaker.cpp

HEADERS  += mainwindow.h \
    randomnumbergenerator.h \
    randomnumbergeneratormemento.h \
    randomnumbercaretaker.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
