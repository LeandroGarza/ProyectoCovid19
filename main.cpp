#include <iostream>
#include "Headers/Lista.h"
#include "Headers/datosNecesarios.h"
#include "Headers/provincia.h"
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

void p_casos(int);  //las hizo juan a casos y muertes en una sola (las hicimos los 2....)
void p_muertes(int); //las hizo juan a casos y muertes en una sola (las hicimos los 2....)
void quickSort(int, int, int);  //el mismo que hicimos en clase
void casos_cui(string, string); //recibe la fecha y el nombre de archivo


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
            casos_cui(fecha, ultimo);

        }

        if(arg == "-casos_edad"){

        }

        else{
            cout<<"Ingreso un argumento incorrecto"<<endl;
        }
    }

    return 0;
}

void fallecidos(int numero , string ultimo){

    //lista<string> listaProvincias[24];

    const string provincias[] = {"Buenos Aires","Capital Federal","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};

    /*for(int i = 0 ; i < 24 ; i++){
        listaProvincias.insertar(i,provincias[i]);
    }*/

    provincia fallecidos[24];
    provincia contagiados[24];

    for (int i = 0; i < 24; i++) {
        fallecidos[i] = provincia(provincias[i], 0);
        contagiados[i] = provincia(provincias[i], 0);
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
            datosNecesarios.analizarDatos(line);
            if(datosNecesarios.clasificacion() == "Confirmado"){
                for(int i = 0 ; i < 24 ; i++){
                    if(datosNecesarios.provincia() == contagiados[i].getNombre()){
                        contagiados[i].contador();
                    }
                }
            }
            else{
                if(datosNecesarios.fallecio() == "SI"){
                    datosNecesarios.analizarDatos(line)
                    for(int i = 0 ; i < 24 ; i++){
                        if(datosNecesarios.provincia() == fallecidos[i].getNombre()){
                            fallecidos[i].contador();
                        }
                    }
                }
            }
        }
        quickSort(contagiados,0,23);
        cout<<"Casos de contagiados por provincias: "<<endl;
        for(int i = 0 ; i < 24 ; i++){
            cout<<contagiados[i]<<endl;
        }
        else{

        }


    }



}

void quickSort(int *arreglo, int inicio, int fin){

    int medio = (inicio + fin) / 2;
    int pivot = arreglo[medio];
    int aux;
    int i = inicio;
    int j = fin;

    do{
        while(arreglo[i] < pivot) i++;
        while(arreglo[j] > pivot) j--;

        if(i <= j){
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
            i++;
            j--;
        }

    }while(i <= j);

    if(j < inicio){
        quickSort(arreglo, inicio, j);
        quickSort(arreglo, i, fin);
    }
}

void casos_cui(string fecha, string ultimo){

    lista<Casos> listaCUI;
    datosNecesarios cui;

    fstream fin;
    fin.open(ultimo, ios::in);

    if(fin.fail()){
        cout << "No se pudo abrir el archivo"<<endl;
    }
    else{
        string line;
        getline(fin, line);
        while (getline(fin, line)) {
            cui.analizarDatos(line);
            if(cui.CUI() == "SI" && cui.fechaCUI() > fecha) {
                listaCUI.insertarPrimero(cui);
            }
        }

        datosNecesarios arregloCUI[listaCUI.getTamanio()];
        for (int i = 0 ; i < listaCUI.getTamanio() ; i++) {
            arregloCUI[i] = listaCUI.getDato(i);
        }

        QuickSort(arregloCUI, 0, listaCUI.getTamanio());
        cout<<"Casos mayores a "<<fecha<<":" << endl;

        for(int i = 0 ; i < listaCUI.getTamanio() ; i++) {
            if(arregloCUI[i] > fecha) {
                cout<<arregloCUI[i]<<endl;
            }
        }
    }
}
