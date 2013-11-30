#include "headers/asistente.h"
#include "ui_asistente.h"

Asistente::Asistente(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Asistente)
{
    ui->setupUi(this);
    initGui();
    logica();
}

void Asistente::initGui()
{
    this->setWindowTitle("Datos del Telescopio");
    ui->posicionDedosXLineEdit->setEnabled(false);
    ui->posicionDedosYLineEdit->setEnabled(false);
    ui->posicionDedosZLineEdit->setEnabled(false);
    ui->posicionDedosTLineEdit->setEnabled(false);
    ui->temperaturaDedosXLineEdit->setEnabled(false);
    ui->temperaturaDedosYLineEdit->setEnabled(false);
    ui->temperaturaDedosZLineEdit->setEnabled(false);
    ui->temperaturaDedosTLineEdit->setEnabled(false);
    ui->humedadDomoLineEdit->setEnabled(false);
    ui->vacioLineaSuperiorLineEdit->setEnabled(false);
    ui->vacioLineaInferiorLineEdit->setEnabled(false);
    ui->vacioCamaralineEdit->setEnabled(false);
    ui->temperaturaNeveraLineEdit->setEnabled(false);
    ui->temperaturaDomoLineEdit->setEnabled(false);
}

void Asistente::logica()
{
    //Numero aleatorio para posicion dedo x
    int num=rand()%499;


    ui->posicionDedosXLineEdit->setText(QString::number(num));
    ui->posicionDedosYLineEdit->setText(QString::number(num));
    ui->posicionDedosZLineEdit->setText(QString::number(num));
    ui->posicionDedosTLineEdit->setText(QString::number(num));

    num=rand()%80;
    ui->temperaturaDedosXLineEdit->setText("-"+QString::number(num));
    ui->temperaturaDedosYLineEdit->setText("-"+QString::number(num));
    ui->temperaturaDedosZLineEdit->setText("-"+QString::number(num));
    ui->temperaturaDedosTLineEdit->setText("-"+QString::number(num));

    num=30+rand()%50;
    ui->temperaturaNeveraLineEdit->setText("-"+QString::number(num));

    num=rand()%500;
    ui->vacioLineaSuperiorLineEdit->setText(QString::number(num));
    ui->vacioLineaInferiorLineEdit->setText(QString::number(num));
    ui->vacioCamaralineEdit->setText(QString::number(num));

    num=rand()%100;
    ui->humedadDomoLineEdit->setText(QString::number(num));

    num=rand()%15;
    ui->temperaturaDomoLineEdit->setText(QString::number(num));

}

Asistente::~Asistente()
{
    delete ui;
}
