#ifndef FORMSIMULADOR_H
#define FORMSIMULADOR_H

#include <QWidget>
#include <QPixmap>
#include "headers/adquisiciondatos.h"
#include "headers/cabecerasfits.h"
#include "headers/mybuttonicon.h"

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
    AdquisicionDatos* getAdquisicionDatos(); //Retorna la variable adquisicionDatos;
    ~FormSimulador();


public slots:
    void slotIniciarObservacion();
    void slotModia();
    void slotControlShmidt();
    
private:
    Ui::FormSimulador *ui;
    AdquisicionDatos *adquisicionDatos;
    myButtonIcon *iconControlSchmidt;
    //CabecerasFits *cabecerasFits;
    QPixmap fondo;
    QPixmap scaledPixmap;

};

#endif // FORMSIMULADOR_H
