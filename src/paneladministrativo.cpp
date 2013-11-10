#include "headers/paneladministrativo.h"
#include "ui_paneladministrativo.h"
#include <QDebug>

PanelAdministrativo::PanelAdministrativo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PanelAdministrativo)
{
    ui->setupUi(this);
    initGui();
}

void PanelAdministrativo::initGui()
{
    this->setWindowTitle("Crear Prueba");
    cargarPrueba = new CargarPrueba;
    ui->tabWidget->setCurrentIndex(0);

    QStringList filtros;
    filtros << "Yale Johnson U1" << "Yale Johnson U2" << "Yale Johnson B1" << "Yale Johnson B2"
            << "Yale Johnson V1" << "Yale Johnson V2" << "Yale Johnson V3" << "Yale Johnson V4"
            << "Yale Johnson R1" << "Yale Johnson R2" << "Yale Johnson R3" << "Yale Alfa"
            << "Yale l1" << "Yale Johnson l2" << "CLR" << "Yale Hot Mirror" << "UCM Halfa"
            << "Yale Blue Prims 1" << "Yale Blue Prims 2" << "Yale Red Prims 1" << "Yale Red Prims 1";
    ui->comboBoxFiltro1->addItems(filtros);
    ui->comboBoxFiltro2->addItems(filtros);
    ui->comboBoxFiltro3->addItems(filtros);
    ui->comboBoxFiltro4->addItems(filtros);

    ui->comboBoxInstrumento->addItem("YIC");
    ui->comboBoxInstrumento->addItem("YIC+Prims");

    QSqlQuery query;
    query.exec("SELECT id,nombre,apellido,email FROM persona WHERE tipo='Estudiante'");

    while (query.next()) {
        ui->comboBoxUsuario->addItem(query.value(3).toString()+" "+"Nombre: "+query.value(1).toString() +" "+ query.value(2).toString());
    }

    connect(ui->pushButtonCargarPrueba,SIGNAL(clicked()),this,SLOT(slotCargarPrueba()));
    connect(ui->pushButtonAceptar,SIGNAL(clicked()),this,SLOT(slotAceptar()));
    connect(ui->pushButtonLimpiar,SIGNAL(clicked()),this,SLOT(slotLimpiar()));

}

PanelAdministrativo::~PanelAdministrativo()
{
    delete ui;
}

void PanelAdministrativo::slotCargarPrueba()
{
    connect(cargarPrueba,SIGNAL(enviarDatos(QSqlQuery,QSqlQuery)),this,SLOT(slotAsignarDatos(QSqlQuery,QSqlQuery)));
    cargarPrueba->show();

}

