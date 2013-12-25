#include "headers/controlschmitd/shutdall.h"
#include "ui_shutdall.h"

ShutdAll::ShutdAll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShutdAll)
{
    ui->setupUi(this);
}

ShutdAll::~ShutdAll()
{
    delete ui;
}
