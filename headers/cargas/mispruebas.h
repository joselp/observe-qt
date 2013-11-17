#ifndef MISPRUEBAS_H
#define MISPRUEBAS_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <headers/cargas/formprotocolo.h>

namespace Ui {
class MisPruebas;
}

class MisPruebas : public QWidget
{
    Q_OBJECT
    
public:
    explicit MisPruebas(QWidget *parent = 0);
    void cargarPruebas(QString idUsuario);
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
};

#endif // MISPRUEBAS_H
