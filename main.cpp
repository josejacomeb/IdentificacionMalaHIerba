/*
*   Examen I Unidad, miembros del Grupo: Barreno Mauricio, Jácome José, Semanate Clinton
*   Instrucciones: Ingresar la Ruta del Video en el String rutavideo
*   Ingresar la ruta de la mascara roja(Archivo Rojo.png)
*   Compilar y ejecutar
*   p pausa el Video, e reanuda el video, q para salir!
*/
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


using namespace std;
using namespace cv;

int h_min = 33, s_min = 88,  v_min = 90;
int h_max = 55, s_max = 111, v_max = 255;
String rutavideo1 = "/home/josejacomeb/QT/IdentificacionMalaHIerba/Maíz.mp4";
String rutavideo2 = "/home/josejacomeb/QT/IdentificacionMalaHIerba/EtapaInicial1.mp4";
String rutavideo3 = "/home/josejacomeb/QT/IdentificacionMalaHIerba/EtapaInicial2.mp4";
Mat resultado,hsv,sliders,color;

int pausa, opcion;

void cambio(int, void* );

int main()
{
    opcion = 2;
    namedWindow("Original",WINDOW_AUTOSIZE);
    namedWindow("Sliders",WINDOW_AUTOSIZE);
    namedWindow("HSV",WINDOW_AUTOSIZE);
    createTrackbar( "Hmin", "Sliders", &h_min, h_max,cambio);
    createTrackbar( "Hmax", "Sliders", &h_max, 255,cambio);
    createTrackbar( "Smin", "Sliders", &s_min, s_max,cambio);
    createTrackbar( "Smax", "Sliders", &s_max, 255,cambio);
    createTrackbar( "Vmin", "Sliders", &v_min, h_max,cambio);
    createTrackbar( "Vmax", "Sliders", &v_max, 255,cambio);
    VideoCapture video;
    if(opcion == 1) video.open(rutavideo1);
    else if(opcion == 2) video.open(rutavideo2);
    else if(opcion == 3) video.open(rutavideo3);
    for(;;){
        char c = (char)waitKey(20);
        if( c == 'p') pausa = 1;
        if( c == 'e') pausa = 0;
        if(pausa == 0) video>>resultado;
        cvtColor(resultado,hsv,CV_BGR2HSV);
        inRange(resultado,Scalar(h_min,s_min,v_min),Scalar(h_max,s_max,v_max),hsv);
        if(resultado.empty()) break;
        cout<<resultado.rows <<endl;
        cout<<resultado.cols <<endl;
        imshow("Original",resultado);
        imshow("HSV",hsv);

        if(c == 'q'){
            cout<<"Presione cualquier tecla para continuar"<<endl;
            break;
        }

    }
    return 0;
}

void cambio(int, void*){
    inRange(resultado,Scalar(h_min,s_min,v_min),Scalar(h_max,s_max,v_max),hsv);
    hsv = ~hsv;
    imshow("HSV",hsv);
}
