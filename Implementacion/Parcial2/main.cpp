#include <iostream>
#include <QImage>

using namespace std;

int main()
{
    string filename = "../Parcial2/imagenes/brasil.jpg";
    QImage imagen(filename.c_str());

    unsigned int pixelX = 200;
    unsigned int pixelY = 200;

    cout << imagen.width()<<endl;
    cout << imagen.height()<<endl;

    cout << " Valor de rojo " << imagen.pixelColor(pixelX,pixelY).red() << endl;
    cout << " Valor de verde " << imagen.pixelColor(pixelX,pixelY).green() << endl;
    cout << " Valor de azul " << imagen.pixelColor(pixelX,pixelY).blue() << endl;

    for (int indx = 0; indx< imagen.width();++indx){
        for (int indy = 0; indy < imagen.height(); ++indy){
            //cout << indx<<", "<<indy<<" = " << imagen.pixelColor(indx,indy).red()<<endl;
        }
    }


    return 0;
}
