#include "headers/myscrollarea.h"

MyScrollArea::MyScrollArea(QWidget *parent) : QScrollArea(parent)
{
    /* Aquí se coloca todo el código necesario para la creación e
     inicialización del widget */
}

/* Redefinición del método mousePressEvent para tomar las coordenadas x e y del
ratón y almacenarlas en las variables enteras xRaton y yRaton respectivamente */

void MyScrollArea::mousePressEvent(QMouseEvent *event)
{
    int xRaton = event->pos().x() + this->horizontalScrollBar()->value();
    int yRaton = event->pos().y() + this->verticalScrollBar()->value();
    //emitir la señal mousePressed
    emit mousePressed(xRaton, yRaton);
}
