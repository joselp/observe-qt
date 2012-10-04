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
    ~AdquisicionDatos();

private slots:

private:
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
