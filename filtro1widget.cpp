#include "filtro1widget.h"
#include "ui_filtro1widget.h"

Filtro1Widget::Filtro1Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Filtro1Widget)
{
    ui->setupUi(this);
    auxButton= new QPushButton;
    auxActivar = new char[1];

}

Filtro1Widget::~Filtro1Widget()
{
    delete ui;
}

void Filtro1Widget::iniciarConnects(QPushButton *a, char *b)
{

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


void Filtro1Widget::cambiarTexto1()
{
    auxButton->setText("U1");
    auxActivar[0] = 's';

    this->hide();
    delete this;

}

void Filtro1Widget::cambiarTexto2()
{
    auxButton->setText("U2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto3()
{
    auxButton->setText("B1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto4()
{
    auxButton->setText("B2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto5()
{
    auxButton->setText("V1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto6()
{
    auxButton->setText("V2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto7()
{
    auxButton->setText("V3");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto8()
{
    auxButton->setText("V4");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto9()
{
    auxButton->setText("R1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto10()
{
    auxButton->setText("R2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto11()
{
    auxButton->setText("R3");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto12()
{
    auxButton->setText("Ha1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto13()
{
    auxButton->setText("l1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto14()
{
    auxButton->setText("l2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto15()
{
    auxButton->setText("CLR");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto16()
{
    auxButton->setText("CLR");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto17()
{
    auxButton->setText("UHa");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto18()
{
    auxButton->setText("BP1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto19()
{
    auxButton->setText("BP2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto20()
{
    auxButton->setText("RP1");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}

void Filtro1Widget::cambiarTexto21()
{
    auxButton->setText("RP2");
    auxActivar[0] = 's';

    this->hide();
    delete this;
}
