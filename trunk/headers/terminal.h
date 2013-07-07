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
    ~Terminal();
    
private:
    Ui::Terminal *ui;
    miTextArea *consolaComandos; //Variable que me permitira simular un terminal
};

#endif // TERMINAL_H
