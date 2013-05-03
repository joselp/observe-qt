#include "formsimulador.h"
#include "ui_formsimulador.h"

FormSimulador::FormSimulador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSimulador)
{
    ui->setupUi(this);
    adquisicionDatos= new AdquisicionDatos;
    //cabecerasFits = new CabecerasFits;
}

void FormSimulador::asignarVentanas()
{
        ui->mdiArea->addSubWindow(adquisicionDatos);
        ui->mdiArea->addSubWindow(adquisicionDatos->obtenerCabeceraFits());
        adquisicionDatos->show();
        adquisicionDatos->obtenerCabeceraFits()->show();
}


FormSimulador::~FormSimulador()
{
    delete ui;
}
