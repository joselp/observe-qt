#ifndef FORMPROTOCOLO_H
#define FORMPROTOCOLO_H

#include <QWidget>

namespace Ui {
class FormProtocolo;
}

class FormProtocolo : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormProtocolo(QWidget *parent = 0);
    void asignarFiltro1(QString f);
    void asignarFiltro2(QString f);
    void asignarFiltro3(QString f);
    void asignarFiltro4(QString f);
    void asignarDeclinacion(QString d);
    void asignarAnguloHorario(QString aH);
    void asignarDuracion(QString d);
    void asignarTipoObservacion(QString t);
    void asignarInstrumento(QString i);
    void asignarProyecto(QString p);
    ~FormProtocolo();
    
private:
    Ui::FormProtocolo *ui;
};

#endif // FORMPROTOCOLO_H
