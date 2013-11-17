#include "headers/controlschmitd/controlschmitd.h"
#include "ui_controlschmitd.h"

Controlschmitd::Controlschmitd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controlschmitd)
{
    ui->setupUi(this);
    initAction();
}

void Controlschmitd::initAction()
{
    connect(ui->actionFoco, SIGNAL(triggered()), this, SLOT(slotFoco()));
    connect(ui->actionObserve,SIGNAL(triggered()),this,SLOT(slotObserve()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotSalir()));
}

void Controlschmitd::slotFoco()
{
}

void Controlschmitd::slotObserve()
{
    emit abrirObserve();
}

void Controlschmitd::slotSummary()
{
}

void Controlschmitd::slotLimpiar()
{
}

void Controlschmitd::slotTransferir()
{
}

void Controlschmitd::slotAnalizar()
{
}

void Controlschmitd::slotSlayall()
{
}

void Controlschmitd::slotShutdall()
{
}

void Controlschmitd::slotAyuda()
{
}

void Controlschmitd::slotSalir()
{
    this->close();
}



Controlschmitd::~Controlschmitd()
{
    delete ui;
}
