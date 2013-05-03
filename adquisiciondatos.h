#ifndef ADQUISICIONDATOS_H
#define ADQUISICIONDATOS_H

#include <QMainWindow>
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include <QRegExp>
#include "cabecerasfits.h"
#include "visualizador.h"

namespace Ui {
    class AdquisicionDatos;
}

class AdquisicionDatos : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdquisicionDatos(QWidget *parent = 0);
    void iniciarGui();
    void logicaGui();
    void verificarDatos(); //Verifica si todos los datos son correcto para comenzar la observacion.
    void crearRetardoFit();
    void closeEvent(QCloseEvent *); //Captura el evento cerrar Aplicacion.
    CabecerasFits* obtenerCabeceraFits();
    ~AdquisicionDatos();

private slots:
    void slotComandoDeObservacion(int); //Cambiar GUI segun asignacion
    void slotModoLineaReloj(int); //Cambia GUI segun asignacion
    void slotEmcabezados(); //Activa la ventana CabeceraFits
    void slotObservar(); //Comienza la observacion.
    void slotModia(); //Despliega la imagen
    void slotCancelarObservacion(); //Cancela la observacion una vez iniciada
    void slotLogTimer(); //crea la el retardo para el log
    void slotTiempoExposicion();//Crea el contador del tiempo de exposicion.
    void slotSalir();

private:
    bool realizarObservacion; //Determina si se debe hacer la observacion o no
    bool primero; //Para determinar la primera entrada al sistema y colocar en ComboBox "seleccione"
    bool eliminar; //Para eliminar el valor de "seleccione" de los ComboBox
    bool datosCorrectos; //Para determinar si todos los datos estan correctos y comenzar con la observacion

    int lineasLeidas; //Cantidad  de lineas leidas desde los ccds
    int tiempoExposicion; //Tiempo de exposicion para algunos tipos de imagenes.
    int contadorTiempoExposicion; //LLeva la cantidad de tiempo que ha transcurrido.

    QTimer *logTimer; //Variable para crear el tiempo de creacion de un archivo fits
    QTimer *tiempoExposicionTimer;//Variable para crear el contador del tiempo de exposcion.

    CabecerasFits *ventanaCabeceraFits;
    Visualizador *visualizador;
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
