#include "formhome.h"
#include "ui_formhome.h"
#include <QtGui>

FormHome::FormHome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome)
{
    ui->setupUi(this);

}

bool FormHome::autenticar()
{
    return true;
}

FormHome::~FormHome()
{
    delete ui;
}

QPushButton *FormHome::obtenerButtonAcceder()
{
    return ui->acccederPushButton;
}
