#ifndef ASISTENTE_H
#define ASISTENTE_H

#include <QWidget>

namespace Ui {
class Asistente;
}

class Asistente : public QWidget
{
    Q_OBJECT
    
public:
    explicit Asistente(QWidget *parent = 0);
    void initGui(); //Inicia la gui
    void logica(); //Valida cada campo de la ventana asistente
    ~Asistente();
    
private:
    Ui::Asistente *ui;
};

#endif // ASISTENTE_H
