#include <iostream>
#include "Headers/Lista.h"
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

void casosFallecidos(int, string);


int main(int argc, char **argv){

    string ultimo =argv[argc - 1];

    for(int i = 1 ; i < argc - 1 ; i++){
        //podria hacer switch pero las funciones van a ser largas
        if(arg == "-estad"){

        }

        if(arg == "-p_casos"){

        }

        if(arg == "-p_muertes"){

        }

        if(arg == "-casos_cui"){

        }

        if(arg == "-casos_edad"){

        }

        else{
            cout<<"Ingreso un argumento incorrecto"<<endl;
        }
    }

    return 0;
}

void casosFallecidos(int numero , string ultimo){

    lista<string> listaProvincias[24];

    const string provincias[] = {"Buenos Aires","Capital Federal","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};

    for(int i = 0 ; i < 24 ; i++){
        listaProvincias.insertar(i,provincias[i]);
    }

    fstream fin;
    fin.open(ultimo, ios::in);
    if(fin.fail()){
        cout<<"No se pudo abrir el txt"<<endl;
    }
    else{
        string line;
        getline(fin, line);
        while(getline(fin, line)){

        }

    }



}
