#include "headers/adquisiciondatos.h"
#include "ui_adquisiciondatos.h"


AdquisicionDatos::AdquisicionDatos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdquisicionDatos)
{
    ui->setupUi(this);
    iniciarGui();
    logicaGui();
    primero=true;
    eliminar=true;
    lineasLeidas=0;
    tiempoExposicion=0;
    prueba = false;
    contadorTiempoExposicion=0;
}

void AdquisicionDatos::iniciarGui()
{
    ventanaCabeceraFits = new CabecerasFits();
    //ventanaCabeceraFits->show();

    visualizador = new Visualizador();

    //Panel de control de los CCD
    QStringList itemsComandoDeObservacion;
    itemsComandoDeObservacion << "Seleccione un Modo" << "Observacion Drifscan" << "Drifscan Modificado" << "Observacion Guiada" << "Darks Guiado"
                              << "Darks Drifscan" << "Flats Guiado" << "Flats Drifscan" << "Bias" << "Foco";
    ui->comandoDeObservacionComboBox->addItems(itemsComandoDeObservacion);

    ui->NumeroLineasLeerlineEdit->setText("4096");

    ui->tiempoExposicionlineEdit->setEnabled(false);
    ui->tiempoExposicionlineEdit->setText("No Usado");

    //Control de hadware
    QStringList itemsModoDeLaLineaDelReloj;
    itemsModoDeLaLineaDelReloj<< "Declinacion Automatica" << "Read-Rate Automatica" << "Manual";

    ui->modoDeLaLineaDelRelojComboBox->setWindowTitle("HOLAS");
    ui->modoDeLaLineaDelRelojComboBox->addItems(itemsModoDeLaLineaDelReloj);

    ui->declinacionGradosDecLineEdit->setText("0.0");

    ui->tasaDeLecturaHzLineEdit->setEnabled(false);
    ui->tasaDeLecturaHzLineEdit->setText("No Usado");

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

    itemsFormatoImagen << "FITS Format" << "Compressed FITS Format";
    ui->formatoDeLaImagenComboBox->addItems(itemsFormatoImagen);
    ui->formatoDeLaImagenComboBox->setCurrentIndex(1);

    ui->lineaDeDatosPorArchivoLineEdit->setText("2048");
    ui->indiceDeLaObservacionLineEdit->setText("400");

    //Control del log.
    QDateTime dateTime;
    QString NombreDia = dateTime.currentDateTime().date().shortDayName(dateTime.currentDateTime().date().day());
    QString NombreMes = dateTime.currentDateTime().date().shortMonthName(dateTime.currentDateTime().date().month());
    int dia = dateTime.currentDateTime().date().day();
    QString hora = dateTime.currentDateTime().time().toString("hh:mm:ss");
    int anyo =  dateTime.currentDateTime().date().year();

    ui->LogTextEdit->setText("ARCHIVO DE LOG: "+NombreDia+" "+" "+NombreMes+" "+QString::number(dia)+" "+hora+
                             " VET "+ QString::number(anyo)+"\n\n"+"TAIL OF ERROR LOG:");

    //ui->LogTextEdit->setReadOnly(true);

    //Titulo ventana

    //this->setWindowTitle("Adquisicion de Datos "+QString::number(dia)+" "+NombreMes+" "+QString::number(anyo));
    this->setWindowIcon(QIcon(":/images/cidaicon.png"));
    this->setWindowTitle("Adquisicion de Datos "+dateTime.currentDateTime().date().toString());


}

void AdquisicionDatos::logicaGui()
{
    connect(ui->comandoDeObservacionComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotComandoDeObservacion(int)));
    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotModoLineaReloj(int)));

    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(activated(int)),this,SLOT(slotModoLineaReloj(int)));

    connect(ui->emcabezadosPushButton,SIGNAL(clicked()),this,SLOT(slotEmcabezados()));

    //connect(ui->observarPushButton,SIGNAL(clicked()),this,SLOT(slotObservar()));

    //connect(ui->modiaPushButton,SIGNAL(clicked()),this,SLOT(slotModia()));

    connect(ui->salirPushButton,SIGNAL(clicked()),this,SLOT(slotSalir()));

}

