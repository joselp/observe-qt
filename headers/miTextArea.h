#ifndef MITEXTAREA_H
#define MITEXTAREA_H

#include <QObject>
#include <QKeyEvent>
#include <QTextEdit>
#include <QDebug>
#include <QTextCursor>
#include <QProcess>
#include <QMessageBox>
#include <QBitArray>
#include <QRegExp>

//Esta clase me permite un area de texto que simulará un terminal.

class miTextArea : public QTextEdit
{
     Q_OBJECT
public:
    explicit miTextArea(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);
    void ejecutar(QString comando); //Funcion que ejecuta un comando en el terminal del sistema
    void asignarError1(bool );
    void asignarError2(bool );
    void asignarError3(bool );
    void asignarError4(bool );
    void asignarError5(bool );
    void asignarError6(bool );

public slots:

signals:
    void ejecutarComando(QString);

private:
    QTextCursor cursor;
    bool qnx1; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool qnx2; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool qnx3; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool qnx4; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool qnx5; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool qnx6; //variable que me indica si estoy dentro de alguna qnx desde la consola
    bool obtupas; //Variable que me indica si estoy ejecutando obtupas
    bool obturador1; //Variable que me indica si estoy ejecutando obtupas
    bool movd2; //Variable que me indica si estoy ejecutando movde2
    int posx,posy,posz,post; //Variables que mantienen las posiciones de los dedos
    bool dedox,dedoy,dedoz,dedot; //Me indica si se esta moviendo un dedo en especifico
    bool error1, error2, error3, error4, error5, error6;

};

#endif // MITEXTAREA_H
