#ifndef ADQUISICIONDATOS_H
#define ADQUISICIONDATOS_H


#include <QMainWindow>
#include <QDateTime>
#include <QDebug>
#include <QMouseEvent>
#include "cabecerasfits.h"


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
    void closeEvent(QCloseEvent *); //Captura el evento cerrar Aplicacion.
    ~AdquisicionDatos();

private slots:
    void slotComandoDeObservacion(int); //Cambiar GUI segun asignacion
    void slotModoLineaReloj(int); //Cambia GUI segun asignacion
    void slotEmcabezados(); //Activa la ventana CabeceraFits
    void slotObservar(); //Comienza la observacion.
    void slotSalir();

private:
    bool primero; //Para determinar la primera entrada al sistema y colocar en ComboBox "seleccione"
    bool eliminar; //Para eliminar el valor de "seleccione" de los ComboBox
    bool datosCorrectos; //Para determinar si todos los datos estan correctos y comenzar con la observacion.

    CabecerasFits *ventanaCabeceraFits;
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
