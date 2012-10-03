#ifndef ADQUISICIONDATOS_H
#define ADQUISICIONDATOS_H

#include <QMainWindow>

namespace Ui {
    class AdquisicionDatos;
}

class AdquisicionDatos : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdquisicionDatos(QWidget *parent = 0);
    ~AdquisicionDatos();

private:
    Ui::AdquisicionDatos *ui;
};

#endif // ADQUISICIONDATOS_H
