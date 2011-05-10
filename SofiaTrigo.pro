#-------------------------------------------------
#
# Project created by QtCreator 2011-05-02T22:30:47
#
#-------------------------------------------------

QT       += core gui declarative webkit

TARGET = SofiaTrigo
TEMPLATE = app


SOURCES += main.cpp\
        strigo.cpp \
    plotwidget.cpp \
    function.cpp \
    dragdroparea.cpp \
    dropbox.cpp

HEADERS  += strigo.h \
    plotwidget.h \
    function.h \
    dragdroparea.h \
    dropbox.h

FORMS    += widget.ui

OTHER_FILES += \
    tabFunc.qml \
    tab3.qml

RESOURCES += \
    resources.qrc
