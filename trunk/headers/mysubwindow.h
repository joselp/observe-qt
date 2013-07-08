#ifndef MYSUBWINDOW_H
#define MYSUBWINDOW_H

#include <QtGui>
#include <QCloseEvent>
#include <QMdiSubWindow>

class MySubWindow : public QMdiSubWindow
{
    Q_OBJECT
public:
    MySubWindow(QWidget *parent = 0);

    void closeEvent(QCloseEvent *);

signals:
    void mousePressed(int x, int y);

};



#endif // MYSUBWINDOW_H
