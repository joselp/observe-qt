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

    activarFiltroWidget = new char[1];
    activarFiltroWidget[0] = 's';

    iniciarGui();
    validarCampos();

}

CabecerasFits::~CabecerasFits()
{
    delete ui;
}

void CabecerasFits::iniciarGui()
{

    connect(ui->nombreProyectopushButton,SIGNAL(clicked()),this,SLOT(slotMostrarNombreProyectoWidget()));
    connect(ui->filtro1PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro1Widget()));
    connect(ui->filtro2PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro2Widget()));
    connect(ui->filtro3PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro3Widget()));
    connect(ui->filtro4PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro4Widget()));
    connect(ui->cerrarPushButton,SIGNAL(clicked()),this,SLOT(slotcerrar()));

    QStringList declinacionAnguloItems;
    declinacionAnguloItems << "Este" << "Oeste" << "Meridiano";
    ui->declinacionAnguloComboBox->addItems(declinacionAnguloItems);

    ui->noRadioButto->setChecked(true);

    QStringList condicionesCieloItems;
    condicionesCieloItems << "Despejado" << "Nublado" << "50% Nublado" << "25% Nublado" << "Despejado Bruma Alta";
    ui->condicionesCieloComboBox->addItems(condicionesCieloItems);

    ui->temperaturaNeveraLineEdit->setText("-65");

    ui->orientacionPrismaLineEdit->setText("-1");
    ui->orientacionPrismaLineEdit->setEnabled(false);

    ui->frecuenciaYicLineEdit->setText("0.0");
    ui->frecuenciaYicLineEdit->setEnabled(false);

    ui->frecuenciaRaLineEdit->setText("0.0");
    ui->frecuenciaRaLineEdit->setEnabled(false);

    ui->frecuenciaDecLineEdit->setText("0.0");
    ui->frecuenciaDecLineEdit->setEnabled(false);

    ui->instrumentoUsadoComboBox->addItem("YIC");
    ui->instrumentoUsadoComboBox->addItem("YIC+PRISMA");

    QStringList observadores;
    observadores << "Alfredo Mejia" << "Bolivia Cuevas" << "Cecilia Mateu" << "Cesar Bricenno" << "Elvis LaCruz" << "Fabiola Hernandez"
                 << "Ismael Santana" << "Ivan Vivas" << "Ivan Cabrera" << "Jesus Hernandez" << "Jose Fernandez" << "Juan Downes"
                 << "Kathy Vivas" << "Leidy Penna" << "Luz Zambrano" << "Madeleine Rodriguez" << "Maria Batista" << "Maria Ocando"
                 << "Nidia Lugo" << "Quriaky Gomez" << "Rafael Gamez" << "Yolanda Landaeta" << "Observador Invitado";
    ui->observadorComboBox->addItems(observadores);

}

void CabecerasFits::slotMostrarNombreProyectoWidget()
{

    if(activarNombreProyectoWidget[0] == 's'){

        activarNombreProyectoWidget[0] = 'n';

        nombreProyecto = new NombreProyectoWidget(this);
        nombreProyecto->setGeometry(233, 25, 812, 443);
        nombreProyecto->setVisible(true);

        nombreProyecto->iniciarConnects(ui->nombreProyectopushButton,activarNombreProyectoWidget);

    }

}

void CabecerasFits::slotMostrarFiltro1Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(694, 25, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro1PushButton,activarFiltroWidget);

    }

}

void CabecerasFits::slotMostrarFiltro2Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(694, 48, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro2PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro3Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(694, 83, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro3PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro4Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(694, 118, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro4PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotcerrar(){
    this->close();
}

void CabecerasFits::activarFrecuenciaDM(bool b)
{
    ui->frecuenciaYicLineEdit->setEnabled(b);
    ui->frecuenciaRaLineEdit->setEnabled(b);
    ui->frecuenciaDecLineEdit->setEnabled(b);
}

void CabecerasFits::validarCampos()
{
    ui->raHhLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-2][0-3]|[0-9]|[0-1][0-9])"),this));
    ui->raMmLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[0-5][0-9])"),this));
    ui->raSsLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])"),this));
    ui->focoTelescopioLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]{3})"),this));

}


