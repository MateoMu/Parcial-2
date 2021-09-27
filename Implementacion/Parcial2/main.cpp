#include <iostream>
#include <QImage>
#include <vector>
#include <QColor>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string filename = "../Parcial2/imagenes/brasil.jpg";
    QImage imagen(filename.c_str());
    fstream file;
    file.open("muestreo.txt");
    ofstream f("muestreo.txt");
    f<<"holi"<<endl;

    int limX=0,limY=0;
    int R=0, G=0, B=0;
    //submuestreo la imagen original en una relacion 4:4 a 1 pixel, es decir
    //promedio la intensidad RGB de 16 pixeles en  1

     while( limY< imagen.height()){
     int plusR=0,plusG=0,plusB=0,cont=0;
        for (int indy=limY; indy<limY+4; ++indy){
            for(int indx=limX; indx<limX+4 ; ++indx){
                plusR= plusR + imagen.pixelColor(indx,indy).red();
                plusG = plusG + imagen.pixelColor(indx,indy).green();
                plusB= plusB + imagen.pixelColor(indx,indy).blue();
                    cont+=1;
            }
        }

        R= (plusR / cont);
        G= (plusG / cont);
        B= (plusB /cont);

        QColor **mat=NULL;

        mat = new QColor * [(imagen.height()/4)]; //se crea matriz para llenarla con los RGB
        for (int fil = 0; fil<(imagen.width())/4; fil++){
            mat[fil] = new QColor [(imagen.width())/4];
        }

        //for (int i=0; i<fil) {

        //}

        limX+=4;
        if(limX>=imagen.width()){
            limX=0;
            limY+=4;
        }

     }

    return 0;
}
