#ifndef CONTROLSCHMITD_H
#define CONTROLSCHMITD_H

#include <QMainWindow>
#include <QDebug>
#include <QMdiArea>
#include "headers/controlschmitd/summary.h"
#include "headers/controlschmitd/limpiar.h"
#include "headers/controlschmitd/shutdall.h"
#include "headers/controlschmitd/slayall.h"
#include "headers/mysubwindow.h"

namespace Ui {
class Controlschmitd;
}

class Controlschmitd : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Controlschmitd(QWidget *parent = 0);
    void initAction();
    void setControlSchmitd(QMdiArea *m);
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

signals:
    void abrirObserve();

private:
    Ui::Controlschmitd *ui;
    QMdiArea *mdiArea;
    Summary *summary;
    Limpiar *limpiar;
    ShutdAll *shutdAll;
    SlayAll *slayAll;
};

#endif // CONTROLSCHMITD_H