AdquisicionDatos::~AdquisicionDatos()
{
    delete ui;
}

//Slots
void AdquisicionDatos::slotComandoDeObservacion(int item)
{
    if(prueba==true){
        if(tipoObs != ui->comandoDeObservacionComboBox->currentText()){
            QMessageBox msg;
            msg.warning(this,"Advertencia","Este no es el tipo de Obsevacion\nque debe realizar verifique.");
        }
    }

    if(primero==true){

        if(item!=0){
            if(eliminar==true){
                eliminar=false;
                ui->comandoDeObservacionComboBox->removeItem(0);

            }
        }
        primero=false;

        if(item==1){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(0);

            ui->tasaDeLecturaHzLineEdit->setText("No Usado");
            ui->tasaDeLecturaHzLineEdit->setEnabled(false);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("400");

            ui->NumeroLineasLeerlineEdit->setText("4096");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==2){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("15.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("500");

            ui->NumeroLineasLeerlineEdit->setText("4096");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(true);

        }

        if (item==3){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("700");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(false);

        }

        if(item==4){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("200");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Darks_Guiado");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==5){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(0);

            ui->tasaDeLecturaHzLineEdit->setText("No Usado");
            ui->tasaDeLecturaHzLineEdit->setEnabled(false);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("200");

            ui->NumeroLineasLeerlineEdit->setText("20480");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Darks_Driftscan");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==6){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("300");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Flats_Guiado");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==7){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("300");

            ui->NumeroLineasLeerlineEdit->setText("20480");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Flats_Driftscan");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==8){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("100");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("0");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setRaHh("0");
            ventanaCabeceraFits->setRaMm("0");
            ventanaCabeceraFits->setRaSs("0.00");

            ventanaCabeceraFits->setFocoTelescopio("0");

            ventanaCabeceraFits->setAHorarioHh("0");
            ventanaCabeceraFits->setAHorarioMm("0");
            ventanaCabeceraFits->setAHorarioSs("0");

            ventanaCabeceraFits->setDeclinacionGg("0");
            ventanaCabeceraFits->setDeclinacionMm("0");
            ventanaCabeceraFits->setDeclinacionSs("0.00");

            ventanaCabeceraFits->setNombreObjeto("Bias");
            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==9){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("600");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("0");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(false);

            ui->IniciarSec1PushButton->setEnabled(true);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setRaHh("0");
            ventanaCabeceraFits->setRaMm("0");
            ventanaCabeceraFits->setRaSs("0.00");

            ventanaCabeceraFits->setFocoTelescopio("0");

            ventanaCabeceraFits->setAHorarioHh("0");
            ventanaCabeceraFits->setAHorarioMm("0");
            ventanaCabeceraFits->setAHorarioSs("0");

            ventanaCabeceraFits->setDeclinacionGg("0");
            ventanaCabeceraFits->setDeclinacionMm("0");
            ventanaCabeceraFits->setDeclinacionSs("0.00");

            ventanaCabeceraFits->setNombreObjeto("Foco");
            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }
    }

    else{

        if(item==0){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(0);

            ui->tasaDeLecturaHzLineEdit->setText("No Usado");
            ui->tasaDeLecturaHzLineEdit->setEnabled(false);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("400");

            ui->NumeroLineasLeerlineEdit->setText("4096");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(false);

        }

        if(item==1){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("15.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("500");

            ui->NumeroLineasLeerlineEdit->setText("4096");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ventanaCabeceraFits->activarFrecuenciaDM(true);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(true);

        }

        if (item==2){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("700");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("");

            ventanaCabeceraFits->activarFrecuenciaDM(false);

        }

        if(item==3){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("200");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Darks_Guiado");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==4){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(0);

            ui->tasaDeLecturaHzLineEdit->setText("No Usado");
            ui->tasaDeLecturaHzLineEdit->setEnabled(false);

            ui->declinacionGradosDecLineEdit->setText("0.0");
            ui->declinacionGradosDecLineEdit->setEnabled(true);

            ui->indiceDeLaObservacionLineEdit->setText("200");

            ui->NumeroLineasLeerlineEdit->setText("20480");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Darks_Driftscan");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==5){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("300");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("10");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Flats_Guiado");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==6){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("300");

            ui->NumeroLineasLeerlineEdit->setText("20480");
            ui->NumeroLineasLeerlineEdit->setEnabled(true);

            ui->tiempoExposicionlineEdit->setText("No Usado");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setNombreObjeto("Flats_Driftscan");

            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==7){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("100");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("0");
            ui->tiempoExposicionlineEdit->setEnabled(true);

            ui->observarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setRaHh("0");
            ventanaCabeceraFits->setRaMm("0");
            ventanaCabeceraFits->setRaSs("0.00");

            ventanaCabeceraFits->setFocoTelescopio("0");

            ventanaCabeceraFits->setAHorarioHh("0");
            ventanaCabeceraFits->setAHorarioMm("0");
            ventanaCabeceraFits->setAHorarioSs("0");

            ventanaCabeceraFits->setDeclinacionGg("0");
            ventanaCabeceraFits->setDeclinacionMm("0");
            ventanaCabeceraFits->setDeclinacionSs("0.00");

            ventanaCabeceraFits->setNombreObjeto("Bias");
            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }

        if(item==8){
            ui->modoDeLaLineaDelRelojComboBox->setCurrentIndex(1);

            ui->tasaDeLecturaHzLineEdit->setText("17.0");
            ui->tasaDeLecturaHzLineEdit->setEnabled(true);

            ui->declinacionGradosDecLineEdit->setText("No Usado");
            ui->declinacionGradosDecLineEdit->setEnabled(false);

            ui->indiceDeLaObservacionLineEdit->setText("600");

            ui->NumeroLineasLeerlineEdit->setText("No Usado");
            ui->NumeroLineasLeerlineEdit->setEnabled(false);

            ui->tiempoExposicionlineEdit->setText("0");
            ui->tiempoExposicionlineEdit->setEnabled(false);

            ui->observarPushButton->setEnabled(false);

            ui->IniciarSec1PushButton->setEnabled(true);

            ui->tiempoExposicionFocoLineEdit->setEnabled(true);
            ui->numeroExposicionesLineEdit->setEnabled(true);

            ////////////Cambios en cabecera Fits.//////////////

            ventanaCabeceraFits->setRaHh("0");
            ventanaCabeceraFits->setRaMm("0");
            ventanaCabeceraFits->setRaSs("0.00");

            ventanaCabeceraFits->setFocoTelescopio("0");

            ventanaCabeceraFits->setAHorarioHh("0");
            ventanaCabeceraFits->setAHorarioMm("0");
            ventanaCabeceraFits->setAHorarioSs("0");

            ventanaCabeceraFits->setDeclinacionGg("0");
            ventanaCabeceraFits->setDeclinacionMm("0");
            ventanaCabeceraFits->setDeclinacionSs("0.00");

            ventanaCabeceraFits->setNombreObjeto("Foco");
            ventanaCabeceraFits->activarFrecuenciaDM(false);
        }
    }

}

