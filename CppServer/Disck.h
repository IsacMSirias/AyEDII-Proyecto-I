#ifndef PRUEBAS_DISCK_H
#define PRUEBAS_DISCK_H
#include <unistd.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Tarjeta.h"




class Disck {

public:
    Disck();
    void crear_Disco();
    Tarjeta get_tarjeta_enDisco(int i, int j);
    void set_tarjeta_enDisco(int i, int j, int id, int status);
};


#endif //PRUEBAS_DISCK_H