void PanelAdministrativo::slotAsignarDatos(QSqlQuery query, QSqlQuery query2)
{
    idPrueba=query.value(0).toString();
    desactivarCampos();
    if(query.value(1).toString()=="normales")
        ui->NormalesCheckBox->setChecked(true);
    else if (query.value(1).toString()=="viento")
        ui->NormalesCheckBox->setChecked(false);
    else if (query.value(1).toString()=="nublado")
        ui->NormalesCheckBox->setChecked(false);

    if(query.value(2).toBool()==true)
        ui->checkBoxDedos->setChecked(true);

    if(query.value(3).toBool()==true)
        ui->checkBoxFoco->setChecked(true);

    if(query.value(4).toString()=="abierto")
        ui->checkBoxObturador->setChecked(true);

    if(query.value(5).toBool()==true)
        ui->checkBoxPrisma->setChecked(true);

    if(query.value(6).toBool()==true)
        ui->checkBoxConexion->setChecked(true);

    ui->textEditNombrePrueba->setText(query.value(8).toString());

    //Combo filtro 1
    if(query2.value(1)=="Yale Johnson U1")
        ui->comboBoxFiltro1->setCurrentIndex(0);
    if(query2.value(1)=="Yale Johnson U2")
        ui->comboBoxFiltro1->setCurrentIndex(1);
    if(query2.value(1)=="Yale Johnson B1")
        ui->comboBoxFiltro1->setCurrentIndex(2);
    if(query2.value(1)=="Yale Johnson B2")
        ui->comboBoxFiltro1->setCurrentIndex(3);
    if(query2.value(1)=="Yale Johnson V1")
        ui->comboBoxFiltro1->setCurrentIndex(4);
    if(query2.value(1)=="Yale Johnson V2")
        ui->comboBoxFiltro1->setCurrentIndex(5);
    if(query2.value(1)=="Yale Johnson V3")
        ui->comboBoxFiltro1->setCurrentIndex(6);
    if(query2.value(1)=="Yale Johnson V4")
        ui->comboBoxFiltro1->setCurrentIndex(7);
    if(query2.value(1)=="Yale Johnson R1")
        ui->comboBoxFiltro1->setCurrentIndex(8);
    if(query2.value(1)=="Yale Johnson R2")
        ui->comboBoxFiltro1->setCurrentIndex(9);
    if(query2.value(1)=="Yale Johnson R3")
        ui->comboBoxFiltro1->setCurrentIndex(10);
    if(query2.value(1)=="Yale Alfa")
        ui->comboBoxFiltro1->setCurrentIndex(11);
    if(query2.value(1)=="Yale l1")
        ui->comboBoxFiltro1->setCurrentIndex(12);
    if(query2.value(1)=="Yale l2")
        ui->comboBoxFiltro1->setCurrentIndex(13);
    if(query2.value(1)=="CLR")
        ui->comboBoxFiltro1->setCurrentIndex(14);
    if(query2.value(1)=="Yale Hot Mirror")
        ui->comboBoxFiltro1->setCurrentIndex(15);
    if(query2.value(1)=="UCM Halfa")
        ui->comboBoxFiltro1->setCurrentIndex(16);
    if(query2.value(1)=="Yale Blue Prims 1")
        ui->comboBoxFiltro1->setCurrentIndex(17);
    if(query2.value(1)=="Yale Blue Prims 2")
        ui->comboBoxFiltro1->setCurrentIndex(18);
    if(query2.value(1)=="Yale Red Prims 1")
        ui->comboBoxFiltro1->setCurrentIndex(19);
    if(query2.value(1)=="Yale Red Prims 2")
        ui->comboBoxFiltro1->setCurrentIndex(20);

    //Combo filtro 2
    if(query2.value(2)=="Yale Johnson U1")
        ui->comboBoxFiltro2->setCurrentIndex(0);
    if(query2.value(2)=="Yale Johnson U2")
        ui->comboBoxFiltro2->setCurrentIndex(1);
    if(query2.value(2)=="Yale Johnson B1")
        ui->comboBoxFiltro2->setCurrentIndex(2);
    if(query2.value(2)=="Yale Johnson B2")
        ui->comboBoxFiltro2->setCurrentIndex(3);
    if(query2.value(2)=="Yale Johnson V1")
        ui->comboBoxFiltro2->setCurrentIndex(4);
    if(query2.value(2)=="Yale Johnson V2")
        ui->comboBoxFiltro2->setCurrentIndex(5);
    if(query2.value(2)=="Yale Johnson V3")
        ui->comboBoxFiltro2->setCurrentIndex(6);
    if(query2.value(2)=="Yale Johnson V4")
        ui->comboBoxFiltro2->setCurrentIndex(7);
    if(query2.value(2)=="Yale Johnson R1")
        ui->comboBoxFiltro2->setCurrentIndex(8);
    if(query2.value(2)=="Yale Johnson R2")
        ui->comboBoxFiltro2->setCurrentIndex(9);
    if(query2.value(2)=="Yale Johnson R3")
        ui->comboBoxFiltro2->setCurrentIndex(10);
    if(query2.value(2)=="Yale Alfa")
        ui->comboBoxFiltro2->setCurrentIndex(11);
    if(query2.value(2)=="Yale l1")
        ui->comboBoxFiltro2->setCurrentIndex(12);
    if(query2.value(2)=="Yale l2")
        ui->comboBoxFiltro2->setCurrentIndex(13);
    if(query2.value(2)=="CLR")
        ui->comboBoxFiltro2->setCurrentIndex(14);
    if(query2.value(2)=="Yale Hot Mirror")
        ui->comboBoxFiltro2->setCurrentIndex(15);
    if(query2.value(2)=="UCM Halfa")
        ui->comboBoxFiltro2->setCurrentIndex(16);
    if(query2.value(2)=="Yale Blue Prims 1")
        ui->comboBoxFiltro2->setCurrentIndex(17);
    if(query2.value(2)=="Yale Blue Prims 2")
        ui->comboBoxFiltro2->setCurrentIndex(18);
    if(query2.value(2)=="Yale Red Prims 1")
        ui->comboBoxFiltro2->setCurrentIndex(19);
    if(query2.value(2)=="Yale Red Prims 2")
        ui->comboBoxFiltro2->setCurrentIndex(20);

    //Combo filtro 3
    if(query2.value(3)=="Yale Johnson U1")
        ui->comboBoxFiltro3->setCurrentIndex(0);
    if(query2.value(3)=="Yale Johnson U2")
        ui->comboBoxFiltro3->setCurrentIndex(1);
    if(query2.value(3)=="Yale Johnson B1")
        ui->comboBoxFiltro3->setCurrentIndex(2);
    if(query2.value(3)=="Yale Johnson B2")
        ui->comboBoxFiltro3->setCurrentIndex(3);
    if(query2.value(3)=="Yale Johnson V1")
        ui->comboBoxFiltro3->setCurrentIndex(4);
    if(query2.value(3)=="Yale Johnson V2")
        ui->comboBoxFiltro3->setCurrentIndex(5);
    if(query2.value(3)=="Yale Johnson V3")
        ui->comboBoxFiltro3->setCurrentIndex(6);
    if(query2.value(3)=="Yale Johnson V4")
        ui->comboBoxFiltro3->setCurrentIndex(7);
    if(query2.value(3)=="Yale Johnson R1")
        ui->comboBoxFiltro3->setCurrentIndex(8);
    if(query2.value(3)=="Yale Johnson R2")
        ui->comboBoxFiltro3->setCurrentIndex(9);
    if(query2.value(3)=="Yale Johnson R3")
        ui->comboBoxFiltro3->setCurrentIndex(10);
    if(query2.value(3)=="Yale Alfa")
        ui->comboBoxFiltro3->setCurrentIndex(11);
    if(query2.value(3)=="Yale l1")
        ui->comboBoxFiltro3->setCurrentIndex(12);
    if(query2.value(3)=="Yale l2")
        ui->comboBoxFiltro3->setCurrentIndex(13);
    if(query2.value(3)=="CLR")
        ui->comboBoxFiltro3->setCurrentIndex(14);
    if(query2.value(3)=="Yale Hot Mirror")
        ui->comboBoxFiltro3->setCurrentIndex(15);
    if(query2.value(3)=="UCM Halfa")
        ui->comboBoxFiltro3->setCurrentIndex(16);
    if(query2.value(3)=="Yale Blue Prims 1")
        ui->comboBoxFiltro3->setCurrentIndex(17);
    if(query2.value(3)=="Yale Blue Prims 2")
        ui->comboBoxFiltro3->setCurrentIndex(18);
    if(query2.value(3)=="Yale Red Prims 1")
        ui->comboBoxFiltro3->setCurrentIndex(19);
    if(query2.value(3)=="Yale Red Prims 2")
        ui->comboBoxFiltro3->setCurrentIndex(20);

    //Combo filtro 4
    if(query2.value(4)=="Yale Johnson U1")
        ui->comboBoxFiltro4->setCurrentIndex(0);
    if(query2.value(4)=="Yale Johnson U2")
        ui->comboBoxFiltro4->setCurrentIndex(1);
    if(query2.value(4)=="Yale Johnson B1")
        ui->comboBoxFiltro4->setCurrentIndex(2);
    if(query2.value(4)=="Yale Johnson B2")
        ui->comboBoxFiltro4->setCurrentIndex(3);
    if(query2.value(4)=="Yale Johnson V1")
        ui->comboBoxFiltro4->setCurrentIndex(4);
    if(query2.value(4)=="Yale Johnson V2")
        ui->comboBoxFiltro4->setCurrentIndex(5);
    if(query2.value(4)=="Yale Johnson V3")
        ui->comboBoxFiltro4->setCurrentIndex(6);
    if(query2.value(4)=="Yale Johnson V4")
        ui->comboBoxFiltro4->setCurrentIndex(7);
    if(query2.value(4)=="Yale Johnson R1")
        ui->comboBoxFiltro4->setCurrentIndex(8);
    if(query2.value(4)=="Yale Johnson R2")
        ui->comboBoxFiltro1->setCurrentIndex(9);
    if(query2.value(4)=="Yale Johnson R3")
        ui->comboBoxFiltro4->setCurrentIndex(10);
    if(query2.value(4)=="Yale Alfa")
        ui->comboBoxFiltro4->setCurrentIndex(11);
    if(query2.value(4)=="Yale l1")
        ui->comboBoxFiltro4->setCurrentIndex(12);
    if(query2.value(4)=="Yale l2")
        ui->comboBoxFiltro1->setCurrentIndex(13);
    if(query2.value(4)=="CLR")
        ui->comboBoxFiltro4->setCurrentIndex(14);
    if(query2.value(4)=="Yale Hot Mirror")
        ui->comboBoxFiltro4->setCurrentIndex(15);
    if(query2.value(4)=="UCM Halfa")
        ui->comboBoxFiltro4->setCurrentIndex(16);
    if(query2.value(4)=="Yale Blue Prims 1")
        ui->comboBoxFiltro4->setCurrentIndex(17);
    if(query2.value(4)=="Yale Blue Prims 2")
        ui->comboBoxFiltro4->setCurrentIndex(18);
    if(query2.value(4)=="Yale Red Prims 1")
        ui->comboBoxFiltro4->setCurrentIndex(19);
    if(query2.value(4)=="Yale Red Prims 2")
        ui->comboBoxFiltro4->setCurrentIndex(20);

    ui->lineEditDeclinacion->setText(query2.value(5).toString());
    ui->lineEditAnguloHorario->setText(query2.value(6).toString());
    ui->lineEditTipoObservacion->setText(query2.value(7).toString());
    ui->lineEditDuracion->setText(query2.value(8).toString());

    if(query2.value(10)=="YIC")
        ui->comboBoxInstrumento->setCurrentIndex(0);
    if(query2.value(10)=="YIC+Prims")
        ui->comboBoxInstrumento->setCurrentIndex(1);

    ui->textEditProyecto->setText(query2.value(9).toString());
}

