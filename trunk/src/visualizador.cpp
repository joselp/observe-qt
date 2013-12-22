#include "headers/visualizador.h"
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
    this->setFixedSize(930,620);
    this->setWindowIcon(QIcon(":/images/cidaicon.png"));

    //Creo el proceso de la lectura de la imagen y lo enserto en la scena para poder hacer los zoom
    procesoFits = new ProcesoFits;
    //procesoFits = new Utils;

    //Creo el GraphWidget donde se mostrara la imagen fits
    //visor = new GraphWidget(this);
    //visor->setGeometry(10,170,1000,532);
    //visor->setGeometry(0,0,2050,2050);

    //scene = new QGraphicsScene();
    //visor->setScene(scene);

    //Creo un scroll area donde se insertara el GraphWidget ya que este es mucho mas grande

    //    scrollArea->setGeometry(10,170,1000,532);
    //    scrollArea->setWidget(visor);

    //ui->scrollArea->setWidget(visor);

    //ui->graphicsView->setScene(scene);

    //scene->addWidget(procesoFits);


    //Scroll donde se insertara el widget.
    myScroll = new MyScrollArea;
    myScroll->verticalScrollBar()->setHidden(true);
    //myScroll->verticalScrollBar()->setDisabled(true);
    myScroll->setWidget(procesoFits);
    ui->verticalLayout->addWidget(myScroll);
    procesoFits->barraVisualizador(myScroll);

    //Connecto los botonos de zoom
//    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(zoomIn()));
//    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(zoomOut()));
//    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(zoomNormal()));
    connect(myScroll, SIGNAL(mousePressed(int, int)), this, SLOT(slotParaManejarRaton(int, int)));

    //Asigno los textos de los Label de la ventana visualizador
    ui->labelCcds->setText("<h3><i><font color=blue>CCDs:</font></i></h3>");
    ui->labelCuentas->setText("<h3><i><font color=blue>Cuentas:</font></i></h3>");
    ui->labelFondoCielo->setText("<h3><i><font color=blue>Fondo de Cielo:</font></i></h3>");
    ui->labelValor->setText("<h3><i>Valor =  </i></h3>");
    ui->labelValorX->setText("<h3><i>X =  </i></h3>");
    ui->labelValorY->setText("<h3><i>Y =  </i></h3>");
    ui->labelMu->setText("<h3><i>&mu; =  <i></h3>");
    ui->labelSigma->setText("<h3><i>&sigma; =  </i></h3>");


    //Se definen los connects para los botones QNX y CCDs
    connect(ui->pushButtonQnx1,SIGNAL(clicked()),this,SLOT(slotQnx1()));
    connect(ui->pushButtonQnx2,SIGNAL(clicked()),this,SLOT(slotQnx2()));
    connect(ui->pushButtonQnx3,SIGNAL(clicked()),this,SLOT(slotQnx3()));
    connect(ui->pushButtonQnx4,SIGNAL(clicked()),this,SLOT(slotQnx4()));
    connect(ui->pushButtonCcd1,SIGNAL(clicked()),this,SLOT(slotCcd1()));
    connect(ui->pushButtonCcd2,SIGNAL(clicked()),this,SLOT(slotCcd2()));
    connect(ui->pushButtonCcd3,SIGNAL(clicked()),this,SLOT(slotCcd3()));
    connect(ui->pushButtonCcd4,SIGNAL(clicked()),this,SLOT(slotCcd4()));

    //Por defecto se reciben datos de QNX1 y CCD1
    ui->pushButtonQnx1->setEnabled(false);
    ui->pushButtonCcd1->setEnabled(false);

}

//Inicio el proceso para leer el archivo fits asi como mostrarlo

void Visualizador::initLectura()
{
    procesoFits->setTotalLineas(totalLineas);
    procesoFits->leerFits();
}

//void Visualizador::zoomIn()
//{
//    //visor->scale(1.1,1.1);
//}

