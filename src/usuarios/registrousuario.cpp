#include "headers/usuarios/registrousuario.h"
#include "ui_registrousuario.h"

RegistroUsuario::RegistroUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistroUsuario)
{
    ui->setupUi(this);
}

RegistroUsuario::~RegistroUsuario()
{
    delete ui;
}
