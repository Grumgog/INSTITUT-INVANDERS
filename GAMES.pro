#-------------------------------------------------
#
# Project created by QtCreator 2017-03-02T14:07:38
#
#-------------------------------------------------

QT       += core gui opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GAMES
TEMPLATE = app

LIBS+= -lSDL2
LIBS+= -lSDL2_mixer
LIBS+= -lSDL2main

SOURCES += main.cpp\
        widget.cpp \
    UserClass/paintobjectabstract.cpp \
    UserClass/point.cpp \
    UserClass/npc.cpp \
    UserClass/player.cpp \
    UserClass/enemy.cpp \
    UserClass/bullet.cpp \
    helping.cpp \
    UserClass/statusmanager.cpp

HEADERS  += widget.h \
    UserClass/paintobjectabstract.h \
    UserClass/point.h \
    UserClass/npc.h \
    UserClass/player.h \
    UserClass/enemy.h \
    UserClass/bullet.h \
    helping.h \
    UserClass/statusmanager.h

FORMS    += widget.ui
