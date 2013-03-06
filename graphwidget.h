#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QMouseEvent>

class GraphWidget : public QGraphicsView
{

    Q_OBJECT
public:
    GraphWidget(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *event);

signals:
    void mousePressed(int x, int y);


};

#endif // GRAPHWIDGET_H
