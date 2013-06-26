#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QWidget>
#include <QtGui>
#include "procesofits.h"
#include <QGraphicsView>
#include <QScrollArea>
#include "headers/graphwidget.h"
#include "headers/myscrollarea.h"

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
    ~Visualizador();

    //Setters
    void setTotalLineas(int total); //Asigna el total de lineas para al proceso fits
    void setPrueba(QString); //Asigna la variable prueba que se realizara en proceso fits
    void setNumeroLineaActual(int); //Asigna el numero de linea que se esta leyendo al procesoFits
    void setCondicionesCielo(QString ); //Envia las condiciones del cielo a procesoFits

private slots:
//    void zoomIn();
//    void zoomOut();
//    void zoomNormal();
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
    QString prueba;

};

#endif // VISUALIZADOR_H
