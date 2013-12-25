#include "headers/controlschmitd/slayall.h"
#include "ui_slayall.h"

SlayAll::SlayAll(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SlayAll)
{
    ui->setupUi(this);
}

SlayAll::~SlayAll()
{
    delete ui;
}
