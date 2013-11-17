#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include "headers/formhome.h"
#include "headers/formsimulador.h"
#include "headers/paneladministrativo.h"
#include "headers/controlschmitd/controlschmitd.h"
#include "bd/manejadorbd.h"
#include "headers/cargas/mispruebas.h"
#include <QDesktopWidget>
#include <QSqlQuery>

namespace Ui {
class Simulador;
}

class Simulador : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Simulador(QWidget *parent = 0);
    void initGui();
    void configurarSesionBd(); //Configura las variables para establecer la conexion con la base de datos
    void cambiarPanel(QWidget*); //Me permite cambiar los paneles de la ventana principal del simulador
    void removerContenidoWidget(); //Remueve el widget que se encuentre en el layout de contenido
    void mostrarMenu();//Muestra el menu del lado izquierdo
    void ocultarMenu();//Oculta el menu del lado izquierdo
    FormSimulador *getFormSimulador(); //Retorna formSimulador para poder cambiar el fondo
    void resizeEvent(QResizeEvent *);
    ~Simulador();
    
public slots:
    void slotAcceder(); //Verifico si puedo acceder al simulador
    void slotPanelAdministrativo(); //Inicia la ventana de panel administrativo
    void slotMisPruebas(); //Inicia la ventana Mis pruebas
    void slotDrifscan();
    void slotDrifscanMod();
    void slotBias();
    void slotDarkDrifscan();
    void slotSalir(); //Cierra el sistema
    void slotSistemaDatos(); //Inicia el sistema de adquisicion de datos
    void slotConsola();
    void slotControlShmitd();
    void slotMostrarConsola();
    void slotOcultarConsola();
    void slotAbrirObserve(); //Inicia Observe para una prueba libre
    void slotCargarPrueba(QSqlQuery); //Carga la prueba del usuario

private:
    Ui::Simulador *ui;
    ManejadorBd *manejadorBd;
    FormHome *formHome;
    FormSimulador *formSimulador;
    PanelAdministrativo *panelAdministrativo;
    MisPruebas *misPruebas;
    Controlschmitd *controlSchmitd;
    RegistroUsuario *registroUsuario;
    QString idUsuario;
    QSqlQuery prueba; //Variable para guardar la prueba que selecciono el usuario

};

#endif // SIMULADOR_H
