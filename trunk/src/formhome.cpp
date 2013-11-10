#include "headers/formhome.h"
#include "ui_formhome.h"
#include <QSqlQuery>
#include <QtGui>

FormHome::FormHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome)
{
    ui->setupUi(this);
    connect(ui->crearCuentaPushButton,SIGNAL(clicked()), this, SLOT(slotCrearUsuario()));
}

bool FormHome::autenticar()
{
        QSqlQuery query;
        query.exec("SELECT id,email,pass FROM persona");
        while (query.next()) {
            if(query.value(1).toString() == ui->userLineEdit->text() && query.value(2).toString() == ui->passLineEdi->text()){
                idUsuario = query.value(0).toInt(0);
                return true;
            }
        }

    return false;
}

FormHome::~FormHome()
{
    delete ui;
}

void FormHome::slotCrearUsuario()
{
        registroUsuario = new RegistroUsuario;
        registroUsuario->show();
}

QPushButton *FormHome::getButtonAcceder()
{
    return ui->acccederPushButton;
}

int FormHome::obtenerIdUsuario()
{
    return idUsuario;
}
