#include "headers/cargas/reportes.h"
#include "ui_reportes.h"
#include <QDebug>

Reportes::Reportes(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Reportes)
{
    ui->setupUi(this);

    this->setWindowTitle("Reportes");

    tablePrestamo = new QTableWidget(this);
    tablePrestamo->setColumnCount(3);
    tablePrestamo->setGeometry(10,80,500,200);
    QStringList listHeader;
    listHeader << "Observador" << "Prueba" << "ID";
    int rowCount = tablePrestamo->rowCount();
    tablePrestamo->setHorizontalHeaderLabels(listHeader);

    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), tablePrestamo, SLOT(selectRow(int)));
    connect(tablePrestamo, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(slotRowSelected(int)));
    connect(ui->pushButtonAceptar,SIGNAL(clicked()),this,SLOT(slotCerrar()));

    QSqlQuery query;
    QString strQuery = "SELECT * FROM reporte r JOIN prueba p ON p.id=r.prueba_id JOIN protocolo pt ON pt.id=p.protocolo_id JOIN persona per ON per.id=r.persona_id";

    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No Hay reportes.");
        return;
    }
    else {

        rowCount += 1;
        tablePrestamo->setRowCount(rowCount);
        rowCount = tablePrestamo->rowCount();

        if( rowCount < 6 )
            tablePrestamo->setGeometry(10,80,500,200);
        else
            tablePrestamo->setGeometry(10,80,534,200);

        for( int row = rowCount - 1; row < rowCount; row++ ) {

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(25).toString());
            tablePrestamo->setItem(row, 0, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(12).toString());
            tablePrestamo->setItem(row, 1, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(2).toString());
            tablePrestamo->setItem(row, 2, item);

        }

        while( query.next() ) {

            rowCount += 1;
            tablePrestamo->setRowCount(rowCount);
            rowCount = tablePrestamo->rowCount();

            if( rowCount < 6 )
                tablePrestamo->setGeometry(55,80,518,175);
            else
                tablePrestamo->setGeometry(42,80,534,173);

            for( int row = rowCount - 1; row < rowCount; row++ ) {

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(25).toString());
                tablePrestamo->setItem(row, 0, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(12).toString());
                tablePrestamo->setItem(row, 1, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(2).toString());
                tablePrestamo->setItem(row, 2, item);

            }
        }
    }

}

void Reportes::setIdPersona(int i)
{
    idPersona = i;
    qDebug()<<idPersona;
}

Reportes::~Reportes()
{
    delete ui;
}

void Reportes::slotRowSelected(int row)
{
    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,2);

    QSqlQuery query;
    QString strQuery = "SELECT * FROM reporte r JOIN prueba p ON p.id=r.prueba_id JOIN protocolo pt ON pt.id=p.protocolo_id JOIN persona per ON per.id=r.persona_id WHERE p.id='"+item->text()+"'";
    query.exec(strQuery);

    if(query.next()){
    reporteAdmin = new ReporteAdmin;
    reporteAdmin->asignarDatos(query);
    query.clear();
    reporteAdmin->show();
    }
}

void Reportes::slotCerrar()
{
    this->close();
}
