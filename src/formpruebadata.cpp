#include "headers/formpruebadata.h"
#include "ui_formpruebadata.h"

FormPruebaData::FormPruebaData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormPruebaData)
{
    ui->setupUi(this);
    ui->textEditProyecto->setEnabled(false);
}

void FormPruebaData::setCondiciones(QString s)
{
    ui->lineEditCondiciones->setText(s);
}

void FormPruebaData::setFiltro1(QString s)
{
    ui->lineEditFiltro1->setText(s);
}

void FormPruebaData::setFiltro2(QString s)
{
    ui->lineEditFiltro2->setText(s);
}

void FormPruebaData::setFiltro3(QString s)
{
    ui->lineEditFiltro3->setText(s);
}

void FormPruebaData::setFiltro4(QString s)
{
    ui->lineEditFiltro4->setText(s);
}

void FormPruebaData::setDeclinacion(QString s)
{
    ui->lineEditDeclinacion->setText(s);
}

void FormPruebaData::setAHorario(QString s)
{
    ui->lineEditAnguloHorario->setText(s);
}

void FormPruebaData::setObservacion(QString s)
{
    ui->lineEditTipoObservacion->setText(s);
}

void FormPruebaData::setDuracion(QString s)
{
    ui->lineEditDuracion->setText(s);
}

void FormPruebaData::setInstrumento(QString s)
{
    ui->lineEditInstrumento->setText(s);
}

void FormPruebaData::setProyecto(QString s)
{
    ui->textEditProyecto->setText(s);
}

FormPruebaData::~FormPruebaData()
{
    delete ui;
}
