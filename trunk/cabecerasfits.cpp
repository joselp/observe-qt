#include "cabecerasfits.h"
#include "ui_cabecerasfits.h"
#include <QLayout>

CabecerasFits::CabecerasFits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CabecerasFits)
{
    ui->setupUi(this);
    this->setWindowTitle("Cabeceras Fits");

    activarNombreProyectoWidget = new char[1];
    activarNombreProyectoWidget[0] = 's';

    iniciarGui();
    iniciarNombreProyectoWidget();

}

CabecerasFits::~CabecerasFits()
{
    delete ui;
}

void CabecerasFits::iniciarGui()
{

//    comboBox = new QComboBoxEvent;

//    ui->verticalLayout->addWidget(comboBox);

//    QStringList itemNombreProyecto;
//    itemNombreProyecto << "A Southern Sky Survey for Pluto Size Trans-Neptunians Object"
//                       << "Buscando Estrellas Jovenes Variables en la Cabeza de Orion"
//                       << "Busqueda de Estrellas Tardias en la Via Lactea"
//                       << "Busqueda de Planetas Menores, Transneptunianos, Cometas y otros Objetos del Sistema"
//                       << "Caracterizacion de la Poblacion de RR Lyrae en el Disco Grueso de la Galaxia"
//                       <<"";
//    comboBox->addItems(itemNombreProyecto);

    //ui->comboBox->setItemData(1,QVariant(QString("HOLA")),0);
    //ui->comboBox->setItemText(2,"HOLAMUNDO");

    //connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(cambiarNombreProyecto(int)));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(mostrarNombreProyectoWidget()));

}

void CabecerasFits::iniciarNombreProyectoWidget()
{


}

void CabecerasFits::mostrarNombreProyectoWidget()
{


    if(activarNombreProyectoWidget[0] == 's'){
        //iniciarNombreProyectoWidget();
        activarNombreProyectoWidget[0] = 'n';
        qDebug()<< activarNombreProyectoWidget[0];

        nombreProyecto = new NombreProyectoWidget();
        ui->verticalLayout->addWidget(nombreProyecto);
        nombreProyecto->iniciarConnects(ui->pushButton,activarNombreProyectoWidget);

    }

}

