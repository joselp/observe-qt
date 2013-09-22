#ifndef FORMSIMULADOR_H
#define FORMSIMULADOR_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include "headers/mysubwindow.h"
#include "headers/adquisiciondatos.h"
#include "headers/cabecerasfits.h"
#include "headers/mybuttonicon.h"
#include "headers/terminal.h"
#include "headers/sistemadatos.h"

namespace Ui {
class FormSimulador;
}

class FormSimulador : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormSimulador(QWidget *parent = 0);
    void asignarVentanas();
    void iniciarVisualizador();
    void resizeEvent(QResizeEvent *); //Para redimensionar el fondo
    void mouseDoubleClickEvent(QMouseEvent *);
    AdquisicionDatos* getAdquisicionDatos(); //Retorna la variable adquisicionDatos;
    void abrirSitemaDatos();
    void asignarFondo(bool encendido);
    void abrirTerminal();
    ~FormSimulador();


public slots:
    void slotIniciarObservacion();
    void slotModia();
    void slotEncambezados();
    void slotCerrarCabeceras();
    void slotControlShmidt();
    void slotMostrarFondo();
    void slotOcultarFondo();
    void slotParaManejarRaton(int, int);

signals:
    void mousePressed(int x, int y);
    void mostrarConsola();
    void ocultarConsola();
    
private:
    Ui::FormSimulador *ui;
    AdquisicionDatos *adquisicionDatos;
    Terminal *terminal;
    myButtonIcon *iconControlSchmidt;
    myButtonIcon *iconTerminal; //Botton que simula el icono de un terminal
    //CabecerasFits *cabecerasFits;
    QPixmap fondo;
    QPixmap scaledPixmap;
    MySubWindow *subWindowCabeceraFits;
    MySubWindow *subWindowSistemaDatos;
    SistemaDatos *sistemaDatos;

};

#endif // FORMSIMULADOR_H
