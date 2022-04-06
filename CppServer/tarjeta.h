#ifndef tarjeta_h
#define tarjeta_h

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
    int i, j, id, status;
    string img;
    tarjeta(int i , int j , int type , int status);
    void get_image(int type);
    void print() const;

};

#endif 
