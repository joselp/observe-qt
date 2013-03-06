#ifndef PANELADMINISTRATIVO_H
#define PANELADMINISTRATIVO_H

#include <QWidget>

namespace Ui {
    class PanelAdministrativo;
}

class PanelAdministrativo : public QWidget
{
    Q_OBJECT

public:
    explicit PanelAdministrativo(QWidget *parent = 0);
    ~PanelAdministrativo();

private:
    Ui::PanelAdministrativo *ui;
};

#endif // PANELADMINISTRATIVO_H
