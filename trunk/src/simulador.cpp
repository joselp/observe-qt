#include "headers/simulador.h"
#include "ui_simulador.h"
#include <QtGui>

Simulador::Simulador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulador)
{
    ui->setupUi(this);

    connect(ui->actionSalir,SIGNAL(triggered()),this,SLOT(slotSalir()));
    connect(ui->actionSistema_de_Adquisici_on_de_Datos,SIGNAL(triggered()),this,SLOT(slotSistemaDatos()));
    //this->showMaximized();

    panelAdministrativo = new PanelAdministrativo;
    formSimulador = new FormSimulador;

    formHome = new FormHome;

    initGui();
    ocultarMenu();


}

void Simulador::initGui()
{
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
    formSimulador->abrirSitemaDatos();

}
