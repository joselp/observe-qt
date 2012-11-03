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

    mapperLineEdits = new QSignalMapper(this);

    mapperTimers = new QSignalMapper(this);

    activarAnimacion = true;

    iniciarGui();
    iniciarConnects();
}

CabecerasFits::~CabecerasFits()
{
    delete ui;
}

void CabecerasFits::iniciarGui()
{   

    ui->raSsLineEdit->setText("00.00");

    QStringList declinacionAnguloItems;
    declinacionAnguloItems << "Este" << "Oeste" << "Meridiano";
    ui->declinacionAnguloComboBox->addItems(declinacionAnguloItems);

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

    //Tooltips para los campos.
    ui->raHhLineEdit->setToolTip("[0;23]");
    ui->raMmLineEdit->setToolTip("[0;59]");
    ui->raSsLineEdit->setToolTip("[0.00;59.99]");
    ui->focoTelescopioLineEdit->setToolTip("[0;999]");
    ui->anguloHorarioHhLineEdit->setToolTip("[0;6]");
    ui->anguloHorarioMmLineEdit->setToolTip("[0;59]");
    ui->anguloHorarioSsLineEdit->setToolTip("[0.0;59.99]");
    ui->declinacionGgLineEdit->setToolTip("[0;90]");
    ui->declinacionMmLineEdit->setToolTip("[0;59]");
    ui->declinacionSsLineEdit->setToolTip("[0.0,59.9]");
    ui->nombreObjetoLineEdit->setToolTip("<p>No debe estar vac&iacute;a ni tener espacios en blanco");
    ui->posicionDedosXLineEdit->setToolTip("[0;999]");
    ui->posicionDedosYLineEdit->setToolTip("[0;999]");
    ui->posicionDedosZLineEdit->setToolTip("[0;999]");
    ui->posicionDedosTLineEdit->setToolTip("[0;999]");
    ui->temperaturaDedosXLineEdit->setToolTip("[-80;2 0]");
    ui->temperaturaDedosXLineEdit->setToolTip("[-80;2 0]");
    ui->temperaturaDedosYLineEdit->setToolTip("[-80;2 0]");
    ui->temperaturaDedosZLineEdit->setToolTip("[-80;2 0]");
    ui->temperaturaDedosTLineEdit->setToolTip("[-80;2 0]");
    ui->vacioLineaInferiorLineEdit->setToolTip("[0;499]");
    ui->vacioLineaInferiorLineEdit->setToolTip("[0;499]");
    ui->temperaturaNeveraLineEdit->setToolTip("[-50;-80]");
    ui->orientacionPrismaLineEdit->setToolTip("[0-360]");
    ui->temperaturaDomoLineEdit->setToolTip("[-5, 25]");
    ui->humedadDomoLineEdit->setToolTip("[0-100]");

}

