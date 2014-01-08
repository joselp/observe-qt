#include "headers/cargas/reporte.h"
#include "ui_reporte.h"

Reporte::Reporte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reporte)
{
    ui->setupUi(this);
    this->setWindowTitle("Reporte");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(slotEnviar()));
}

void Reporte::setIdPrueba(int i)
{
    idPrueba = i;
}

void Reporte::setIdPersona(int i)
{
    idPersona=i;
}

Reporte::~Reporte()
{
    delete ui;
}

void Reporte::slotEnviar()
{
    QString sql = "INSERT INTO reporte (prueba_id, persona_id, reporte) VALUES ('"+QString::number(idPrueba)+"','"+QString::number(idPersona)+"','"+ui->textEdit->toPlainText()+"')";
    QString sql2 = "DELETE FROM prueba_persona WHERE id_prueba='"+QString::number(idPrueba)+"'";
    QSqlQuery query;
    QSqlQuery query2;

    if(query.exec(sql) && query2.exec(sql2)){
        QMessageBox msg;
        msg.about(this,"Reporte Enviado","El reporte ha sido enviado\na los investigadores");
        this->close();
    }
    else{
        QMessageBox msg;
        msg.warning(this,"Error","Ha ocurrido un error al enviar el reporte");
    }

}
