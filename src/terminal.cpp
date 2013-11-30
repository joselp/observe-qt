#include "headers/terminal.h"
#include "ui_terminal.h"

Terminal::Terminal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Terminal)
{
    ui->setupUi(this);
    initGui();

}

void Terminal::initGui()
{
    consolaComandos = new miTextArea(this);
    consolaComandos->setGeometry(0,0,this->width(),this->height());
}

miTextArea *Terminal::obtenerConsolaComandos()
{
    return consolaComandos;
}

Terminal::~Terminal()
{
    delete ui;
}
