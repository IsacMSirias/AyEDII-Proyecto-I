#include "Disck.h"
#include <string>

#include <iostream>
#include <cstdlib>

using namespace std;



/**
 * @file Disck.cpp
 * @author Isac Marin Sirias
 * @brief Esta clase se encarga de manejar toda la paginacion que realiza dentro del "disco"(cuando se quema la memoria)
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

 /**
     * @brief parametro utilizado para abrir el disco.
     * 
     */

fstream archDisck;
/**
 * @brief constructor por defecto de la clase Disck
 * 
 */
Disck::Disck(){
}


/**
 * @brief Este metodo extrae la tarjeta solicitada por el cliente si es que esta se encuentra en disco.
 * 
 * @param i posicion i de la matriz en interfaz grafica
 * @param j posicion j en la matriz en interfaz grafica
 * @return objeto tarjeta
 */

Tarjeta Disck::get_tarjeta_enDisco(int i, int j){

    archDisck.open("disco", ios::in | ios::out | ios::binary);


    archDisck.seekg((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta), ios::beg);
    char *buffer = (char*) malloc(sizeof(Tarjeta));
    archDisck.read(buffer, sizeof(Tarjeta));

    Tarjeta* tarj = (Tarjeta*) buffer;

    Tarjeta tarjeta = *tarj;

    //tarjeta.print_Tarjeta();
    
    archDisck.close();
    free(buffer);
    buffer = nullptr;

    return tarjeta;

}

/**
 * @brief Este metodo agrega una un objeto tarjeta al disco.
 * 
 * @param i posicion i del objeto tarjeta 
 * @param j posicion j del objeto tarjeta
 */
void Disck::set_tarjeta_enDisco(int i, int j, const char* image){

    Tarjeta tarjeta;
    tarjeta.i = i;
    tarjeta.j = j;
    tarjeta.image = image;

    archDisck.open("disco", ios::in | ios::out | ios::binary);

    archDisck.seekg(((i-1)*(4)*sizeof(Tarjeta)+(j-1)*sizeof(Tarjeta)),ios::beg);
    archDisck.write((char*)&tarjeta, sizeof(Tarjeta));
    archDisck.close();



}

