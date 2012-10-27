#ifndef CABECERASFITS_H
#define CABECERASFITS_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QRegExp>
#include <QTimer>
#include <QSignalMapper>
#include <QLineEdit>
#include "nombreproyectowidget.h"
#include "filtro1widget.h"

namespace Ui {
    class CabecerasFits;
}

class CabecerasFits : public QWidget
{
    Q_OBJECT

public:
    explicit CabecerasFits(QWidget *parent = 0);
    void iniciarGui(); //Inicia toda la GUI de la ventana CabeceraFits.
    void iniciarConnects();
    void activarFrecuenciaDM(bool); //Activa los campos para la Freecuencia en una observacion DrifScan Modificada.

    ~CabecerasFits();

private slots:
    void slotMostrarNombreProyectoWidget(); //Muestra el widget NombreProyecto
    void slotMostrarFiltro1Widget(); //Muestra el widget Filtro al dar click en filtro1PushButton
    void slotMostrarFiltro2Widget(); //Muestra el widget Filtro al dar click en filtro2PushButton
    void slotMostrarFiltro3Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton
    void slotMostrarFiltro4Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton

    void slotVerificar(int);

    void slotTimerRaHh();
    void slotTimerRaMm();
    void slotTimerRaSs(); //Crear la animacion de error para el campo Ss de RA
    void slotTimerFocoT();
    void slotTimerAHHh();
    void slotTimerAHMm();
    void slotTimerAHSs();
    void slotTimerDeGg();
    void slotTimerDeMm();
    void slotTimerDeSs();
    void slotTimerNomObjeto();
    void slotTimerPosDX();
    void slotTimerPosDY();
    void slotTimerPosDZ();
    void slotTimerPosDT();
    void slotTimerTempDX();
    void slotTimerTempDY();
    void slotTimerTempDZ();
    void slotTimerTempDT();
    void slotTimerVacioCam();
    void slotTimerLineaSup();
    void slotTimerLineaInf();
    void slotTimerTempNev(); //Crear la animacion de error para el campo temperatura nevera.
    void slotTimerTempDomo(); //Crear la animacion de error para el campo temperatura del domo
    void slotTimerHumDomo();


    void slotcerrar();

private:

    NombreProyectoWidget *nombreProyecto;
    char *activarNombreProyectoWidget; //Para activar o no el Widget NombreProyecto

    Filtro1Widget *filtro;
    char *activarFiltroWidget; //Para activar o no el Widget Filtro

    QTimer *timer[29];
    QTimer *t3;

    int contador;

    QSignalMapper *mapperLineEdits; //Para mapear todos los LineEdit de esta clase para Verificarlos.
    QSignalMapper *mapperTimers;

    bool activarAnimacion; //Activa la animacion de los errores.


    Ui::CabecerasFits *ui;

};

#endif // CABECERASFITS_H
