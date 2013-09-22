#-------------------------------------------------
#
# Project created by QtCreator 2012-10-03T10:34:32
#
#-------------------------------------------------

QT       += core gui sql webkit qsqlpsql qsqlmysql


TARGET = ObserveQt
TEMPLATE = app


SOURCES += bd/manejadorbd.cpp \
    src/visualizador.cpp \
    src/simulador.cpp \
    src/procesofits.cpp \
    src/paneladministrativo.cpp \
    src/nombreproyectowidget.cpp \
    src/myscrollarea.cpp \
    src/mybuttonicon.cpp \
    src/main.cpp \
    src/graphwidget.cpp \
    src/formsimulador.cpp \
    src/formhome.cpp \
    src/filtro1widget.cpp \
    src/cabecerasfits.cpp \
    src/adquisiciondatos.cpp \
    src/miTextArea.cpp \
    src/terminal.cpp \
    src/sistemadatos.cpp \
    src/mysubwindow.cpp \
    src/controlschmitd/controlschmitd.cpp \
    src/mensajeopciones.cpp

HEADERS  += bd/manejadorbd.h \
    headers/visualizador.h \
    headers/simulador.h \
    headers/procesofits.h \
    headers/nombreproyectowidget.h \
    headers/myscrollarea.h \
    headers/mybuttonicon.h \
    headers/graphwidget.h \
    headers/formsimulador.h \
    headers/formhome.h \
    headers/filtro1widget.h \
    headers/conexion.h \
    headers/cabecerasfits.h \
    headers/adquisiciondatos.h \
    headers/paneladministrativo.h \
    headers/miTextArea.h \
    headers/terminal.h \
    headers/sistemadatos.h \
    headers/mysubwindow.h \
    headers/controlschmitd/controlschmitd.h \
    headers/mensajeopciones.h

FORMS    += gui/visualizador.ui \
    gui/simulador.ui \
    gui/paneladministrativo.ui \
    gui/nombreproyectowidget.ui \
    gui/formsimulador.ui \
    gui/formhome.ui \
    gui/filtro1widget.ui \
    gui/cabecerasfits.ui \
    gui/adquisiciondatos.ui \
    gui/terminal.ui \
    gui/sistemadatos.ui \
    gui/controlschmitd/controlschmitd.ui \
    gui/mensajeopciones.ui

LIBS += -L. \
        -lm \
        -lnsl \
        -lcfitsio \

OTHER_FILES += \
    BD/SimuladorDB.db


RESOURCES += \
    resource.qrc
