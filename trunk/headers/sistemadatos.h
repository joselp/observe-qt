#ifndef SISTEMADATOS_H
#define SISTEMADATOS_H

#include<QWidget>
#include<QMessageBox>
#include<QDebug>


namespace Ui {
class SistemaDatos;
}

class SistemaDatos : public QWidget
{
    Q_OBJECT
    
public:
    explicit SistemaDatos(QWidget *parent = 0);
    void initGui();
    ~SistemaDatos();

    //setters
    void setQnx1(bool a);
    void setQnx2(bool a);
    void setQnx3(bool a);
    void setQnx4(bool a);
    void setPc5(bool a);
    void setPc6(bool a);

    //getters
    bool getQnx1();
    bool getQnx2();
    bool getQnx3();
    bool getQnx4();
    bool getPc5();
    bool getPc6();
    
public slots:
    void slotQnx1Encender();
    void slotQnx2Encender();
    void slotQnx3Encender();
    void slotQnx4Encender();
    void slotPc5Encender();
    void slotPc6Encender();
    void slotQnx1Apagar();
    void slotQnx2Apagar();
    void slotQnx3Apagar();
    void slotQnx4Apagar();
    void slotPc5Apagar();
    void slotPc6Apagar();


private:
    Ui::SistemaDatos *ui;
    bool qnx1; //Indica si qnx1 esta encendida o apagada
    bool qnx2; //Indica si qnx2 esta encendida o apagada
    bool qnx3; //Indica si qnx3 esta encendida o apagada
    bool qnx4; //Indica si qnx4 esta encendida o apagada
    bool pc5; //Indica si Pc5 esta encendida o apagada
    bool pc6; //Indica si Pc6 esta encendida o apagada

};

#endif // SISTEMADATOS_H
