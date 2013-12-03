#include"headers/miTextArea.h"
#include <iostream>

using namespace std;

miTextArea::miTextArea(QWidget *parent):
    QTextEdit(parent)
{
    qnx1=false;
    qnx2=false;
    qnx3=false;
    qnx4=false;
    qnx5=false;
    qnx6=false;
    obtupas=false;
    obturador1=false;
    this->setText("usuario>");
    //Posiciono el cursor al final de la cadena de caracteres
    QTextCursor cursor(this->textCursor());
    cursor.movePosition(QTextCursor::End);
    this->setTextCursor(cursor);
}

void miTextArea::keyPressEvent(QKeyEvent *e)
{

    //qDebug()<<e->key();

    //Tecla borrar: 16777219
    if(e->key()==16777219){

        string aux2 = this->toPlainText().toStdString();

        if(qnx1==false && qnx2==false && qnx3==false && qnx4==false && qnx5==false && qnx6==false){
            if( (aux2.size()!=8 && aux2.compare(aux2.size()-8,aux2.size(),"usuario>")!=0))
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);

                this->setText(aux);
            }
        }
        else{
        qDebug()<<aux2.compare(aux2.size()-5,aux2.size(),"QNX1>");
        qDebug()<<aux2.compare(aux2.size()-5,aux2.size(),"QNX2>");
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX1>")!=0) && qnx1==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX2>")!=0) && qnx2==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX3>")!=0) && qnx3==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX4>")!=0) && qnx4==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX5>")!=0) && qnx5==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"QNX6>")!=0) && qnx6==true)
            {
                QString aux = this->toPlainText();
                aux.truncate(this->toPlainText().count()-1);
                this->setText(aux);

                //Posiciono el cursor al final de la cadena de caracteres
                QTextCursor cursor(this->textCursor());
                cursor.movePosition(QTextCursor::End);
                //cursor.setPosition(3);
                this->setTextCursor(cursor);
                return;
            }

        }
    }

    //Tecla Enter: 16777220
    else if(e->key()==16777220){

        QStringList listaComandos; //Variable que almacerá el comando a realizar el Qprocess
        listaComandos.clear();
        listaComandos<<this->toPlainText().split(">");
        qDebug()<<listaComandos.value(1);

        ejecutar(listaComandos.last());
    }

    else
        this->setText(this->toPlainText()+e->text());

    //this->setText(this->toPlainText().toStdString().substr(0,this->textCursor().position()).c_str()+e->text()+this->toPlainText().toStdString().substr(this->textCursor().position(),this->toPlainText().toStdString().size()).c_str());

    //Posiciono el cursor al final de la cadena de caracteres
    QTextCursor cursor(this->textCursor());
    cursor.movePosition(QTextCursor::End);
    //cursor.setPosition(3);
    this->setTextCursor(cursor);
}

