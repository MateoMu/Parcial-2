#include <iostream>
#include <QImage>
#include <vector>
#include <QColor>
#include <string>
#include <fstream>
#include <QRgb>

using namespace std;
void submuestreo(string filename);

int main()
{
    string filename = "../Parcial2/imagenes/brasil.jpg";
    /*QImage imagen(filename.c_str());
    fstream file;
    file.open("muestreo.txt");
    ofstream f("muestreo.txt");
    f<<"holi"<<endl;

    int limX=0,limY=0,iter=0, iter2=0;
    short int R=0, G=0, B=0;
    //submuestreo la imagen original en una relacion 4:4 a 1 pixel, es decir
    //promedio la intensidad RGB de 16 pixeles en  1

    QRgb **mat=NULL;

    mat = new QRgb*[(imagen.height()/4)]; //se crea matriz y espacio en la memoria para llenarla con los RGB
    for (int fil = 0; fil<(imagen.height()/4); ++fil){
        mat[fil] = new QRgb [(imagen.width()/4)];
    }

     while( limY< imagen.height()){
     int plusR=0,plusG=0,plusB=0,cont=0;
        for (int indy=limY; indy<limY+4; ++indy){ //Sumatoria de cada RGB
            for(int indx=limX; indx<limX+4 ; ++indx){
                plusR= plusR + imagen.pixelColor(indx,indy).red();
                plusG = plusG + imagen.pixelColor(indx,indy).green();
                plusB= plusB + imagen.pixelColor(indx,indy).blue();
                    cont+=1;
            }
        }
        //Promedio de cada RGB
        R= (plusR / cont);
        G= (plusG / cont);
        B= (plusB / cont);



        for (int i= iter ; i<iter+1;i++){
            for (int j=iter2; j<(iter2+1);j++){
                mat[i][j]= qRgb(R,G,B);
                cout <<"Red: "<< qRed(mat[i][j])<<" Green: "<<qGreen(mat[i][j])<<" Blue: "<<qBlue(mat[i][j])<<" Iters: "<<i<<":"<<j<<endl;
            }
        }
        iter2+=1;

        limX+=4;
        if(limX>=imagen.width()){
            limX=0;
            limY+=4;
            iter+=1;
            iter2+=0;
        }

     }
     for (int i=0; i<(imagen.height()/4); ++i){
            delete [] *(mat+i);
        }
        delete [] mat;

*/
    submuestreo(filename);
    return 0;
}

void submuestreo(string filename){
    QImage imagen(filename.c_str());
    int limX=0,limY=0,iter=0,iter2=0;
    short int R=0, G=0, B=0;


    QRgb **mat=NULL;

    mat= new QRgb*[imagen.width()/4]; //se crea matriz y espacio en la memoria para llenarla con los RGB
    for (int fil=0; fil<(imagen.width()/4);++fil){
        mat[fil]= new QRgb[imagen.height()/4];
    }

    while( limY< imagen.height()){ //iteramos la imagen cada 4x4 pixeles y obtenemos el promedio del RGB
    int sumR=0,sumG=0,sumB=0,cont=0;
    for (int indy=limY; indy<limY+4; ++indy){ //Sumatoria de los RGB
        for(int indx=limX; indx<limX+4; ++indx){
            sumR= sumR + imagen.pixelColor(indx,indy).red();
            sumG = sumG + imagen.pixelColor(indx,indy).green();
            sumB= sumB + imagen.pixelColor(indx,indy).blue();
            cont+=1;
        }
    }
    //Promedio de la sumatoria de los RGB
    R= sumR / cont;
    G= sumG / cont;
    B= sumB /cont;

    //Agregamos a la matriz cada promedio RGB
    for(int j=iter;j<iter+1;j++){
        for(int i=iter2;i<(iter2+1);i++ ){
            mat[i][j]= qRgb(R,G,B);
            //cout<<"Red: "<< qRed(mat[i][j])<<" Green: "<<qGreen(mat[i][j])<<" Blue: "<<qBlue(mat[i][j])<<" Iters: "<<i<<":"<<j<<endl;
        }
    }
    iter2+=1;
    limX+=4;

    if(limX>=imagen.width()){
        limX=0;
        limY+=4;
        iter+=1;
        iter2=0;
    }
    }

    //Declaracion del ancho y alto de la imagen para dividirlo entre 4 y obtener la nueva posicion
    int height = imagen.height();
    int width = imagen.width();

    height/=4; //Altura new
    width/=4;   //Ancho new

    // Utilizamos el mismo procedimeinto pero con con la condicion de los pixeles deseado
    while(width > 8){ // 8 pixeles de ancho deseados
        if(height>=8){ // 8 Pixeles de alto deseados
            int limX=0, limY=0,iter=0,iter2=0;

            QRgb **mat2=NULL;
            mat2= new QRgb*[height/4]; //Se crea la matriz mat2

            for (int fil=0; fil<(height/4);++fil){ //Se separa el espacio en la memoria de mat2
                mat2[fil]= new QRgb[width/4];
            }

            //Iteramos la matriz mat cada 4x4 de nuevo para obtener un promedio de los RGB
            while( limY< height){
                int sumR=0,sumG=0,sumB=0,cont=0;
                for (int indy=limY; indy<limY+4; ++indy){ //Sumatoria de los RGB de la matriz mat
                    for(int indx=limX; indx<(limX+4) ; ++indx){
                        sumR= sumR + qRed(mat[indx][indy]);
                        sumG = sumG + qGreen(mat[indx][indy]);
                        sumB= sumB + qBlue(mat[indx][indy]);
                        cont+=1;
                    }
                }

        //Promedios de la suma de los RGB de la matriz
        R= sumR / cont;
        G= sumG / cont;
        B= sumB /cont;

        //Agregamos a la matriz mat2 cada promedio RGB
        for(int i=iter;i<iter+1;i++){
            for(int j=iter2;j<(iter2+1);j++ ){
                mat2[i][j]= qRgb(R,G,B);
                cout<<"Red: "<< qRed(mat2[i][j])<<" Green: "<<qGreen(mat2[i][j])<<" Blue: "<<qBlue(mat2[i][j])<<" Iters: "<<i<<":"<<j<<endl;
            }
        }
        iter2+=1;
        limX+=4;

        if(limX>=width){
            limX=0;
            limY+=4;
            iter+=1;
            iter2=0;}
        }
            //Destruimos la informacion de la memoria de la matriz mat2
            for (int i=0; i<(height/4); ++i){
                delete [] *(mat2+i);
            }
            delete [] mat2;
        }
    }
    //Destruimos la informacion de la memoria de la matriz mat
    for (int i=0; i<(imagen.height()/4); ++i){
        delete [] *(mat+i);
    }
    delete [] mat;


}

