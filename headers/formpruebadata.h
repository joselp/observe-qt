#ifndef FORMPRUEBADATA_H
#define FORMPRUEBADATA_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>

namespace Ui {
class FormPruebaData;
}

class FormPruebaData : public QWidget
{
    Q_OBJECT
    
public:
    explicit FormPruebaData(QWidget *parent = 0);

    //Setters
    void setCondiciones(QString s);
    void setFiltro1(QString s);
    void setFiltro2(QString s);
    void setFiltro3(QString s);
    void setFiltro4(QString s);
    void setDeclinacion(QString s);
    void setAHorario(QString s);
    void setObservacion(QString s);
    void setDuracion(QString s);
    void setInstrumento(QString s);
    void setProyecto(QString s);
    void setObturador(QString s);
    void limpiarCampos();

    //Getters
    QLabel *getObturador();

    ~FormPruebaData();
    
private:
    Ui::FormPruebaData *ui;
};

#endif // FORMPRUEBADATA_H
