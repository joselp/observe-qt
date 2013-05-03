#include <QtGui/QApplication>
#include "adquisiciondatos.h"
#include "simulador.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    AdquisicionDatos VentanaAdquisicionDatos;

//    VentanaAdquisicionDatos.show();

    Simulador simulador;
    simulador.show();

    return a.exec();
}
