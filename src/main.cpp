#include <QtGui/QApplication>
#include "headers/adquisiciondatos.h"
#include "headers/simulador.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    AdquisicionDatos VentanaAdquisicionDatos;

//    VentanaAdquisicionDatos.show();

    Simulador simulador;
    simulador.show();

//    Terminal terminal;
//    terminal.show();

    return a.exec();
}
