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

    filtroUnico = false;

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
        auxButton->setText("U1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==2){
        auxButton->setText("U2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==3){
        auxButton->setText("B1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==4){
        auxButton->setText("B2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==5){
        auxButton->setText("V1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==6){
        auxButton->setText("V2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==7){
        auxButton->setText("V3");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==8){
        auxButton->setText("V4");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==9){
        auxButton->setText("R1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==10){
        auxButton->setText("R2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==11){
        auxButton->setText("R3");
        auxActivar[0] = 's';

        this->hide();
        delete this;;
    }

    if(i==12){
        auxButton->setText("Ha1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==13){
        auxButton->setText("l1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==14){
        auxButton->setText("l2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==15){
        auxButton->setText("CLR");
        auxButton2->setText("CLR");
        auxButton3->setText("CLR");
        auxButton4->setText("CLR");
        auxActivar[0] = 's';

        this->hide();
        delete this;
        filtroUnico = true;
    }

    if(i==16){
        auxButton->setText("HOT");
        auxButton2->setText("HOT");
        auxButton3->setText("HOT");
        auxButton4->setText("HOT");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==17){
        auxButton->setText("UHa");
        auxButton2->setText("UHa");
        auxButton3->setText("UHa");
        auxButton4->setText("UHa");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==18){
        auxButton->setText("BP1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==19){
        auxButton->setText("BP2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==20){
        auxButton->setText("RP1");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }

    if(i==21){
        auxButton->setText("RP2");
        auxActivar[0] = 's';

        this->hide();
        delete this;
    }
}


