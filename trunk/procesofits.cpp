#include "procesofits.h"
#include <QApplication>
#include <math.h>

ProcesoFits::ProcesoFits(QWidget *parent) :
    QWidget(parent)
{
    resize(2048,2048);
    image = new QImage(2048, 2100, QImage::Format_ARGB32_Premultiplied);

    target.setRect(0, 0, 2048, 2048);
    source.setRect(0, 0, 2048, 2048);

    lineas = 0;
    line = 0;


}

//ProcesoFits::~ProcesoFits()
//{
//    delete ui;
//}

void ProcesoFits::leerFits()
{
    startTimer(5);
    fitsfile *fptr;
    ushort nullval, pline[2049];
    int status = 0, anynull=0;
    long fpixel = 1;
    ushort value1 = 32768;
    ushort value2 = 1;
    char keyname1[] = "BZERO";
    char keyname2[] = "BSCALE";
    char comment1[] = "offset data range to that of unsigned short";
    char comment2[] = "default scaling factor";
    char filename[] = "obs401.qnx3.ccd2.n110.fits";

    char card[FLEN_CARD];   /* standard string lengths defined in fitsioc.h */

    if (fits_open_file(&fptr, filename, READWRITE, &status)){
        printerror(status);
    }

   /*Se cambian los valores de la cabecera BZERO y BSCALE a valores ushort para
       que al leer la linea del fits, la lea como ushort y no como float.*/

    if (fits_update_key(fptr, TUSHORT, keyname1, &value1, comment1, &status))
       printerror(status);

    if (fits_update_key(fptr, TUSHORT, keyname2, &value2, comment2, &status))
         printerror(status);

    int nkeys, keypos;

    /* get no. of keywords */
    if (fits_get_hdrpos(fptr, &nkeys, &keypos, &status) )
        printerror( status );

    qDebug()<<nkeys;

    //Imprime la cabecera del archivo fits
    qDebug()<<"Header listing for HDU"<< nkeys;
    for (int i = 1; i <= nkeys; i++)  {
        if ( fits_read_record(fptr, i, card, &status) )
             printerror( status );

        qDebug()<<card; /* print the keyword card */
    }

    for (int i=0; i<2048; i++)
    {

        if ( fits_read_img(fptr, TUSHORT, fpixel, 2048, &nullval, pline, &anynull, &status) )
                   printerror( status );

        for (int j=0; j<2048; j++){
            //matrix(i, j) = pline[j];

            image->setPixel(j,2048-i, qRgb(scalar8bit(pline[j]),scalar8bit(pline[j]),scalar8bit(pline[j])));
            //image->setPixel(i,j,qGray(matrix(i, j)));

        }

        fpixel = fpixel + 2100;
    }
    qDebug()<< matrix(400,400);
    qDebug()<<qGray(matrix(400,400));
    qDebug()<<image->pixel(400,400);

}

int ProcesoFits::scalar8bit(int valor)
{
    if( (valor*255.0)/65535.0 < 0.0 ){
        return 0;
    }

    else if( (valor*255.0)/65535.0 > 255 ){
        return 255;
    }
    else{
        return ( (valor*255.0)/65535.0 );
    }
}

void ProcesoFits::printerror(int)
{
    if (status)
    {
      fits_report_error(stderr, status); /* print error report */
      exit( status );    /* terminate the program, returning error status */
    }
}

void ProcesoFits::dibujarLinea()
{
    source.setHeight(line);
    target.setHeight(line);
    qApp->processEvents();
}

void ProcesoFits::paintEvent(QPaintEvent *event)
{
    QPainter painter (this);
    painter.drawImage(source, *image, target,Qt::PreferDither);
}

void ProcesoFits::timerEvent(QTimerEvent *e)
{
    source.setHeight(line);
    target.setHeight(line);
    line=line+1;

    if ( line==2048 )
           killTimer(e->timerId());

        repaint(); /* NO OLVIDAR */
}


