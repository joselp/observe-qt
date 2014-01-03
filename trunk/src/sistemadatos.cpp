#include "headers/sistemadatos.h"
#include "ui_sistemadatos.h"

SistemaDatos::SistemaDatos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SistemaDatos)
{
    ui->setupUi(this);
    initGui();

}

void SistemaDatos::initGui()
{
    this->setWindowTitle("Sistema de datos");
    semilla = 50;
    reinicarSistema();

}

void SistemaDatos::closeEvent(QCloseEvent *)
{
    this->hide();
}

void SistemaDatos::reinicarSistema()
{
    ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/sistemaDatos.png"));

    ui->pushButtonQnx1Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonQnx2Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonQnx3Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonQnx4Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonQnx5Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonQnx6Encender->setIcon(QIcon(":/images/iconApagar.png"));
    ui->pushButtonBabel->setIcon(QIcon(":/images/iconApagar.png"));

    qnx1=false;
    qnx2=false;
    qnx3=false;
    qnx4=false;
    Qnx5=false;
    Qnx6=false;
    babel=false;

    //Conecto todos los botones

    connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    connect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Encender()));
    connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
    connect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Encender()));
    connect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Encender()));
    connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));
    connect(ui->pushButtonBabel,SIGNAL(clicked()),this,SLOT(slotBabelEncender()));
    emit ocultarFondo();
}

SistemaDatos::~SistemaDatos()
{
    delete ui;
}

void SistemaDatos::setQnx1(bool a)
{
    qnx1=a;
}

void SistemaDatos::setQnx2(bool a)
{
    qnx2=a;
}

void SistemaDatos::setQnx3(bool a)
{
    qnx3=a;
}

void SistemaDatos::setQnx4(bool a)
{
    qnx4=a;
}

void SistemaDatos::setQnx5(bool a)
{
    Qnx5=a;
}

void SistemaDatos::setQnx6(bool a)
{
    Qnx6=a;
}

void SistemaDatos::setSemilla(int i)
{
    semilla = i;
}

bool SistemaDatos::getQnx1()
{
    return qnx1;
}

bool SistemaDatos::getQnx2()
{
    return qnx2;
}

bool SistemaDatos::getQnx3()
{
    return qnx3;
}

bool SistemaDatos::getQnx4()
{
    return qnx4;
}

bool SistemaDatos::getQnx5()
{
    return Qnx5;
}

bool SistemaDatos::getQnx6()
{
    return Qnx6;
}

bool SistemaDatos::getBabel()
{
    return babel;
}

bool SistemaDatos::getError1()
{
    return error1;
}

bool SistemaDatos::getError2()
{
    return error2;
}

bool SistemaDatos::getError3()
{
    return error3;
}

bool SistemaDatos::getError4()
{
    return error4;
}

bool SistemaDatos::getError5()
{
    return error5;
}

bool SistemaDatos::getError6()
{
    return error6;
}

int SistemaDatos::getSemilla()
{
    return semilla;
}

void SistemaDatos::slotQnx1Encender()
{
    qnx1=true;
    if(babel == true)
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx2qnx3qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
    else
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx1Encendida.png"));
    ui->pushButtonQnx1Encender->setIcon(QIcon(":/images/iconEncender.png"));
    disconnect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Apagar()));
}

void SistemaDatos::slotQnx2Encender()
{
    if(qnx1==true){
        qnx2=true;
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx3qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx2Encendida.png"));
        ui->pushButtonQnx2Encender->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Encender()));
        connect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Apagar()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx1");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx3Encender()
{
    if(qnx2==true){
        qnx3=true;
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx3Encendida.png"));
        ui->pushButtonQnx3Encender->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
        connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Apagar()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero QNX2");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx4Encender()
{
    if(qnx3==true){
        qnx4=true;
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx5qnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx4Encendida.png"));

        ui->pushButtonQnx4Encender->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Encender()));
        connect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Apagar()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx3");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx5Encender()
{
    QString imagen;
    if(babel == true){
        imagen = ":/images/adquisicionDatos/qnx6ApagadaBabelEncendida.png";
    }
    else{
        imagen = ":/images/adquisicionDatos/qnx5Encendidaqnx1okqnx2ok.png";
    }

    if(qnx4==true){
        Qnx5=true;
        ui->labelQnx->setPixmap(QPixmap(imagen));
        ui->pushButtonQnx5Encender->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Encender()));
        connect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Apagar()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx4");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }

    /*if(error==true){

        MensajeOpciones *mensaje = new MensajeOpciones();
        connect(mensaje,SIGNAL(opcionCorrecta(int)),this,SLOT(slotOpcion(int)));
        mensaje->show();

    }
    */
}

void SistemaDatos::slotQnx6Encender()
{
    QString imagen;
    if(babel == true)
        imagen = ":/images/adquisicionDatos/babelEncendidoqnx5okqnx6ok.png";
    else{
        imagen = ":/images/adquisicionDatos/qnx6Encendidoqnx3okqnx4ok.png";

    }
    if(Qnx5==true){
        Qnx6=true;
        ui->labelQnx->setPixmap(QPixmap(imagen));
        ui->pushButtonQnx6Encender->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));
        connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Apagar()));

    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx5");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }

    /*if(error==true){

        MensajeOpciones *mensaje = new MensajeOpciones();
        connect(mensaje,SIGNAL(opcionCorrecta(int)),this,SLOT(slotOpcion(int)));
        mensaje->show();

    }
    */
}

