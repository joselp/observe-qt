#ifndef CABECERASFITS_H
#define CABECERASFITS_H

#include <QWidget>

namespace Ui {
    class CabecerasFits;
}

class CabecerasFits : public QWidget
{
    Q_OBJECT

public:
    explicit CabecerasFits(QWidget *parent = 0);
    ~CabecerasFits();

private:
    Ui::CabecerasFits *ui;
};

#endif // CABECERASFITS_H
