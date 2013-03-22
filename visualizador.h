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
    ~Visualizador();

private slots:
    void zoomIn();
    void zoomOut();
    void zoomNormal();
    void slotParaManejarRaton(int, int);

private:

    ProcesoFits *procesoFits;
    QGraphicsScene *scene;
    GraphWidget *visor;
    Ui::Visualizador *ui;
    QScrollArea *scrollArea;  /*!< Área de scroll.  */
    MyScrollArea *myScroll;
};

#endif // VISUALIZADOR_H
