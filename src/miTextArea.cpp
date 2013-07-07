#include"headers/miTextArea.h"

miTextArea::miTextArea(QWidget *parent):
    QTextEdit(parent)
{
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
        QString aux = this->toPlainText();
        aux.truncate(this->toPlainText().count()-1);
        this->setText(aux);
    }

    //Tecla Enter
    else if(e->key()==16777220){
        QStringList listaComandos; //Variable que almacerá el comando a realizar el Qprocess
        listaComandos<<this->toPlainText().split(">");
        qDebug()<<listaComandos.value(1);

        ejecutar(listaComandos.last());
    }

    else
        this->setText(this->toPlainText()+e->text());

    //Posiciono el cursor al final de la cadena de caracteres
    QTextCursor cursor(this->textCursor());
    cursor.movePosition(QTextCursor::End);
    this->setTextCursor(cursor);
}

void miTextArea::ejecutar(QString comando)
{

    bool comandoValido=false; //Me permite saber si es un comando por los reconocidos en el simulador

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

        bash.write((const char *)aux.toStdString().c_str());
        comandoValido=true;

    }

    QRegExp rx3("([p][e][r][l][\\s][o][b][s][e][r][v][a][c][i][o][n][_][d][i][r][e][c][t][a][_][v][7][.][p][l]|[p][e][r][l][\\s][o][b][s][e][r][v][a][c][i][o][n][_][d][i][r][e][c][t][a][_][v][7][.][p][l][\\s][\\w]*[\\s][\\w]*[\\s][\\w]*[\\s][\\w]*)");

    if(rx3.exactMatch(comando)){

        QString aux;
        aux.append(comando);

        bash.write((const char *)aux.toStdString().c_str());
        comandoValido=true;

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
    else
        this->setText(this->toPlainText()+"\n"+"Orden no encontrada"+"\n"+"usuario>");

    bash.close();
}

