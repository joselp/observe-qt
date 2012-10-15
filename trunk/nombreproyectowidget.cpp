#include "nombreproyectowidget.h"
#include "ui_nombreproyectowidget.h"
#include<QDebug>

NombreProyectoWidget::NombreProyectoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NombreProyectoWidget)
{
    ui->setupUi(this);
    auxButton= new QPushButton;
    auxActivar = new char[1];
}

NombreProyectoWidget::~NombreProyectoWidget()
{
    delete ui;
}

void NombreProyectoWidget::iniciarConnects(QPushButton *a, char *b){

    auxButton = a;
    auxActivar = b;
    qDebug()<< auxActivar[0];
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(cambiarTexto1()));
}

void NombreProyectoWidget::cambiarTexto1()
{
    auxButton->setText("SS-TNOs");
    auxActivar[0] = 's';

    this->hide();
    delete this;

}
