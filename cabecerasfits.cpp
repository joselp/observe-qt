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
    connect(ui->raSsLineEdit,SIGNAL(editingFinished()),this,SLOT(slotVerificarRaSs()));
    connect(ui->anguloHorarioSsLineEdit,SIGNAL(editingFinished()),this,SLOT(slotVerificarAHSs()));
    connect(ui->declinacionSsLineEdit,SIGNAL(editingFinished()),this,SLOT(slotVerificarDeSs()));
    connect(ui->temperaturaNeveraLineEdit,SIGNAL(editingFinished()),this,SLOT(slotVerificarTempNev()));
    connect(ui->temperaturaDomoLineEdit,SIGNAL(editingFinished()),this,SLOT(slotVerificarTemDomo()));
    connect(ui->cerrarPushButton,SIGNAL(clicked()),this,SLOT(slotcerrar()));

    QStringList declinacionAnguloItems;
    declinacionAnguloItems << "Este" << "Oeste" << "Meridiano";
    ui->declinacionAnguloComboBox->addItems(declinacionAnguloItems);

    ui->raSsLineEdit->setText("00.00");
    ui->anguloHorarioSsLineEdit->setText("00.00");
    ui->declinacionSsLineEdit->setText("00.00");

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
        filtro->setGeometry(700, 28, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro1PushButton,activarFiltroWidget);

    }

}

void CabecerasFits::slotMostrarFiltro2Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 58, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro2PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro3Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 88, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro3PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro4Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 118, 155, 423);
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

    ui->focoTelescopioLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]{3})"),this));

    ui->anguloHorarioHhLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-6])"),this));
    ui->anguloHorarioMmLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[0-5][0-9])"),this));

    ui->declinacionGgLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]{3})"),this));
    ui->declinacionMmLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[0-5][0-9])"),this));

    ui->nombreObjetoLineEdit->setValidator(new QRegExpValidator(QRegExp("([^\\s]*)"),this));

    ui->posicionDedosXLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-9]{3})"),this));
    ui->posicionDedosYLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-9]{3})"),this));
    ui->posicionDedosZLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-9]{3})"),this));
    ui->posicionDedosTLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-9]{3})"),this));

    ui->temperaturaDedosXLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[1-2][0])"),this));
    ui->temperaturaDedosYLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[1-2][0])"),this));
    ui->temperaturaDedosZLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[1-2][0])"),this));
    ui->temperaturaDedosTLineEdit->setValidator(new QRegExpValidator(QRegExp("([0-9]|[1-2][0])"),this));

    ui->vacioCamaralineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-4][0-9]{2})"),this));

    ui->vacioLineaInferiorLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-4][0-9]{2})"),this));

    ui->vacioLineaSuperiorLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-4][0-9]{2})"),this));

    ui->humedadDomoLineEdit->setValidator(new QRegExpValidator(QRegExp("([0]|[1-9][0-9]|[1][0]{2})"),this));

}

void CabecerasFits::slotVerificarRaSs()
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerRa()));


    QRegExp rx("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(rx.exactMatch(ui->raSsLineEdit->text())){
        ui->raSsLineEdit->setStyleSheet("background-color:white;"); 
    }

    else{
        contador = 0;
        ui->raSsLineEdit->setFocus();
        timer->start();
    }

}

void CabecerasFits::slotTimerRa(){

    if(contador%2==0){

        ui->raSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->raSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer->stop();
        delete timer;
    }

    contador++;
}

void CabecerasFits::slotVerificarAHSs()
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerAH()));


    QRegExp rx("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(rx.exactMatch(ui->anguloHorarioSsLineEdit->text())){
        ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:white;");
    }

    else{
        contador = 0;
        ui->anguloHorarioSsLineEdit->setFocus();
        timer->start();
    }

}

void CabecerasFits::slotTimerAH()
{
    if(contador%2==0){

        ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer->stop();
        delete timer;
    }

    contador++;
}

void CabecerasFits::slotVerificarDeSs()
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerDe()));


    QRegExp rx("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
    if(rx.exactMatch(ui->declinacionSsLineEdit->text())){
        ui->declinacionSsLineEdit->setStyleSheet("background-color:white;");
    }

    else{
        contador = 0;
        ui->declinacionSsLineEdit->setFocus();
        timer->start();
    }
}

void CabecerasFits::slotTimerDe()
{
    if(contador%2==0){

        ui->declinacionSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->declinacionSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer->stop();
        delete timer;
    }

    contador++;
}

void CabecerasFits::slotVerificarTempNev()
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerTempNev()));

    QRegExp rx("([-][4][9]|[-][5-7][0-9]|[-][8][0])");
    if(rx.exactMatch(ui->temperaturaNeveraLineEdit->text())){
        ui->temperaturaNeveraLineEdit->setStyleSheet("background-color:white;");
    }

    else{
        contador = 0;
        ui->temperaturaNeveraLineEdit->setFocus();
        timer->start();
    }
}

void CabecerasFits::slotTimerTempNev()
{
    if(contador%2==0){

        ui->temperaturaNeveraLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaNeveraLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer->stop();
        delete timer;
    }

    contador++;
}

void CabecerasFits::slotVerificarTemDomo()
{
    timer = new QTimer(this);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),this,SLOT(slotTimerTemDomo()));

    QRegExp rx("([-][1-5]|[1][0-9]|[2][0-5]|[0-9])");
    if(rx.exactMatch(ui->temperaturaDomoLineEdit->text())){
        ui->temperaturaDomoLineEdit->setStyleSheet("background-color:white;");
    }

    else{
        contador = 0;
        ui->temperaturaDomoLineEdit->setFocus();
        timer->start();
    }
}

void CabecerasFits::slotTimerTemDomo()
{
    if(contador%2==0){

        ui->temperaturaDomoLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDomoLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer->stop();
        delete timer;
    }

    contador++;
}
