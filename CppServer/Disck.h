#ifndef Disck_h

#include <iostream>
#include <vector>
#include "vector"
#include "tarjeta.h"
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
#include <string>
#include <bits/stdc++.h>


class Disck
{


public:

    void cargarDisco();

    tarjeta get_tarjeta_enDisco(int i , int j);

    void set_tarjeta_enDisco(int i, int j, int id, int memory);
    

};

#endif 