//void Visualizador::zoomOut()
//{
//    //visor->scale(0.9,0.9);
//}

//void Visualizador::zoomNormal()
//{
//    // visor->resetTransform();
//}

Visualizador::~Visualizador()
{
    delete ui;
}

ProcesoFits *Visualizador::getProcesoFits()
{
    return procesoFits;
}

void Visualizador::slotParaManejarRaton(int x, int y)
{
    ui->labelValorXEdit->setText(QString::number(x));
    ui->labelValorYEdit->setText(QString::number(y));
    ui->labelValorEdit->setText(QString::number(procesoFits->valorMatriz(x,y)));
}

void Visualizador::setTotalLineas(int total)
{
    totalLineas = total;
}

void Visualizador::setPrueba(QString p)
{

    procesoFits->setPrueba(p);
}

void Visualizador::setNumeroLineaActual(int l)
{
    procesoFits->setLineaActual(l);
}

void Visualizador::setCondicionesCielo(QString condiciones)
{
    procesoFits->setCondicionesCielo(condiciones);
}

//Definicion de los slots para manejar los botones QNX y CCDs

void Visualizador::slotQnx1()
{
    ui->pushButtonQnx1->setEnabled(false);
    ui->pushButtonQnx2->setEnabled(true);
    ui->pushButtonQnx3->setEnabled(true);
    ui->pushButtonQnx4->setEnabled(true);

    procesoFits->setQnx("qnx1");

    procesoFits->resetProceso();
}

void Visualizador::slotQnx2()
{
    ui->pushButtonQnx1->setEnabled(true);
    ui->pushButtonQnx2->setEnabled(false);
    ui->pushButtonQnx3->setEnabled(true);
    ui->pushButtonQnx4->setEnabled(true);

    procesoFits->setQnx("qnx2");

    procesoFits->resetProceso();
}

void Visualizador::slotQnx3()
{
    ui->pushButtonQnx1->setEnabled(true);
    ui->pushButtonQnx2->setEnabled(true);
    ui->pushButtonQnx3->setEnabled(false);
    ui->pushButtonQnx4->setEnabled(true);

    procesoFits->setQnx("qnx3");

    procesoFits->resetProceso();
}

void Visualizador::slotQnx4()
{
    ui->pushButtonQnx1->setEnabled(true);
    ui->pushButtonQnx2->setEnabled(true);
    ui->pushButtonQnx3->setEnabled(true);
    ui->pushButtonQnx4->setEnabled(false);

    procesoFits->setQnx("qnx4");

    procesoFits->resetProceso();
}

void Visualizador::slotCcd1()
{
    ui->pushButtonCcd1->setEnabled(false);
    ui->pushButtonCcd2->setEnabled(true);
    ui->pushButtonCcd3->setEnabled(true);
    ui->pushButtonCcd4->setEnabled(true);

    procesoFits->setCcd("ccd1");

    procesoFits->resetProceso();
}

void Visualizador::slotCcd2()
{
    ui->pushButtonCcd1->setEnabled(true);
    ui->pushButtonCcd2->setEnabled(false);
    ui->pushButtonCcd3->setEnabled(true);
    ui->pushButtonCcd4->setEnabled(true);

    procesoFits->setCcd("ccd2");

    procesoFits->resetProceso();
}
void Visualizador::slotCcd3()
{
    ui->pushButtonCcd1->setEnabled(true);
    ui->pushButtonCcd2->setEnabled(true);
    ui->pushButtonCcd3->setEnabled(false);
    ui->pushButtonCcd4->setEnabled(true);

    procesoFits->setCcd("ccd3");

    procesoFits->resetProceso();
}
void Visualizador::slotCcd4()
{
    ui->pushButtonCcd1->setEnabled(true);
    ui->pushButtonCcd2->setEnabled(true);
    ui->pushButtonCcd3->setEnabled(true);
    ui->pushButtonCcd4->setEnabled(false);

    procesoFits->setCcd("ccd4");

    procesoFits->resetProceso();
}




