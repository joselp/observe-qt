#ifndef PROCESOFITS_H
#define PROCESOFITS_H

#include <QtGui>
#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QGenericMatrix>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimerEvent>
#include <string>
#include <QString>
#include "stdio.h"
#include "iostream"
#include "stdlib.h"
//#include <fitsio.h> //Libreria para cargar imagenes fits
#include <cfitsio/fitsio.h>

class ProcesoFits : public QWidget
{
    Q_OBJECT
public:
    explicit ProcesoFits(QWidget *parent = 0);
    void leerFits();
    int scalar8bit(int valor);
    int valorMatriz(int x,int y); //Devuelve el valor del pixel que contiene la matriz de la imagen
    void printerror(int );
    void dibujarLinea();
    void barraVisualizador(QScrollArea *scrollArea);
    void resetProceso(); //Funcion que reinicia el proceso de lectura del archivo fits para comenzar la lectura de un nuevo archivo fits

    //Cargar Pruebas
    void pruebaDriftScan();
    void pruebaDriftScanModificado();
    void pruebaGuiada();
    void pruebaDarkGuiada();
    void pruebaDarkDriftScan();
    void pruebaDarkDriftScanNublado();
    void pruebaFlatsGuiada();
    void pruebaFlatsDriftScan();
    void pruebaBias();
    void pruebaObturador();

    void guardarImagenes();

    //Getters
    QString getQnx();

    //Setters
    void setTotalLineas(int total);
    void setPrueba(QString); //Asigna la prueba que se realizara
    void setQnx(QString);
    void setCcd(QString);
    void setLineaActual(int);
    void setCondicionesCielo(QString condiciones);
    void setObturador(bool o);

protected:
    /*!
     Esta función crea el espacio donde se mostrara la imagen digital en la interfaz gráfica.
   */
    void paintEvent(QPaintEvent *event);
   /*!
    Esta función es llamada por la función repaint() y es la que efectivamente pinta la línea de la imagen digital
    a través de la interfaz gráfica.
  */
    void timerEvent(QTimerEvent *);

private:

    QImage *image;
    QImage *image2;
    fitsfile *fptr1;                                /*!< Puntero que se utiliza para la creación y escritura en un archivo Fits. */
    fitsfile *fptr2;                                /*!< Puntero que se utiliza para la creación y escritura en un archivo Fits. */
    int status;                                     /*!< Se utiliza como parámetro en algunas funciones para el manejo de archivos Fits. Almacena un valor entero correspondiente al estado (de exito o fracaso) de haber utilizado la función. */
    long fpixel;                                    /*!< Almacena la posición del primer píxel (en la matriz de datos del Fits) que se escribirá. Ejem: el primer píxel de la primera fila está en la posición 1, el primer píxel de la segunda fila está en la posición 2049, etc.*/
    long nelements;                                 /*!< Almacena la cantidad de píxeles de la nueva imagen, es decir: 512 * 2048. Se utiliza como parámetro en algunas funciones para el manejo de archivos Fits.*/
    long naxis;                                     /*!< Almacena la cantidad de ejes de la imagen. Obviamente para una imagen bidimensional su valor es 2. Se utiliza como parámetro en algunas funciones para el manejo de archivos Fits.*/
    long naxes[2];
    QGenericMatrix<2048, 2048, ushort> matriz; //<columnas, filas, tipo>

    //ushort line[2048];
    int line;
    QString fileLine, value;

    int lineas; //Total de lineas que se han leido
    int totalLineas; //Total de lineas que se deben leer segun Adquisicion de datos.
    int lineaActual; //Linea que va procesando el simulador.
    int lineaActualAux; //Variable que se usa para mantener el valor original de la variable lineaActual
    int Numeroimagen; //Numero de imagenes que se han leido
    int tam; //Tamaño que va creciendo target y source. (Los rectangulos donde se muestra la imagen)

    QPainter *painter;

    QRect target;                                  /*!< Se utiliza como parámetro en la función drawImage dentro del método paintEvent(). Define un rectángulo en un plano.  */
    QRect source;                                  /*!< Se utiliza como parámetro en la función drawImage dentro del método paintEvent(). Define un rectángulo en un plano.  */

    QTimer *timer;

    //para la imagen
    QLabel *imageLabel;
    double scaleFactor;
    int multiplo;
    QString ccd; //Indica el ccd en que se encuentra observando
    QString qnx; //Indica el Qnx que se encuentra observando
    QString condicionesCielo; //Condiciones en que se encuentra el cielo(Nublado-Despeado, etc)

    QVBoxLayout *vlayout;
    QScrollArea *scrollAux;

    bool primera; //Permite saber si es la primera imagen que se muestra
    bool cambio; //Permite saber si se cambia de ccd o qnx
    bool finalizado; //Permite saber si se finalizo la observacion
    int initTimer; //Permite saber si se debe iniciar el timer
    QString prueba;
    bool obturador; //Para saber si el obturador esta abierto o cerrado

    QVector<QString> imagenesObservacion;

    QProcess *bash; //Variable para ejecutar comando en un terminal.
    QString auxComando; //Variable que contendra el comando a ser  ejecutado en un terminal.

signals:

public slots:

};

#endif // PROCESOFITS_H
