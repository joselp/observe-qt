#ifndef SHUTDALL_H
#define SHUTDALL_H

#include <QWidget>

namespace Ui {
class ShutdAll;
}

class ShutdAll : public QWidget
{
    Q_OBJECT
    
public:
    explicit ShutdAll(QWidget *parent = 0);
    ~ShutdAll();
    
private:
    Ui::ShutdAll *ui;
};

#endif // SHUTDALL_H
