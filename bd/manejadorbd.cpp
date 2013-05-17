#include "manejadorbd.h"

QSqlDatabase ManejadorBd::db=QSqlDatabase::addDatabase("QPSQL");

ManejadorBd::ManejadorBd()
{
    driver="QPSQL";

}


//-------------------------------Configuracion de la session-----------------
void ManejadorBd::establecerPuerto(int puerto)
{
    db.setPort(puerto);
}

void ManejadorBd::establecerDriverComercial(string driver)
{
    db=QSqlDatabase::addDatabase(driver.c_str());
}

void ManejadorBd::establecerHost(string host)
{
    db.setHostName(host.c_str());
}

void ManejadorBd::establecerNombreUsuario(string usuario)
{
    db.setUserName(usuario.c_str());
}

void ManejadorBd::establecerPassword(string pass)
{
    db.setPassword(pass.c_str());
}

void ManejadorBd::establecerBaseDatos(string nombreBd)
{
    db.setDatabaseName(nombreBd.c_str());
}

//----------------------Acciones sobre la transaccion/sesion----------------------
bool ManejadorBd::abrirSesion()
{

    if (!db.open())
    {
        qDebug() << "Error Al abrir la base de datos";
        return false;
    }
    return true;
}

bool ManejadorBd::cerrarSesion()
{
    db.close();
    return !db.isOpen();

}

bool ManejadorBd::rollback()
{
    return db.rollback();
}