void AdquisicionDatos::slotModoLineaReloj(int item)
{
    if(item==0){
        ui->tasaDeLecturaHzLineEdit->setText("No Usado");
        ui->tasaDeLecturaHzLineEdit->setEnabled(false);

        ui->declinacionGradosDecLineEdit->setText("0.0");
        ui->declinacionGradosDecLineEdit->setEnabled(true);
    }

    if(item==1){
        ui->tasaDeLecturaHzLineEdit->setText("15.0");
        ui->tasaDeLecturaHzLineEdit->setEnabled(true);

        ui->declinacionGradosDecLineEdit->setText("No Usado");
        ui->declinacionGradosDecLineEdit->setEnabled(false);
    }

    if(item==2){
        ui->tasaDeLecturaHzLineEdit->setText("No Usado");
        ui->tasaDeLecturaHzLineEdit->setEnabled(false);

        ui->declinacionGradosDecLineEdit->setText("No Usado");
        ui->declinacionGradosDecLineEdit->setEnabled(false);
    }

}

void AdquisicionDatos::closeEvent(QCloseEvent *)
{
    //delete ventanaCabeceraFits;
    //ventanaCabeceraFits->close();
    this->close();
    //exit(0);
}

CabecerasFits *AdquisicionDatos::getCabeceraFits()
{
    return ventanaCabeceraFits;
}

