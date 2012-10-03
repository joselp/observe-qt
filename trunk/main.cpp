#include <QtGui/QApplication>
#include "adquisiciondatos.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdquisicionDatos w;
    w.show();

    return a.exec();
}
