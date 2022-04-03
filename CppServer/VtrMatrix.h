#ifndef VrtMatrix_h

#include <string>
#include <iostream>
#include <vector>
#include "vector"


class VtrMatrix
{

private:

    std::vector<tarjeta> tarjeta_Matrix;

public:

    void Build_Matrix();

    tarjeta get_tarjeta_enMemoria(int i, int j);

    tarjeta reemplazar(int i, int j);

    void print_VtrMatrix();
};

#endif 

