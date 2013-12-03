#include "headers/formsimulador.h"
#include "ui_formsimulador.h"

FormSimulador::FormSimulador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSimulador)
{
    ui->setupUi(this);
    cargarPrueba = false;
    //Login de babel.
    pass = new QLineEdit(ui->mdiArea);
    pass->setEchoMode(QLineEdit::Password);
    pass->setGeometry(QRect(50,332,200,25));
    pass->setVisible(false);
    login = new QPushButton("Login", ui->mdiArea);
    login->setGeometry(QRect(200,370,70,30));
    login->setVisible(false);
    obturador = new QLabel;

    //Agrego y muestro el sistema de datos al formSimulador
    sistemaDatos = new SistemaDatos;
    subWindowSistemaDatos = new MySubWindow();
    subWindowSistemaDatos->setWidget(sistemaDatos);
    subWindowSistemaDatos->hide();
    ui->mdiArea->addSubWindow(subWindowSistemaDatos);

    fondo.load(":/images/pantallaApagada.jpeg");

    //fondo.load(":/images/pantalla.jpg");

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

    connect(sistemaDatos,SIGNAL(mostrarFondo(bool,bool,bool,bool,bool,bool)),this, SLOT(slotMostrarFondo(bool, bool, bool, bool , bool, bool)));
    connect(login, SIGNAL(clicked()), this, SLOT(slotVerificarSesion()));


}

