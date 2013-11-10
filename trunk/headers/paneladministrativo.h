#ifndef PANELADMINISTRATIVO_H
#define PANELADMINISTRATIVO_H

#include <QWidget>
#include <QSqlQuery>
#include <headers/cargas/cargarprueba.h>

namespace Ui {
    class PanelAdministrativo;
}

class PanelAdministrativo : public QWidget
{
    Q_OBJECT

public:
    explicit PanelAdministrativo(QWidget *parent = 0);
    void initGui(); //Inicia la interfaz del panel administrativo
    void desactivarCampos(); //Funcion que deshabilita la edicion de los campos
    ~PanelAdministrativo();

public slots:
    void slotCargarPrueba();
    void slotAsignarDatos(QSqlQuery,QSqlQuery);
    void slotAceptar();
    void slotLimpiar(); //Reinicia todos los valores de los campos editables

private:
    Ui::PanelAdministrativo *ui;
    CargarPrueba *cargarPrueba;
    bool pruebaNueva; //Indica si la prueba es nueva o es una prueba cargada
    QString idPrueba;
};

#endif // PANELADMINISTRATIVO_H
