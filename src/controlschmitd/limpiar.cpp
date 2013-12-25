#include "headers/controlschmitd/limpiar.h"
#include "ui_limpiar.h"

Limpiar::Limpiar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Limpiar)
{
    ui->setupUi(this);

    //Inicio una consola
    bash = new QProcess(this);
    bash->setWorkingDirectory("../observe-qt/observaciones");
    qDebug()<<bash->workingDirectory()<<" este es el directorio"<<endl;

    connect(ui->pushButtonEjecutar,SIGNAL(clicked()),this,SLOT(slotEjecutar()));
}

Limpiar::~Limpiar()
{
    delete ui;
}

void Limpiar::slotEjecutar()
{
    bash->start("bash");
    if(!bash->waitForStarted()){
        QMessageBox::critical(this,"ERROR","ERROR: bash no responde");

    }

    ui->textEdit->setText("");
    ui->textEdit->setText("Borrando datos de Qnx5\n");

    comando.append("rm images1/*.fits");
    bash->write((const char *)comando.toStdString().c_str());
    comando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    if(bash->exitCode()!=0){
        qDebug()<< bash->readAllStandardError();
    }

    bash->start("bash");
    comando.append("rm images2/*.fits");
    bash->write((const char *)comando.toStdString().c_str());
    comando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");
    }

    if(bash->exitCode()!=0){
        qDebug()<< bash->readAllStandardError();
    }

    else{
        ui->textEdit->setText(ui->textEdit->toPlainText()+"Borrando datos de Qnx6\n");
    }

    bash->start("bash");
    comando.append("rm images3/*.fits");
    bash->write((const char *)comando.toStdString().c_str());
    comando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");
    }

    if(bash->exitCode()!=0){
        qDebug()<< bash->readAllStandardError();
    }

    bash->start("bash");
    comando.append("rm images4/*.fits");
    bash->write((const char *)comando.toStdString().c_str());
    comando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    if(bash->exitCode()!=0){
        qDebug()<< bash->readAllStandardError();
    }
    else{
        ui->textEdit->setText(ui->textEdit->toPlainText()+"Limpieza Terminada\n");
    }

    bash->close();
}
