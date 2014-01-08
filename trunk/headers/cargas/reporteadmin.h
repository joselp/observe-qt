#ifndef REPORTEADMIN_H
#define REPORTEADMIN_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class ReporteAdmin;
}

class ReporteAdmin : public QWidget
{
    Q_OBJECT
    
public:
    explicit ReporteAdmin(QWidget *parent = 0);
    void asignarDatos(QSqlQuery query);
    ~ReporteAdmin();
    
public slots:
    void slotCerrar();
    void slotEliminar();

private:
    Ui::ReporteAdmin *ui;
    int idPrueba;
};

#endif // REPORTEADMIN_H
