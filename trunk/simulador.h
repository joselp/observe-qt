#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include "formhome.h"
#include "formsimulador.h"
#include "paneladministrativo.h"


namespace Ui {
class Simulador;
}

class Simulador : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Simulador(QWidget *parent = 0);
    void cambiarPanel(QWidget*); //Me permite cambiar los paneles de la ventana principal del simulador
    void removerContenidoWidget(); //Remueve el widget que se encuentre en el layout de contenido
    void mostrarMenu();//Muestra el menu del lado izquierdo
    void ocultarMenu();//Oculta el menu del lado izquierdo
    void resizeEvent(QResizeEvent *);
    ~Simulador();
    
public slots:
    void slotAcceder(); //Verifico si puedo acceder al simulador
    void slotPanelAdministrativo(); //Inicia la ventana de panel administrativo
    void slotImagenesNormales();
    void slotSalir(); //Cierra el sistema


private:
    Ui::Simulador *ui;
    FormHome *formHome;
    FormSimulador *formSimulador;
    PanelAdministrativo *panelAdministrativo;

};

#endif // SIMULADOR_H
