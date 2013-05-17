#include "headers/nombreproyectowidget.h"
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

    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(cambiarTexto1()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(cambiarTexto2()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(cambiarTexto3()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(cambiarTexto4()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(cambiarTexto5()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(cambiarTexto6()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(cambiarTexto7()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(cambiarTexto8()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(cambiarTexto9()));
    connect(ui->pushButton10,SIGNAL(clicked()),this,SLOT(cambiarTexto10()));
    connect(ui->pushButton11,SIGNAL(clicked()),this,SLOT(cambiarTexto11()));
    connect(ui->pushButton12,SIGNAL(clicked()),this,SLOT(cambiarTexto12()));
    connect(ui->pushButton13,SIGNAL(clicked()),this,SLOT(cambiarTexto13()));
    connect(ui->pushButton14,SIGNAL(clicked()),this,SLOT(cambiarTexto14()));
    connect(ui->pushButton15,SIGNAL(clicked()),this,SLOT(cambiarTexto15()));
    connect(ui->pushButton16,SIGNAL(clicked()),this,SLOT(cambiarTexto16()));
    connect(ui->pushButton17,SIGNAL(clicked()),this,SLOT(cambiarTexto17()));
    connect(ui->pushButton18,SIGNAL(clicked()),this,SLOT(cambiarTexto18()));
    connect(ui->pushButton19,SIGNAL(clicked()),this,SLOT(cambiarTexto19()));
    connect(ui->pushButton20,SIGNAL(clicked()),this,SLOT(cambiarTexto20()));
    connect(ui->pushButton21,SIGNAL(clicked()),this,SLOT(cambiarTexto21()));

}

void NombreProyectoWidget::cambiarTexto1()
{
    auxButton->setText("SS-TNOs");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();

}

void NombreProyectoWidget::cambiarTexto2()
{
    auxButton->setText("JH-CABEZAORION");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto3()
{
    auxButton->setText("FF-TARDIAS");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto4()
{
    auxButton->setText("ON-TNO");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto5()
{
    auxButton->setText("MY-RRLYRAE");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();;
}

void NombreProyectoWidget::cambiarTexto6()
{
    auxButton->setText("KV-LMC");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto7()
{
    auxButton->setText("JH-PRISMORI");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto8()
{
    auxButton->setText("JH-PRISMSERP");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto9()
{
    auxButton->setText("JD-PELAIDES");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto10()
{
    auxButton->setText("CB-MCNEIL");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto11()
{
    auxButton->setText("PS-TNO");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto12()
{
    auxButton->setText("KV-OCEN");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto13()
{
    auxButton->setText("IF-SSS");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto14()
{
    auxButton->setText("JH-PRISM-ORION");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto15()
{
    auxButton->setText("CB-VARIABILIDAD");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto16()
{
    auxButton->setText("CB-L1641");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto17()
{
    auxButton->setText("BS-BAADES");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto18()
{
    auxButton->setText("GJ-SEXTANS-CEPH");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto19()
{
    auxButton->setText("JD-ENANASMARRONES");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto20()
{
    auxButton->setText("CB-YETI");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();
}

void NombreProyectoWidget::cambiarTexto21()
{
    auxButton->setText("PRUEBAS");
    auxActivar[0] = 's';

    eliminarWidgetNombreProyecto();

}

void NombreProyectoWidget::eliminarWidgetNombreProyecto()
{
    this->hide();
    delete this;
}
