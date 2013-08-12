#ifndef CONTROLSCHMIDT_H
#define CONTROLSCHMIDT_H

#include <QWidget>

namespace Ui {
class ControlSchmidt;
}

class ControlSchmidt : public QWidget
{
    Q_OBJECT
    
public:
    explicit ControlSchmidt(QWidget *parent = 0);
    ~ControlSchmidt();
    
private:
    Ui::ControlSchmidt *ui;
};

#endif // CONTROLSCHMIDT_H
