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
        qDebug()<<aux2.compare(aux2.size()-5,aux2.size(),"qnx1>");
        qDebug()<<aux2.compare(aux2.size()-5,aux2.size(),"qnx2>");
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx1>")!=0) && qnx1==true)
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
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx2>")!=0) && qnx2==true)
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
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx3>")!=0) && qnx3==true)
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
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx4>")!=0) && qnx4==true)
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
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx5>")!=0) && qnx5==true)
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
           if(aux2.size()!=5 && (aux2.compare(aux2.size()-5,aux2.size(),"qnx6>")!=0) && qnx6==true)
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
        this->setText(this->toPlainText()+"\n"+"qnx1>");
        qnx1=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx1"+"\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx2"){
        if(error2 == false){
        this->setText(this->toPlainText()+"\n"+"qnx2>");
        qnx2=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx2"+"\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx3"){
        if(error3 == false){
        this->setText(this->toPlainText()+"\n"+"qnx3>");
        qnx3=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx3"+"\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx4"){
        if(error4 == false){
        this->setText(this->toPlainText()+"\n"+"qnx4>");
        qnx4=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx4"+"\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx5"){
        if(error5 == false){
        this->setText(this->toPlainText()+"\n"+"qnx5>");
        qnx5=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx5"+"\n"+"usuario>");
        return;
    }

    if(comando=="rlogin qnx6"){
        if(error6 == false){
        this->setText(this->toPlainText()+"\n"+"qnx6>");
        qnx6=true;
        }
        else
            this->setText(this->toPlainText()+"\n"+"usuario> Error de conexion con qnx6"+"\n"+"usuario>");
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
