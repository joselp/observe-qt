#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <QWidget>

namespace Ui {
class RegistroUsuario;
}

class RegistroUsuario : public QWidget
{
    Q_OBJECT
    
public:
    explicit RegistroUsuario(QWidget *parent = 0);
    ~RegistroUsuario();
    
private:
    Ui::RegistroUsuario *ui;
};

#endif // REGISTROUSUARIO_H
