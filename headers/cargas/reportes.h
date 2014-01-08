#ifndef REPORTES_H
#define REPORTES_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>
#include <headers/cargas/reporteadmin.h>

namespace Ui {
class Reportes;
}

class Reportes : public QWidget
{
    Q_OBJECT
    
public:
    explicit Reportes(QWidget *parent = 0);
    void setIdPersona(int i);
    ~Reportes();
    
public slots:
    void slotRowSelected(int);
    void slotCerrar();

private:
    Ui::Reportes *ui;
    QTableWidget *tablePrestamo;
    QTableWidgetItem *item;
    ReporteAdmin *reporteAdmin;
    int idPersona;
};

#endif // REPORTES_H
