#include "headers/mybuttonicon.h"

myButtonIcon::myButtonIcon(QWidget *parent):
    QPushButton(parent)
{
}

void myButtonIcon::mouseDoubleClickEvent(QMouseEvent *e)
{
    emit doubleclick();
}
