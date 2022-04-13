#ifndef PRUEBAMATRIX_VIRTUALMATRIX_H
#define PRUEBAMATRIX_VIRTUALMATRIX_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tarjeta.h"
using namespace std;
using std::fstream;
using std::ofstream;
using std::ios;




class VirtualMatrix {

    int rows =  6;
    int cols = 6;
    int Hit = 0;
    int Fault = 0;
    int TarjTotales = rows*cols;
    vector <Tarjeta> enMatrix;


public:
    fstream archDisck;
    VirtualMatrix();
    void crear_Disco();
    void crear_Matrix(int rows, int cols);
    void s_Matrix();
    Tarjeta buscar_enMatrix(int i, int j);
    Tarjeta check_Disco(int i, int j);
    vector <const char*> s_Tarjetas();

};


#endif //PRUEBAMATRIX_VIRTUALMATRIX_H
