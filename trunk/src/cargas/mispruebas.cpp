#include "headers/cargas/mispruebas.h"
#include "ui_mispruebas.h"

MisPruebas::MisPruebas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MisPruebas)
{
    ui->setupUi(this);

    this->setWindowTitle("Pruebas");
    formProtocolo = new FormProtocolo;
    connect(ui->pushButtonAceptar,SIGNAL(clicked()),this,SLOT(slotAceptar()));

}

void MisPruebas::cargarPruebas(QString idUsuario)
{
    tablePrestamo = new QTableWidget(this);
    tablePrestamo->setColumnCount(3);
    tablePrestamo->setGeometry(10,20,500,200);

    QStringList listHeader;
    listHeader << "Prueba" << "Protocolo" << "id";
    int rowCount = tablePrestamo->rowCount();
    tablePrestamo->setHorizontalHeaderLabels(listHeader);

    connect(tablePrestamo, SIGNAL(cellClicked(int,int)), tablePrestamo, SLOT(selectRow(int)));
    connect(tablePrestamo, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(slotRowSelected(int)));

    QString strQuery = "SELECT pt.id, pr.condicion_cielo, pr.mala_posicion_dedos, pr.mal_foco, pr.obturador, pr.prisma, pr.nombre, pr.falla_conexion, pt.filtro_1, pt.filtro_2, pt.filtro_3, pt.filtro_4, pt.declinacion, pt.angulo_horario, pt.tipo_observacion, pt.duracion, pt.nombre_proyecto, pt.instrumento from persona p JOIN prueba_persona pp ON p.id=pp.id_persona JOIN prueba pr ON pr.id=pp.id_prueba JOIN protocolo pt ON pt.id=pr.protocolo_id WHERE p.id=" + idUsuario;

    QSqlQuery query;
    query.exec(strQuery);

    if( !query.next() ) {
        QMessageBox::warning(this, "ADVERTENCIA", "No tiene pruebas asignadas.");
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
            item->setText(query.value(6).toString());
            tablePrestamo->setItem(row, 0, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(16).toString());
            tablePrestamo->setItem(row, 1, item);

            item = new QTableWidgetItem;
            item->setFlags(item->flags() & (~Qt::ItemIsEditable));
            item->setText(query.value(0).toString());
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
                item->setText(query.value(6).toString());
                tablePrestamo->setItem(row, 0, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(16).toString());
                tablePrestamo->setItem(row, 1, item);

                item = new QTableWidgetItem;
                item->setFlags(item->flags() & (~Qt::ItemIsEditable));
                item->setText(query.value(0).toString());
                tablePrestamo->setItem(row, 2, item);

            }
        }
    }
}

MisPruebas::~MisPruebas()
{
    delete ui;
}

void MisPruebas::slotRowSelected(int row)
{

    item = new QTableWidgetItem;
    item = tablePrestamo->item(row,2);

    QString strQuery = "SELECT * FROM protocolo WHERE id = " + item->text();

    QSqlQuery query;
    query.exec(strQuery);

    if( query.next() ) {
        formProtocolo->asignarFiltro1(query.value(1).toString());
        formProtocolo->asignarFiltro2(query.value(2).toString());
        formProtocolo->asignarFiltro3(query.value(3).toString());
        formProtocolo->asignarFiltro4(query.value(4).toString());
        formProtocolo->asignarDeclinacion(query.value(5).toString());
        formProtocolo->asignarAnguloHorario(query.value(6).toString());
        formProtocolo->asignarTipoObservacion(query.value(7).toString());
        formProtocolo->asignarDuracion(query.value(8).toString());
        formProtocolo->asignarProyecto(query.value(9).toString());
        formProtocolo->asignarInstrumento(query.value(10).toString());
        formProtocolo->show();
        emit enviarDatos(query);
    }
}

void MisPruebas::slotAceptar()
{
    this->close();
}
