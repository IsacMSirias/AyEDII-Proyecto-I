
#ifndef PRUEBAMATRIX_VIRTUALMATRIX_H
#define PRUEBAMATRIX_VIRTUALMATRIX_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Tarjeta.h"
#include "Disck.h"
#include "Disck.cpp"
using namespace std;
using std::fstream;
using std::ofstream;
using std::ios;




class VirtualMatrix {

    int rows =  6;
    int cols = 6;
    int Hit = 0;
    int Fault = 0;
    int puntos = 0;
    int TarjTotales = rows*cols;
    


public:

    vector <Tarjeta> enMatrix;
    vector <Tarjeta> fuera_de_Matrix;
    fstream archDisck;
   
    void crear_Matrix(int rows, int cols);
    void eliminar_tarjeta(Tarjeta tarj);
    void match(Tarjeta tar1, Tarjeta tar2);

    Tarjeta buscar_enMatrix(int i, int j);
    Tarjeta check_Disco(int i, int j);
    Tarjeta reemplazar(int i, int j);
    

    void s_Matrix();
    void print_matrix();
    void print_fuera_de_martix();
    void crear_Disco();

    bool es_match(Tarjeta tar1, Tarjeta tar2);
  
    
    VirtualMatrix();

    vector <const char*> s_Tarjetas();

    int get_tarjetas_totales();

};


#endif //PRUEBAMATRIX_VIRTUALMATRIX_H
