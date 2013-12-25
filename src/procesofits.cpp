#include "headers/procesofits.h"
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
    cambio = false;
    finalizado = false;
    initTimer = 0;
    obturador = false;

    ccd = "ccd1";
    qnx = "qnx1";
    Numeroimagen = 1;
    tam = 1;

    //Inicio una consola
    bash = new QProcess(this);
    bash->setWorkingDirectory("../observe-qt/");
    qDebug()<<bash->workingDirectory()<<" este es el directorio"<<endl;
    bash->start("bash");

    if(!bash->waitForStarted()){
        QMessageBox::critical(this,"ERROR","ERROR: bash no responde");

    }

}

//ProcesoFits::~ProcesoFits()
//{
//    delete ui;
//}

void ProcesoFits::leerFits()
{

    qDebug()<<"entro";

    if(finalizado==false){

        qApp->processEvents();

        fitsfile *fptr;
        ushort nullval, pline[2049];
        int status = 0, anynull=0;
        long fpixel = 1; //Primer pixel perteneciente a la imagen (archivo fits)
        ushort value1 = 32768;
        ushort value2 = 1;
        int nkeys, keypos;
        char keyname1[] = "BZERO";
        char keyname2[] = "BSCALE";
        char comment1[] = "offset data range to that of unsigned short";
        char comment2[] = "default scaling factor";
        char card[FLEN_CARD];   /* standard string lengths defined in fitsioc.h */
        fileLine.clear();

        //Se cargan la secuencia de imagenes para la prueba DriftScanBuena


        if(prueba=="DriftScan" && condicionesCielo=="Despejado" && obturador==true){
            pruebaDriftScan();
        }
        if(prueba=="DarkDriftScan" || obturador==false){
            pruebaDarkDriftScanNublado();
        }

        qDebug()<<imagenesObservacion.value(0);

        //imagenesObservacion[0]="obs401.qnx3.ccd2.n110.fits";

        if(primera==true){

            multiplo=2047-lineaActual;

            if(initTimer==0)
                line = lineaActual;

            if(prueba=="DriftScan" && obturador==true)
                fileLine = "../observe-qt/pruebas/"+prueba+"/"+condicionesCielo+"/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1);
            if(prueba=="DarkDriftScan" || obturador==false)
                fileLine = "../observe-qt/pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1);

          image = new QImage(2048, totalLineas, QImage::Format_ARGB32_Premultiplied);

            qDebug()<<fileLine;

            if(cambio==true){
                lineaActual=lineas;
                //line = lineaActual;
                multiplo=2047-lineaActual;
                cambio=false;
            }

            if(lineaActual>=2048)
                lineaActual = 0; //Ecuacion o variable que me determine el numero de imagen en la que se encuentra la observacion

            lineaActualAux = lineaActual;

            if(primera==true && initTimer==0)
                startTimer(30);

        }

        else{
            if(prueba=="DriftScan" && obturador==true)
                fileLine = "../observe-qt/pruebas/"+prueba+"/"+condicionesCielo+"/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1);
            if(prueba=="DarkDriftScan" || obturador==false)
                fileLine = "../observe-qt/pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1);

            qDebug()<<(char *)fileLine.toStdString().c_str();
            lineaActual=0;
        }

        //char card[FLEN_CARD];   /* standard string lengths defined in fitsioc.h */

        if(prueba=="DriftScan" && obturador==true){
            if (fits_open_file(&fptr, (char *)fileLine.toStdString().c_str(), READWRITE, &status)){
                printerror(status);

            }
        }
        if(prueba=="DarkDriftScan" || obturador==false){
            if (fits_open_file(&fptr, (char *)fileLine.toStdString().c_str(), READONLY, &status)){
                printerror(status);

            }
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
        int comenzar=0; //Variable que me permite donde comenzara a leerse el archivo fits

        if(primera==true)
            comenzar=lineaActual;
        else
            comenzar=lineas;



        for (int i=comenzar; i<2048; i++)
        {

            if ( fits_read_img(fptr, TUSHORT, fpixel, 2048, &nullval, pline, &anynull, &status) )
                printerror( status );

            for (int j=0; j<2048; j++){
                matriz(j, 2047-i) = pline[j];

                image->setPixel(j,(multiplo-i)+lineaActual, qRgb(scalar8bit(pline[j]),scalar8bit(pline[j]),scalar8bit(pline[j])));

                //qDebug()<<"Lineas: "<<lineaActual<<" aux: "<<aux<<" j: " <<j;
            }

            fpixel = fpixel + 2100;
        }

    }
    if(Numeroimagen==10)
        Numeroimagen=1;

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

    if ( line+1 >= (totalLineas) ){

        qDebug()<<"Finalizar al "<<totalLineas;
        killTimer(e->timerId());
        qDebug()<<"termino";
        finalizado=true;
    }


    //qApp->processEvents();
    //qDebug()<< (line+1)%2048;
    else{

        //Para pasar de la primera a la segunda imagen
        if(primera==true){
            if((line+1)%(2048)==0){
                multiplo=(multiplo+2047);
                qDebug()<<"Multiplo "<<multiplo;
                primera=false;
                qDebug()<<"Segunda Imagen ";
                //source.moveTop(1);
                lineas=0;

                guardarImagenes();
                Numeroimagen++;
                leerFits();
            }
        }
        //Siguientes imagenes
        else{
            if((line+1)%(2048)==0){
                multiplo=(multiplo+2047);
                qDebug()<<"Multiplo "<<multiplo;
                qDebug()<<"Siguiente Imagen ";
                //source.moveTop(1);
                lineas=0;
                guardarImagenes();
                Numeroimagen++;
                leerFits();
            }
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


        if(tam>440){
            resize(2048,tam);
            //source.moveTop(line+1-512);
            scrollAux->verticalScrollBar()->setValue(tam);
        }

        source.setHeight(tam);
        target.setHeight(tam);

        line=line+1;
        lineas++;
        tam++;

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
    //line = 0;
    tam=0;
    //multiplo = 2047;
    primera = true;
    lineaActual = 0;
    scrollAux->verticalScrollBar()->setValue(0);
    resize(2048,512);
    //delete(image);
    cambio=true;
    initTimer++;
    leerFits();
}

void ProcesoFits::pruebaDriftScan()
{
    imagenesObservacion.clear();

    if(qnx=="qnx1" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx1" && ccd=="ccd2"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx1" && ccd=="ccd3"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx1" && ccd=="ccd4"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx2" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx2" && ccd=="ccd2"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx2" && ccd=="ccd3"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx2" && ccd=="ccd4"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx3" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx3" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx3" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx3" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx4" && ccd=="ccd1"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx4" && ccd=="ccd2"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx4" && ccd=="ccd3"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

    if(qnx=="qnx4" && ccd=="ccd4"){
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
        imagenesObservacion.append("obs401.qnx3.ccd2.n110.fits");
    }

}

void ProcesoFits::setPrueba(QString p)
{
    prueba=p;
}

void ProcesoFits::pruebaDarkDriftScanNublado()
{

    imagenesObservacion.clear();

    if(qnx=="qnx1" && ccd=="ccd1"){

        imagenesObservacion.append("obs205.qnx1.ccd1.n1.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n2.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n3.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n4.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n5.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n6.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n7.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n8.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n9.fits");
        imagenesObservacion.append("obs205.qnx1.ccd1.n10.fits");

    }

    if(qnx=="qnx1" && ccd=="ccd2"){
        imagenesObservacion.append("obs205.qnx1.ccd2.n1.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n2.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n3.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n4.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n5.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n6.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n7.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n8.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n9.fits");
        imagenesObservacion.append("obs205.qnx1.ccd2.n10.fits");

    }

    if(qnx=="qnx1" && ccd=="ccd3"){
        imagenesObservacion.append("obs205.qnx1.ccd3.n1.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n2.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n3.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n4.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n5.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n6.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n7.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n8.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n9.fits");
        imagenesObservacion.append("obs205.qnx1.ccd3.n10.fits");

    }

    if(qnx=="qnx1" && ccd=="ccd4"){
        imagenesObservacion.append("obs205.qnx1.ccd4.n1.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n2.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n3.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n4.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n5.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n6.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n7.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n8.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n9.fits");
        imagenesObservacion.append("obs205.qnx1.ccd4.n10.fits");
    }

}

void ProcesoFits::setQnx(QString q)
{
    qnx = q;
}

void ProcesoFits::setCcd(QString c)
{
    ccd = c;
}

void ProcesoFits::setLineaActual(int l)
{
    lineaActual = l;
}

void ProcesoFits::setCondicionesCielo(QString condiciones)
{
    condicionesCielo=condiciones;
}

void ProcesoFits::setObturador(bool o)
{
    obturador = o;
}

QString ProcesoFits::getQnx()
{
    return qnx;
}

void ProcesoFits::guardarImagenes()
{
    auxComando.clear();

    if(prueba=="DarkDriftScan" || obturador==false){
        //pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1)
        auxComando.append("cp pruebas/DarkDriftScan/qnx1/ccd1/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
        qDebug()<<auxComando;
    }
    else{
    auxComando.append("cp pruebas/"+prueba+"/"+condicionesCielo+"/qnx1/"+"ccd1/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    qDebug()<<"AQUI222";
    }

    bash->write((const char *)auxComando.toStdString().c_str());
    auxComando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    bash->start("bash");
    if(prueba=="DarkDriftScan" || obturador==false){
        //pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1)
        auxComando.append("cp pruebas/DarkDriftScan/qnx1/ccd1/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    else{
    auxComando.append("cp pruebas/"+prueba+"/"+condicionesCielo+"/qnx1/"+"ccd2/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    bash->write((const char *)auxComando.toStdString().c_str());
    auxComando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    bash->start("bash");
    if(prueba=="DarkDriftScan" || obturador==false){
        //pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1)
        auxComando.append("cp pruebas/DarkDriftScan/qnx1/ccd1/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    else{
    auxComando.append("cp pruebas/"+prueba+"/"+condicionesCielo+"/qnx1/"+"ccd3/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    bash->write((const char *)auxComando.toStdString().c_str());
    auxComando.clear();
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }

    bash->start("bash");
    if(prueba=="DarkDriftScan" || obturador==false){
        //pruebas/DarkDriftScan/"+qnx+"/"+ccd+"/"+imagenesObservacion.value(Numeroimagen-1)
        auxComando.append("cp pruebas/DarkDriftScan/qnx1/ccd1/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    else{
    auxComando.append("cp pruebas/"+prueba+"/"+condicionesCielo+"/qnx1/"+"ccd4/"+imagenesObservacion.value(Numeroimagen-1)+" "+"observaciones/images1/"+imagenesObservacion.value(Numeroimagen-1));
    }
    bash->write((const char *)auxComando.toStdString().c_str());
    bash->closeWriteChannel();
    if(!bash->waitForFinished()){
        QMessageBox::critical(this,"ERROR","ERROR: comandos consumiendo recursos en sistemas ");

    }
}

void ProcesoFits::pruebaObturador()
{
    imagenesObservacion.clear();

    imagenesObservacion.append("obs205.qnx1.ccd1.n1.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n2.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n3.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n4.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n5.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n6.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n7.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n8.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n9.fits");
    imagenesObservacion.append("obs205.qnx1.ccd1.n10.fits");
}

