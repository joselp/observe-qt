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
#include "headers/controlschmitd/controlschmitd.h"

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
    void abrirControlSchmitd();
    void asignarPrueba(QSqlQuery, bool); //Asigna si el usuario carga una prueba y la prueba a cargar.
    void asignarObturador(QLabel *obt);
    ~FormSimulador();


public slots:
    void slotIniciarObservacion();
    void slotModia();
    void slotEncambezados();
    void slotCerrarCabeceras();
    void slotControlShmidt();
    void slotMostrarFondo(bool, bool, bool, bool, bool, bool); //Al encender babel muestra el fondo
    void slotOcultarFondo(); //Oculta el fondo al apagar babel.
    void slotParaManejarRaton(int, int);
    void slotVerificarSesion(); //Verifica la sesion ingresada en babel.
    void slotAbrirObserve(); //Inicia Observe para una prueba libre
    void slotObturador(QString); //Enciende o apaga el obturador

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
    MySubWindow *subWindowControl;
    SistemaDatos *sistemaDatos;
    Controlschmitd *controlSchmitd;
    bool error1, error2, error3, error4, error5, error6; //Variables para manejar errores de conexion en qxns
    //Login de babel.
    QLineEdit *pass; //lineEdit para colocar la contraseña
    QPushButton *login; //Boton para iniciar sesion en babel
    bool cargarPrueba; //Variable que indica si el usuario va a realizar una prueba
    QSqlQuery prueba; //Variable que contiene los parametros para la prueba
    QLabel *obturador; //Label que muestra el obutarodos

};

#endif // FORMSIMULADOR_H
