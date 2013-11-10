#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <QWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class RegistroUsuario;
}

class RegistroUsuario : public QWidget
{
    Q_OBJECT
    
public:
    explicit RegistroUsuario(QWidget *parent = 0);
    ~RegistroUsuario();
    
public slots:
    void slotAceptar();
    void slotCancelar();
    void slotRegistroAdmin(int );

private:
    Ui::RegistroUsuario *ui;
};

#endif // REGISTROUSUARIO_H
