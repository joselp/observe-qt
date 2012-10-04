#include "adquisiciondatos.h"
#include "ui_adquisiciondatos.h"

AdquisicionDatos::AdquisicionDatos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdquisicionDatos)
{
    ui->setupUi(this);
    cargarGui();
}

void AdquisicionDatos::cargarGui()
{

    //Panel de control de los CCD
    QStringList itemsComandoDeObservacion;
    itemsComandoDeObservacion << "Seleccione un Modo" << "Drifscan Modificado" << "Observacion Guiada" << "Darks Guiado"
                                 << "Darks Drifscan" << "Flats Guiado" << "Flats Drifscan" << "Bias" << "Foco";
    ui->comandoDeObservacionComboBox->addItems(itemsComandoDeObservacion);

    ui->NumeroLineasLeerlineEdit->setText("4096");

    ui->tiempoExposicionlineEdit->setEnabled(false);
    ui->tiempoExposicionlineEdit->setText("No Usado");

    //Control de hadware
    QStringList itemsModoDeLaLineaDelReloj;
    itemsModoDeLaLineaDelReloj<< "Declinacion Automatica" << "Read-Rate Automatica" << "Manual";
    ui->modoDeLaLineaDelRelojComboBox->addItems(itemsModoDeLaLineaDelReloj);

    ui->declinacionGradosDecLineEdit->setText("0.0");

    ui->texturaDeLecturaHzLineEdit->setEnabled(false);
    ui->texturaDeLecturaHzLineEdit->setText("No Usado");

    ui->posXLineEdit->setText("600");
    ui->posYLineEdit->setText("600");
    ui->posZLineEdit->setText("600");
    ui->posTLineEdit->setText("600");

    ui->tiempoExposicionFocoLineEdit->setEnabled(false);
    ui->numeroExposicionesLineEdit->setEnabled(false);

    ui->IniciarSec1PushButton->setEnabled(false);
    ui->AbortarSecPushButton->setEnabled(false);

    //Control de software
    QStringList itemsFormatoImagen;

    itemsFormatoImagen << "Compressed FITS format" << "Formato FITS" << "Formato FITS Comprimido";
    ui->formatoDeLaImagenComboBox->addItems(itemsFormatoImagen);

    ui->lineaDeDatosPorArchivoLineEdit->setText("2048");
    ui->indiceDeLaObservacionLineEdit->setText("400");

    //Control del log.
    QDateTime dateTime;
    QString NombreDia = dateTime.currentDateTime().date().shortDayName(dateTime.currentDateTime().date().day());
    QString NombreMes = dateTime.currentDateTime().date().shortMonthName(dateTime.currentDateTime().date().month());
    int dia = dateTime.currentDateTime().date().day();
    QString hora = dateTime.currentDateTime().time().toString("hh:mm:ss");
    int anyo =  dateTime.currentDateTime().date().year();

    ui->LogTextEdit->setText("ARCHIVO DE LOG: "+NombreDia+" "+" "+NombreMes+" "+QString::number(dia)+" "+dateTime.currentDateTime().time().toString("hh:mm:ss")+
                             " VET "+ QString::number(anyo));

    //Titulo ventana

    //this->setWindowTitle("Adquisicion de Datos "+QString::number(dia)+" "+NombreMes+" "+QString::number(anyo));
    this->setWindowTitle("Adquisicion de Datos "+dateTime.currentDateTime().date().toString());
}

AdquisicionDatos::~AdquisicionDatos()
{
    delete ui;
}
