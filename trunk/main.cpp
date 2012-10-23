#include <QtGui/QApplication>
#include "adquisiciondatos.h"
#include "cabecerasfits.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AdquisicionDatos VentanaAdquisicionDatos;
    CabecerasFits VentanaCabeceraFits;

    VentanaCabeceraFits.show();
    VentanaAdquisicionDatos.show();

    return a.exec();
}
