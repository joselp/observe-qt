#ifndef ADQUISICIONDATOS_H
#define ADQUISICIONDATOS_H


#include <QMainWindow>
#include <QDateTime>
#include <QDebug>
#include <cabecerasfits.h>


namespace Ui {
    class AdquisicionDatos;
}

class AdquisicionDatos : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdquisicionDatos(QWidget *parent = 0);
    void iniciarGui();
    void logicaGui();
    void closeEvent(QCloseEvent *); //Captura el evento cerrar Aplicacion.
    ~AdquisicionDatos();

private slots:
    void slotComandoDeObservacion(int); //Cambiar GUI segun asignacion
    void slotModoLineaReloj(int); //Cambia GUI segun asignacion

private:
    bool primero; //Para determinar la primera entrada al sistema y colocar en ComboBox "seleccione"
    bool eliminar; //Para eliminar el valor de "seleccione" de los ComboBox

    CabecerasFits *ventanaCabeceraFits;
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
