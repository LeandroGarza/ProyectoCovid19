#include <iostream>
#include "Headers/Lista.h"
#include "Headers/datosNecesarios.h"
#include "Headers/provincias.h"
<<<<<<< HEAD
=======
#include "Headers/HashMap.h"
#include "Headers/pila.h"
>>>>>>> 0b7566fc95e7f1b2209981c73b5db8fc70ce867d
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

void p_casos(string, int);  //las hizo juan a casos y muertes en una sola (las hicimos los 2....)
void p_muertes(string, int); //las hizo juan a casos y muertes en una sola (las hicimos los 2....)
void prov(int, string);
void quickSort(int*, int, int);  //el mismo que hicimos en clase
void quickSortK(int *arreglo1, string *arreglo2, int inicio, int fin); // ordenar arreglo de strings basado en arreglo de ints
void casos_cui(string, string); //recibe la fecha y el nombre de archivo
void estad(string); //mostrara las estadisticas

unsigned int getHash(string s){
  unsigned int hash = 0;
  for(int i = 0; i < s.length(); ++i){
    hash += (s[i]);
  }
  hash += s.size() + s[0];
  return hash;
}

<<<<<<< HEAD
int main(int argc, char **argv){

    string ultimo =argv[argc - 1];

    for(int i = 1 ; i < argc - 1 ; i++){
        string arg = argv[i];
        //podria hacer switch pero las funciones van a ser largas
        if(arg == "-estad"){

        }

        if(arg == "-p_casos"){
=======
HashMap<int, int> loadHashMap(string filepath, int size){
  fstream fin;
  fin.open(filepath, ios::in);
>>>>>>> 0b7566fc95e7f1b2209981c73b5db8fc70ce867d

  string text, word;
  getline(fin, text);

  stringstream s(text);

  HashMap<int, int> hashmap(size);
  while (getline(s, word, ',')){
    word = word.substr(1, word.size() - 2);
    hashmap.put(getHash(word), 0);
  }

<<<<<<< HEAD
        if(arg == "-casos_cui"){
            fecha = argv[i+1];
            casos_cui(fecha, ultimo);
=======
  return hashmap;
}
>>>>>>> 0b7566fc95e7f1b2209981c73b5db8fc70ce867d

int main(int argc, char **argv){

    string archivo = argv[argc - 1];

    for(int i = 1 ; i < argc - 1 ; i++){
        string arg = argv[i];
        // //podria hacer switch pero las funciones van a ser largas
        // if(arg == "-estad"){
        //
        // }
        //
        if(arg == "-p_casos"){
          int num;
          try{
            num = stoi(argv[i + 1]);
          }
          catch(std::invalid_argument){
            num = 24;
          }
          p_casos(archivo, num);
        }

        if(arg == "-p_muertes"){
          int num;
          try{
            num = stoi(argv[i + 1]);
          }
          catch(std::invalid_argument){
            num = 24;
          }
          p_muertes(archivo, num);
        }
        //
        // if(arg == "-casos_cui"){
        //     // casos_cui(fecha, archivo);
        //
        // }
        //
        // if(arg == "-casos_edad"){
        //
        // }
        //
        // else{
        //     cout<<"Ingreso un argumento incorrecto"<<endl;
        // }
    }

    return 0;
}

void p_casos(string archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<int, int> casos = loadHashMap("provincias.txt", 100);

    fstream fin;
    string provincia, clasif;
    unsigned int hash;
    int ordenados[24];
    fin.open(archivo, ios::in);
    int contagiados = 0;
    if(fin.fail()){
        cout<<"No se pudo abrir el csv"<<endl;
    }
    else{
        string line;
        string palabra;
        while(getline(fin, line)){
          int total = 0;
          stringstream s(line);
          while (getline(s, palabra, ',')){
            if(palabra.size() > 0){
              palabra = palabra.substr(1, palabra.size() - 2);
              if(total == 7){provincia = palabra;}
              else if(total == 20){clasif = palabra;}
            }
            total++;
          }
          if(clasif == "Confirmado"){
              hash = getHash(provincia);
              casos.set(hash, casos.get(hash) + 1);
          }
        }

        for(int i = 0; i < 24; i++){
          hash = getHash(provincias[i]);
          ordenados[i] = casos.get(hash);
          contagiados += ordenados[i];
        }

        quickSortK(ordenados, provincias, 0, 24);

        for(int i = 0; i < numero; i++){
          cout<<ordenados[23 - i]<<" "<<provincias[23 - i]<<endl;
        }

    }
}

void p_muertes(string archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<int, int> muertes = loadHashMap("provincias.txt", 100);

    fstream fin;
    string provincia, fallecido;
    unsigned int hash;
    int ordenados[24];
    fin.open(archivo, ios::in);
    if(fin.fail()){
        cout<<"No se pudo abrir el csv"<<endl;
    }
    else{
        string line;
        string palabra;
        while(getline(fin, line)){
          int total = 0;
          stringstream s(line);
          while (getline(s, palabra, ',')){
            if(palabra.size() > 0){
              palabra = palabra.substr(1, palabra.size() - 2);
              if(total == 7){provincia = palabra;}
              else if(total == 14){fallecido = palabra;}
            }
            total++;
          }
          if(fallecido == "SI"){
              hash = getHash(provincia);
              muertes.set(hash, muertes.get(hash) + 1);
          }
        }

        for(int i = 0; i < 24; i++){
          hash = getHash(provincias[i]);
          ordenados[i] = muertes.get(hash);
        }

        quickSortK(ordenados, provincias, 0, 23);

        for(int i = 0; i < numero; i++){
          cout<<ordenados[23 - i]<<" "<<provincias[23 - i]<<endl;
        }

    }
}




void quickSortK(int *arr, string *arr2, int start, int end){
    int medio = (start + end) / 2;
    int pivot = arr[medio];
    int aux;
    string aux2;

    int i = start;
    int j = end;

    do{

        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;


        if(i <= j){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;


            aux2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = aux2;
            i++;
            j--;
        }

    }while(i <= j);


    if(start < j) quickSort(arr, start, j);
    if(end > i) quickSort(arr, i, end);
}


void quickSort(int *arr, int start, int end){
    int medio = (start + end) / 2;
    int pivot = arr[medio];
    int aux;

    int i = start;
    int j = end;

    do{

        while(arr[i] < pivot) i++;
        while(arr[j] > pivot) j--;


        if(i <= j){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;

            i++;
            j--;
        }

    }while(i <= j);


    if(start < j) quickSort(arr, start, j);
    if(end > i) quickSort(arr, i, end);
}

/*
void casos_cui(string fecha, string ultimo){

<<<<<<< HEAD
    lista<datosNecesarios> listaCUI;
=======
    lista<int> listaCUI;
>>>>>>> 0b7566fc95e7f1b2209981c73b5db8fc70ce867d
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

        quickSort(arregloCUI, 0, listaCUI.getTamanio());
        cout<<"Casos mayores a "<<fecha<<":" << endl;

        for(int i = 0 ; i < listaCUI.getTamanio() ; i++) {
            if(arregloCUI[i] > fecha) {
                cout<<arregloCUI[i]<<endl;
            }
        }
    }
}

void estad(string ultimo){
    fstream fin;
    fin.open(ultimo, ios::in);
    float cantidadCasos = 0;

<<<<<<< HEAD
    int edadConfirmados[100];   //todas las edades posibles
    int edadFallecidos[100];

    datosNecesarios casos;
=======
    int estuvieronCUI[100];        //personas que estuvieron en cuidados intensivos
    int edadConfirmados[100];   //todas las edades posibles
    int edadFallecidos[100];

>>>>>>> 0b7566fc95e7f1b2209981c73b5db8fc70ce867d
    for(int i = 0; i < 100; i++){
        edadConfirmados[i] = 0;
        edadFallecidos[i] = 0;
    }

    int contagiados = 0 , fallecidos = 0;

    if(fin.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else{
        string line;
        getline(fin,line);

        while(getline(fin,line)){
            casos.analizarDatos(line);
            cantidadCasos++;

            if(casos._fallecio() == "SI") {
                fallecidos++;
                if (casos._aniosMeses() == "Años") {
                    edadFallecidos[casos._edad()]++;
                }
            }
            else{
                if(casos._clasificacion() == "Confirmado"){
                    contagiados++;
                    if(casos._aniosMeses() == "Años"){
                        edadConfirmados[casos._edad()]++;
                    }
                }
            }
        }
    }
}
*/
