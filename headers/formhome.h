#ifndef FORMHOME_H
#define FORMHOME_H

#include <QWidget>
#include <QPushButton>
#include "headers/usuarios/registrousuario.h"

namespace Ui {
class FormHome;
}

class FormHome : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormHome(QWidget *parent = 0);
    void asignarForm(QWidget *);
    QPushButton* getButtonAcceder();
    QString obtenerIdUsuario();

    bool autenticar();
    ~FormHome();

public slots:
    void slotCrearUsuario();
    
private:
    Ui::FormHome *ui;
    RegistroUsuario *registroUsuario;
    QString idUsuario;
};

#endif // FORMHOME_H
