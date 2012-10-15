#ifndef QCOMBOBOXEVENT_H
#define QCOMBOBOXEVENT_H

#include <QWidget>
#include <QComboBox>
#include <QDebug>
#include <QMouseEvent>

class QComboBoxEvent : public QComboBox
{
    Q_OBJECT
public:
    explicit QComboBoxEvent(QComboBox *parent = 0);

protected:
     void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // QCOMBOBOXEVENT_H
