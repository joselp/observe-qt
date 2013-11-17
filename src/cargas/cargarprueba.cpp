#include "headers/cargas/cargarprueba.h"
#include "ui_cargarprueba.h"

CargarPrueba::CargarPrueba(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CargarPrueba)
{
    ui->setupUi(this);
    this->setWindowTitle("Pruebas");

    tablePrestamo = new QTableWidget(this);
    tablePrestamo->setColumnCount(3);
    tablePrestamo->setGeometry(10,20,500,200);

    QStringList listHeader;
    listHeader << "Id de Prueba" << "Nombre";
    int rowCount = tablePrestamo->rowCount();
    tablePrestamo->setHorizontalHeaderLabels(listHeader);

    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), tablePrestamo, SLOT(selectRow(int)));
    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), this, SLOT(slotRowSelected(int)));
    QString strQuery = "SELECT * FROM prueba";

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No existe pruebas guardadas.");
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
            item->setText(query.value(0).toString());
            tablePrestamo->setItem(row, 0, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(8).toString());
            tablePrestamo->setItem(row, 1, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(7).toString());
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
                item->setText(query.value(0).toString());
                tablePrestamo->setItem(row, 0, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(8).toString());
                tablePrestamo->setItem(row, 1, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(7).toString());
                tablePrestamo->setItem(row, 2, item);

            }
        }
    }
}

void CargarPrueba::slotRowSelected(int row)
{
    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,0);

    QString strQuery = "SELECT * FROM prueba WHERE id = '"
                       + item->text() + "'";

    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,2);

    QString strQuery2 = "SELECT * FROM protocolo WHERE id = " + item->text();

    QSqlQuery query;
    query.exec(strQuery);

    QSqlQuery query2;
    query2.exec(strQuery2);

    if( query.next() && query2.next() ) {
        emit enviarDatos(query,query2);

    }

}

CargarPrueba::~CargarPrueba()
{
    delete ui;
}
