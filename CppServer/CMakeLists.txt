cmake_minimum_required(VERSION 3.22)
project(CppServer)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CppServer
        Disck.cpp
        Disck.h
        main.cpp
        Servidor.cpp
        Tarjeta.h
        VirtualMatrix.cpp
        VirtualMatrix.h)
