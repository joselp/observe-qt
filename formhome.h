#ifndef FORMHOME_H
#define FORMHOME_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class FormHome;
}

class FormHome : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormHome(QWidget *parent = 0);
    void asignarForm(QWidget *);
    QPushButton* obtenerButtonAcceder();

    bool autenticar();
    ~FormHome();


    
private:
    Ui::FormHome *ui;
};

#endif // FORMHOME_H
