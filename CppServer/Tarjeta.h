//
// Created by ims on 12/4/22.
//

#ifndef PRUEBAMATRIX_TARJETA_H
#define PRUEBAMATRIX_TARJETA_H


struct Tarjeta {
    
public:
    int i, j;
    const char* image;

    void print_Tarjeta(){

        std::cout<<"Posicion: "<< i << "," << j << "  imagen: "<< image <<std::endl; 

    };
};





#endif //PRUEBAMATRIX_TARJETA_H
