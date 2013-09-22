#ifndef CONTROLSCHMITD_H
#define CONTROLSCHMITD_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class Controlschmitd;
}

class Controlschmitd : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Controlschmitd(QWidget *parent = 0);
    void initAction();
    ~Controlschmitd();

private slots:
    void slotFoco();
    void slotObserve();
    void slotSummary();
    void slotLimpiar();
    void slotTransferir();
    void slotAnalizar();
    void slotSlayall();
    void slotShutdall();
    void slotAyuda();
    void slotSalir();

private:
    Ui::Controlschmitd *ui;
};

#endif // CONTROLSCHMITD_H
