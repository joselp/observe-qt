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


    qDebug()<<e->key();

    //Tecla borrar: 16777219
    if(e->key()==16777219){
        QString aux = this->toPlainText();
        aux.truncate(this->toPlainText().count()-1);
        this->setText(aux);
    }

    //Tecla Enter
    else if(e->key()==16777220){
        qDebug()<<this->toPlainText().split(">");
    }

    else
        this->setText(this->toPlainText()+e->text());

    //Posiciono el cursor al final de la cadena de caracteres
    QTextCursor cursor(this->textCursor());
    cursor.movePosition(QTextCursor::End);
    this->setTextCursor(cursor);
}

