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

    ui->LogTextEdit->setReadOnly(true);

    //Titulo ventana

    //this->setWindowTitle("Adquisicion de Datos "+QString::number(dia)+" "+NombreMes+" "+QString::number(anyo));
    this->setWindowTitle("Adquisicion de Datos "+dateTime.currentDateTime().date().toString());
}

void AdquisicionDatos::logicaGui()
{
    connect(ui->comandoDeObservacionComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotComandoDeObservacion(int)));
    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotModoLineaReloj(int)));

    connect(ui->modoDeLaLineaDelRelojComboBox,SIGNAL(activated(int)),this,SLOT(slotModoLineaReloj(int)));
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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(false);

            ui->IniciarSec1PushButton->setEnabled(true);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

            ventanaCabeceraFits->activarFrecuenciaDM(true);

        }

        if (item==2){
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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(true);

            ui->IniciarSec1PushButton->setEnabled(false);

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

            ui->ObservarPushButton->setEnabled(false);

            ui->IniciarSec1PushButton->setEnabled(true);

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
    exit(0);
}
