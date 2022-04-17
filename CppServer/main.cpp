#include <iostream>

#include "VirtualMatrix.h"
#include "VirtualMatrix.cpp"

int main(){

    VirtualMatrix *matrix = new VirtualMatrix();

    cout<< "............................\n";
    matrix->buscar_enMatrix(3,5);

    cout<< "............................\n";
    matrix->buscar_enMatrix(1,6);

}