#ifndef SUMMARY_H
#define SUMMARY_H

#include <QWidget>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <iostream>

namespace Ui {
class Summary;
}

class Summary : public QWidget
{
    Q_OBJECT
    
public:
    explicit Summary(QWidget *parent = 0);
    ~Summary();

public slots:
    void slotEjecutar();

    
private:   
    Ui::Summary *ui;
    QString comando;
    QProcess *bash; //Variable para ejecutar comando en un terminal.
};

#endif // SUMMARY_H
