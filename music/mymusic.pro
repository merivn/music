#-------------------------------------------------
#
# Project created by QtCreator 2018-06-20T08:47:29
#
#-------------------------------------------------

QT       += core gui multimedia

QT += sql
QMAKE_CXXFLAGS += -std=c++0x
CONFIG   += c++11




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mymusic
TEMPLATE = app


OTHER_FILES += myico.rc
RC_FILE += myico.rc

SOURCES += main.cpp\
        MusicWindow.cpp \
    configurator.cpp \
    listmusic.cpp \
    localmusic.cpp \
    searchmusic.cpp \
    network.cpp \
    mylrc.cpp \
    baseWidget.cpp \
    LyricWidget.cpp \
    decodekrc.cpp \
    database.cpp \
    myqlistwidget.cpp \
    collectwidget.cpp \
    mycollectwidget.cpp

HEADERS  += MusicWindow.h \
    configurator.h \
    listmusic.h \
    allhead.h \
    localmusic.h \
    ui_localmusic.h \
    searchmusic.h \
    network.h \
    mylrc.h \
    baseWidget.h \
    decodekrc.h \
    LyricWidget.h \
    database.h \
    myqlistwidget.h \
    collectwidget.h \
    mycollectwidget.h


FORMS    += MusicWindow.ui \
    listmusic.ui \
    localmusic.ui \
    searchmusic.ui \
    mylrc.ui

RESOURCES += \
    style.qrc \
    img.qrc \
    mp3.qrc \
    background.qrc

#LIBS += -L ./ -lzdll1
#LIBS += -L./zlib/ -lzdll
#LIBS+= -L$$PWD/zlib/ -lzdll



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/zlib/ -lzdll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/zlib/ -lzdll
else:unix: LIBS += -L$$PWD/zlib/ -lzdll

INCLUDEPATH += $$PWD/zlib
DEPENDPATH += $$PWD/zlib

DISTFILES += \
    myico.rc