void PanelAdministrativo::slotAceptar()
{
    bool insertar = true;

    if(!ui->NormalesCheckBox->isChecked() && !ui->muchoVientoCheckBox->isChecked() && !ui->nubladoCheckBox->isChecked()){
        QMessageBox msg;
        msg.warning(this,"Ingrese los datos","Ingrese al menos un tipo de imagenes");
        insertar=false;
    }

    if(ui->textEditNombrePrueba->toPlainText()==""){
        QMessageBox msg;
        msg.warning(this,"Ingrese los datos","Ingrese el nombre de esta prueba");
        insertar=false;
    }

    if(ui->lineEditDeclinacion->text()=="" && ui->lineEditAnguloHorario->text()=="" && ui->lineEditDuracion->text()==""
            && ui->lineEditTipoObservacion->text()==""){
        QMessageBox msg;
        msg.warning(this,"Ingrese los datos","Asegurese de haber insertado los siguientes datos:\nDeclinacion.\nAngulo Horario.\nDuracion.\nTipo de Observacion.");
        insertar=false;
    }

    if(pruebaNueva==true){
        if(insertar==true){
            QSqlQuery query;
            if(query.exec("INSERT INTO protocolo (filtro_1, filtro_2, filtro_3, filtro_4, declinacion, angulo_horario, tipo_observacion, duracion, nombre_proyecto, instrumento) VALUES ('"+ui->comboBoxFiltro1->currentText()+"','"+ui->comboBoxFiltro2->currentText()+"','"+ui->comboBoxFiltro3->currentText()+"','"+ui->comboBoxFiltro4->currentText()+"','"+ui->lineEditDeclinacion->text()+"','"+ui->lineEditAnguloHorario->text()+"','"+ui->lineEditTipoObservacion->text()+"','"+ui->lineEditDuracion->text()+"','"+ui->textEditProyecto->toPlainText()+"','"+ui->comboBoxInstrumento->currentText()+"')")){
                QString dedos="false",foco="false", prisma="false",conexion="false";
                QString cielo, obturador="cerrado";

                if(ui->checkBoxDedos->isChecked())
                    dedos="true";
                if(ui->checkBoxObturador->isChecked())
                    obturador="abierto";
                if(ui->checkBoxPrisma->isChecked())
                    prisma="true";
                if(ui->checkBoxConexion->isChecked())
                    conexion="true";
                if(ui->NormalesCheckBox->isChecked())
                    cielo = "normales";
                if(ui->nubladoCheckBox->isChecked())
                    cielo = "nublado";
                if(ui->muchoVientoCheckBox->isChecked())
                    cielo = "viento";

                QSqlQuery query2;

                QSqlQuery query3;

                query3.exec("SELECT MAX(id) FROM protocolo;");
                query3.next();
                query2.exec("INSERT INTO prueba (condicion_cielo, mala_posicion_dedos, mal_foco, obturador, prisma, falla_conexion, protocolo_id, nombre) VALUES ('"+cielo+"',"+dedos+","+foco+",'"+obturador+"',"+prisma+","+conexion+","+query3.value(0).toString()+",'"+ui->textEditNombrePrueba->toPlainText()+"')");

                QSqlQuery query6;
                query6.exec("SELECT MAX(id) FROM prueba;");
                query6.next();

                QSqlQuery query5;
                QStringList email = ui->comboBoxUsuario->currentText().split(" ");
                query5.exec("SELECT id FROM persona WHERE email='"+email.value(0)+"'");
                query5.next();

                query2.exec("INSERT INTO prueba_persona (id_prueba, id_persona) values("+query6.value(0).toString()+","+query5.value(0).toString()+")");

                QMessageBox msg;
                msg.information(this,"Exito","La prueba se ha asignado");
                this->hide();
                slotLimpiar();
            }

        }
    }
    else if(pruebaNueva==false){
        QStringList email = ui->comboBoxUsuario->currentText().split(" ");
        QSqlQuery query;
        query.exec("SELECT id FROM persona WHERE email='"+email.value(0)+"'");
        query.next();

        QSqlQuery query2;
        query2.exec("INSERT INTO prueba_persona (id_prueba, id_persona) values("+idPrueba+","+query.value(0).toString()+")");

        QMessageBox msg;
        msg.information(this,"Exito","La prueba se ha asignado");
        this->hide();
        slotLimpiar();
    }

}

