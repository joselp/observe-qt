#ifndef FORMHOME_H
#define FORMHOME_H

#include <QWidget>
#include <QPushButton>
#include "headers/usuarios/registrousuario.h"
#include "headers/usuarios/recuperarpassword.h"

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
    void limpiarCampos();

    bool autenticar();
    ~FormHome();

public slots:
    void slotCrearUsuario();
    void slotRecuperarPass();
    
private:
    Ui::FormHome *ui;
    RegistroUsuario *registroUsuario;
    RecuperarPassWord *recuperarPassWord;
    QString idUsuario;
};

#endif // FORMHOME_H
