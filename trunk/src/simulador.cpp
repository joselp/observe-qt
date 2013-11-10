#include "headers/simulador.h"
#include "ui_simulador.h"
#include <QtGui>

Simulador::Simulador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulador)
{
    ui->setupUi(this);
    manejadorBd = new ManejadorBd();
    configurarSesionBd();
    manejadorBd->abrirSesion();

    connect(ui->actionSalir,SIGNAL(triggered()),this,SLOT(slotSalir()));
    connect(ui->actionSistema_de_Adquisici_on_de_Datos,SIGNAL(triggered()),this,SLOT(slotSistemaDatos()));
    connect(ui->actionConsola,SIGNAL(triggered()),this,SLOT(slotConsola()));
    connect(ui->actionControlShmidt,SIGNAL(triggered()),this,SLOT(slotControlShmitd()));
    //this->showMaximized();

    ui->actionConsola->setVisible(false);

    panelAdministrativo = new PanelAdministrativo;
    formSimulador = new FormSimulador;
    formHome = new FormHome;
    //sistemaDatos = new SistemaDatos;

    initGui();
    ocultarMenu();

}

void Simulador::initGui()
{
    this->setWindowTitle("Simulador de Observaciones Astronomicas");

    formHome->setGeometry(ui->verticalLayoutContenido->geometry());
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //formHome->showMaximized();
    ui->verticalLayoutContenido->addWidget(formHome);

    connect(formHome->getButtonAcceder(),SIGNAL(clicked()),this,SLOT(slotAcceder()));
    //connect(ui->actionAbrir,SIGNAL(triggered()),this,SLOT(slotAcceder()));
    connect(ui->actionPanel_Administrativo,SIGNAL(triggered()),this,SLOT(slotPanelAdministrativo()));

    connect(ui->pushButtonDrifscan,SIGNAL(clicked()),this,SLOT(slotDrifscan()));
    connect(ui->pushButtonDMod,SIGNAL(clicked()),this,SLOT(slotDrifscanMod()));
    connect(ui->pushButtonDarksDrif,SIGNAL(clicked()),this,SLOT(slotDarkDrifscan()));
    ui->pushButtonDMod->setText("Drifscan\nModificado");

    connect(formSimulador,SIGNAL(mostrarConsola()),this,SLOT(slotMostrarConsola()));
}

void Simulador::configurarSesionBd()
{
    manejadorBd->establecerHost("localhost");
    manejadorBd->establecerPuerto(5432);
    manejadorBd->establecerBaseDatos("observeBD");
    manejadorBd->establecerNombreUsuario("joseluis");
    manejadorBd->establecerPassword("joseluis");
}

void Simulador::cambiarPanel(QWidget *widget)
{
    removerContenidoWidget();
    ui->verticalLayoutContenido->addWidget(widget);
    //qDebug()<<ui->verticalLayoutContenido->geometry();
}

void Simulador::removerContenidoWidget()
{
    if(!ui->verticalLayoutContenido->isEmpty())
        delete(ui->verticalLayoutContenido->widget());
}

void Simulador::mostrarMenu()
{
    ui->toolBar->setVisible(true);
    ui->label->setVisible(true);
    ui->pushButtonDrifscan->setVisible(true);
    ui->pushButtonDMod->setVisible(true);
    ui->pushButtonGuiada->setVisible(true);
    ui->pushButtonBias->setVisible(true);
    ui->pushButtonDarksDrif->setVisible(true);
    ui->pushButtonDarksGuiada->setVisible(true);
    ui->pushButtonFlatsDrif->setVisible(true);
    ui->pushButtonFoco->setVisible(true);
    ui->pushButtonFlatsGuiada->setVisible(true);
    ui->menubar->setVisible(true);
}

void Simulador::ocultarMenu()
{
    ui->toolBar->setVisible(false);
    ui->label->setVisible(false);
    ui->pushButtonDrifscan->setVisible(false);
    ui->pushButtonDMod->setVisible(false);
    ui->pushButtonGuiada->setVisible(false);
    ui->pushButtonBias->setVisible(false);
    ui->pushButtonDarksDrif->setVisible(false);
    ui->pushButtonDarksGuiada->setVisible(false);
    ui->pushButtonFlatsDrif->setVisible(false);
    ui->pushButtonFoco->setVisible(false);
    ui->pushButtonFlatsGuiada->setVisible(false);
    ui->menubar->setVisible(false);
}

FormSimulador *Simulador::getFormSimulador()
{
    return formSimulador;
}


//Para redimensionar todos los elementos de la ventana cuando cambie de tamaño.
void Simulador::resizeEvent(QResizeEvent *)
{
    ui->verticalLayoutContenido->setGeometry(QRect(ui->verticalLayoutContenido->geometry().x(),ui->verticalLayoutContenido->geometry().y(),ui->verticalLayoutContenido->geometry().width(),ui->centralwidget->height()-10));
    //formSimulador->resizeFondo();
}

