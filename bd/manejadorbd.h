#ifndef MANEJADORBD_H
#define MANEJADORBD_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include <QDebug>
using namespace std;


class ManejadorBd
{

public:

    ManejadorBd();

    //-------Funciones para configurar Conexion-----------
    void establecerPuerto(int puerto);
    void establecerDriverComercial(string Driver);
    void establecerHost(string host);
    void establecerNombreUsuario(string usuario);
    void establecerPassword(string pass);
    void establecerBaseDatos(string nombreBd);

    //-------Funciones para manejo Transacciones/Sesiones----------
    bool abrirSesion();
    bool cerrarSesion();
    bool rollback();
    bool commit();

private:

    static QSqlDatabase db;
    string driver;


};




#endif // MANEJADORBD_H
