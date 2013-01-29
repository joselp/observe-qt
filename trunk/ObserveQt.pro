#-------------------------------------------------
#
# Project created by QtCreator 2012-10-03T10:34:32
#
#-------------------------------------------------

QT       += core gui

TARGET = ObserveQt
TEMPLATE = app


SOURCES += main.cpp\
        adquisiciondatos.cpp \
    cabecerasfits.cpp \
    nombreproyectowidget.cpp \
    filtro1widget.cpp \
    procesofits.cpp \
    visualizador.cpp

HEADERS  += adquisiciondatos.h \
    cabecerasfits.h \
    nombreproyectowidget.h \
    filtro1widget.h \
    procesofits.h \
    visualizador.h

FORMS    += adquisiciondatos.ui \
    cabecerasfits.ui \
    nombreproyectowidget.ui \
    filtro1widget.ui \
    visualizador.ui

RESOURCES += \
    resource.qrc

LIBS += -L. \
        -lcfitsio \
        -lm \
        -lnsl \
