#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include "headers/formhome.h"
#include "headers/formsimulador.h"
#include "headers/paneladministrativo.h"
#include "headers/sistemadatos.h"


namespace Ui {
class Simulador;
}

class Simulador : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Simulador(QWidget *parent = 0);
    void initGui();
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
    void slotDrifscan();
    void slotDrifscanMod();
    void slotBias();
    void slotDarkDrifscan();
    void slotSalir(); //Cierra el sistema
    void slotSistemaDatos(); //Inicia el sistema de adquisicion de datos
    void slotConsola();


private:
    Ui::Simulador *ui;
    FormHome *formHome;
    FormSimulador *formSimulador;
    PanelAdministrativo *panelAdministrativo;
    SistemaDatos *sistemaDatos;

};

#endif // SIMULADOR_H