void SistemaDatos::slotBabelEncender()
{
    num=rand()%semilla;
    QString imagen;
    error1=false;
    error2=false;
    error3=false;
    error4=false;
    error5=false;
    error6=false;

    if(num == 1){
        error1=true;
    }

    num=rand()%semilla;
    if(num == 1){

        error2=true;
    }

    num=rand()%semilla;
    if(num == 1){

        error3=true;
    }

    num=rand()%semilla;
    if(num == 1){

        error4=true;
    }

    num=rand()%semilla;
    if(num == 1){
        error5=true;
    }

    num=rand()%semilla;
    if(num == 1){

        error6=true;
    }

    //else{
    imagen = ":/images/adquisicionDatos/babelEncendidoqnx5okqnx6ok.png";
    //}
    if(Qnx6==true){
        babel = true;
        ui->labelQnx->setPixmap(QPixmap(imagen));
        ui->pushButtonBabel->setIcon(QIcon(":/images/iconEncender.png"));
        disconnect(ui->pushButtonBabel,SIGNAL(clicked()),this,SLOT(slotBabelEncender()));
        connect(ui->pushButtonBabel,SIGNAL(clicked()),this,SLOT(slotBabelApagar()));
        emit mostrarFondo(error1, error2, error3, error4, error5, error6);
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx6");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }

    /*if(error==true){

        MensajeOpciones *mensaje = new MensajeOpciones();
        connect(mensaje,SIGNAL(opcionCorrecta(int)),this,SLOT(slotOpcion(int)));
        mensaje->show();

    }*/

}

void SistemaDatos::slotQnx1Apagar()
{

    if(qnx2 == false){
        setQnx1(false);
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx1ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/sistemaDatos.png"));
        ui->pushButtonQnx1Encender->setIcon(QIcon(":/images/iconApagar.png"));
        disconnect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Apagar()));
        connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\napagar primero Qnx2");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx2Apagar()
{

    if(qnx3 == false){
        setQnx2(false);
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx2qnx3qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx1Encendida.png"));
        ui->pushButtonQnx2Encender->setIcon(QIcon(":/images/iconApagar.png"));
        disconnect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Apagar()));
        connect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Encender()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\napagar primero Qnx3");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx3Apagar()
{

    if(qnx4 == false){
        setQnx3(false);
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx3qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx2Encendida.png"));
        ui->pushButtonQnx3Encender->setIcon(QIcon(":/images/iconApagar.png"));
        disconnect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Apagar()));
        connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\napagar primero Qnx4");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx4Apagar()
{

    if(Qnx5 == false){
        setQnx4(false);
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx4Apagadaqnx5Apagadaqnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx3Encendida.png"));
        ui->pushButtonQnx4Encender->setIcon(QIcon(":/images/iconApagar.png"));
        disconnect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Apagar()));
        connect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Encender()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\napagar primero Qnx5");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx5Apagar()
{

    if(Qnx6 == false){
        setQnx5(false);
        if(babel == true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx5qnx6ApagadaBabelEncendida.png"));
        else
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx4Encendida.png"));

        ui->pushButtonQnx5Encender->setIcon(QIcon(":/images/iconApagar.png"));
        disconnect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Apagar()));
        connect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Encender()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\napagar primero Qnx6");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx6Apagar()
{
    setQnx6(false);
    if(babel == true)
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx6ApagadaBabelEncendida.png"));
    else
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx6Apagadaqnx3Encendidaqnx4Encendida.png"));
    ui->pushButtonQnx6Encender->setIcon(QIcon(":/images/iconApagar.png"));
    disconnect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Apagar()));
    connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));
}

void SistemaDatos::slotBabelApagar()
{
    if(Qnx5 == true)
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx5Encendidaqnx1okqnx2ok.png"));
    if(Qnx6 == true)
        ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx6Encendidoqnx3okqnx4ok.png"));

    ui->pushButtonBabel->setIcon(QIcon(":/images/iconApagar.png"));
    disconnect(ui->pushButtonBabel,SIGNAL(clicked()),this,SLOT(slotBabelApagar()));
    connect(ui->pushButtonBabel,SIGNAL(clicked()),this,SLOT(slotBabelEncender()));
    babel = false;
    emit ocultarFondo();
}

void SistemaDatos::slotOpcion(int item)
{
    if(item == 0){
        QMessageBox msg;
        msg.critical(this,"Error","Opcion Incorrecta.\nEl sistema de datos se reiniciara\nDebe elegir la opcion correcta");
        reinicarSistema();
    }

    else{
        QMessageBox msg;
        msg.information(this,"Correcto","Ha elegido la opcion correcta");
        if(Qnx5==true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx5Encendidaqnx1okqnx2ok.png"));
        if(Qnx6==true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/qnx6Encendidoqnx3okqnx4ok.png"));
        if(babel==true)
            ui->labelQnx->setPixmap(QPixmap(":/images/adquisicionDatos/babelEncendidoqnx5okqnx6ok.png"));
    }
}
