#include "headers/cargas/formprotocolo.h"
#include "ui_formprotocolo.h"

FormProtocolo::FormProtocolo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormProtocolo)
{
    ui->setupUi(this);
    this->setWindowTitle("Protocolo");
}

void FormProtocolo::asignarFiltro1(QString f)
{
    ui->lineEditFiltro1->setText(f);
}

void FormProtocolo::asignarFiltro2(QString f)
{
    ui->lineEditFiltro2->setText(f);
}

void FormProtocolo::asignarFiltro3(QString f)
{
    ui->lineEditFiltro3->setText(f);
}

void FormProtocolo::asignarFiltro4(QString f)
{
    ui->lineEditFiltro4->setText(f);
}

void FormProtocolo::asignarDeclinacion(QString d)
{
    ui->lineEditDeclinacion->setText(d);
}

void FormProtocolo::asignarAnguloHorario(QString aH)
{
    ui->lineEditAnguloHorario->setText(aH);
}

void FormProtocolo::asignarDuracion(QString d)
{
    ui->lineEditDuracion->setText(d);
}

void FormProtocolo::asignarTipoObservacion(QString t)
{
    ui->lineEditTipoObservacion->setText(t);
}

void FormProtocolo::asignarInstrumento(QString i)
{
    ui->lineEditInstrumento->setText(i);
}

void FormProtocolo::asignarProyecto(QString p)
{
    ui->textEditProyecto->setText(p);
}

FormProtocolo::~FormProtocolo()
{
    delete ui;
}
