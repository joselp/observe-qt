#include "adquisiciondatos.h"
#include "ui_adquisiciondatos.h"

AdquisicionDatos::AdquisicionDatos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdquisicionDatos)
{
    ui->setupUi(this);
}

AdquisicionDatos::~AdquisicionDatos()
{
    delete ui;
}
