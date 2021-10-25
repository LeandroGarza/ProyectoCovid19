#ifndef PROYECTOCOVID19_PROVINCIAS_H
#define PROYECTOCOVID19_PROVINCIAS_H

#include <iostream>
#include "string.h"

using namespace std;

class provincia {
private:
    string nombre;
    int cuenta;

public:
    provincia(){
        nombre = " ";
        cuenta = 0;
    }

    Provincia(string &nombre, int cuent) : nombre(nombre) {
        cuenta = cuent;
    }

    string &getNombre(){
        return nombre;
    }

    void setNombre(string &nombr){
        nombre = nombr;
    }
}

#endif //PROYECTOCOVID19_PROVINCIAS_H
