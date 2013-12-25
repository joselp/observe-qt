#include "headers/controlschmitd/summary.h"
#include "ui_summary.h"

Summary::Summary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Summary)
{
    ui->setupUi(this);

    //Inicio una consola
    bash = new QProcess(this);
    bash->setWorkingDirectory("../observe-qt/observaciones");
    qDebug()<<bash->workingDirectory()<<" este es el directorio"<<endl;

    connect(ui->pushButtonEjecutar,SIGNAL(clicked()),this,SLOT(slotEjecutar()));
}

Summary::~Summary()
{
    delete ui;
}

void Summary::slotEjecutar()
{
    bash->start("bash");

    if(!bash->waitForStarted()){
        QMessageBox::critical(this,"ERROR","ERROR: bash no responde");

    }

    ui->textEdit->setText("");
    ui->textEdit->setText("Espere por favor....\nCalculando....\n");

    comando.append("du -s -k images1 images2 images3 images4");
    bash->write((const char *)comando.toStdString().c_str());
    comando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    if(bash->exitCode()!=0){
        //qDebug()<< bash.readAllStandardError();

        qDebug()<< bash->readAllStandardError();
    }
    else{

        QString salida; //Mensaje de error que lanza el sistema
        salida.append(bash->readAllStandardOutput().data()); //Obtengo el mensaje del proceso
        ui->textEdit->setText(ui->textEdit->toPlainText()+salida);

    }

    bash->close();
}
