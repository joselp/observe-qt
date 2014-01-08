#ifndef REPORTE_H
#define REPORTE_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class Reporte;
}

class Reporte : public QWidget
{
    Q_OBJECT
    
public:
    explicit Reporte(QWidget *parent = 0);
    void setIdPrueba(int i);
    void setIdPersona(int i);
    ~Reporte();
    
public slots:
    void slotEnviar();

private:
    Ui::Reporte *ui;
    QSqlQuery query;
    int idPrueba; //Id de la prueba
    int idPersona; //Id de la persona
};

#endif // REPORTE_H
