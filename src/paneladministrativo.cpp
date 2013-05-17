#include "headers/paneladministrativo.h"
#include "ui_paneladministrativo.h"

PanelAdministrativo::PanelAdministrativo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PanelAdministrativo)
{
    ui->setupUi(this);
}

PanelAdministrativo::~PanelAdministrativo()
{
    delete ui;
}
