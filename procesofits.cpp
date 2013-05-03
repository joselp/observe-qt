#include "procesofits.h"
#include <QApplication>
#include <math.h>

ProcesoFits::ProcesoFits(QWidget *parent) :
    QWidget(parent)
{


    resize(2048,512);
    //image = new QImage(2048, totalLineas, QImage::Format_ARGB32_Premultiplied);
    target.setRect(0, 0, 2048, 1);
    source.setRect(0, 0, 2048, 1);

    lineas = 0;
    line = 0;
    primera = true;
    multiplo=2047;

}

//ProcesoFits::~ProcesoFits()
//{
//    delete ui;
//}

void ProcesoFits::leerFits()
{

    qDebug()<<"entro";

    qApp->processEvents();

    fitsfile *fptr;
    ushort nullval, pline[2049];
    int status = 0, anynull=0;
    long fpixel = 1;
    ushort value1 = 32768;
    ushort value2 = 1;
    int nkeys, keypos;
    char keyname1[] = "BZERO";
    char keyname2[] = "BSCALE";
    char comment1[] = "offset data range to that of unsigned short";
    char comment2[] = "default scaling factor";
    char card[FLEN_CARD];   /* standard string lengths defined in fitsioc.h */

    qDebug()<<multiplo;

    if(primera==true){
        qDebug()<<"ENTRE";
        fileLine = "obs401.qnx3.ccd2.n110.fits";
        image = new QImage(2048, totalLineas, QImage::Format_ARGB32_Premultiplied);
        startTimer(30);
    }

    else{

        fileLine = "obs401.qnx3.ccd2.n110.fits";
        qDebug()<<(char *)fileLine.toStdString().c_str();
    }

    //char card[FLEN_CARD];   /* standard string lengths defined in fitsioc.h */

    if (fits_open_file(&fptr, (char *)fileLine.toStdString().c_str(), READWRITE, &status)){
        printerror(status);
    }

    /*Se cambian los valores de la cabecera BZERO y BSCALE a valores ushort para
       que al leer la linea del fits, la lea como ushort y no como float.*/

    if (fits_update_key(fptr, TUSHORT, keyname1, &value1, comment1, &status))
        printerror(status);

    if (fits_update_key(fptr, TUSHORT, keyname2, &value2, comment2, &status))
        printerror(status);

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

    //qApp->processEvents();
    for (int i=0; i<2048; i++)
    {

        if ( fits_read_img(fptr, TUSHORT, fpixel, 2048, &nullval, pline, &anynull, &status) )
            printerror( status );

        for (int j=0; j<2048; j++){
            matriz(j, 2047-i) = pline[j];

            image->setPixel(j,multiplo-i, qRgb(scalar8bit(pline[j]),scalar8bit(pline[j]),scalar8bit(pline[j])));

        }

        fpixel = fpixel + 2100;
    }

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
    qApp->processEvents();

    source.setHeight(line);
    target.setHeight(line);
    resize(2048,line+1);

}

void ProcesoFits::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(source, *image, target,Qt::PreferDither);
}

void ProcesoFits::timerEvent(QTimerEvent *e)
{
    //        source.setHeight(line);
    //        target.setHeight(line);
    //        line=line+1;


    if ( line+1>=totalLineas ){
        killTimer(e->timerId());
        qDebug()<<line;
        qDebug()<<"termino";
    }


    //qApp->processEvents();
    //qDebug()<< (line+1)%2048;
    else{
        if((line+1)%2048==0){
            multiplo=multiplo+2047;
            primera=false;
            qDebug()<<"Segunda Imagen ";
            //source.moveTop(1);

            leerFits();

        }

        if(line>512){
            resize(2048,line+1);
            //source.moveTop(line+1-512);
            scrollAux->verticalScrollBar()->setValue(line);
        }

        //        if(line<512){
        //            source.setHeight(line);
        //            target.setHeight(line);
        //        }
        //        else{
        //            source.moveTop(line+1-512);
        //        }

        //        if(line==2048){
        //            source.moveTop(1);
        //        }

        source.setHeight(line);
        target.setHeight(line);

        line=line+1;



        //qDebug()<<line;

        update();

    }
    //repaint(); /* NO OLVIDAR */

}

int ProcesoFits::valorMatriz(int x, int y)
{
    if(line < y)
        return 0;

    else{
        return matriz(x,y);
    }
}

void ProcesoFits::barraVisualizador(QScrollArea *scrollArea)
{
    scrollAux = new QScrollArea;
    scrollAux = scrollArea;
}

void ProcesoFits::setTotalLineas(int total)
{
    totalLineas = total;
}

void ProcesoFits::resetProceso()
{
    target.setRect(0, 0, 2048, 1);
    source.setRect(0, 0, 2048, 1);
    line = 0;
    multiplo = 2047;
    primera = false;
    scrollAux->verticalScrollBar()->setValue(0);
    resize(2048,512);
    //delete(image);
    leerFits();
}


