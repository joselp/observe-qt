#include "headers/controlschmitd/controlschmitd.h"
#include "ui_controlschmitd.h"

Controlschmitd::Controlschmitd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Controlschmitd)
{
    ui->setupUi(this);
    mdiArea = new QMdiArea;
    initAction();
}

void Controlschmitd::initAction()
{
    connect(ui->actionFoco, SIGNAL(triggered()), this, SLOT(slotFoco()));
    connect(ui->actionObserve,SIGNAL(triggered()),this,SLOT(slotObserve()));
    connect(ui->actionSalir, SIGNAL(triggered()), this, SLOT(slotSalir()));
    connect(ui->actionSummary,SIGNAL(triggered()),this,SLOT(slotSummary()));
    connect(ui->actionLimpiar,SIGNAL(triggered()),this,SLOT(slotLimpiar()));
    connect(ui->actionSlayall,SIGNAL(triggered()),this,SLOT(slotSlayall()));
    connect(ui->actionShutdAll,SIGNAL(triggered()),this,SLOT(slotShutdall()));
}

void Controlschmitd::setControlSchmitd(QMdiArea *m)
{
    mdiArea = m;
}

void Controlschmitd::slotFoco()
{
}

void Controlschmitd::slotObserve()
{
    emit abrirObserve();
}

void Controlschmitd::slotSummary()
{
    summary = new Summary;
    MySubWindow *summaryWindows = new MySubWindow;
    summaryWindows->setWindowTitle("Summary");
    summaryWindows->setWidget(summary);
    mdiArea->addSubWindow(summaryWindows);
    summaryWindows->show();
}

void Controlschmitd::slotLimpiar()
{
    limpiar = new Limpiar;
    MySubWindow *limpiarWindows = new MySubWindow;
    limpiarWindows->setWindowTitle("Limpiar");
    limpiarWindows->setWidget(limpiar);
    mdiArea->addSubWindow(limpiarWindows);
    limpiarWindows->show();
}

void Controlschmitd::slotTransferir()
{
}

void Controlschmitd::slotAnalizar()
{
}

void Controlschmitd::slotSlayall()
{
    slayAll = new SlayAll;
    MySubWindow *slayAllWindows = new MySubWindow;
    slayAllWindows->setWindowTitle("slayAll");
    slayAllWindows->setWidget(slayAll);
    mdiArea->addSubWindow(slayAllWindows);
    slayAllWindows->show();
}

void Controlschmitd::slotShutdall()
{
    shutdAll = new ShutdAll;
    MySubWindow *shutdAllWindows = new MySubWindow;
    shutdAllWindows->setWindowTitle("ShutAll");
    shutdAllWindows->setWidget(shutdAll);
    mdiArea->addSubWindow(shutdAllWindows);
    shutdAllWindows->show();
}

void Controlschmitd::slotAyuda()
{
}

void Controlschmitd::slotSalir()
{
    this->close();
}

Controlschmitd::~Controlschmitd()
{
    delete ui;
}
