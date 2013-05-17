#ifndef MYSCROLLAREA_H
#define MYSCROLLAREA_H

#include <QMouseEvent>
#include <QScrollArea>
#include <QtGui>

class MyScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    MyScrollArea(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *event);

signals:
    void mousePressed(int x, int y);

};

#endif // MYSCROLLAREA_H
