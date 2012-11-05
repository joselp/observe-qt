#include "filtro1widget.h"
#include "ui_filtro1widget.h"

Filtro1Widget::Filtro1Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Filtro1Widget)
{
    ui->setupUi(this);
    auxButton= new QPushButton;
    auxActivar = new char[1];

    mapper = new QSignalMapper(this);


}

Filtro1Widget::~Filtro1Widget()
{
    delete ui;
}

void Filtro1Widget::iniciarConnects(QPushButton *a,QPushButton *b,QPushButton *c,QPushButton *d, char *e)
{
    auxButton = a;
    auxButton2 = b;
    auxButton3 = c;
    auxButton4 = d;
    auxActivar = e;

    //Conecto todos los botones al QSignalMapper.

    connect(ui->pushButton1, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton2, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton3, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton4, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton5, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton6, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton7, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton8, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton9, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton10, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton11, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton12, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton13, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton14, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton15, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton16, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton17, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton18, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton19, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton20, SIGNAL(clicked()), mapper, SLOT(map()));
    connect(ui->pushButton21, SIGNAL(clicked()), mapper, SLOT(map()));

    //Asigno un Id a cada Boton.

    mapper->setMapping(ui->pushButton1, 1);
    mapper->setMapping(ui->pushButton2, 2);
    mapper->setMapping(ui->pushButton3, 3);
    mapper->setMapping(ui->pushButton4, 4);
    mapper->setMapping(ui->pushButton5, 5);
    mapper->setMapping(ui->pushButton6, 6);
    mapper->setMapping(ui->pushButton7, 7);
    mapper->setMapping(ui->pushButton8, 8);
    mapper->setMapping(ui->pushButton9, 9);
    mapper->setMapping(ui->pushButton10, 10);
    mapper->setMapping(ui->pushButton11, 11);
    mapper->setMapping(ui->pushButton12, 12);
    mapper->setMapping(ui->pushButton13, 13);
    mapper->setMapping(ui->pushButton14, 14);
    mapper->setMapping(ui->pushButton15, 15);
    mapper->setMapping(ui->pushButton16, 16);
    mapper->setMapping(ui->pushButton17, 17);
    mapper->setMapping(ui->pushButton18, 18);
    mapper->setMapping(ui->pushButton19, 19);
    mapper->setMapping(ui->pushButton20, 20);
    mapper->setMapping(ui->pushButton21, 21);

    connect(mapper, SIGNAL(mapped(int)),this, SLOT(cambiarTexto(int)));

}

void Filtro1Widget::cambiarTexto(int i)
{
    if(i==1){
        if(auxButton2->text()!="U1" && auxButton3->text()!="U1" && auxButton4->text()!="U1"){
            auxButton->setText("U1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==2){
        if(auxButton2->text()!="U2" && auxButton3->text()!="U2" && auxButton4->text()!="U2"){
            auxButton->setText("U2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==3){
        if(auxButton2->text()!="B1" && auxButton3->text()!="B1" && auxButton4->text()!="B1"){
            auxButton->setText("B1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==4){
        if(auxButton2->text()!="B2" && auxButton3->text()!="B2" && auxButton4->text()!="B2"){
            auxButton->setText("B2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==5){
        if(auxButton2->text()!="V1" && auxButton3->text()!="V1" && auxButton4->text()!="V1"){
            auxButton->setText("V1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==6){
        if(auxButton2->text()!="V2" && auxButton3->text()!="V2" && auxButton4->text()!="V2"){
            auxButton->setText("V2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==7){
        if(auxButton2->text()!="V3" && auxButton3->text()!="V3" && auxButton4->text()!="V3"){
            auxButton->setText("V3");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==8){
        if(auxButton2->text()!="V4" && auxButton3->text()!="V4" && auxButton4->text()!="V4"){
            auxButton->setText("V4");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==9){
        if(auxButton2->text()!="R1" && auxButton3->text()!="R1" && auxButton4->text()!="R1"){
            auxButton->setText("R1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==10){
        if(auxButton2->text()!="R2" && auxButton3->text()!="R2" && auxButton4->text()!="R2"){
            auxButton->setText("R2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==11){
        if(auxButton2->text()!="R3" && auxButton3->text()!="R3" && auxButton4->text()!="R3"){
            auxButton->setText("R3");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==12){
        if(auxButton2->text()!="Ha1" && auxButton3->text()!="Ha1" && auxButton4->text()!="Ha1"){
            auxButton->setText("Ha1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==13){
        if(auxButton2->text()!="l1" && auxButton3->text()!="l1" && auxButton4->text()!="l1"){
            auxButton->setText("l1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==14){
        if(auxButton2->text()!="l2" && auxButton3->text()!="l2" && auxButton4->text()!="l2"){
            auxButton->setText("l2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==15){
        auxButton->setText("CLR");
        auxButton2->setText("CLR");
        auxButton3->setText("CLR");
        auxButton4->setText("CLR");
        auxActivar[0] = 's';

        eliminarWidgetFiltro();

    }

    if(i==16){
        auxButton->setText("HOT");
        auxButton2->setText("HOT");
        auxButton3->setText("HOT");
        auxButton4->setText("HOT");
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==17){
        auxButton->setText("UHa");
        auxButton2->setText("UHa");
        auxButton3->setText("UHa");
        auxButton4->setText("UHa");
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==18){
        if(auxButton2->text()!="BP1" && auxButton3->text()!="BP1" && auxButton4->text()!="BP1"){
            auxButton->setText("BP1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==19){
        if(auxButton2->text()!="BP2" && auxButton3->text()!="BP2" && auxButton4->text()!="BP2"){
            auxButton->setText("BP2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==20){
        if(auxButton2->text()!="RP1" && auxButton3->text()!="RP1" && auxButton4->text()!="RP1"){
            auxButton->setText("RP1");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }

    if(i==21){
        if(auxButton2->text()!="RP2" && auxButton3->text()!="RP2" && auxButton4->text()!="RP2"){
            auxButton->setText("RP2");
        }
        auxActivar[0] = 's';

        eliminarWidgetFiltro();
    }
}

void Filtro1Widget::eliminarWidgetFiltro()
{
    this->hide();
    delete this;
}


