#ifndef CABECERASFITS_H
#define CABECERASFITS_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include "nombreproyectowidget.h"

namespace Ui {
    class CabecerasFits;
}

class CabecerasFits : public QWidget
{
    Q_OBJECT

public:
    explicit CabecerasFits(QWidget *parent = 0);
    void iniciarGui();
    void iniciarNombreProyectoWidget();
    ~CabecerasFits();

private slots:
    void mostrarNombreProyectoWidget();

private:

    NombreProyectoWidget *nombreProyecto;
    char *activarNombreProyectoWidget; //Para activar o no el Widget NombreProyecto

    Ui::CabecerasFits *ui;

};

#endif // CABECERASFITS_H
