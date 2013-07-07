#include "headers/sistemadatos.h"
#include "ui_sistemadatos.h"

SistemaDatos::SistemaDatos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SistemaDatos)
{
    ui->setupUi(this);
}

SistemaDatos::~SistemaDatos()
{
    delete ui;
}
