#include "cabecerasfits.h"
#include "ui_cabecerasfits.h"

CabecerasFits::CabecerasFits(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CabecerasFits)
{
    ui->setupUi(this);
    this->setWindowTitle("Cabeceras Fits");
}

CabecerasFits::~CabecerasFits()
{
    delete ui;
}
