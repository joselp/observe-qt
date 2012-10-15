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
    void iniciarConnects(QPushButton *, char *);
    ~NombreProyectoWidget();

private slots:
    void cambiarTexto1();
//    void cambiarTexto2(QPushButton *);
//    void cambiarTexto3(QPushButton);
//    void cambiarTexto4(QPushButton);
//    void cambiarTexto5(QPushButton);
//    void cambiarTexto6(QPushButton);
//    void cambiarTexto7(QPushButton);
//    void cambiarTexto8(QPushButton);
//    void cambiarTexto9(QPushButton);
//    void cambiarTexto10(QPushButton);
//    void cambiarTexto11(QPushButton);
//    void cambiarTexto12(QPushButton);
//    void cambiarTexto13(QPushButton);
//    void cambiarTexto14(QPushButton);
//    void cambiarTexto15(QPushButton);
//    void cambiarTexto16(QPushButton);
//    void cambiarTexto17(QPushButton);
//    void cambiarTexto18(QPushButton);
//    void cambiarTexto19(QPushButton);
//    void cambiarTexto20(QPushButton);
//    void cambiarTexto21(QPushButton);
//    void cambiarTexto22(QPushButton);


private:
    QPushButton *auxButton;
    char *auxActivar;
    Ui::NombreProyectoWidget *ui;
};

#endif // NOMBREPROYECTOWIDGET_H
