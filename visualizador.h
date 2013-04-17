#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QWidget>
#include <QtGui>
#include "procesofits.h"
#include <QGraphicsView>
#include <QScrollArea>
#include "graphwidget.h"
#include "myscrollarea.h"

namespace Ui {
    class Visualizador;
}

class Visualizador : public QWidget
{
    Q_OBJECT

public:
    explicit Visualizador(QWidget *parent = 0);
    void initGui();
    void initLectura(); //Comienza la lectura de linea de datos del archivo fits.
    void setTotalLineas(int total); //Coloca el total de lineas para asignarlo al proceso fits
    ~Visualizador();

private slots:
    void zoomIn();
    void zoomOut();
    void zoomNormal();
    void slotParaManejarRaton(int, int);
    void slotQnx1();
    void slotQnx2();
    void slotQnx3();
    void slotQnx4();
    void slotCcd1();
    void slotCcd2();
    void slotCcd3();
    void slotCcd4();

private:


    ProcesoFits *procesoFits;
    QGraphicsScene *scene;
    GraphWidget *visor;
    Ui::Visualizador *ui;
    QScrollArea *scrollArea;  /*!< Área de scroll.  */
    MyScrollArea *myScroll;
    int totalLineas;
};

#endif // VISUALIZADOR_H
