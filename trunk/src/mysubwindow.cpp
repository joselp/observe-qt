#include "headers/mysubwindow.h"

MySubWindow::MySubWindow(QWidget *parent) : QMdiSubWindow(parent)
{
    /* Aquí se coloca todo el código necesario para la creación e
     inicialización del widget */
    //this->setWindowFlags( Qt::Window | Qt::WindowStaysOnTopHint | Qt::CustomizeWindowHint);
    this->setWindowFlags( Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

}

void MySubWindow::closeEvent(QCloseEvent *)
{
    this->hide();
}

