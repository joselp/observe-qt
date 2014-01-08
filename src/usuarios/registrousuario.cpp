#include "headers/usuarios/registrousuario.h"
#include "ui_registrousuario.h"
#include <QRegExp>

RegistroUsuario::RegistroUsuario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistroUsuario)
{
    ui->setupUi(this);
    this->setWindowTitle("Registro de Usuarios");
    ui->tipoDeUsuarioComboBox->addItem("Estudiante");
    ui->tipoDeUsuarioComboBox->addItem("Administrador");
    ui->codigoDeAdministradorLabel->setVisible(false);
    ui->codigoDeAdministradorLineEdit->setVisible(false);
    //ui->eMailLineEdit->setValidator(new QRegExpValidator(QRegExp("^[^0-9][a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*[@][a-zA-Z0-9_]+([.][a-zA-Z0-9_]+)*[.][a-zA-Z]{2,4}$"),this));
    connect(ui->tipoDeUsuarioComboBox,SIGNAL(currentIndexChanged(int)), this, SLOT(slotRegistroAdmin(int )));
    connect(ui->aceptarPushButton, SIGNAL(clicked()), this, SLOT(slotAceptar()));
    connect(ui->cancelarPushButton, SIGNAL(clicked()), this, SLOT(slotCancelar()));
}

RegistroUsuario::~RegistroUsuario()
{
    delete ui;
}

void RegistroUsuario::slotAceptar()
{
    if(!ui->nombreLineEdit->text().size()==0 && !ui->apellidoLineEdit->text().size()==0 && !ui->eMailLineEdit->text().size()==0
            && !ui->contrasenaLineEdit->text().size()==0 && !ui->repitaContrasenaLineEdit->text().size()==0 && !ui->fraseSecretaLineEdit->text().size()==0
            && (ui->contrasenaLineEdit->text() == ui->repitaContrasenaLineEdit->text())){
        QSqlQuery query;
        QString sql;
        if(ui->tipoDeUsuarioComboBox->currentText()=="Administrador" && ui->codigoDeAdministradorLineEdit->text()=="admin123"){
            sql = "INSERT INTO persona (nombre,apellido, email, pass, tipo, frase_secretra) VALUES ('"+ui->nombreLineEdit->text()+"','"+ui->apellidoLineEdit->text()+"','"+ui->eMailLineEdit->text()+"','"+ui->contrasenaLineEdit->text()+"','"+ui->tipoDeUsuarioComboBox->currentText()+"','"+ui->fraseSecretaLineEdit->text()+"')";
            qDebug()<<sql;
            if(query.exec(sql)){
                this->close();
                QMessageBox msg;
                msg.information(this, "Registro exitoso", "Se ha registrado con exito");
            }

            else{
                QMessageBox msg;
                msg.critical(this, "Error", "Ocurrio un error, el email ya existe o codigo\nde administrador invalido.");
            }
        }
        else{
            sql = "INSERT INTO persona (nombre,apellido, email, pass, tipo, frase_secreta) VALUES ('"+ui->nombreLineEdit->text()+"','"+ui->apellidoLineEdit->text()+"','"+ui->eMailLineEdit->text()+"','"+ui->contrasenaLineEdit->text()+"','"+ui->tipoDeUsuarioComboBox->currentText()+"','"+ui->fraseSecretaLineEdit->text()+"')";
            qDebug()<<sql;
            if(query.exec(sql)){
                this->close();
                QMessageBox msg;
                msg.information(this, "Registro exitoso", "Se ha registrado con exito");
            }

            else{
                QMessageBox msg;
                msg.critical(this, "Error", "Ocurrio un error, el email ya existe.");
            }
        }
    }
    else{
        QMessageBox msg;
        msg.critical(this, "Error", "Debe rellenar todos los campos correctamente");
    }

}

void RegistroUsuario::slotCancelar()
{
    this->close();
}

void RegistroUsuario::slotRegistroAdmin(int i)
{
    if(i==0){
        ui->codigoDeAdministradorLabel->setVisible(false);
        ui->codigoDeAdministradorLineEdit->setVisible(false);
    }
    if(i==1){
        ui->codigoDeAdministradorLabel->setVisible(true);
        ui->codigoDeAdministradorLineEdit->setVisible(true);
    }
}
