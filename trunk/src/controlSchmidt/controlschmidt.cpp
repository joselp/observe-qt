#include "headers/controlSchmidt/controlschmidt.h"
#include "ui_controlschmidt.h"

ControlSchmidt::ControlSchmidt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ControlSchmidt)
{
    ui->setupUi(this);
}

ControlSchmidt::~ControlSchmidt()
{
    delete ui;
}