void FormSimulador::asignarVentanas()
{

    adquisicionDatos= new AdquisicionDatos;

//    if(cargarPrueba==true){

//        if(prueba.value(7).toString() == "Observacion Drifscan")
//            adquisicionDatos->asignarComandoObservacion(1);
//        else if(prueba.value(7).toString() == "Drifscan Modificado")
//            adquisicionDatos->asignarComandoObservacion(2);
//        else if(prueba.value(7).toString() == "Observacion Guiada")
//            adquisicionDatos->asignarComandoObservacion(3);
//        else if(prueba.value(7).toString() == "Darks Guiado")
//            adquisicionDatos->asignarComandoObservacion(4);
//        else if(prueba.value(7).toString() == "Darks Drifscan")
//            adquisicionDatos->asignarComandoObservacion(5);
//        else if(prueba.value(7).toString() == "Flats Guiado")
//            adquisicionDatos->asignarComandoObservacion(6);
//        else if(prueba.value(7).toString() == "Flats Drifscan")
//            adquisicionDatos->asignarComandoObservacion(7);
//        else if(prueba.value(7).toString() == "Bias")
//            adquisicionDatos->asignarComandoObservacion(8);
//        else if(prueba.value(7).toString() == "Foco")
//            adquisicionDatos->asignarComandoObservacion(9);
//    }

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

    if(adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Observacion Drifscan")
        this->getAdquisicionDatos()->getVisualizador()->setPrueba("DriftScan");
    if(adquisicionDatos->getComandoDeObservacionComboBox()->currentText()=="Darks Drifscan")
        this->getAdquisicionDatos()->getVisualizador()->setPrueba("DarkDriftScan");
    //adquisicionDatos->verificarDatos();
    //if(adquisicionDatos->getRealizarObservacion()==true){
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
    else{
        //        //if(visualizador->isVisible()){
        adquisicionDatos->getVisualizador()->setTotalLineas(adquisicionDatos->getNumeroLineasLeer()->text().toInt());
    //            visualizador->initLectura();
    // }
    //    }

    //    if(realizarObservacion==false)
    //        qDebug()<<"Observacion no realizada";
    }
    adquisicionDatos->getVisualizador()->setCondicionesCielo(adquisicionDatos->getCabeceraFits()->getCondicionesCielo());

    //    adquisicionDatos->getVisualizador()->initLectura();
    adquisicionDatos->crearRetardoFit();

    //    ui->mdiArea->addSubWindow(adquisicionDatos->getVisualizador());
    //adquisicionDatos->getVisualizador();
    //}
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

void FormSimulador::slotMostrarFondo(bool qnx1, bool qnx2, bool qnx3, bool qnx4, bool qnx5, bool qnx6)
{
    error1 = qnx1;
    error2 = qnx2;
    error3 = qnx3;
    error4 = qnx4;
    error5 = qnx5;
    error6 = qnx6;

    qDebug()<< qnx1;
    qDebug()<< qnx2;
    qDebug()<< qnx3;
    qDebug()<< qnx4;
    qDebug()<< qnx5;
    qDebug()<< qnx6;
    sistemaDatos->showMinimized();
    pass->setVisible(true);
    login->setVisible(true);
    fondo.load(":/images/pantallaLogin.png");
    ui->mdiArea->setBackground(*new QBrush(fondo));
    this->setGeometry(this->geometry().x(),this->geometry().y()+1,this->geometry().width(),this->geometry().height()+1);

    disconnect(sistemaDatos,SIGNAL(mostrarFondo(bool,bool,bool,bool,bool,bool)),this, SLOT(slotMostrarFondo(bool,bool,bool,bool,bool,bool)));
    connect(sistemaDatos,SIGNAL(ocultarFondo()),this, SLOT(slotOcultarFondo()));   
}

void FormSimulador::slotOcultarFondo(){

    fondo.load(":/images/pantallaApagada.jpeg");
    ui->mdiArea->setBackground(*new QBrush(fondo));
    this->setGeometry(this->geometry().x(),this->geometry().y()-1,this->geometry().width(),this->geometry().height()-1);
    pass->setVisible(false);
    login->setVisible(false);

    disconnect(sistemaDatos,SIGNAL(ocultarFondo()),this, SLOT(slotOcultarFondo()));
    connect(sistemaDatos,SIGNAL(mostrarFondo(bool,bool,bool,bool,bool,bool)),this, SLOT(slotMostrarFondo(bool,bool,bool,bool,bool,bool)));
    ui->mdiArea->closeAllSubWindows();
    emit ocultarConsola();

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
    subWindowSistemaDatos->show();

    if(subWindowSistemaDatos->isHidden())
        subWindowSistemaDatos->show();

//    if(subWindowSistemaDatos->isMinimized()){

//        ui->mdiArea->setActiveSubWindow(subWindowSistemaDatos);
//    }

}

void FormSimulador::asignarFondo(bool encendido)
{
    if(encendido==true){
        fondo.load(":/images/pantalla.jpg");
        ui->mdiArea->setBackground(*new QBrush(fondo));
        this->setGeometry(this->geometry().x(),this->geometry().y()+1,this->geometry().width(),this->geometry().height()+1);
    }
    //emit mostrarConsola();
}

void FormSimulador::slotVerificarSesion()
{
    if(pass->text() == "Miydas"){
        fondo.load(":/images/pantalla.jpg");
        ui->mdiArea->setBackground(*new QBrush(fondo));
        this->setGeometry(this->geometry().x(),this->geometry().y()+1,this->geometry().width(),this->geometry().height()+1);
        pass->setVisible(false);
        login->setVisible(false);
        emit mostrarConsola();
    }
}

void FormSimulador::slotAbrirObserve()
{
    this->asignarVentanas();
}

void FormSimulador::slotObturador(QString c)
{
    if(c=="abrir")
        obturador->setPixmap(QPixmap(":/images/obt_abierto.jpg"));
    if(c=="cerrar")
        obturador->setPixmap(QPixmap(":/images/obt_cerrado.gif"));
}

void FormSimulador::abrirTerminal()
{
    terminal = new Terminal();
    terminal->obtenerConsolaComandos()->asignarError1(error1);
    terminal->obtenerConsolaComandos()->asignarError2(error2);
    terminal->obtenerConsolaComandos()->asignarError3(error3);
    terminal->obtenerConsolaComandos()->asignarError4(error4);
    terminal->obtenerConsolaComandos()->asignarError5(error5);
    terminal->obtenerConsolaComandos()->asignarError6(error6);
    connect(terminal->obtenerConsolaComandos(),SIGNAL(ejecutarComando(QString)),this,SLOT(slotObturador(QString)));
    ui->mdiArea->addSubWindow(terminal);
    terminal->show();
}

void FormSimulador::abrirControlSchmitd()
{
    controlSchmitd = new Controlschmitd;
    subWindowControl = new MySubWindow();
    subWindowControl->setWidget(controlSchmitd);
    connect(controlSchmitd,SIGNAL(abrirObserve()),this,SLOT(slotAbrirObserve()));
    ui->mdiArea->addSubWindow(subWindowControl);
    subWindowControl->show();
}

void FormSimulador::asignarPrueba(QSqlQuery p, bool cp)
{
    prueba = p;
    cargarPrueba = cp;
}

void FormSimulador::asignarObturador(QLabel *obt)
{
    obturador = obt;
}
