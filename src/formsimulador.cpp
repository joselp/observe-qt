#include "headers/formsimulador.h"
#include "ui_formsimulador.h"

FormSimulador::FormSimulador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSimulador)
{
    ui->setupUi(this);

        fondo.load(":/images/pantallaApagada.jpeg");

        //fondo.load(":/images/pantalla1.jpg");

    subWindowCabeceraFits = new MySubWindow();

    //ui->mdiArea->setBackground(*new QBrush(*new QPixmap(":/images/fedora17.png")));

    ui->mdiArea->setBackground(*new QBrush(scaledPixmap));
    ui->mdiArea->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    //    adquisicionDatos= new AdquisicionDatos;
    //    //cabecerasFits = new CabecerasFits;
    //    connect(adquisicionDatos->getBotonObservar(),SIGNAL(clicked()),this,SLOT(slotIniciarObservacion()));
    //    connect(adquisicionDatos->getBotonModia(),SIGNAL(clicked()),this,SLOT(slotModia()));

    //Boton que emula icono en el escritorio.

    //    QPushButton *boton;
    //    boton = new QPushButton(ui->mdiArea);
    //    boton->setGeometry(QRect(20,20,50,50));
    //    boton->setStyleSheet( "QPushButton{background-color: white;background-image:url(':/images/cidaicon.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; min-width: 10em; text-align:left;}");
    //    connect(boton,SIGNAL(clicked()),this,SLOT(slotControlShmidt()));

//    iconControlSchmidt = new myButtonIcon(ui->mdiArea);
//    iconControlSchmidt->setGeometry(QRect(20,20,32,30));
//    iconControlSchmidt->setToolTip("Control Schmidt");
//    iconControlSchmidt->setStyleSheet( "QPushButton{background-image:url(':/images/iconControlS.jpg'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
//    connect(iconControlSchmidt,SIGNAL(doubleclick()),this,SLOT(slotControlShmidt()));

//    iconTerminal = new myButtonIcon(ui->mdiArea);
//    iconTerminal->setGeometry(QRect(20,60,32,30));
//    iconTerminal->setToolTip("Terminalt");
//    iconTerminal->setStyleSheet( "QPushButton{background-image:url(':/images/consola.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
//    connect(iconTerminal,SIGNAL(doubleclick()),this,SLOT(slotTerminal()));

    connect(this, SIGNAL(mousePressed(int, int)), this, SLOT(slotParaManejarRaton(int, int)));

}

void FormSimulador::asignarVentanas()
{
    //delete adquisicionDatos;
    //adquisicionDatos= new AdquisicionDatos;

    adquisicionDatos= new AdquisicionDatos;
    //cabecerasFits = new CabecerasFits;
    connect(adquisicionDatos->getButtonObservar(),SIGNAL(clicked()),this,SLOT(slotIniciarObservacion()));
    connect(adquisicionDatos->getButtonModia(),SIGNAL(clicked()),this,SLOT(slotModia()));
    connect(adquisicionDatos->getButtonEncabezados(),SIGNAL(clicked()),this,SLOT(slotEncambezados()));
    connect(adquisicionDatos->getCabeceraFits()->getButtonCerrar(),SIGNAL(clicked()),this,SLOT(slotCerrarCabeceras()));

    subWindowCabeceraFits->setWidget(adquisicionDatos->getCabeceraFits());

    ui->mdiArea->addSubWindow(adquisicionDatos);
    //ui->mdiArea->addSubWindow(adquisicionDatos->getCabeceraFits());
    ui->mdiArea->addSubWindow(subWindowCabeceraFits);
    adquisicionDatos->show();
    adquisicionDatos->getCabeceraFits()->show();

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

    if(adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Observacion Guiada" || adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Darks Guiado" ||
            adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Flats Guiado" || adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Bias"){

        adquisicionDatos->getVisualizador()->setTotalLineas(2048);

    }
    else
        //        //if(visualizador->isVisible()){
        adquisicionDatos->getVisualizador()->setTotalLineas(adquisicionDatos->getNumeroLineasLeer()->text().toInt());
    //            visualizador->initLectura();
    // }
    //    }

    //    if(realizarObservacion==false)
    //        qDebug()<<"Observacion no realizada";

    adquisicionDatos->getVisualizador()->setCondicionesCielo(adquisicionDatos->getCabeceraFits()->getCondicionesCielo());

    //    adquisicionDatos->getVisualizador()->initLectura();
    adquisicionDatos->crearRetardoFit();

    //    ui->mdiArea->addSubWindow(adquisicionDatos->getVisualizador());
    //adquisicionDatos->getVisualizador();
}

void FormSimulador::slotModia()
{

    adquisicionDatos->getVisualizador()->setNumeroLineaActual(adquisicionDatos->getLineasLeidas());

    adquisicionDatos->getVisualizador()->initLectura();

    ui->mdiArea->addSubWindow(adquisicionDatos->getVisualizador());
    adquisicionDatos->getVisualizador()->show();

}

void FormSimulador::slotEncambezados()
{
    subWindowCabeceraFits->show();
}

void FormSimulador::slotCerrarCabeceras()
{
    subWindowCabeceraFits->hide();
}

void FormSimulador::slotControlShmidt()
{
    qDebug()<<"HOLA MUNDO";
}


void FormSimulador::slotParaManejarRaton(int x, int y)
{
    qDebug()<<x;
    qDebug()<<y;
}

FormSimulador::~FormSimulador()
{
    delete ui;
}

void FormSimulador::resizeEvent(QResizeEvent *)
{

    scaledPixmap = fondo.scaled(ui->mdiArea->size());

    ui->mdiArea->setBackground(*new QBrush(scaledPixmap));

}

void FormSimulador::mouseDoubleClickEvent(QMouseEvent *event)
{
    int xRaton = event->pos().x();
    int yRaton = event->pos().y();
    //emitir la señal mousePressed
    emit mousePressed(xRaton, yRaton);
}

AdquisicionDatos *FormSimulador::getAdquisicionDatos()
{
    return adquisicionDatos;
}

void FormSimulador::abrirSitemaDatos()
{
//    sistemaDatos = new SistemaDatos();
//    //ui->mdiArea->addSubWindow(sistemaDatos);
//    sistemaDatos->show();
}

void FormSimulador::asignarFondo(bool encendido)
{
    if(encendido==true){
        fondo.load(":/images/pantalla1.jpg");
        ui->mdiArea->setBackground(*new QBrush(fondo));
        this->setGeometry(this->geometry().x(),this->geometry().y()+1,this->geometry().width(),this->geometry().height()+1);
    }
    emit mostrarConsola();

}

void FormSimulador::abrirTerminal()
{
    terminal = new Terminal();
    ui->mdiArea->addSubWindow(terminal);
    terminal->show();
}
