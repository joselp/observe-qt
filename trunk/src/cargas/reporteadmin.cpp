#include "headers/cargas/reporteadmin.h"
#include "ui_reporteadmin.h"

ReporteAdmin::ReporteAdmin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReporteAdmin)
{
    ui->setupUi(this);
    this->setWindowTitle("Reporte");
    ui->textEditDesarrollo->setEnabled(false);
    ui->textEditNombrePrueba->setEnabled(false);
    ui->textEditProyecto->setEnabled(false);
    ui->checkBoxConexion->setEnabled(false);
    ui->checkBoxDedos->setEnabled(false);
    ui->checkBoxFoco->setEnabled(false);
    ui->checkBoxObturador->setEnabled(false);
    ui->checkBoxPrisma->setEnabled(false);

    connect(ui->pushButtonCerrar,SIGNAL(clicked()),this,SLOT(slotCerrar()));
    connect(ui->pushButtonEliminar,SIGNAL(clicked()),this,SLOT(slotEliminar()));
}

void ReporteAdmin::asignarDatos(QSqlQuery query)
{

    ui->lineEditCondiciones->setText(query.value(5).toString());

    if(query.value(6).toString() == "true")
        ui->checkBoxDedos->setChecked(true);
    if(query.value(7).toString() == "true")
        ui->checkBoxFoco->setChecked(true);
    if(query.value(8).toString() == "cerrado")
        ui->checkBoxObturador->setChecked(true);
    if(query.value(9).toString() == "true")
        ui->checkBoxPrisma->setChecked(true);
    if(query.value(10).toString() == "true")
        ui->checkBoxConexion->setChecked(true);

    ui->textEditNombrePrueba->setText(query.value(12).toString());
    ui->lineEditFiltro1->setText(query.value(14).toString());
    ui->lineEditFiltro2->setText(query.value(15).toString());
    ui->lineEditFiltro3->setText(query.value(16).toString());
    ui->lineEditFiltro4->setText(query.value(17).toString());
    ui->lineEditDeclinacion->setText(query.value(18).toString());
    ui->lineEditAnguloHorario->setText(query.value(19).toString());
    ui->lineEditTipoObservacion->setText(query.value(20).toString());
    ui->lineEditDuracion->setText(query.value(21).toString());
    ui->textEditProyecto->setText(query.value(22).toString());
    ui->lineEditInstrumento->setText(query.value(23).toString());
    ui->textEditDesarrollo->setText(query.value(1).toString());

    idPrueba = query.value(2).toInt();

}

ReporteAdmin::~ReporteAdmin()
{
    delete ui;
}

void ReporteAdmin::slotCerrar()
{
    this->close();
}

void ReporteAdmin::slotEliminar()
{
    QString sql = "DELETE FROM reporte WHERE prueba_id='"+QString::number(idPrueba)+"'";
    QSqlQuery query;

    if(query.exec(sql)){
        QMessageBox msg;
        msg.about(this,"Reporte Eliminado","El reporte ha sido eliminado");
        this->close();
    }
    else{
        QMessageBox msg;
        msg.warning(this,"Error","Ha ocurrido un error al eliminar el reporte");
    }


}