Visualizador *AdquisicionDatos::getVisualizador()
{
    return visualizador;
}

QPushButton *AdquisicionDatos::getButtonObservar()
{
    return ui->observarPushButton;
}

QPushButton *AdquisicionDatos::getButtonModia()
{
    return ui->modiaPushButton;
}

QPushButton *AdquisicionDatos::getButtonEncabezados()
{
    return ui->emcabezadosPushButton;
}

QComboBox *AdquisicionDatos::getComandoDeObservacionComboBox()
{
    return ui->comandoDeObservacionComboBox;
}

QLineEdit *AdquisicionDatos::getNumeroLineasLeer()
{
    return ui->NumeroLineasLeerlineEdit;
}

int AdquisicionDatos::getLineasLeidas()
{
    return lineasLeidas;
}

void AdquisicionDatos::seleccionarComandoDeObservacionComboBox(int i)
{
    if(primero==true)
        ui->comandoDeObservacionComboBox->setCurrentIndex(i);
    else
        ui->comandoDeObservacionComboBox->setCurrentIndex(i-1);
}

void AdquisicionDatos::stopLogTimer()
{
    logTimer->stop();
    ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Observacion Cancelada");
    delete logTimer;
    lineasLeidas=0;
}


bool AdquisicionDatos::getRealizarObservacion()
{
    return realizarObservacion;
}

bool AdquisicionDatos::getQnx1()
{
    if(ui->checkBoxQnx1->isChecked())
        return true;
    else
        return false;
}

bool AdquisicionDatos::getQnx2()
{
    if(ui->checkBoxQnx2->isChecked())
        return true;
    else
        return false;
}

bool AdquisicionDatos::getQnx3()
{
    if(ui->checkBoxQnx3->isChecked())
        return true;
    else
        return false;
}

bool AdquisicionDatos::getQnx4()
{
    if(ui->checkBoxQnx4->isChecked())
        return true;
    else
        return false;
}

void AdquisicionDatos::asignarComandoObservacion(int i)
{
    ui->comandoDeObservacionComboBox->setCurrentIndex(i);
    ui->comandoDeObservacionComboBox->setDisabled(true);
}

void AdquisicionDatos::asignarTipoObs(QString s)
{
    tipoObs = s;
}

void AdquisicionDatos::asignarPrueba(bool p)
{
    prueba = p;
}

void AdquisicionDatos::slotEmcabezados()
{
    ventanaCabeceraFits->show();
}

void AdquisicionDatos::slotSalir()
{
    exit(0);
}


void AdquisicionDatos::slotObservar()
{

//    //    verificarDatos();
//    //    if(realizarObservacion==true){
//    //        disconnect(ui->observarPushButton,SIGNAL(clicked()),0,0);
//    //        ui->observarPushButton->setStyleSheet("background-color:GRAY;"
//    //                                              "color:RED;"
//    //                                              "border-style: inset;"
//    //                                              "border-width: 1px;"
//    //                                              "border-radius: 1px;"
//    //                                              "border-color: black;");
//    //        ui->observarPushButton->setText("Abortar");
//    //        connect(ui->observarPushButton,SIGNAL(clicked()),this,SLOT(slotCancelarObservacion()));
//    //        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Observacion Iniciada");
//    //        crearRetardoFit();


//    //Verifico el tipo de observacion para asi determinar el total de lineas a mostrar en el visualizador

//    if(ui->comandoDeObservacionComboBox->currentText()=="Observacion Guiada" || ui->comandoDeObservacionComboBox->currentText()=="Darks Guiado" ||
//            ui->comandoDeObservacionComboBox->currentText()=="Flats Guiado" || ui->comandoDeObservacionComboBox->currentText()=="Bias"){

//        visualizador->setTotalLineas(2048);

//    }
//    else
//        //        //if(visualizador->isVisible()){
//        visualizador->setTotalLineas(ui->NumeroLineasLeerlineEdit->text().toInt());
//    //            visualizador->initLectura();
//    // }
//    //    }

//    //    if(realizarObservacion==false)
//    //        qDebug()<<"Observacion no realizada";

//    visualizador->initLectura();
//    crearRetardoFit();

}

