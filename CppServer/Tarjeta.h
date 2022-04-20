/**
 * @file Tarjeta.h
 * @author Isac Marin Sirias
 * @brief Esta es la estructura rajeta la cual contiene las posiciones i, j y la imagen de un objeto tarjeta
 * @version 0.1
 * @date 2022-04-19 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef PRUEBAMATRIX_TARJETA_H
#define PRUEBAMATRIX_TARJETA_H


/**
 * @brief almacena la posición en i, j y la imagen de la tarjeta
 * 
 */
struct Tarjeta {
    
public:
    int i, j;
    const char* image;

    /**
 * @brief metodo que imprime cada parametro del struct tarjeta
 * 
 */

    void print_Tarjeta(){

        std::cout<<"Posicion: "<< i << "," << j << "  imagen: "<< image <<std::endl; 

    };
};





#endif //PRUEBAMATRIX_TARJETA_H
