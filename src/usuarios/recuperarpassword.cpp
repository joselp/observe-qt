#include "headers/usuarios/recuperarpassword.h"
#include "ui_recuperarpassword.h"

RecuperarPassWord::RecuperarPassWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecuperarPassWord)
{
    ui->setupUi(this);
    this->setWindowTitle("Recuperar Contraseña");
    connect(ui->pushButtonRecuperar,SIGNAL(clicked()),this,SLOT(slotRecuperar()));
}

RecuperarPassWord::~RecuperarPassWord()
{
    delete ui;
}

void RecuperarPassWord::slotRecuperar()
{
    ui->labelPass->setText("");
    bool enviado;
    enviado = false;
    QSqlQuery query;
    query.exec("SELECT email,pass FROM persona WHERE email='"+ui->lineEditEmail->text()+"' AND frase_secreta='"+ui->lineEditFrase->text()+"'");
    if(query.next()) {
        ui->labelPass->setText(query.value(1).toString());
        }
    else{
        QMessageBox msg;
        msg.about(this,"Incorrecto","Email y Frase no coinciden");
    }

}
