#ifndef FORMSIMULADOR_H
#define FORMSIMULADOR_H

#include <QWidget>
#include "adquisiciondatos.h"
#include "cabecerasfits.h"

namespace Ui {
class FormSimulador;
}

class FormSimulador : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormSimulador(QWidget *parent = 0);
    void asignarVentanas();
    ~FormSimulador();
    
private:
    Ui::FormSimulador *ui;
    AdquisicionDatos *adquisicionDatos;
    //CabecerasFits *cabecerasFits;

};

#endif // FORMSIMULADOR_H
