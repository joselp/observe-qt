#ifndef SISTEMADATOS_H
#define SISTEMADATOS_H

#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <headers/mensajeopciones.h>

namespace Ui {
class SistemaDatos;
}

class SistemaDatos : public QWidget
{
    Q_OBJECT

public:
    explicit SistemaDatos(QWidget *parent = 0);
    void initGui();
    void closeEvent(QCloseEvent *); //Captura el evento cerrar Aplicacion.
    void reinicarSistema();
    ~SistemaDatos();

    //setters
    void setQnx1(bool a);
    void setQnx2(bool a);
    void setQnx3(bool a);
    void setQnx4(bool a);
    void setQnx5(bool a);
    void setQnx6(bool a);
    void setSemilla(int i);

    //getters
    bool getQnx1();
    bool getQnx2();
    bool getQnx3();
    bool getQnx4();
    bool getQnx5();
    bool getQnx6();
    bool getBabel();
    bool getError1();
    bool getError2();
    bool getError3();
    bool getError4();
    bool getError5();
    bool getError6();
    int getSemilla();
    
public slots:
    void slotQnx1Encender();
    void slotQnx2Encender();
    void slotQnx3Encender();
    void slotQnx4Encender();
    void slotQnx5Encender();
    void slotQnx6Encender();
    void slotBabelEncender();
    void slotQnx1Apagar();
    void slotQnx2Apagar();
    void slotQnx3Apagar();
    void slotQnx4Apagar();
    void slotQnx5Apagar();
    void slotQnx6Apagar();
    void slotBabelApagar();
    void slotOpcion(int );

signals:
    void mostrarFondo(bool, bool, bool, bool, bool, bool);
    void ocultarFondo();

private:
    Ui::SistemaDatos *ui;
    bool qnx1; //Indica si qnx1 esta encendida o apagada
    bool qnx2; //Indica si qnx2 esta encendida o apagada
    bool qnx3; //Indica si qnx3 esta encendida o apagada
    bool qnx4; //Indica si qnx4 esta encendida o apagada
    bool Qnx5; //Indica si Qnx5 esta encendida o apagada
    bool Qnx6; //Indica si Qnx6 esta encendida o apagada
    bool babel; //Indica si babel esta encendida o apagada
    bool error1; //Variable que indica error en la conexion de qnx1
    bool error2; //Variable que indica error en la conexion de qnx1
    bool error3; //Variable que indica error en la conexion de qnx1
    bool error4; //Variable que indica error en la conexion de qnx1
    bool error5; //Variable que indica error en la conexion de qnx1
    bool error6; //Variable que indica error en la conexion de qnx1
    int num; //Varible generada aleatoriamente para saber si hay o no conexion
    int semilla; //Variable que aumenta o dismuniye estadistica para errores de conexion

};




#endif // SISTEMADATOS_H
