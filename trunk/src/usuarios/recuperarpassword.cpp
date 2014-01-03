#include "headers/usuarios/recuperarpassword.h"
#include "ui_recuperarpassword.h"

RecuperarPassWord::RecuperarPassWord(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecuperarPassWord)
{
    ui->setupUi(this);
    connect(ui->pushButtonEnviar,SIGNAL(clicked()),this,SLOT(slotEnviar()));
}

RecuperarPassWord::~RecuperarPassWord()
{
    delete ui;
}

void RecuperarPassWord::slotEnviar()
{
    bool enviado;
    enviado = false;
    QSqlQuery query;
    query.exec("SELECT email,pass FROM persona WHERE email='"+ui->lineEditEmail->text()+"'");
    if(query.next()) {
        QMessageBox msg;
        msg.about(this,"Mensaje Enviado","Se ha enviado un correo con su contraseña");
        enviado=true;
        }
    else
        qDebug()<<"Nooo hijo";

    if(enviado==true)
        this->close();
}
