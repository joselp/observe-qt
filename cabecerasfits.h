#ifndef CABECERASFITS_H
#define CABECERASFITS_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QRegExp>
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
    void validarCampos();
    void activarFrecuenciaDM(bool); //Activa los campos para la Freecuencia en una observacion DrifScan Modificada.

    ~CabecerasFits();

private slots:
    void slotMostrarNombreProyectoWidget(); //Muestra el widget NombreProyecto
    void slotMostrarFiltro1Widget(); //Muestra el widget Filtro al dar click en filtro1PushButton
    void slotMostrarFiltro2Widget(); //Muestra el widget Filtro al dar click en filtro2PushButton
    void slotMostrarFiltro3Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton
    void slotMostrarFiltro4Widget(); //Muestra el widget Filtro al dar click en filtro3PushButton
    void slotcerrar();

private:

    NombreProyectoWidget *nombreProyecto;
    char *activarNombreProyectoWidget; //Para activar o no el Widget NombreProyecto

    Filtro1Widget *filtro;
    char *activarFiltroWidget; //Para activar o no el Widget Filtro


    Ui::CabecerasFits *ui;

};

#endif // CABECERASFITS_H
