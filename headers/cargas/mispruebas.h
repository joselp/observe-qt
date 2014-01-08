#ifndef MISPRUEBAS_H
#define MISPRUEBAS_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <headers/cargas/formprotocolo.h>
#include <headers/cargas/reporte.h>

namespace Ui {
class MisPruebas;
}

class MisPruebas : public QWidget
{
    Q_OBJECT
    
public:
    explicit MisPruebas(QWidget *parent = 0);
    void cargarPruebas(QString idUsuario);
    void setIdPersona(int i);
    void setReporte(bool r);
    ~MisPruebas();
    
public slots:
    void slotRowSelected(int);
    void slotAceptar();

signals:
    void enviarDatos(QSqlQuery);

private:
    Ui::MisPruebas *ui;
    QTableWidget *tablePrestamo;
    QTableWidgetItem *item;
    FormProtocolo *formProtocolo;
    int idUsuarioAux;
    Reporte *report; //Ventana para generar el reporte.
    bool reporte; //Me indica si ingrese a esta ventana por la accion reporte.
};

#endif // MISPRUEBAS_H
