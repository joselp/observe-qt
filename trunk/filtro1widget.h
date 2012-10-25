#ifndef FILTRO1WIDGET_H
#define FILTRO1WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

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

    void cambiarTexto1();
    void cambiarTexto2();
    void cambiarTexto3();
    void cambiarTexto4();
    void cambiarTexto5();
    void cambiarTexto6();
    void cambiarTexto7();
    void cambiarTexto8();
    void cambiarTexto9();
    void cambiarTexto10();
    void cambiarTexto11();
    void cambiarTexto12();
    void cambiarTexto13();
    void cambiarTexto14();
    void cambiarTexto15();
    void cambiarTexto16();
    void cambiarTexto17();
    void cambiarTexto18();
    void cambiarTexto19();
    void cambiarTexto20();
    void cambiarTexto21();

private:
    QPushButton *auxButton;
    char *auxActivar;
    Ui::Filtro1Widget *ui;
};

#endif // FILTRO1WIDGET_H
