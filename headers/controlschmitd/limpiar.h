#ifndef LIMPIAR_H
#define LIMPIAR_H

#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class Limpiar;
}

class Limpiar : public QWidget
{
    Q_OBJECT
    
public:
    explicit Limpiar(QWidget *parent = 0);
    ~Limpiar();
    
public slots:
    void slotEjecutar();

private:
    Ui::Limpiar *ui;

    QString comando;
    QProcess *bash; //Variable para ejecutar comando en un terminal.
};

#endif // LIMPIAR_H
