#include "headers/graphwidget.h"
#include <QDebug>

GraphWidget::GraphWidget(QWidget *parent) : QGraphicsView(parent) {
    /* Aquí se coloca todo el código necesario para la creación e
     inicialización del widget */
}

/* Redefinición del método mousePressEvent para tomar las coordenadas x e y del
ratón y almacenarlas en las variables enteras xRaton y yRaton respectivamente */

void GraphWidget::mousePressEvent(QMouseEvent *event){

    int xRaton = event->pos().x();
    int yRaton = event->pos().y();
    //emitir la señal mousePressed
    emit mousePressed(xRaton, yRaton);

}

