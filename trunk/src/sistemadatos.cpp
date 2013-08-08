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

    //Todas las computadoras inician apagadas

    qnx1=false;
    qnx2=false;
    qnx3=false;
    qnx4=false;
    Qnx5=false;
    Qnx6=false;
    ui->pushButtonQnx1Apagar->setDisabled(true);
    ui->pushButtonQnx2Apagar->setDisabled(true);
    ui->pushButtonQnx3Apagar->setDisabled(true);
    ui->pushButtonQnx4Apagar->setDisabled(true);
    ui->pushButtonQnx5Apagar->setDisabled(true);
    ui->pushButtonQnx6Apagar->setDisabled(true);


    //Conecto todos los botones

    connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    connect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Encender()));
    connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
    connect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Encender()));
    connect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Encender()));
    connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));

    connect(ui->pushButtonQnx1Apagar,SIGNAL(clicked()),this,SLOT(slotQnx1Apagar()));
    connect(ui->pushButtonQnx2Apagar,SIGNAL(clicked()),this,SLOT(slotQnx2Apagar()));
    connect(ui->pushButtonQnx3Apagar,SIGNAL(clicked()),this,SLOT(slotQnx3Apagar()));
    connect(ui->pushButtonQnx4Apagar,SIGNAL(clicked()),this,SLOT(slotQnx4Apagar()));
    connect(ui->pushButtonQnx5Apagar,SIGNAL(clicked()),this,SLOT(slotQnx5Apagar()));
    connect(ui->pushButtonQnx6Apagar,SIGNAL(clicked()),this,SLOT(slotQnx6Apagar()));
}

void SistemaDatos::closeEvent(QCloseEvent *)
{
    this->hide();
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

void SistemaDatos::setFormSimulador(FormSimulador *f)
{
    formSimulador = new FormSimulador;
    formSimulador = f;
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

void SistemaDatos::slotQnx1Encender()
{
    qnx1=true;

    ui->pushButtonQnx1Encender->setDisabled(true);
    ui->pushButtonQnx1Apagar->setDisabled(false);
    ui->labelQnx->setPixmap(QPixmap(":/images/qnxEncendida.png"));
}

void SistemaDatos::slotQnx2Encender()
{
    if(qnx1==true){
        qnx2=true;
        ui->pushButtonQnx2Encender->setDisabled(true);
        ui->pushButtonQnx2Apagar->setDisabled(false);
        ui->labelQnx_2->setPixmap(QPixmap(":/images/qnxEncendida.png"));
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
        ui->pushButtonQnx3Encender->setDisabled(true);
        ui->pushButtonQnx3Apagar->setDisabled(false);
        ui->labelQnx_3->setPixmap(QPixmap(":/images/qnxEncendida.png"));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx2");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx4Encender()
{
    if(qnx3==true){
        qnx4=true;
        ui->pushButtonQnx4Encender->setDisabled(true);
        ui->pushButtonQnx4Apagar->setDisabled(false);
        ui->labelQnx_4->setPixmap(QPixmap(":/images/qnxEncendida.png"));
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

    if(qnx4==true){
        Qnx5=true;
        ui->pushButtonQnx5Encender->setDisabled(true);
        ui->pushButtonQnx5Apagar->setDisabled(false);
        ui->labelPc_5->setPixmap(QPixmap(":/images/pcEncendida.png"));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx4");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx6Encender()
{
    if(Qnx5==true){
        Qnx6=true;
        ui->pushButtonQnx6Encender->setDisabled(true);
        ui->pushButtonQnx6Apagar->setDisabled(false);
        ui->labelPc_6->setPixmap(QPixmap(":/images/pcEncendida.png"));
        //Esto debe ir al encender BABEL
        formSimulador->asignarFondo(true);
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero Qnx5");
        msg.setWindowTitle("ADVERTENCIA");
        msg.setIconPixmap(QPixmap(":/images/warning.png"));
        msg.exec();
    }
}

void SistemaDatos::slotQnx1Apagar()
{
    setQnx1(false);
    ui->pushButtonQnx1Encender->setDisabled(false);
    ui->pushButtonQnx1Apagar->setDisabled(true);
    ui->labelQnx->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx2Apagar()
{
    setQnx2(false);
    ui->pushButtonQnx2Encender->setDisabled(false);
    ui->pushButtonQnx2Apagar->setDisabled(true);
    ui->labelQnx_2->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx3Apagar()
{
    setQnx3(false);
    ui->pushButtonQnx3Encender->setDisabled(false);
    ui->pushButtonQnx3Apagar->setDisabled(true);
    ui->labelQnx_3->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx4Apagar()
{
    setQnx4(false);
    ui->pushButtonQnx4Encender->setDisabled(false);
    ui->pushButtonQnx4Apagar->setDisabled(true);
    ui->labelQnx_4->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx5Apagar()
{
    setQnx4(false);
    ui->pushButtonQnx5Encender->setDisabled(false);
    ui->pushButtonQnx5Apagar->setDisabled(true);
    ui->labelPc_5->setPixmap(QPixmap(":/images/pc.png"));
}

void SistemaDatos::slotQnx6Apagar()
{
    setQnx6(false);
    ui->pushButtonQnx6Encender->setDisabled(false);
    ui->pushButtonQnx6Apagar->setDisabled(true);
    ui->labelPc_6->setPixmap(QPixmap(":/images/pc.png"));
}
