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
    bool orientacionPrimasIsActive(); //Verifico si esta activo la orientacion del prisma para validas este dato o no.

    //Getters
    QString getRaHh();
    QString getRaMm();
    QString getRaSs();
    QString getFocoTelescopio();
    QString getAHorarioHh();
    QString getAHorarioMm();
    QString getAHorarioSs();
    QString getDeclinacionGg();
    QString getDeclinacionMm();
    QString getDeclinacionSs();
    QString getNombreObjeto();
    QString getPosDedosX();
    QString getPosDedosY();
    QString getPosDedosZ();
    QString getPosDedosT();
    QString getTemDedosX();
    QString getTemDedosY();
    QString getTemDedosZ();
    QString getTemDedosT();
    QString getVacioCamara();
    QString getVacioLineaSuperior();
    QString getVacioLineaInferior();
    QString getTempNevera();
    QString getOrientacionPrisma();
    QString getTempDomo();
    QString getHumedadDomo();
    QString getFrecuenciaYic();
    QString getFrecuenciaRa();
    QString getFrecuenciaDec();

    //Setter
    void setNombreObjeto(QString);

    ~CabecerasFits();

private slots:
    void slotMostrarNombreProyectoWidget(); //Muestra el widget NombreProyecto
    void slotMostrarFiltro1Widget(); //Muestra el widget Filtro al dar click en filtro1PushButton
    void slotMostrarFiltro2Widget(); //Muestra el widget Filtro al dar click en filtro2PushButton
    void slotMostrarFiltro3Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton
    void slotMostrarFiltro4Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton

    //Slot para verificar los campos
    void slotVerificar(int);

    //Slots para crear animaciones de los campos al haber valores erroneos.
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

    void slotInstrumentoUsado(int);

    void slotcerrar();

private:

    NombreProyectoWidget *nombreProyecto;
    char *activarNombreProyectoWidget; //Para activar o no el Widget NombreProyecto

    Filtro1Widget *filtro;
    char *activarFiltroWidget; //Para activar o no el Widget Filtro

    QTimer *timer[29];

    int contador;

    QSignalMapper *mapperLineEdits; //Para mapear todos los LineEdit de esta clase para Verificarlos.
    QSignalMapper *mapperTimers;

    bool activarAnimacion; //Activa la animacion de los errores.


    Ui::CabecerasFits *ui;

};

#endif // CABECERASFITS_H
