#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T01:07:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DB_project
TEMPLATE = app


SOURCES += main.cpp\
        db_project.cpp \
    dialog_createkey.cpp

HEADERS  += db_project.h \
    dialog_createkey.h

FORMS    += db_project.ui \
    dialog_createkey.ui

DISTFILES += \
    Resource/img/bg.jpg \
    Resource/img/JJang.jpg \
    Resource/img/JJang1.jpg \
    Resource/img/all_icon.png \
    Resource/img/left_icon.png \
    Resource/img/right_icon.png \
    Resource/img/search_icon.png \
    img \
    listview.qml

RESOURCES +=
