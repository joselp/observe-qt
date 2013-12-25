#ifndef SLAYALL_H
#define SLAYALL_H

#include <QWidget>

namespace Ui {
class SlayAll;
}

class SlayAll : public QWidget
{
    Q_OBJECT
    
public:
    explicit SlayAll(QWidget *parent = 0);
    ~SlayAll();
    
private:
    Ui::SlayAll *ui;
};

#endif // SLAYALL_H
