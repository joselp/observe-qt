#include "headers/mysubwindow.h"

MySubWindow::MySubWindow(QWidget *parent) : QMdiSubWindow(parent)
{
    /* Aquí se coloca todo el código necesario para la creación e
     inicialización del widget */
}

void MySubWindow::closeEvent(QCloseEvent *)
{
    this->hide();
}

