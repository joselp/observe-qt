#ifndef RECUPERARPASSWORD_H
#define RECUPERARPASSWORD_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class RecuperarPassWord;
}

class RecuperarPassWord : public QWidget
{
    Q_OBJECT
    
public:
    explicit RecuperarPassWord(QWidget *parent = 0);
    ~RecuperarPassWord();
    
public slots:
    void slotRecuperar();

private:
    Ui::RecuperarPassWord *ui;
};

#endif // RECUPERARPASSWORD_H
