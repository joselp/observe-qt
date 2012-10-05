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
    void cargarGui();
    void logicaGui();
    ~AdquisicionDatos();

private slots:
    void slotComandoDeObservacion(int);
    void slotModoLineaReloj(int);

private:
    bool primero;
    bool eliminar;
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
