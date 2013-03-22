#-------------------------------------------------
#
# Project created by QtCreator 2012-10-03T10:34:32
#
#-------------------------------------------------

QT       += core gui sql

TARGET = ObserveQt
TEMPLATE = app


SOURCES += main.cpp\
        adquisiciondatos.cpp \
    cabecerasfits.cpp \
    nombreproyectowidget.cpp \
    filtro1widget.cpp \
    procesofits.cpp \
    visualizador.cpp \
    paneladministrativo.cpp \
    graphwidget.cpp \
    myscrollarea.cpp

HEADERS  += adquisiciondatos.h \
    cabecerasfits.h \
    nombreproyectowidget.h \
    filtro1widget.h \
    procesofits.h \
    visualizador.h \
    conexion.h \
    paneladministrativo.h \
    graphwidget.h \
    myscrollarea.h

FORMS    += adquisiciondatos.ui \
    cabecerasfits.ui \
    nombreproyectowidget.ui \
    filtro1widget.ui \
    visualizador.ui \
    paneladministrativo.ui

RESOURCES += \
    resource.qrc

LIBS += -L. \
        -lcfitsio \
        -lm \
        -lnsl \

OTHER_FILES += \
    BD/SimuladorDB.db