void AdquisicionDatos::slotModia()
{
    visualizador->show();
    //    visualizadosFits = new VisualizadorFits();
    //    visualizadosFits->show();
}

void AdquisicionDatos::slotCancelarObservacion()
{
    ui->observarPushButton->setStyleSheet("");
    ui->observarPushButton->setText("Observar");
    disconnect(ui->observarPushButton,SIGNAL(clicked()),0,0);
    connect(ui->observarPushButton,SIGNAL(clicked()),this,SLOT(slotObservar()));
    ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Observacion Cancelada");
    logTimer->stop();
    delete logTimer;
    lineasLeidas=0;
}

///////////////////////////Verificar datos antes de observar///////////////////////////////////////////

void AdquisicionDatos::verificarDatos()
{

    realizarObservacion=true;
    QString error;
    error = "<font color=""red"">Error: </font>";

    QRegExp rx;

    rx=QRegExp("([0-2][0-3]|[0-9]|[0-1][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaHh())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (HH) de RA");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (MM) de RA");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (SS) de RA");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getFocoTelescopio())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Foco del Telescopio");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-6])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioHh())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (HH) del Angulo Horario");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (MM) del Angulo Horario");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-5][0-9]\\.[0-9]|[0-9]\\.[0][0]|[0-5][0-9]\\.[0][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (SS) del Angulo Horario");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-8][0-9]|[9][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionGg())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (GG) de la Declinacion");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (MM) de la Declinacion");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (Ss) de la Declinacion");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([^\\s]*)");
    if(!rx.exactMatch(ventanaCabeceraFits->getNombreObjeto()) || ventanaCabeceraFits->getNombreObjeto().size()==0){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo nombre del objeto");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosX())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo X");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosY())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo Y");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosZ())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo Z");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosT())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo T");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosX())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo X");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosY())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo Y");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosZ())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo Z");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosT())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo T");
        realizarObservacion=false;
        return;
    }

    /////////////////Falta colocar a los siguientes tres valores el warning de torr./////////////////
    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioCamara())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Camara");
        realizarObservacion=false;
        return;
    }
    if(ventanaCabeceraFits->getVacioCamara().toInt()>200){
        QMessageBox msg;
        msg.setText("El valor vacio de la camara ("+ventanaCabeceraFits->getVacioCamara()+"<br>mTorr) es muy elevado!<br><br>Por favor, llame al tecnico de<br>guardia");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioLineaSuperior())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Linea Superior");
        realizarObservacion=false;
        return;
    }
    if(ventanaCabeceraFits->getVacioLineaSuperior().toInt()>200){
        QMessageBox msg;
        msg.setText("El valor de vacio de la linea <br> superior ("+ventanaCabeceraFits->getVacioLineaSuperior()+
                    "mTorr) es muy<br>elevado!<br><br>Por favor, llame al tecnico de<br>guardia");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();

    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioLineaInferior())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Linea Inferior");
        realizarObservacion=false;
        return;
    }
    if(ventanaCabeceraFits->getVacioLineaInferior().toInt()>200){
        QMessageBox msg;
        msg.setText("El valor de vacio de la linea <br> inferior ("+ventanaCabeceraFits->getVacioLineaInferior()+
                    "mTorr) es muy<br>elevado!<br><br>Por favor, llame al tecnico de<br>guardia");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
    }

    rx=QRegExp("([-][4][9]|[-][5-7][0-9]|[-][8][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTempNevera())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura de la Nevera");
        realizarObservacion=false;
        return;
    }

    if(ventanaCabeceraFits->orientacionPrimasIsActive()){
        rx=QRegExp("([0-9]|[0-9]{2}|[1-2][0-9]{2}|[3][0-5][0-9]|[3][6][0])");
        if(!rx.exactMatch(ventanaCabeceraFits->getOrientacionPrisma())){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Orientacion del Prisma");
            realizarObservacion=false;
            return;
        }
    }

    rx=QRegExp("([-][1-5]|[1][0-9]|[2][0-5]|[0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTempDomo())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Temperatura del Domo");
        realizarObservacion=false;
        return;
    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1][0]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getHumedadDomo())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Humedad del Domo");
        realizarObservacion=false;
        return;
    }

    if(ventanaCabeceraFits->verificarFiltros()!=0){
        if(ventanaCabeceraFits->verificarFiltros()==1){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser Clear Window (CLR)");
            realizarObservacion=false;
        }
        if(ventanaCabeceraFits->verificarFiltros()==2){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser Yale Hot Mirror (HOT)");
            realizarObservacion=false;
        }
        if(ventanaCabeceraFits->verificarFiltros()==3){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser UCM Halfa (UHa)");
            realizarObservacion=false;
        }
        return;
    }

    if(ui->comandoDeObservacionComboBox->currentText()=="Seleccione un Modo"){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>**************************************<br>"+
                                 "Seleccione un Modo de Observacion<br>"+
                                 "**************************************");
        realizarObservacion=false;
    }


}

