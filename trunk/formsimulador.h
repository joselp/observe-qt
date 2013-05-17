#ifndef FORMSIMULADOR_H
#define FORMSIMULADOR_H

#include <QWidget>
#include "adquisiciondatos.h"
#include "cabecerasfits.h"
#include "mybuttonicon.h"

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
    ~FormSimulador();


public slots:
    void slotIniciarObservacion();
    void slotControlShmidt();
    
private:
    Ui::FormSimulador *ui;
    AdquisicionDatos *adquisicionDatos;
    myButtonIcon *iconControlSchmidt;
    //CabecerasFits *cabecerasFits;

};

#endif // FORMSIMULADOR_H
