#include "formsimulador.h"
#include "ui_formsimulador.h"

FormSimulador::FormSimulador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSimulador)
{
    ui->setupUi(this);
    adquisicionDatos= new AdquisicionDatos;
    //cabecerasFits = new CabecerasFits;
    connect(adquisicionDatos->obtenerBotonObservar(),SIGNAL(clicked()),this,SLOT(slotIniciarObservacion()));
}

void FormSimulador::asignarVentanas()
{

        qDebug()<<"Hola Mundo";

        ui->mdiArea->addSubWindow(adquisicionDatos);
        ui->mdiArea->addSubWindow(adquisicionDatos->obtenerCabeceraFits());
        adquisicionDatos->show();
        adquisicionDatos->obtenerCabeceraFits()->show();
}

void FormSimulador::slotIniciarObservacion()
{

    //    verificarDatos();
    //    if(realizarObservacion==true){
    //        disconnect(ui->observarPushButton,SIGNAL(clicked()),0,0);
    //        ui->observarPushButton->setStyleSheet("background-color:GRAY;"
    //                                              "color:RED;"
    //                                              "border-style: inset;"
    //                                              "border-width: 1px;"
    //                                              "border-radius: 1px;"
    //                                              "border-color: black;");
    //        ui->observarPushButton->setText("Abortar");
    //        connect(ui->observarPushButton,SIGNAL(clicked()),this,SLOT(slotCancelarObservacion()));
    //        ui->LogTextEdit->setHtml(ui->LogTextEdit->toHtml()+"<br><br>"+"Observacion Iniciada");
    //        crearRetardoFit();


    //Verifico el tipo de observacion para asi determinar el total de lineas a mostrar en el visualizador

    if(adquisicionDatos->obtenerComandoDeObservacionComboBox()->currentText()=="Observacion Guiada" || adquisicionDatos->obtenerComandoDeObservacionComboBox()->currentText()=="Darks Guiado" ||
            adquisicionDatos->obtenerComandoDeObservacionComboBox()->currentText()=="Flats Guiado" || adquisicionDatos->obtenerComandoDeObservacionComboBox()->currentText()=="Bias"){

        adquisicionDatos->obtenerVisualizador()->setTotalLineas(2048);

    }
    else
        //        //if(visualizador->isVisible()){
        adquisicionDatos->obtenerVisualizador()->setTotalLineas(adquisicionDatos->obtenerNumeroLineasLeer()->text().toInt());
    //            visualizador->initLectura();
    // }
    //    }

    //    if(realizarObservacion==false)
    //        qDebug()<<"Observacion no realizada";

    qDebug()<<adquisicionDatos->obtenerNumeroLineasLeer()->text().toInt();

    adquisicionDatos->obtenerVisualizador()->initLectura();
    adquisicionDatos->crearRetardoFit();

    ui->mdiArea->addSubWindow(adquisicionDatos->obtenerVisualizador());
    //adquisicionDatos->obtenerVisualizador();
}


FormSimulador::~FormSimulador()
{
    delete ui;
}

