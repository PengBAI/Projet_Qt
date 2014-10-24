#-------------------------------------------------
#
# Project created by QtCreator 2014-03-13T09:50:35
#
#-------------------------------------------------

QT       += core gui\
                sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    clientdialog.cpp \
    personneldialog.cpp \
    aproposdialog.cpp \
    c_init_bd.cpp \
    modeleclient.cpp \
    modeleressource.cpp \
    gestionbdd.cpp \
    client.cpp \
    modeleplanning.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    clientdialog.h \
    personneldialog.h \
    aproposdialog.h \
    c_init_bd.h \
    modeleclient.h \
    modeleressource.h \
    gestionbdd.h \
    client.h \
    modeleplanning.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    clientdialog.ui \
    personneldialog.ui \
    aproposdialog.ui

RESOURCES += \
    image/image.qrc
