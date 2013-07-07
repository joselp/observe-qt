#ifndef FORMSIMULADOR_H
#define FORMSIMULADOR_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include "headers/adquisiciondatos.h"
#include "headers/cabecerasfits.h"
#include "headers/mybuttonicon.h"
#include "headers/terminal.h"

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
    ~FormSimulador();


public slots:
    void slotIniciarObservacion();
    void slotModia();
    void slotControlShmidt();
    void slotTerminal();
    void slotParaManejarRaton(int, int);

signals:
    void mousePressed(int x, int y);
    
private:
    Ui::FormSimulador *ui;
    AdquisicionDatos *adquisicionDatos;
    Terminal *terminal;
    myButtonIcon *iconControlSchmidt;
    myButtonIcon *iconTerminal; //Botton que simula el icono de un terminal
    //CabecerasFits *cabecerasFits;
    QPixmap fondo;
    QPixmap scaledPixmap;

};

#endif // FORMSIMULADOR_H
