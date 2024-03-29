#-------------------------------------------------
#
# Project created by QtCreator 2012-10-03T10:34:32
#
#-------------------------------------------------

QT       += core gui sql webkit qsqlpsql qsqlmysql network

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
    src/mensajeopciones.cpp \
    src/usuarios/registrousuario.cpp \
    src/cargas/cargarprueba.cpp \
    src/cargas/mispruebas.cpp \
    src/cargas/formprotocolo.cpp \
    src/formhome2.cpp \
    src/formpruebadata.cpp \
    src/asistente.cpp \
    src/controlschmitd/summary.cpp \
    src/controlschmitd/limpiar.cpp \
    src/controlschmitd/slayall.cpp \
    src/controlschmitd/shutdall.cpp \
    src/usuarios/recuperarpassword.cpp \
    src/cargas/reporte.cpp \
    src/cargas/reportes.cpp \
    src/cargas/reporteadmin.cpp \

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
    headers/mensajeopciones.h \
    headers/usuarios/registrousuario.h \
    headers/cargas/cargarprueba.h \
    headers/cargas/mispruebas.h \
    headers/cargas/formprotocolo.h \
    headers/formhome2.h \
    headers/formpruebadata.h \
    headers/asistente.h \
    headers/controlschmitd/summary.h \
    headers/controlschmitd/limpiar.h \
    headers/controlschmitd/slayall.h \
    headers/controlschmitd/shutdall.h \
    headers/usuarios/recuperarpassword.h \
    headers/cargas/reporte.h \
    headers/cargas/reportes.h \
    headers/cargas/reporteadmin.h \

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
    gui/mensajeopciones.ui \
    gui/usuarios/registrousuario.ui \
    gui/cargas/cargarprueba.ui \
    gui/cargas/mispruebas.ui \
    gui/cargas/formprotocolo.ui \
    gui/formhome2.ui \
    gui/formpruebadata.ui \
    gui/asistente.ui \
    gui/controlschmitd/summary.ui \
    gui/controlschmitd/limpiar.ui \
    gui/controlschmitd/slayall.ui \
    gui/controlschmitd/shutdall.ui \
    gui/usuarios/recuperarpassword.ui \
    gui/cargas/reporte.ui \
    gui/cargas/reportes.ui \
    gui/cargas/reporteadmin.ui \

LIBS += -L. \
        -lm \
        -lnsl \
        -lcfitsio \

OTHER_FILES += \
    BD/SimuladorDB.db


RESOURCES += \
    resource.qrc
