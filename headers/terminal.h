#ifndef TERMINAL_H
#define TERMINAL_H

#include <QWidget>
#include "headers/miTextArea.h"

namespace Ui {
class Terminal;
}

class Terminal : public QWidget
{
    Q_OBJECT
    
public:
    explicit Terminal(QWidget *parent = 0);
    void initGui();
    miTextArea * obtenerConsolaComandos(); //Funcion que retorna el textArea que simula la consola de comandos
    ~Terminal();
    
private:
    Ui::Terminal *ui;
    miTextArea *consolaComandos; //Variable que me permitira simular un terminal
    };

#endif // TERMINAL_H
