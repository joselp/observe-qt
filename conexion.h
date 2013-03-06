#ifndef CONEXION_H
#define CONEXION_H

#include<QDebug>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

bool crearConexion(){


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("SimuladorDB.db");

    qDebug() << QSqlDatabase::drivers();

    if (!db.open())
    {
        qDebug() << "Error Al abrir la base de datos";
        return false;
    }
    else{
        qDebug()<< "Base de datos iniciada";
        return true;
    }

}

#endif // CONEXION_H
