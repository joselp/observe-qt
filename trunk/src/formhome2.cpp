#include "headers/formhome2.h"
#include "ui_formhome2.h"

FormHome2::FormHome2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHome2)
{
    ui->setupUi(this);
}

FormHome2::~FormHome2()
{
    delete ui;
}
