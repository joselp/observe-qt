#ifndef MYBUTTONICON_H
#define MYBUTTONICON_H

#include <QObject>
#include <QMouseEvent>
#include <qpushbutton.h>


//Esta clase me permite definir los iconos que se usaran en la clase Simulador.

class myButtonIcon : public QPushButton
{
    Q_OBJECT
public:
    explicit myButtonIcon(QWidget *parent = 0);
    void mouseDoubleClickEvent(QMouseEvent *);
    
signals:
    void doubleclick();
    
public slots:
    
};

#endif // MYBUTTONICON_H
