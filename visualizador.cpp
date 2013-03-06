#include "visualizador.h"
#include "ui_visualizador.h"

Visualizador::Visualizador(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Visualizador)
{
    ui->setupUi(this);
    initGui();

}

void Visualizador::initGui()
{
    this->setFixedSize(1024,710);
    this->setWindowIcon(QIcon(":/images/cidaicon.png"));


    //Creo el proceso de la lectura de la imagen y lo enserto en la scena para poder hacer los zoom
    procesoFits = new ProcesoFits;

    visor = new GraphWidget(this);
    visor->setGeometry(10,170,1000,532);

    scene = new QGraphicsScene();
    visor->setScene(scene);
    //ui->graphicsView->setScene(scene);

    scene->addWidget(procesoFits);

    //Connecto los botonos de zoom
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(zoomIn()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(zoomOut()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(zoomNormal()));
    connect(visor, SIGNAL(mousePressed(int, int)), this, SLOT(slotParaManejarRaton(int, int)));

    //Asigno los textos de los Label de la ventana visualizador
    ui->labelCcds->setText("<h3><i><font color=blue>CCDs:</font></i></h3>");
    ui->labelCuentas->setText("<h3><i><font color=blue>Cuentas:</font></i></h3>");
    ui->labelFondoCielo->setText("<h3><i><font color=blue>Fondo de Cielo:</font></i></h3>");
    ui->labelValor->setText("<h3><i>Valor =  </i></h3>");
    ui->labelValorX->setText("<h3><i>X =  </i></h3>");
    ui->labelValorY->setText("<h3><i>Y =  </i></h3>");
    ui->labelMu->setText("<h3><i>&mu; =  <i></h3>");
    ui->labelSigma->setText("<h3><i>&sigma; =  </i></h3>");

    //Inicio el proceso para leer el archivo fits asi como mostrarlo
    //
}

void Visualizador::initLectura()
{
   procesoFits->leerFits();
}


void Visualizador::zoomIn()
{
    visor->scale(1.1,1.1);
}

void Visualizador::zoomOut()
{
    visor->scale(0.9,0.9);
}

void Visualizador::zoomNormal()
{
    visor->resetTransform();
}

Visualizador::~Visualizador()
{
    delete ui;
}

void Visualizador::slotParaManejarRaton(int x, int y)
{
    ui->labelValorXEdit->setText(QString::number(x));
    ui->labelValorYEdit->setText(QString::number(y));
}


