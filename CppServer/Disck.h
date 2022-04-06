#ifndef PRUEBAS_DISCK_H
#define PRUEBAS_DISCK_H
#include <unistd.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "tarjeta.h"
#include "tarjeta.cpp"

class Disck {

public:
    void crear_Disco();
    tarjeta get_tarjeta_enDisco(int i, int j); 
    void set_tarjeta_enDisco(int i, int j, int type, int status);
};


#endif //PRUEBAS_DISCK_H
