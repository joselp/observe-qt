#include "headers/formhome.h"
#include "ui_formhome.h"
#include <QSqlQuery>
#include <QtGui>

FormHome::FormHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome)
{
    ui->setupUi(this);

}

bool FormHome::autenticar()
{
        QSqlQuery query;
        query.exec("SELECT email,pass FROM persona");
        while (query.next()) {
            if(query.value(0).toString() == ui->userLineEdit->text() && query.value(1).toString() == ui->passLineEdi->text())
                return true;
        }

    return false;
}

FormHome::~FormHome()
{
    delete ui;
}

QPushButton *FormHome::getButtonAcceder()
{
    return ui->acccederPushButton;
}
