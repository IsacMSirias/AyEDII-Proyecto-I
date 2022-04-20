#ifndef PRUEBAS_DISCK_H
#define PRUEBAS_DISCK_H
#include <unistd.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Tarjeta.h"

/**
 * @file Disck.h
 * @author Isac Marin Sirias
 * @brief Esta clase se encarga de manejar toda la paginacion que realiza dentro del "disco"(cuando se quema la memoria)
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */


class Disck {



public:
    Disck();
    Tarjeta get_tarjeta_enDisco(int i, int j);
    void set_tarjeta_enDisco(int i, int j, const char* image);
};


#endif //PRUEBAS_DISCK_H
