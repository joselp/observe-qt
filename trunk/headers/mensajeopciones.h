#ifndef MENSAJEOPCIONES_H
#define MENSAJEOPCIONES_H

#include <QWidget>
#include <stdlib.h>
#include <time.h>
#include <QDebug>

namespace Ui {
class MensajeOpciones;
}

class MensajeOpciones : public QWidget
{
    Q_OBJECT
    
public:
    explicit MensajeOpciones(QWidget *parent = 0);
    void cargarOpciones(); //Funcion que carga las opciones a mostrar
        ~MensajeOpciones();

public slots:
    void slotAceptar(); //Slot para el boton aceptar
    
signals:
    void opcionCorrecta(int );

private:
    QStringList correctas; //Opciones correctas
    QStringList errores; //Opciones invalidas
    Ui::MensajeOpciones *ui;
};

#endif // MENSAJEOPCIONES_H