void AdquisicionDatos::crearRetardoFit()
{
    logTimer = new QTimer(this);

    connect(logTimer,SIGNAL(timeout()),this,SLOT(slotLogTimer()));
    logTimer->start();

    if(ui->comandoDeObservacionComboBox->currentText()=="Observacion Guiada" || ui->comandoDeObservacionComboBox->currentText()=="Darks Guiado" ||
            ui->comandoDeObservacionComboBox->currentText()=="Flats Guiado" || ui->comandoDeObservacionComboBox->currentText()=="Bias"){

        tiempoExposicion=ui->tiempoExposicionlineEdit->text().toInt();
        logTimer->setInterval(1000);

    }
    else{
        logTimer->setInterval(30);
    }
}

void AdquisicionDatos::slotLogTimer()
{

    //Verifico si el tipo de observacion implica tiempo de exposicion y se hace su simulacion
    if(ui->comandoDeObservacionComboBox->currentText()=="Observacion Guiada" || ui->comandoDeObservacionComboBox->currentText()=="Darks Guiado" ||
            ui->comandoDeObservacionComboBox->currentText()=="Flats Guiado" || ui->comandoDeObservacionComboBox->currentText()=="Bias"){

        ui->tiempoExposicionlineEdit->setText(QString::number(contadorTiempoExposicion)+"/"+QString::number(tiempoExposicion));

        if(tiempoExposicion==0){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Iniciando Observe:\n"

                                     +"Running /home/survey/jas/tio_ctrl with command:<br>"
                                     +"3<br>"
                                     +"17.0<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"Done: /home/survey/jas/tio_ctrl<br>"
                                     +"Running /home/survey/jas/tio_ctrl with command:<br>"
                                     +"1<br>"
                                     +"Done: /home/survey/jas/tio_ctrl<br>");
        }

        if(contadorTiempoExposicion%4==0)
                ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"1024 lineas leidas");

        if(contadorTiempoExposicion==tiempoExposicion){
            logTimer->stop();
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Observacion Terminada");
        }
        contadorTiempoExposicion++;

    }

    //Verifico si el tipo de observacion no implica tiempo de exposicion y se hace su simulacion
    else{
        if(lineasLeidas==0){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Iniciando Observe:\n"

                                     +"Running /home/survey/jas/tio_ctrl with command:<br>"
                                     +"3<br>"
                                     +"17.0<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"9999<br>"
                                     +"Done: /home/survey/jas/tio_ctrl<br>"
                                     +"Running /home/survey/jas/tio_ctrl with command:<br>"
                                     +"1<br>"
                                     +"Done: /home/survey/jas/tio_ctrl<br>");
        }
        //if(ui->comandoDeObservacionComboBox->currentText()=="Observacion Drifscan"){
        lineasLeidas++;
        //visualizador->setNumeroLineaActual(lineasLeidas);
        if(lineasLeidas%512==0){
            //qDebug()<<"Lineas Leidas "<<lineasLeidas<<" Hola";
            if(lineasLeidas < ui->NumeroLineasLeerlineEdit->text().toInt(0))
                ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"
                                         +"Issuing command: rsh qnx1 /home/survey/cnsFits/ccd/ccd -scan -nlfile 2048<br>"
                                         +"-nread 78323 -out //5/home/survey/images1/obs410.qnx1 -port 2241 -chips 4321<br>"
                                         +"-write /home/survey/cnsFits/ccd/../writer/writer -stats<br>"
                                         +"/home/survey/cnsFits/ccd/../survey/survey -obj -1 -obs 410  -project CM-RRLYRAE -freq 14.264843<br>"
                                         +"-ra1 5 -ra2 42 -ra3 0.00 -telfocus 873 -focuschk 1  -ha1 00 -ha2 30 -ha3 0.00<br>"
                                         +"-direcha Oeste -dec1 12 -dec2 0 -dec3 0.0 -nameobj discoG  -osimode DS<br>"
                                         +"-dateobs 2013-10-31T08:17:50 -ut1 08:17:50 -fingposx 661 -fingposy  640 -fingposz 477<br>"
                                         +"-fingpost 200 -fingerstempx -57.1 -fingerstempy -60.4<br>"
                                         +"-fingerstempz -61.5  -fingerstempt -61.2 -exptime 0.0 -cameravac 30 -uplinevac 30<br>"
                                         +"-lowlinevac 40 -chilltemp -67.5 -filter1 V1 -filter2 V2 -filter3 I1  -filter4 I2 -instrume<br>"
                                         +"YIC -prismang -1 -nameobs -weather Despejado_Bruma_Alta  -dometemp 10<br>"
                                         +"-domehum 75 -frecyic 0.0 -frecra 0.0 -frecdec 0.0   -imgtype DriftscanObservation<br>"
                                         +"Date: jue oct 31 03:48:02 VET 2013<br>"
                                         +"Clock rate: 14.264843<br>"
                                         +"Finger x position: -1<br>"
                                         +"Finger y position: -1<br>"
                                         +"Finger z position: -1<br>"
                                         +"Finger t position: -1<br>"
                                         +"qnx4: line is "+ QString::number(lineasLeidas)+"<br>"
                                         +"qnx1: line is "+ QString::number(lineasLeidas)+"<br>"
                                         +"qnx2: line is "+ QString::number(lineasLeidas)+"<br>"
                                         +"qnx3: line is "+ QString::number(lineasLeidas)+"<br>");
            //lineasLeidas++;
            if(lineasLeidas >= ui->NumeroLineasLeerlineEdit->text().toInt(0)){
                ui->observarPushButton->setStyleSheet("");
                ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"Observacion Terminada");
                logTimer->stop();
                delete logTimer;
                lineasLeidas=0;
            }
        }

    }

    ui->LogTextEdit->moveCursor(QTextCursor::End);
}

void AdquisicionDatos::slotTiempoExposicion()
{
    ui->tiempoExposicionlineEdit->setText(QString::number(contadorTiempoExposicion)+"/"+QString::number(tiempoExposicion));

    contadorTiempoExposicion++;
    qDebug()<<contadorTiempoExposicion;
    qDebug()<<tiempoExposicion;

    if(contadorTiempoExposicion==tiempoExposicion)
        tiempoExposicionTimer->stop();
}