void CabecerasFits::iniciarConnects()
{

    //Conecto todos los LineEdits al mapper
    connect(ui->raHhLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->raMmLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->raSsLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->focoTelescopioLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->anguloHorarioHhLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->anguloHorarioMmLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->anguloHorarioSsLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->declinacionGgLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->declinacionMmLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->declinacionSsLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->nombreObjetoLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->posicionDedosXLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->posicionDedosYLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->posicionDedosZLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->posicionDedosTLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaDedosXLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaDedosYLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaDedosZLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaDedosTLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->vacioCamaralineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->vacioLineaSuperiorLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->vacioLineaInferiorLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaNeveraLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->temperaturaDomoLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));
    connect(ui->humedadDomoLineEdit, SIGNAL(editingFinished()), mapperLineEdits, SLOT(map()));

    //Asigno un Id a cada Boton.

    mapperLineEdits->setMapping(ui->raHhLineEdit, 1);
    mapperLineEdits->setMapping(ui->raMmLineEdit, 2);
    mapperLineEdits->setMapping(ui->raSsLineEdit, 3);
    mapperLineEdits->setMapping(ui->focoTelescopioLineEdit, 4);
    mapperLineEdits->setMapping(ui->anguloHorarioHhLineEdit, 5);
    mapperLineEdits->setMapping(ui->anguloHorarioMmLineEdit, 6);
    mapperLineEdits->setMapping(ui->anguloHorarioSsLineEdit, 7);
    mapperLineEdits->setMapping(ui->declinacionGgLineEdit, 8);
    mapperLineEdits->setMapping(ui->declinacionMmLineEdit, 9);
    mapperLineEdits->setMapping(ui->declinacionSsLineEdit, 10);
    mapperLineEdits->setMapping(ui->nombreObjetoLineEdit, 11);
    mapperLineEdits->setMapping(ui->posicionDedosXLineEdit, 12);
    mapperLineEdits->setMapping(ui->posicionDedosYLineEdit, 13);
    mapperLineEdits->setMapping(ui->posicionDedosZLineEdit, 14);
    mapperLineEdits->setMapping(ui->posicionDedosTLineEdit, 15);
    mapperLineEdits->setMapping(ui->temperaturaDedosXLineEdit, 16);
    mapperLineEdits->setMapping(ui->temperaturaDedosYLineEdit, 17);
    mapperLineEdits->setMapping(ui->temperaturaDedosZLineEdit, 18);
    mapperLineEdits->setMapping(ui->temperaturaDedosTLineEdit, 19);
    mapperLineEdits->setMapping(ui->vacioCamaralineEdit, 20);
    mapperLineEdits->setMapping(ui->vacioLineaSuperiorLineEdit, 21);
    mapperLineEdits->setMapping(ui->vacioLineaInferiorLineEdit, 22);
    mapperLineEdits->setMapping(ui->temperaturaNeveraLineEdit, 23);
    mapperLineEdits->setMapping(ui->temperaturaDomoLineEdit, 24);
    mapperLineEdits->setMapping(ui->humedadDomoLineEdit, 25);

    connect(mapperLineEdits, SIGNAL(mapped(int)),this, SLOT(slotVerificar(int)));


    ////////////////////////////////////////////////////////////////////////////

    connect(ui->nombreProyectopushButton,SIGNAL(clicked()),this,SLOT(slotMostrarNombreProyectoWidget()));
    connect(ui->filtro1PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro1Widget()));
    connect(ui->filtro2PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro2Widget()));
    connect(ui->filtro3PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro3Widget()));
    connect(ui->filtro4PushButton,SIGNAL(clicked()),this,SLOT(slotMostrarFiltro4Widget()));

    connect(ui->instrumentoUsadoComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(slotInstrumentoUsado(int)));

    connect(ui->cerrarPushButton,SIGNAL(clicked()),this,SLOT(slotcerrar()));
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

        filtro->iniciarConnects(ui->filtro1PushButton,ui->filtro2PushButton,ui->filtro3PushButton,ui->filtro4PushButton,activarFiltroWidget);

    }

}

void CabecerasFits::slotMostrarFiltro2Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 58, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro2PushButton,ui->filtro1PushButton,ui->filtro3PushButton,ui->filtro4PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro3Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 88, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro3PushButton,ui->filtro1PushButton,ui->filtro2PushButton,ui->filtro4PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotMostrarFiltro4Widget()
{
    if(activarFiltroWidget[0] == 's'){

        activarFiltroWidget[0] = 'n';

        filtro = new Filtro1Widget(this);
        filtro->setGeometry(700, 118, 155, 423);
        filtro->setVisible(true);

        filtro->iniciarConnects(ui->filtro4PushButton,ui->filtro1PushButton,ui->filtro2PushButton,ui->filtro3PushButton,activarFiltroWidget);

    }
}

void CabecerasFits::slotcerrar(){
    this->hide();
}

