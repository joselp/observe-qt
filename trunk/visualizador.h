#ifndef VISUALIZADOR_H
#define VISUALIZADOR_H

#include <QWidget>
#include "procesofits.h"
#include <QGraphicsView>

namespace Ui {
    class Visualizador;
}

class Visualizador : public QWidget
{
    Q_OBJECT

public:
    explicit Visualizador(QWidget *parent = 0);
    void initGui();
    void initLectura();
    ~Visualizador();

private slots:
    void zoomIn();
    void zoomOut();
    void zoomNormal();

private:

    ProcesoFits *procesoFits;
    QGraphicsScene * scene;

    Ui::Visualizador *ui;
};

#endif // VISUALIZADOR_H
