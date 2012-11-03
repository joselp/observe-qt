#include "adquisiciondatos.h"
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
}

void AdquisicionDatos::iniciarGui()
{
    ventanaCabeceraFits = new CabecerasFits();
    ventanaCabeceraFits->show();


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

    ui->LogTextEdit->setText("ARCHIVO DE LOG: "+NombreDia+" "+" "+NombreMes+" "+QString::number(dia)+" "+hora+
                             " VET "+ QString::number(anyo)+"\n\n"+"TAIL OF ERROR LOG:");

    //ui->LogTextEdit->setReadOnly(true);

    //Titulo ventana

    //this->setWindowTitle("Adquisicion de Datos "+QString::number(dia)+" "+NombreMes+" "+QString::number(anyo));
    this->setWindowTitle("Adquisicion de Datos "+dateTime.currentDateTime().date().toString());
}

void AdquisicionDatos::logicaGui()
{
    connect(ui->comandoDeObservacionComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotComandoDeObservacion(int)));
    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotModoLineaReloj(int)));

    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(activated(int)),this,SLOT(slotModoLineaReloj(int)));

    connect(ui->emcabezadosPushButton,SIGNAL(clicked()),this,SLOT(slotEmcabezados()));

    connect(ui->observarPushButton,SIGNAL(clicked()),this,SLOT(slotObservar()));
}

AdquisicionDatos::~AdquisicionDatos()
{
    delete ui;
}

//Slots
void AdquisicionDatos::slotComandoDeObservacion(int item)
{

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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(true);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);

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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(false);
            ui->numeroExposicionesLineEdit->setEnabled(false);
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

            ventanaCabeceraFits->activarFrecuenciaDM(false);

            ui->tiempoExposicionFocoLineEdit->setEnabled(true);
            ui->numeroExposicionesLineEdit->setEnabled(true);
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
    exit(0);
}

void AdquisicionDatos::slotEmcabezados()
{
    ventanaCabeceraFits->show();
}

void AdquisicionDatos::slotObservar()
{
    verificarDatos();
}

void AdquisicionDatos::verificarDatos()
{
    QString error;
    error = "<font color=""red"">Error: </font>";

    QRegExp rx;

    rx=QRegExp("([0-2][0-3]|[0-9]|[0-1][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaHh())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (HH) de RA");
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (MM) de RA");
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getRaSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (SS) de RA");
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getFocoTelescopio())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Foco del Telescopio");
        return;
    }

    rx=QRegExp("([0-6])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioHh())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (HH) del Angulo Horario");
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (MM) del Angulo Horario");
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-5][0-9]\\.[0-9]|[0-9]\\.[0][0]|[0-5][0-9]\\.[0][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getAHorarioSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo hora (SS) del Angulo Horario");
        return;
    }

    rx=QRegExp("([0-9]|[0-8][0-9]|[9][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionGg())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (GG) de la Declinacion");
        return;
    }

    rx=QRegExp("([0-9]|[0-5][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionMm())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (MM) de la Declinacion");
        return;
    }

    rx=QRegExp("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getDeclinacionSs())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo grados (Ss) de la Declinacion");
        return;
    }

    rx=QRegExp("([^\\s]*)");
    if(!rx.exactMatch(ventanaCabeceraFits->getNombreObjeto()) || ventanaCabeceraFits->getNombreObjeto().size()==0){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo nombre del objeto");
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosX())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo X");
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosY())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo Y");
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosZ())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo Z");
        return;
    }

    rx=QRegExp("([0-9]|[0-9]{2}|[0-9]{3})");
    if(!rx.exactMatch(ventanaCabeceraFits->getPosDedosT())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Posicion del Dedo T");
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosX())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo X");
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosY())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo Y");
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosZ())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo Z");
        return;
    }

    rx=QRegExp("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTemDedosT())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura del Dedo T");
        return;
    }

    /////////////////Falta colocar a los siguientes tres valores el warning de torr./////////////////
    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioCamara())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Camara");
        return;
    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioLineaSuperior())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Linea Superior");
        return;
    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getVacioLineaInferior())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el Vacio de la Linea Inferior");
        return;
    }

    rx=QRegExp("([-][4][9]|[-][5-7][0-9]|[-][8][0])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTempNevera())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique la Temperatura de la Nevera");
        return;
    }

    if(ventanaCabeceraFits->orientacionPrimasIsActive()){
        rx=QRegExp("([0-9]|[0-9]{2}|[1-2][0-9]{2}|[3][0-5][0-9]|[3][6][0])");
        if(!rx.exactMatch(ventanaCabeceraFits->getOrientacionPrisma())){
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Orientacion del Prisma");
            return;
        }
    }

    rx=QRegExp("([-][1-5]|[1][0-9]|[2][0-5]|[0-9])");
    if(!rx.exactMatch(ventanaCabeceraFits->getTempDomo())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Temperatura del Domo");
        return;
    }

    rx=QRegExp("([0-9]|[0-9][0-9]|[1][0]{2})");
    if(!rx.exactMatch(ventanaCabeceraFits->getHumedadDomo())){
        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Verifique el campo Humedad del Domo");
        return;
    }

    if(ventanaCabeceraFits->verificarFiltros()!=0){
        if(ventanaCabeceraFits->verificarFiltros()==1)
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser Clear Window (CLR)");

        if(ventanaCabeceraFits->verificarFiltros()==2)
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser Yale Hot Mirror (HOT)");

        if(ventanaCabeceraFits->verificarFiltros()==3)
            ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+error+"Todos los filtros deben ser UCM Halfa (UHa)");
    }

}
