#include "simulador.h"
#include "ui_simulador.h"
#include <QtGui>

Simulador::Simulador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulador)
{
    ui->setupUi(this);

    //this->showMaximized();

    panelAdministrativo = new PanelAdministrativo;

    formHome = new FormHome;
    formHome->setGeometry(ui->verticalLayoutContenido->geometry());
    //this->setWindowFlags(Qt::FramelessWindowHint);
    //formHome->showMaximized();
    ui->verticalLayoutContenido->addWidget(formHome);

    connect(formHome->obtenerButtonAcceder(),SIGNAL(clicked()),this,SLOT(slotAcceder()));
    //connect(ui->actionAbrir,SIGNAL(triggered()),this,SLOT(slotAcceder()));
    connect(ui->actionPanel_Administrativo,SIGNAL(triggered()),this,SLOT(slotPanelAdministrativo()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotImagenesNormales()));
    ui->pushButton->setText("Imagenes\nNormales");

    ocultarMenu();
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
    ui->pushButton->setVisible(true);
    ui->menubar->setVisible(true);
}

void Simulador::ocultarMenu()
{
    ui->toolBar->setVisible(false);
    ui->label->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->menubar->setVisible(false);
}

//Para redimensionar todos los elementos de la ventana cuando cambie de tamaño.
void Simulador::resizeEvent(QResizeEvent *)
{
    ui->verticalLayoutContenido->setGeometry(QRect(ui->verticalLayoutContenido->geometry().x(),ui->verticalLayoutContenido->geometry().y(),ui->verticalLayoutContenido->geometry().width(),ui->centralwidget->height()-30));
}

Simulador::~Simulador()
{
    delete ui;
}

void Simulador::slotAcceder()
{
    if(formHome->autenticar()==true){

        removerContenidoWidget();
        formSimulador = new FormSimulador;
        cambiarPanel(formSimulador);
        mostrarMenu();
    }
}

void Simulador::slotPanelAdministrativo()
{
    //Debo verificar antes si en realidad el usuario conectado es un administrador
    panelAdministrativo->show();
}

void Simulador::slotImagenesNormales()
{
    formSimulador->asignarVentanas();
}
