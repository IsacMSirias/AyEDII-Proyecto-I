/**
 * @file main.cpp
 * @author Isac Marin Sirias
 * @brief esta clase se encarga de realizar las pruebas necesarias para poder probar la paginacion.
 * @version 0.1
 * @date 2022-04-19 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "Disck.h"
#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"



/**
 * @brief Metodo main.
 */

int main(){

    VirtualMatrix *matrix = new VirtualMatrix();

    Disck *disck = new Disck();

    matrix->s_Matrix();
    matrix->print_matrix();
    cout<< "............................\n";
    matrix->buscar_enMatrix(5,3);
    cout<< "............................\n";
    matrix->buscar_enMatrix(5,3);
    cout<< "............................\n";
    matrix->buscar_enMatrix(5,3);
    matrix->buscar_enMatrix(5,3);
    matrix->buscar_enMatrix(5,3);
    matrix->buscar_enMatrix(5,3);

    cout<<"el vector tiene" <<": "<<matrix->enMatrix.size()<< "  Tarjetas"<<endl;

    matrix->print_matrix();


 



}