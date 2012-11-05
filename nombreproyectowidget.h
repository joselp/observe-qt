#ifndef NOMBREPROYECTOWIDGET_H
#define NOMBREPROYECTOWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class NombreProyectoWidget;
}

class NombreProyectoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NombreProyectoWidget(QWidget *parent = 0);
    void iniciarConnects(QPushButton *, char *); //Inicia todos los conects para los botones
                                                 // del Widget NombreProyecto.
    void eliminarWidgetNombreProyecto(); //Elimina el widget nombre proyecto.

    ~NombreProyectoWidget();

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
    Ui::NombreProyectoWidget *ui;
};

#endif // NOMBREPROYECTOWIDGET_H
