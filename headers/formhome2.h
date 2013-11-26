#ifndef FORMHOME2_H
#define FORMHOME2_H

#include <QWidget>

namespace Ui {
class FormHome2;
}

class FormHome2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormHome2(QWidget *parent = 0);
    ~FormHome2();
    
private:
    Ui::FormHome2 *ui;
};

#endif // FORMHOME2_H