void CabecerasFits::activarFrecuenciaDM(bool b)
{
    ui->frecuenciaYicLineEdit->setEnabled(b);
    ui->frecuenciaRaLineEdit->setEnabled(b);
    ui->frecuenciaDecLineEdit->setEnabled(b);
}


///////////////Verificacion de campos bien escritos mas no vacios///////////////////////////////////////////

void CabecerasFits::slotVerificar(int i)
{

    if(i==1){

        QRegExp rx("([0-2][0-3]|[0-9]|[0-1][0-9])");
        if(rx.exactMatch(ui->raHhLineEdit->text()) || ui->raHhLineEdit->text().size()==0){

            ui->raHhLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->raHhLineEdit->setFocus();
            if(activarAnimacion==true){

                timer[0]= new QTimer(this);
                timer[0]->setInterval(200);
                connect(timer[0],SIGNAL(timeout()),this,SLOT(slotTimerRaHh()));

                contador = 0;
                activarAnimacion=false;
                ui->raHhLineEdit->setFocus();
                timer[0]->start();
            }

        }


    }

    if(i==2){

        QRegExp rx("([0-9]|[0-5][0-9])");
        if(rx.exactMatch(ui->raMmLineEdit->text()) || ui->raMmLineEdit->text().size()==0){
            ui->raMmLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->raMmLineEdit->setFocus();
            if(activarAnimacion==true){

                timer[1]= new QTimer(this);
                timer[1]->setInterval(200);

                connect(timer[1],SIGNAL(timeout()),this,SLOT(slotTimerRaMm()));
                contador = 0;
                activarAnimacion=false;
                ui->raMmLineEdit->setFocus();
                timer[1]->start();
            }

        }
    }
    if(i==3){


        QRegExp rx("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
        if(rx.exactMatch(ui->raSsLineEdit->text()) || ui->raSsLineEdit->text().size()==0){
            ui->raSsLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->raSsLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[2]= new QTimer(this);
                timer[2]->setInterval(200);
                connect(timer[2],SIGNAL(timeout()),this,SLOT(slotTimerRaSs()));

                contador = 0;
                activarAnimacion=false;
                ui->raSsLineEdit->setFocus();
                timer[2]->start();
            }

        }
    }

    if(i==4){

        QRegExp rx("([0-9]|[0-9]{2}|[0-9]{3})");
        if(rx.exactMatch(ui->focoTelescopioLineEdit->text()) || ui->focoTelescopioLineEdit->text().size()==0){
            ui->focoTelescopioLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->focoTelescopioLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[3]= new QTimer(this);
                timer[3]->setInterval(200);
                connect(timer[3],SIGNAL(timeout()),this,SLOT(slotTimerFocoT()));
                contador = 0;
                activarAnimacion=false;
                ui->focoTelescopioLineEdit->setFocus();
                timer[3]->start();
            }

        }
    }

    if(i==5){


        QRegExp rx("([0-6])");
        if(rx.exactMatch(ui->anguloHorarioHhLineEdit->text()) || ui->anguloHorarioHhLineEdit->text().size()==0){
            ui->anguloHorarioHhLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->anguloHorarioHhLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[4]= new QTimer(this);
                timer[4]->setInterval(200);
                connect(timer[4],SIGNAL(timeout()),this,SLOT(slotTimerAHHh()));
                contador = 0;
                activarAnimacion=false;
                ui->anguloHorarioHhLineEdit->setFocus();
                timer[4]->start();
            }

        }
    }
    if(i==6){


        QRegExp rx("([0-9]|[0-5][0-9])");
        if(rx.exactMatch(ui->anguloHorarioMmLineEdit->text()) || ui->anguloHorarioMmLineEdit->text().size()==0){
            ui->anguloHorarioMmLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->anguloHorarioMmLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[5]= new QTimer(this);
                timer[5]->setInterval(200);
                connect(timer[5],SIGNAL(timeout()),this,SLOT(slotTimerAHMm()));
                contador = 0;
                activarAnimacion=false;
                ui->anguloHorarioMmLineEdit->setFocus();
                timer[5]->start();
            }

        }
    }

    if(i==7){

        QRegExp rx("([0-9]\\.[0-9]|[0-9]\\.[0-9][0-9]|[0-5][0-9]\\.[0-9]|[0-5][0-9]\\.[0-9][0-9])");
        if(rx.exactMatch(ui->anguloHorarioSsLineEdit->text()) || ui->anguloHorarioSsLineEdit->text().size()==0){
            ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->anguloHorarioSsLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[6]= new QTimer(this);
                timer[6]->setInterval(200);
                connect(timer[6],SIGNAL(timeout()),this,SLOT(slotTimerAHSs()));
                contador = 0;
                activarAnimacion=false;
                ui->anguloHorarioSsLineEdit->setFocus();
                timer[6]->start();
            }
        }
    }

    if(i==8){

    }

    if(i==9){
        QRegExp rx("([0-9]|[0-5][0-9])");

        if(rx.exactMatch(ui->declinacionMmLineEdit->text()) || ui->declinacionMmLineEdit->text().size()==0){
            ui->declinacionMmLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->declinacionMmLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[7]= new QTimer(this);
                timer[7]->setInterval(200);
                connect(timer[7],SIGNAL(timeout()),this,SLOT(slotTimerDeMm()));
                contador = 0;
                activarAnimacion=false;
                ui->declinacionMmLineEdit->setFocus();
                timer[7]->start();
            }
        }
    }

    if(i==10){
        QRegExp rx("([0-9]\\.[0-9]|[0-5][0-9]\\.[0-9]|[0-9]\\.[0][0]|[0-5][0-9]\\.[0][0])");

        if(rx.exactMatch(ui->declinacionSsLineEdit->text()) || ui->declinacionSsLineEdit->text().size()==0){
            ui->declinacionSsLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->declinacionSsLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[9]= new QTimer(this);
                timer[9]->setInterval(200);
                connect(timer[9],SIGNAL(timeout()),this,SLOT(slotTimerDeSs()));
                contador = 0;
                activarAnimacion=false;
                ui->declinacionSsLineEdit->setFocus();
                timer[9]->start();
            }
        }
    }

    if(i==11){
        QRegExp rx("([^\\s]*)");

        if(rx.exactMatch(ui->nombreObjetoLineEdit->text()) || ui->nombreObjetoLineEdit->text().size()==0){
            ui->nombreObjetoLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->nombreObjetoLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[10]= new QTimer(this);
                timer[10]->setInterval(200);
                connect(timer[10],SIGNAL(timeout()),this,SLOT(slotTimerNomObjeto()));
                contador = 0;
                activarAnimacion=false;
                ui->nombreObjetoLineEdit->setFocus();
                timer[10]->start();
            }
        }
    }

    if(i==12){
        QRegExp rx("([0-9]|[0-9]{2}|[0-9]{3})");

        if(rx.exactMatch(ui->posicionDedosXLineEdit->text()) || ui->posicionDedosXLineEdit->text().size()==0){
            ui->posicionDedosXLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->posicionDedosXLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[11]= new QTimer(this);
                timer[11]->setInterval(200);
                connect(timer[11],SIGNAL(timeout()),this,SLOT(slotTimerPosDX()));
                contador = 0;
                activarAnimacion=false;
                ui->posicionDedosXLineEdit->setFocus();
                timer[11]->start();
            }
        }
    }

    if(i==13){
        QRegExp rx("([0-9]|[0-9]{2}|[0-9]{3})");

        if(rx.exactMatch(ui->posicionDedosYLineEdit->text()) || ui->posicionDedosYLineEdit->text().size()==0){
            ui->posicionDedosYLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->posicionDedosYLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[12]= new QTimer(this);
                timer[12]->setInterval(200);
                connect(timer[12],SIGNAL(timeout()),this,SLOT(slotTimerPosDY()));
                contador = 0;
                activarAnimacion=false;
                ui->posicionDedosYLineEdit->setFocus();
                timer[12]->start();
            }
        }
    }

    if(i==14){
        QRegExp rx("([0-9]|[0-9]{2}|[0-9]{3})");

        if(rx.exactMatch(ui->posicionDedosZLineEdit->text()) || ui->posicionDedosZLineEdit->text().size()==0){
            ui->posicionDedosZLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->posicionDedosZLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[13]= new QTimer(this);
                timer[13]->setInterval(200);
                connect(timer[13],SIGNAL(timeout()),this,SLOT(slotTimerPosDZ()));
                contador = 0;
                activarAnimacion=false;
                ui->posicionDedosZLineEdit->setFocus();
                timer[13]->start();
            }
        }
    }

    if(i==15){
        QRegExp rx("([0-9]|[0-9]{2}|[0-9]{3})");

        if(rx.exactMatch(ui->posicionDedosTLineEdit->text()) || ui->posicionDedosTLineEdit->text().size()==0){
            ui->posicionDedosTLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->posicionDedosTLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[14]= new QTimer(this);
                timer[14]->setInterval(200);
                connect(timer[14],SIGNAL(timeout()),this,SLOT(slotTimerPosDT()));
                contador = 0;
                activarAnimacion=false;
                ui->posicionDedosTLineEdit->setFocus();
                timer[14]->start();
            }
        }
    }

    if(i==16){
        QRegExp rx("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");

        if(rx.exactMatch(ui->temperaturaDedosXLineEdit->text()) || ui->temperaturaDedosXLineEdit->text().size()==0){
            ui->temperaturaDedosXLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaDedosXLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[15]= new QTimer(this);
                timer[15]->setInterval(200);
                connect(timer[15],SIGNAL(timeout()),this,SLOT(slotTimerTempDX()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaDedosXLineEdit->setFocus();
                timer[15]->start();
            }
        }
    }

    if(i==17){
        QRegExp rx("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");

        if(rx.exactMatch(ui->temperaturaDedosYLineEdit->text()) || ui->temperaturaDedosYLineEdit->text().size()==0){
            ui->temperaturaDedosYLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaDedosYLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[16]= new QTimer(this);
                timer[16]->setInterval(200);
                connect(timer[16],SIGNAL(timeout()),this,SLOT(slotTimerTempDY()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaDedosYLineEdit->setFocus();
                timer[16]->start();
            }
        }
    }

    if(i==18){
        QRegExp rx("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");

        if(rx.exactMatch(ui->temperaturaDedosZLineEdit->text()) || ui->temperaturaDedosZLineEdit->text().size()==0){
            ui->temperaturaDedosZLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaDedosZLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[17]= new QTimer(this);
                timer[17]->setInterval(200);
                connect(timer[17],SIGNAL(timeout()),this,SLOT(slotTimerTempDZ()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaDedosZLineEdit->setFocus();
                timer[17]->start();
            }
        }
    }

    if(i==19){
        QRegExp rx("([-][0-9]|[-][0-7][0-9]|[-][8][0]|[0-9]|[1][0-9]|[2][0])");

        if(rx.exactMatch(ui->temperaturaDedosTLineEdit->text()) || ui->temperaturaDedosTLineEdit->text().size()==0){
            ui->temperaturaDedosTLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaDedosTLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[18]= new QTimer(this);
                timer[18]->setInterval(200);
                connect(timer[18],SIGNAL(timeout()),this,SLOT(slotTimerTempDT()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaDedosTLineEdit->setFocus();
                timer[18]->start();
            }
        }
    }

    if(i==20){
        QRegExp rx("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");

        if(rx.exactMatch(ui->vacioCamaralineEdit->text()) || ui->vacioCamaralineEdit->text().size()==0){
            ui->vacioCamaralineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->vacioCamaralineEdit->setFocus();
            if(activarAnimacion==true){
                timer[19]= new QTimer(this);
                timer[19]->setInterval(200);
                connect(timer[19],SIGNAL(timeout()),this,SLOT(slotTimerVacioCam()));
                contador = 0;
                activarAnimacion=false;
                ui->vacioCamaralineEdit->setFocus();
                timer[19]->start();
            }
        }
    }

    if(i==21){
        QRegExp rx("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");

        if(rx.exactMatch(ui->vacioLineaSuperiorLineEdit->text()) || ui->vacioLineaSuperiorLineEdit->text().size()==0){
            ui->vacioLineaSuperiorLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->vacioLineaSuperiorLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[20]= new QTimer(this);
                timer[20]->setInterval(200);
                connect(timer[20],SIGNAL(timeout()),this,SLOT(slotTimerLineaSup()));
                contador = 0;
                activarAnimacion=false;
                ui->vacioLineaSuperiorLineEdit->setFocus();
                timer[20]->start();
            }
        }
    }

    if(i==22){
        QRegExp rx("([0-9]|[0-9][0-9]|[1-4][0-9]{2})");

        if(rx.exactMatch(ui->vacioLineaInferiorLineEdit->text()) || ui->vacioLineaInferiorLineEdit->text().size()==0){
            ui->vacioCamaralineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->vacioLineaInferiorLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[21]= new QTimer(this);
                timer[21]->setInterval(200);
                connect(timer[21],SIGNAL(timeout()),this,SLOT(slotTimerLineaInf()));
                contador = 0;
                activarAnimacion=false;
                ui->vacioLineaInferiorLineEdit->setFocus();
                timer[21]->start();
            }
        }
    }

    if(i==23){
        QRegExp rx("([-][4][9]|[-][5-7][0-9]|[-][8][0])");

        if(rx.exactMatch(ui->temperaturaNeveraLineEdit->text()) || ui->temperaturaNeveraLineEdit->text().size()==0){
            ui->temperaturaNeveraLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaNeveraLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[22]= new QTimer(this);
                timer[22]->setInterval(200);
                connect(timer[22],SIGNAL(timeout()),this,SLOT(slotTimerTempNev()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaNeveraLineEdit->setFocus();
                timer[22]->start();
            }
        }
    }

    if(i==24){
        QRegExp rx("([-][1-5]|[1][0-9]|[2][0-5]|[0-9])");

        if(rx.exactMatch(ui->temperaturaDomoLineEdit->text()) || ui->temperaturaDomoLineEdit->text().size()==0){
            ui->temperaturaDomoLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->temperaturaDomoLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[23]= new QTimer(this);
                timer[23]->setInterval(200);
                connect(timer[23],SIGNAL(timeout()),this,SLOT(slotTimerTempDomo()));
                contador = 0;
                activarAnimacion=false;
                ui->temperaturaDomoLineEdit->setFocus();
                timer[23]->start();
            }
        }
    }

    if(i==25){
        QRegExp rx("([0-9]|[0-9][0-9]|[1][0]{2})");

        if(rx.exactMatch(ui->humedadDomoLineEdit->text()) || ui->humedadDomoLineEdit->text().size()==0){
            ui->humedadDomoLineEdit->setStyleSheet("background-color:white;");
        }
        else{
            ui->humedadDomoLineEdit->setFocus();
            if(activarAnimacion==true){
                timer[24]= new QTimer(this);
                timer[24]->setInterval(200);
                connect(timer[24],SIGNAL(timeout()),this,SLOT(slotTimerHumDomo()));
                contador = 0;
                activarAnimacion=false;
                ui->humedadDomoLineEdit->setFocus();
                timer[24]->start();
            }
        }
    }
}

////////////////////////////Slots para los Timer////////////////////////////////////////////////

void CabecerasFits::slotTimerRaHh()
{

    if(contador%2==0){

        ui->raHhLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->raHhLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[0]->stop();
        delete timer[0];
        activarAnimacion=true;
    }

    contador++;
}
void CabecerasFits::slotTimerRaMm()
{
    if(contador%2==0){

        ui->raMmLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->raMmLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[1]->stop();
        delete timer[1];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerRaSs(){

    if(contador%2==0){

        ui->raSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->raSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[2]->stop();
        delete timer[2];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerFocoT()
{
    if(contador%2==0){

        ui->focoTelescopioLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->focoTelescopioLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[3]->stop();
        delete timer[3];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerAHHh()
{
    if(contador%2==0){

        ui->anguloHorarioHhLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->anguloHorarioHhLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[4]->stop();
        delete timer[4];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerAHMm()
{
    if(contador%2==0){

        ui->anguloHorarioMmLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->anguloHorarioMmLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[5]->stop();
        delete timer[5];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerAHSs()
{
    if(contador%2==0){

        ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->anguloHorarioSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[6]->stop();
        delete timer[6];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerDeGg()
{
}

void CabecerasFits::slotTimerDeMm()
{
    if(contador%2==0){

        ui->declinacionMmLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->declinacionMmLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[8]->stop();
        delete timer[8];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerDeSs()
{
    if(contador%2==0){

        ui->declinacionSsLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->declinacionSsLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[9]->stop();
        delete timer[9];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerNomObjeto()
{
    if(contador%2==0){

        ui->nombreObjetoLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->nombreObjetoLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[10]->stop();
        delete timer[10];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerPosDX()
{
    if(contador%2==0){

        ui->posicionDedosXLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->posicionDedosXLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[11]->stop();
        delete timer[11];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerPosDY()
{
    if(contador%2==0){

        ui->posicionDedosYLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->posicionDedosYLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[12]->stop();
        delete timer[12];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerPosDZ()
{
    if(contador%2==0){

        ui->posicionDedosZLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->posicionDedosZLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[13]->stop();
        delete timer[13];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerPosDT()
{
    if(contador%2==0){

        ui->posicionDedosTLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->posicionDedosTLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[14]->stop();
        delete timer[14];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerTempDX()
{
    if(contador%2==0){

        ui->temperaturaDedosXLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDedosXLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[15]->stop();
        delete timer[15];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerTempDY()
{
    if(contador%2==0){

        ui->temperaturaDedosYLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDedosYLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[16]->stop();
        delete timer[16];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerTempDZ()
{
    if(contador%2==0){

        ui->temperaturaDedosZLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDedosZLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[17]->stop();
        delete timer[17];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerTempDT()
{
    if(contador%2==0){

        ui->temperaturaDedosTLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDedosTLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[18]->stop();
        delete timer[18];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerVacioCam()
{
    if(contador%2==0){

        ui->vacioCamaralineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->vacioCamaralineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[19]->stop();
        delete timer[19];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerLineaSup()
{
    if(contador%2==0){

        ui->vacioLineaSuperiorLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->vacioLineaSuperiorLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[20]->stop();
        delete timer[20];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerLineaInf()
{
    if(contador%2==0){

        ui->vacioLineaInferiorLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->vacioLineaInferiorLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[21]->stop();
        delete timer[21];
        activarAnimacion=true;
    }

    contador++;
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
        timer[22]->stop();
        delete timer[22];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerTempDomo()
{
    if(contador%2==0){

        ui->temperaturaDomoLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->temperaturaDomoLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[23]->stop();
        delete timer[23];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotTimerHumDomo()
{
    if(contador%2==0){

        ui->humedadDomoLineEdit->setStyleSheet("background-color:RED;");
    }
    else{
        ui->humedadDomoLineEdit->setStyleSheet("background-color:white;");

    }
    if(contador==5){
        timer[24]->stop();
        delete timer[24];
        activarAnimacion=true;
    }

    contador++;
}

void CabecerasFits::slotInstrumentoUsado(int i)
{
    if(i==0){
        ui->orientacionPrismaLineEdit->setEnabled(false);
        ui->orientacionPrismaLineEdit->setText("-1");
    }
    if(i==1){
        ui->orientacionPrismaLineEdit->setEnabled(true);
        ui->orientacionPrismaLineEdit->setText("");
    }
}

bool CabecerasFits::orientacionPrimasIsActive()
{
    return ui->orientacionPrismaLineEdit->isEnabled();
}


////////////////////////Getters////////////////////////////////////////////
QString CabecerasFits::getRaHh()
{
    return ui->raHhLineEdit->text();
}

QString CabecerasFits::getRaMm()
{
    return ui->raMmLineEdit->text();
}

QString CabecerasFits::getRaSs()
{
    return ui->raSsLineEdit->text();
}

QString CabecerasFits::getFocoTelescopio()
{
    return ui->focoTelescopioLineEdit->text();
}

QString CabecerasFits::getAHorarioHh()
{
    return ui->anguloHorarioHhLineEdit->text();
}

QString CabecerasFits::getAHorarioMm()
{
    return ui->anguloHorarioMmLineEdit->text();
}

QString CabecerasFits::getAHorarioSs()
{
    return ui->anguloHorarioSsLineEdit->text();
}

QString CabecerasFits::getDeclinacionGg()
{
    return ui->declinacionGgLineEdit->text();
}

QString CabecerasFits::getDeclinacionMm()
{
    return ui->declinacionMmLineEdit->text();
}

QString CabecerasFits::getDeclinacionSs()
{
    return ui->declinacionSsLineEdit->text();
}

QString CabecerasFits::getNombreObjeto()
{
    return ui->nombreObjetoLineEdit->text();
}

QString CabecerasFits::getPosDedosX()
{
    return ui->posicionDedosXLineEdit->text();
}

QString CabecerasFits::getPosDedosY()
{
    return ui->posicionDedosYLineEdit->text();
}

QString CabecerasFits::getPosDedosZ()
{
    return ui->posicionDedosZLineEdit->text();
}

QString CabecerasFits::getPosDedosT()
{
    return ui->posicionDedosTLineEdit->text();
}

QString CabecerasFits::getTemDedosX()
{
    return ui->temperaturaDedosXLineEdit->text();
}

QString CabecerasFits::getTemDedosY()
{
    return ui->temperaturaDedosYLineEdit->text();
}

QString CabecerasFits::getTemDedosZ()
{
    return ui->temperaturaDedosZLineEdit->text();
}

QString CabecerasFits::getTemDedosT()
{
    return ui->temperaturaDedosTLineEdit->text();
}

QString CabecerasFits::getVacioCamara()
{
    return ui->vacioCamaralineEdit->text();
}

QString CabecerasFits::getVacioLineaSuperior()
{
    return ui->vacioLineaSuperiorLineEdit->text();
}

QString CabecerasFits::getVacioLineaInferior()
{
    return ui->vacioLineaInferiorLineEdit->text();
}

QString CabecerasFits::getTempNevera()
{
    return ui->temperaturaNeveraLineEdit->text();
}

QString CabecerasFits::getTempDomo()
{
    return ui->temperaturaDomoLineEdit->text();
}

QString CabecerasFits::getHumedadDomo()
{
    return ui->humedadDomoLineEdit->text();
}

QString CabecerasFits::getFrecuenciaYic()
{
    return ui->frecuenciaYicLineEdit->text();
}

QString CabecerasFits::getFrecuenciaRa()
{
    return ui->frecuenciaRaLineEdit->text();
}

QString CabecerasFits::getFrecuenciaDec()
{
    return ui->frecuenciaDecLineEdit->text();
}

QString CabecerasFits::getOrientacionPrisma()
{
    return ui->orientacionPrismaLineEdit->text();
}

////////////////Setters/////////////////////////////////
void CabecerasFits::setNombreObjeto(QString text)
{
    ui->nombreObjetoLineEdit->setText(text);
}

