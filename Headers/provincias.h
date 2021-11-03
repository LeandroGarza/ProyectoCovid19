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
        nombre = "NA";
        cuenta = 0;
    }

    provincia(const string &nombre, int cuent) : nombre(nombre) {
        cuenta = cuent;
    }

    const string &getNombre(){
        return nombre;
    }

    void setNombre(const string &nombr){
        nombre = nombr;
    }

    void contador(){
        cuenta++;
    }

   /*
    bool operator > (const provincia &rhs){
        return cuenta > rhs.cuenta;
    }
    }*/

    bool operator==(const provincia &rhs) const {
        return nombre == rhs.nombre;
    }

    bool operator<(const provincia &rhs) const {
        return cuenta < rhs.cuenta;
    }

    bool operator>(const provincia &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const provincia &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const provincia &rhs) const {
        return !(*this < rhs);
    }

    bool operator!=(const provincia &rhs) const {
        return !(rhs == *this);
    }

};

#endif //PROYECTOCOVID19_PROVINCIAS_H