Simulador::~Simulador()
{
    delete ui;
}

void Simulador::slotAcceder()
{
    if(formHome->autenticar()==true){

        removerContenidoWidget();

        cambiarPanel(formSimulador);
        mostrarMenu();
        this->setGeometry(0,0,QApplication::desktop()->width(),QApplication::desktop()->height());
        idUsuario = formHome->obtenerIdUsuario();
    }
    else{
        QMessageBox msg;
        msg.critical(this, "Error", "Error al iniciar sesion\nUsuario o contraseña incorrecta");
    }
}

void Simulador::slotPanelAdministrativo()
{
    //Debo verificar antes si en realidad el usuario conectado es un administrador
    panelAdministrativo->show();
}

void Simulador::slotDrifscan()
{
    formSimulador->asignarVentanas();

    //ui->actionCargar_Prueba->setDisabled(true);
    formSimulador->getAdquisicionDatos()->seleccionarComandoDeObservacionComboBox(1);

    formSimulador->getAdquisicionDatos()->getVisualizador()->setPrueba("DriftScan");

    ui->pushButtonDrifscan->setDisabled(true);
    ui->pushButtonDMod->setDisabled(false);
    ui->pushButtonGuiada->setDisabled(false);
    ui->pushButtonBias->setDisabled(false);
    ui->pushButtonDarksDrif->setDisabled(false);
    ui->pushButtonDarksGuiada->setDisabled(false);
    ui->pushButtonFlatsDrif->setDisabled(false);
    ui->pushButtonFoco->setDisabled(false);
    ui->pushButtonFlatsGuiada->setDisabled(false);

}

void Simulador::slotDrifscanMod()
{
    ui->pushButtonDrifscan->setDisabled(false);
    ui->pushButtonDMod->setDisabled(true);
    ui->pushButtonGuiada->setDisabled(false);
    ui->pushButtonBias->setDisabled(false);
    ui->pushButtonDarksDrif->setDisabled(false);
    ui->pushButtonDarksGuiada->setDisabled(false);
    ui->pushButtonFlatsDrif->setDisabled(false);
    ui->pushButtonFoco->setDisabled(false);
    ui->pushButtonFlatsGuiada->setDisabled(false);
}

void Simulador::slotBias()
{
    ui->pushButtonDrifscan->setDisabled(false);
    ui->pushButtonDMod->setDisabled(false);
    ui->pushButtonGuiada->setDisabled(false);
    ui->pushButtonBias->setDisabled(true);
    ui->pushButtonDarksDrif->setDisabled(false);
    ui->pushButtonDarksGuiada->setDisabled(false);
    ui->pushButtonFlatsDrif->setDisabled(false);
    ui->pushButtonFoco->setDisabled(false);
    ui->pushButtonFlatsGuiada->setDisabled(false);
}

void Simulador::slotDarkDrifscan()
{
    formSimulador->asignarVentanas();

    formSimulador->getAdquisicionDatos()->seleccionarComandoDeObservacionComboBox(5);

    formSimulador->getAdquisicionDatos()->getVisualizador()->setPrueba("DarkDriftScan");

    ui->pushButtonDrifscan->setDisabled(false);
    ui->pushButtonDMod->setDisabled(false);
    ui->pushButtonGuiada->setDisabled(false);
    ui->pushButtonBias->setDisabled(false);
    ui->pushButtonDarksDrif->setDisabled(true);
    ui->pushButtonDarksGuiada->setDisabled(false);
    ui->pushButtonFlatsDrif->setDisabled(false);
    ui->pushButtonFoco->setDisabled(false);
    ui->pushButtonFlatsGuiada->setDisabled(false);
}

void Simulador::slotSalir()
{
    exit(0);
}

void Simulador::slotSistemaDatos()
{
    //ui->->addSubWindow(sistemaDatos);

    formSimulador->abrirSitemaDatos();

//    if(sistemaDatos->isHidden())
//        sistemaDatos->show();
//    else
//        sistemaDatos->activateWindow();

//    sistemaDatos->setFormSimulador(this->getFormSimulador());

}

void Simulador::slotConsola()
{
    formSimulador->abrirTerminal();
}

void Simulador::slotControlShmitd()
{
    controlSchmitd = new Controlschmitd();
    controlSchmitd->show();
}

void Simulador::slotMostrarConsola()
{
   ui->actionConsola->setVisible(true);
   disconnect(formSimulador,SIGNAL(mostrarConsola()),this,SLOT(slotMostrarConsola()));
   connect(formSimulador,SIGNAL(ocultarConsola()),this,SLOT(slotOcultarConsola()));
}

void Simulador::slotOcultarConsola()
{
    ui->actionConsola->setVisible(false);
    disconnect(formSimulador,SIGNAL(ocultarConsola()),this,SLOT(slotOcultarConsola()));
    connect(formSimulador,SIGNAL(mostrarConsola()),this,SLOT(slotMostrarConsola()));
}
