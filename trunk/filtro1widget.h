#ifndef FILTRO1WIDGET_H
#define FILTRO1WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QSignalMapper>

namespace Ui {
    class Filtro1Widget;
}

class Filtro1Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Filtro1Widget(QWidget *parent = 0);
    void iniciarConnects(QPushButton *, char *); //Inicia todos los conects para los botones
                                                 // del Widget NombreProyecto.
    ~Filtro1Widget();

private slots:

    void cambiarTexto(int); //Cambia el texto de los Botones para los Filtros.

private:
    QPushButton *auxButton;
    char *auxActivar;
    Ui::Filtro1Widget *ui;

    QSignalMapper *mapper;
};

#endif // FILTRO1WIDGET_H
