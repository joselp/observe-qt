#ifndef ADQUISICIONDATOS_H
#define ADQUISICIONDATOS_H

#include <QMainWindow>
#include <QDateTime>
#include <QDebug>

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
    ~AdquisicionDatos();

private slots:
    void slotComandoDeObservacion(int);
    void slotModoLineaReloj(int);

private:
    bool primero; //Para determinar la primera entrada al sistema y colocar en ComboBox "seleccione"
    bool eliminar; //Para eliminar el valor de "seleccione" de los ComboBox
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
