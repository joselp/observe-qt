#ifndef CARGARPRUEBA_H
#define CARGARPRUEBA_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class CargarPrueba;
}

class CargarPrueba : public QWidget
{
    Q_OBJECT
    
public:
    explicit CargarPrueba(QWidget *parent = 0);
    ~CargarPrueba();
    
public slots:
    void slotRowSelected(int);

private:
    Ui::CargarPrueba *ui;
    QTableWidget * tablePrestamo;
    QTableWidgetItem * item;

signals:
    void enviarDatos(QSqlQuery,QSqlQuery);
};

#endif // CARGARPRUEBA_H
