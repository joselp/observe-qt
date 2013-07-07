#ifndef SISTEMADATOS_H
#define SISTEMADATOS_H

#include <QWidget>

namespace Ui {
class SistemaDatos;
}

class SistemaDatos : public QWidget
{
    Q_OBJECT
    
public:
    explicit SistemaDatos(QWidget *parent = 0);
    ~SistemaDatos();
    
private:
    Ui::SistemaDatos *ui;
};

#endif // SISTEMADATOS_H
