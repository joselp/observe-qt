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

    //Estilo de los botones encender
    ui->pushButtonQnx1Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    ui->pushButtonQnx2Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    ui->pushButtonQnx3Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    ui->pushButtonQnx4Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    ui->pushButtonQnx5Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    ui->pushButtonQnx6Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconApagar.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");

    //ui->pushButtonQnx1Encender->setStyleSheet("background: url(:/images/iconEncender.png) no-repeat;");
    //Todas las computadoras inician apagadas

    qnx1=false;
    qnx2=false;
    qnx3=false;
    qnx4=false;
    Qnx5=false;
    Qnx6=false;

    //Conecto todos los botones

    connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    connect(ui->pushButtonQnx2Encender,SIGNAL(clicked()),this,SLOT(slotQnx2Encender()));
    connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
    connect(ui->pushButtonQnx4Encender,SIGNAL(clicked()),this,SLOT(slotQnx4Encender()));
    connect(ui->pushButtonQnx5Encender,SIGNAL(clicked()),this,SLOT(slotQnx5Encender()));
    connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));

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
    ui->labelQnx->setPixmap(QPixmap(":/images/qnx1Encendida.jpg"));
    ui->pushButtonQnx1Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
    disconnect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Encender()));
    connect(ui->pushButtonQnx1Encender,SIGNAL(clicked()),this,SLOT(slotQnx1Apagar()));
}

void SistemaDatos::slotQnx2Encender()
{
    if(qnx1==true){
        qnx2=true;
        ui->pushButtonQnx2Encender->setDisabled(true);
        ui->labelQnx->setPixmap(QPixmap(":/images/qnx2Encendida.jpg"));
        ui->pushButtonQnx2Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
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
        ui->pushButtonQnx3Encender->setDisabled(true);
        ui->labelQnx->setPixmap(QPixmap(":/images/qnx3Encendida.jpg"));
        ui->pushButtonQnx3Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
        disconnect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Encender()));
        connect(ui->pushButtonQnx3Encender,SIGNAL(clicked()),this,SLOT(slotQnx3Apagar()));
    }
    else{
        QMessageBox msg;
        msg.setText("El protocolo indica que debe\nencerder primero jpg");
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
        ui->labelQnx->setPixmap(QPixmap(":/images/qnx4Encendida.jpg"));
        ui->pushButtonQnx4Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
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

    if(qnx4==true){
        Qnx5=true;
        ui->pushButtonQnx5Encender->setDisabled(true);
        ui->labelQnx5->setPixmap(QPixmap(":/images/qnx5Encendida.jpg"));
        ui->pushButtonQnx5Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
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
}

void SistemaDatos::slotQnx6Encender()
{
    if(Qnx5==true){
        Qnx6=true;
        ui->pushButtonQnx6Encender->setDisabled(true);
        ui->labelQnx6->setPixmap(QPixmap(":/images/qnx6Encendida.jpg"));
        ui->pushButtonQnx6Encender->setStyleSheet("QPushButton{background-image:url(':/images/iconEncender.png'); border-style: inset;border-width: 0px;border-radius: 0px;border-color: beige;border-color: rgb(217, 217, 217);font: bold 10px; text-align:left} QPushButton:pressed {background-color:blue; border-style: inset;}");
        disconnect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Encender()));
        connect(ui->pushButtonQnx6Encender,SIGNAL(clicked()),this,SLOT(slotQnx6Apagar()));
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

    ui->labelQnx->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx2Apagar()
{
    setQnx2(false);

    //ui->labelQnx_2->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx3Apagar()
{
    setQnx3(false);

    //ui->labelQnx_3->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx4Apagar()
{
    setQnx4(false);

    //ui->labelQnx_4->setPixmap(QPixmap(":/images/qnx.png"));
}

void SistemaDatos::slotQnx5Apagar()
{
    setQnx4(false);

    //ui->labelPc_5->setPixmap(QPixmap(":/images/pc.png"));
}

void SistemaDatos::slotQnx6Apagar()
{
    setQnx6(false);

    //ui->labelPc_6->setPixmap(QPixmap(":/images/pc.png"));
}
