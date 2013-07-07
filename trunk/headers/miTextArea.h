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

//Esta clase me permite un area de texto que simulará un terminal.

class miTextArea : public QTextEdit
{
     Q_OBJECT
public:
    explicit miTextArea(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e);
    void ejecutar(QString comando); //Funcion que ejecuta un comando en el terminal del sistema


public slots:

private:
    QTextCursor cursor;

};

#endif // MITEXTAREA_H
