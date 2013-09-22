#include "headers/mensajeopciones.h"
#include "ui_mensajeopciones.h"

MensajeOpciones::MensajeOpciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MensajeOpciones)
{
    ui->setupUi(this);
    connect(ui->pushButtonAceptar,SIGNAL(clicked()),this,SLOT(slotAceptar()));
    cargarOpciones();
}

void MensajeOpciones::cargarOpciones()
{
    int num = rand()%4; //Numero aleatorio para elegir la opcion correta
    int num2 = rand()%4; //Numero aleatorio para elegir la opcion correta

    correctas << "Desconectar y conectar el cable de red" << "LLamar al tecnico" << "Reiniciar la computadora en conflicto y volver a sincronizar usando synch.sh" << "Reiniciar todo el sistema de adquisicion de datos";
    errores << "Reiniciar la computadora en conflicto y volver a sincronizar usando synch.pl" << "Dejarla la computadora sin conexion" << "No hacer nada" << "Otra opcion 1" << "No hacer nada 2";

    if(num == 0){
    ui->radioButtonOpcion1->setText(correctas.value(num2));
    ui->radioButtonOpcion2->setText(errores.value(0));
    ui->radioButtonOpcion3->setText(errores.value(1));
    ui->radioButtonOpcion4->setText(errores.value(2));
    }

    if(num == 1){
    ui->radioButtonOpcion2->setText(errores.value(4));
    ui->radioButtonOpcion1->setText(correctas.value(num2));
    ui->radioButtonOpcion3->setText(errores.value(2));
    ui->radioButtonOpcion4->setText(errores.value(3));
    }

    if(num == 2){
    ui->radioButtonOpcion1->setText(errores.value(1));
    ui->radioButtonOpcion2->setText(errores.value(0));
    ui->radioButtonOpcion3->setText(correctas.value(num2));
    ui->radioButtonOpcion4->setText(errores.value(2));
    }

    if(num == 3){
    ui->radioButtonOpcion1->setText(errores.value(3));
    ui->radioButtonOpcion2->setText(errores.value(0));
    ui->radioButtonOpcion3->setText(errores.value(1));
    ui->radioButtonOpcion4->setText(correctas.value(num2));
    }
}

void MensajeOpciones::slotAceptar()
{
    bool entrar = true;

    if( ui->radioButtonOpcion1->isChecked() && (ui->radioButtonOpcion1->text() == correctas.value(0) || ui->radioButtonOpcion1->text() == correctas.value(1)
      || ui->radioButtonOpcion1->text() == correctas.value(2) || ui->radioButtonOpcion1->text() == correctas.value(3))){

        entrar = false;
        this->close();
        emit opcionCorrecta(1);
    }

    if( ui->radioButtonOpcion2->isChecked() && (ui->radioButtonOpcion2->text() == correctas.value(0) || ui->radioButtonOpcion2->text() == correctas.value(1)
      || ui->radioButtonOpcion2->text() == correctas.value(2) || ui->radioButtonOpcion2->text() == correctas.value(3))){

        entrar = false;
        this->close();
        emit opcionCorrecta(1);
    }

    if( ui->radioButtonOpcion3->isChecked() && (ui->radioButtonOpcion3->text() == correctas.value(0) || ui->radioButtonOpcion3->text() == correctas.value(1)
      || ui->radioButtonOpcion3->text() == correctas.value(2) || ui->radioButtonOpcion3->text() == correctas.value(3))){

        entrar = false;
        this->close();
        emit opcionCorrecta(1);
    }

    if( ui->radioButtonOpcion4->isChecked() && (ui->radioButtonOpcion4->text() == correctas.value(0) || ui->radioButtonOpcion4->text() == correctas.value(1)
      || ui->radioButtonOpcion4->text() == correctas.value(2) || ui->radioButtonOpcion4->text() == correctas.value(3))){

        entrar = false;
        this->close();
        emit opcionCorrecta(1);
    }

    if(entrar == true){
        this->close();
        emit opcionCorrecta(0);
    }

}

MensajeOpciones::~MensajeOpciones()
{
    delete ui;
}