void miTextArea::ejecutar(QString comando)
{
    bool comandoValido=false; //Me permite saber si es un comando por los reconocidos en el simulador

    qDebug()<< "Este es el comando"<<comando;

    QProcess bash;
    bash.setWorkingDirectory("../observe-qt/analisisImagenes/");
    qDebug()<<bash.workingDirectory()<<" este es el directorio"<<endl;
    bash.start("bash");
    if(!bash.waitForStarted()){
        QMessageBox::critical(this,"ERROR","ERROR: bash no responde");

    }

    //Expresion regular para reconocer comando rlogin
    QRegExp rx("([r][l][o][g][i][n])");

    //Para rlogin no debo ejecutar comando en consola sino mover path de inicio
    if(rx.exactMatch(comando)){

        QString aux;
        aux.append(comando);

        bash.write((const char *)aux.toStdString().c_str());
        comandoValido=true;
    }

    //Expresion regular para reconocer comando calibracion_v4.pl

    QRegExp rx2("([p][e][r][l][\\s][c][a][l][i][b][r][a][c][i][o][n][_][v][4][.][p][l]|[p][e][r][l][\\s][c][a][l][i][b][r][a][c][i][o][n][_][v][4][.][p][l][\\s][\\w]*[\\s][\\w]*[\\s][\\w]*[\\s][\\w]*)");

    if(rx2.exactMatch(comando)){

        QString aux;
        aux.append(comando);

        //bash.write((const char *)aux.toStdString().c_str());
        bash.write("mkdir hola");
        comandoValido=true;

    }

    QRegExp rx3("([p][e][r][l][\\s][o][b][s][e][r][v][a][c][i][o][n][_][d][i][r][e][c][t][a][_][v][7][.][p][l]|[p][e][r][l][\\s][o][b][s][e][r][v][a][c][i][o][n][_][d][i][r][e][c][t][a][_][v][7][.][p][l][\\s][\\w]*[\\s][\\w]*[\\s][\\w]*[\\s][\\w]*)");

    if(rx3.exactMatch(comando)){

        QString aux;
        aux.append(comando);

        bash.write((const char *)aux.toStdString().c_str());
        comandoValido=true;

    }

    if(comando=="rlogin qnx1"){
        if(error1 == false){
        this->setText(this->toPlainText()+"\n"+"QNX1>");
        qnx1=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx1: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx2"){
        if(error2 == false){
        this->setText(this->toPlainText()+"\n"+"QNX2>");
        qnx2=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx2: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx3"){
        if(error3 == false){
        this->setText(this->toPlainText()+"\n"+"QNX3>");
        qnx3=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx3: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx4"){
        if(error4 == false){
        this->setText(this->toPlainText()+"\n"+"QNX4>");
        qnx4=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx4: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx5"){
        if(error5 == false){
        this->setText(this->toPlainText()+"\n"+"QNX5>");
        qnx5=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx5: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx6"){
        if(error6 == false){
        this->setText(this->toPlainText()+"\n"+"QNX6>");
        qnx6=true;
        }
        else
            this->setText(this->toPlainText()+"\nqnx6: No route to host\n"+"usuario>");
        return;
    }

    if(comando=="exit" && (qnx1==true || qnx2==true || qnx3==true || qnx4==true || qnx5==true || qnx6==true)){
        this->setText(this->toPlainText()+"\n"+"usuario>");
        qnx1=false;
        qnx2=false;
        qnx3=false;
        qnx4=false;
        qnx5=false;
        qnx6=false;

    }

    if(comando=="obtupas" && qnx5==true){
        obtupas=true;
        this->setText(this->toPlainText()+"\n"+"Programa para control del Obturador"
                      +"\nInitial board status: 41"
                      +"\nEmptying buffer..."
                      +"\nBoard status: 41"
                      +"\nTrying to flush out/end bad command"
                      +"\nStatus: 1"
                      +"\nStatus: 41"
                      +"\nStatus: 41"
                      +"\nSearching for board"
                      +"\nPC34 ver 2.16-4"
                      +"\nBoard responding."
                      +"\nStatus after reset board: 61"
                      +"\nEmptying buffer again..."
                      +"\nEmptying buffer..."
                      +"\nPower is on"
                      +"\n******MENU******"
                      +"\n[a] mueve 500"
                      +"\n[b] mueve 100"
                      +"\n[c] mueve 50"
                      +"\n[q] salir programa"
                      +"\n>");

        return;
    }

    if(comando=="obturador1" && qnx5==true){
        obturador1=true;
        this->setText(this->toPlainText()+"\n"+"Programa para control del Obturador"
                      +"\nEmptying buffer..."
                      +"\nPower is on"
                      +"\n******MENU******"
                      +"\n[a] Abrir"
                      +"\n[c] Cerrar"
                      +"\n[q] salir programa"
                      +"\n>");

        return;
    }

    if(obtupas==true && comando=="q"){
        this->setText("QNX5>");
    }

    if(obturador1==true && comando=="q"){
        this->setText("QNX5>");
    }

    if(obturador1==true && comando=="a"){
        this->setText(this->toPlainText()+"\n"+"Programa para control del Obturador"
                      +"\nEmptying buffer..."
                      +"\nPower is on"
                      +"\n******MENU******"
                      +"\n[a] Abrir"
                      +"\n[c] Cerrar"
                      +"\n[q] salir programa"
                      +"\n>");
        emit ejecutarComando("abrir");
    }

    if(obturador1==true && comando=="c"){
        this->setText(this->toPlainText()+"\n"+"Programa para control del Obturador"
                      +"\nEmptying buffer..."
                      +"\nPower is on"
                      +"\n******MENU******"
                      +"\n[a] Abrir"
                      +"\n[c] Cerrar"
                      +"\n[q] salir programa"
                      +"\n>");
        emit ejecutarComando("cerrar");
    }

    if(comandoValido==true){
        bash.closeWriteChannel();

        if(!bash.waitForFinished()){
            QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

        }

        if(bash.exitCode()!=0){
            //qDebug()<< bash.readAllStandardError();
            QString error; //Mensaje de error que lanza el sistema

            error.append(bash.readAllStandardError().data()); //Obtengo el mensaje del proceso

            QStringList mensajes; //Variable para separar los datos que necesito para mostrar

            mensajes << error.split(":");
            this->setText(this->toPlainText()+"\n"+error+"usuario>");
        }
        else{
            qDebug()<< bash.readAllStandardOutput();
        }
    }
    else if (comando=="exit"){

    }

    else if(qnx1==true || qnx2==true || qnx3==true || qnx4==true || qnx5==true || qnx6==true){

    }
    else
        this->setText(this->toPlainText()+"\n"+"Orden no encontrada"+"\n"+"usuario>");


    bash.close();
}

void miTextArea::asignarError1(bool e)
{
    error1 = e;
}

void miTextArea::asignarError2(bool e)
{
    error2 = e;
}

void miTextArea::asignarError3(bool e)
{
    error3 = e;
}

void miTextArea::asignarError4(bool e)
{
    error4 = e;
}

void miTextArea::asignarError5(bool e)
{
    error5 = e;
}

void miTextArea::asignarError6(bool e)
{
    error6 = e;
}
