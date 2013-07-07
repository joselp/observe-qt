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

Terminal::~Terminal()
{
    delete ui;
}