void PanelAdministrativo::slotLimpiar()
{
    ui->NormalesCheckBox->setEnabled(true);
    ui->muchoVientoCheckBox->setEnabled(true);
    ui->nubladoCheckBox->setEnabled(true);
    ui->checkBoxDedos->setEnabled(true);
    ui->checkBoxFoco->setEnabled(true);
    ui->checkBoxObturador->setEnabled(true);
    ui->checkBoxPrisma->setEnabled(true);
    ui->checkBoxConexion->setEnabled(true);
    ui->textEditNombrePrueba->setEnabled(true);

    ui->comboBoxFiltro1->setEnabled(true);
    ui->comboBoxFiltro2->setEnabled(true);
    ui->comboBoxFiltro3->setEnabled(true);
    ui->comboBoxFiltro4->setEnabled(true);
    ui->lineEditDeclinacion->setEnabled(true);
    ui->lineEditAnguloHorario->setEnabled(true);
    ui->lineEditDuracion->setEnabled(true);
    ui->lineEditTipoObservacion->setEnabled(true);
    ui->comboBoxInstrumento->setEnabled(true);
    ui->textEditProyecto->setEnabled(true);

    pruebaNueva = true;

    ui->NormalesCheckBox->setChecked(false);
    ui->muchoVientoCheckBox->setChecked(false);
    ui->nubladoCheckBox->setChecked(false);
    ui->checkBoxDedos->setChecked(false);
    ui->checkBoxFoco->setChecked(false);
    ui->checkBoxObturador->setChecked(false);
    ui->checkBoxPrisma->setChecked(false);
    ui->checkBoxConexion->setChecked(false);
    ui->textEditNombrePrueba->setText("");

    ui->comboBoxFiltro1->setCurrentIndex(0);
    ui->comboBoxFiltro2->setCurrentIndex(0);
    ui->comboBoxFiltro3->setCurrentIndex(0);
    ui->comboBoxFiltro4->setCurrentIndex(0);
    ui->lineEditDeclinacion->setText("");
    ui->lineEditAnguloHorario->setText("");
    ui->lineEditDuracion->setText("");
    ui->lineEditTipoObservacion->setText("");
    ui->comboBoxInstrumento->setCurrentIndex(0);
    ui->textEditProyecto->setText("");
}

void PanelAdministrativo::desactivarCampos()
{
    ui->NormalesCheckBox->setEnabled(false);
    ui->muchoVientoCheckBox->setEnabled(false);
    ui->nubladoCheckBox->setEnabled(false);
    ui->checkBoxDedos->setEnabled(false);
    ui->checkBoxFoco->setEnabled(false);
    ui->checkBoxObturador->setEnabled(false);
    ui->checkBoxPrisma->setEnabled(false);
    ui->checkBoxConexion->setEnabled(false);
    ui->textEditNombrePrueba->setEnabled(false);

    ui->comboBoxFiltro1->setEnabled(false);
    ui->comboBoxFiltro2->setEnabled(false);
    ui->comboBoxFiltro3->setEnabled(false);
    ui->comboBoxFiltro4->setEnabled(false);
    ui->lineEditDeclinacion->setEnabled(false);
    ui->lineEditAnguloHorario->setEnabled(false);
    ui->lineEditDuracion->setEnabled(false);
    ui->lineEditTipoObservacion->setEnabled(false);
    ui->comboBoxInstrumento->setEnabled(false);
    ui->textEditProyecto->setEnabled(false);

    pruebaNueva = false;
}

