#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

class tarjeta{

public:

    int pos_i, pos_j, id, memory;

    string imgprovisional;

    tarjeta(int pos_i, int pos_j, int id, int memory);

    void obtener_imagen(int id);

    void print() const;
    

};

