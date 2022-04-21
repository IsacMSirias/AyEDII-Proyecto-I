
#ifndef PRUEBAMATRIX_VIRTUALMATRIX_H
#define PRUEBAMATRIX_VIRTUALMATRIX_H


/**
 * @file VirtualMatrix.cpp
 * @author Isac Marin Sirias
 * @brief Clase encargada de la administracion y manejo de memoria, junto a la clase Disck 
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/resource.h>
#include "Tarjeta.h"
#include "Disck.h"
#include "Disck.cpp"
using namespace std;
using std::fstream;
using std::ofstream;
using std::ios;




class VirtualMatrix {
  /**
     * @brief numero de filas que tiene la matriz
     * 
     */
    int rows =  6;
     /**
     * @brief numero de columnas que tiene la matriz
     * 
     */
    int cols = 6;
    /**
     * @brief variable que almacena los pageHit que se realizan cada vez que una carta
     * 
     */
    int Hit = 0;
    /**
     * @brief variable que almacena los pageFould que se realizan cada vez que una carta
     * 
     */
    int Fault = 0;
    /**
     * @brief numero de tarjetas totales, tanto en disco como en memoria
     * 
     */
    int TarjTotales = rows*cols;
    


public:

long get_mem_usage() {
    struct rusage myusage;

    getrusage(RUSAGE_SELF, &myusage);
    return myusage.ru_maxrss;
}

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

    int get_pageHits();
    int get_pageFaults();
};


#endif //PRUEBAMATRIX_VIRTUALMATRIX_H
