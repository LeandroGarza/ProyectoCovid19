#include <iostream>
#include "Headers/Lista.h"
#include "Headers/DatosPaciente.h"
#include "Headers/DatosPacienteF.h"
#include "Headers/HashMap.h"
#include "Headers/ArbolBinario.h"
#include "Headers/pila.h"
#include <fstream>
#include <sstream>
#include <exception>

using namespace std;

void p_casos(string&, int);

void p_muertes(string&, int);

void quickSortK(int*, string*, int, int);

void casos_cui(string&, string&);

void casos_edad(string&, int);

void estad(string&);

int compare_dates(string, string);


int main(int argc, char **argv){

    string archivo = argv[argc - 1];

    for(int i = 1 ; i < argc - 1 ; i++){
        string arg = argv[i];

        if(arg == "-estad"){
            estad(archivo);
            return 0;
        }

        if(arg == "-p_casos"){
          int num;
          try{
            num = stoi(argv[i + 1]);
          }
          catch(std::invalid_argument &e){
            num = 24;
          }
          if(num > 24){
            num = 24;
          }
          p_casos(archivo, num);
          return 0;
        }

        if(arg == "-p_muertes"){
          int num;
          try{
            num = stoi(argv[i + 1]);
          }
          catch(std::invalid_argument &e){
            num = 24;
          }
          p_muertes(archivo, num);
          return 0;
        }

        if(arg == "-casos_cui"){
            string fecha = "2020-01-01";
            if (argv[i+1][0] == '2'){
                fecha = argv[i + 1];
            }
            casos_cui(fecha, archivo);
            return 0;
        }

        if(arg == "-casos_edad"){
            int edad = stoi(argv[i + 1]);
            casos_edad(archivo, edad);
            return 0;
        }

    }

    return 0;
}

// false f1 < f2
// true f1 > f2
int compare_dates(string f1, string f2){
  stringstream sf1(f1);
  stringstream sf2(f2);

  int a1, a2, m1, m2, d1, d2;
  string d;

    if(getline(sf1, d, '-')){
        a1 = stoi(d);
        getline(sf1, d, '-');
        m1 = stoi(d);
        getline(sf1, d, '-');
        d1 = stoi(d);
    }else{
      return false;
    }

    if(getline(sf2, d, '-')){
        a2 = stoi(d);
        getline(sf2, d, '-');
        m2 = stoi(d);
        getline(sf2, d, '-');
        d2 = stoi(d);
    }else{
      return true;
    }


  if(a1 < a2){return false;}
  else if(a1 > a2){return true;}

  if(m1 < m2){return false;}
  else if(m1 > m2){return true;}

  if(d1 < d2){return false;}
  else if(d1 > d2){return true;}

  return true; // son iguales
}




template <class T>
HashMap<string, T> loadHashMap(string *arr, int size, int arrSize){

    string text, word;

    HashMap<string, T> hashmap(size);
    for(int i = 0; i < arrSize; i++){
        hashmap.put(arr[i], 0);
    }

    return hashmap;
}

void p_casos(string& archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<string, int> casos = loadHashMap<int>(provincias, 200, 24);
    fstream fin;

    int ordenados[24];


    fin.open(archivo, ios::in);

    if(fin.fail()){
        cout<<"No se pudo abrir el csv"<<endl;
    }
    else{
        string line;
        string palabra, provincia;
        int columna;
        getline(fin, line);
        stringstream s;
        while(getline(fin, line)){
          columna = 0;
          s.clear();
          s.str(line);
          while (getline(s, palabra, ',')){
            if(!palabra.empty()){
              palabra = palabra.substr(1, palabra.size() - 2);
              if(columna == 7){provincia = palabra;}
              else if(columna == 20 && palabra == "Confirmado"){casos.set(provincia, casos.get(provincia) + 1);}
            }
            columna++;
          }
        }

        for(int i = 0; i < 24; i++){
          ordenados[i] = casos.get(provincias[i]);
        }

        quickSortK(ordenados, provincias, 0, 24);

        for(int i = 0; i < numero; i++){
          cout<<ordenados[23 - i]<<" "<<provincias[23 - i]<<endl;
        }

    }
}

void p_muertes(string& archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<string, int> muertes = loadHashMap<int>(provincias, 200, 24);
    string provincia;
    int ordenados[24];
    fstream fin;
    fin.open(archivo, ios::in);
    if(fin.fail()){
        cout<<"No se pudo abrir el csv"<<endl;
    }
    else{
        string line;
        string palabra;
        stringstream s;
        int columna;
        while(getline(fin, line)){
          s.clear();
          s.str(line);
          columna = 0;
          while (getline(s, palabra, ',')){
            if(!palabra.empty()){
              palabra = palabra.substr(1, palabra.size() - 2);
              if(columna == 7){provincia = palabra;}
              else if(columna == 14 && palabra == "SI"){muertes.set(provincia, muertes.get(provincia) + 1);}
            }
            columna++;
          }
        }

        for(int i = 0; i < 24; i++){
          provincia = provincias[i];
          ordenados[i] = muertes.get(provincia);
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

            // Modifica arreglo 2 en base a arreglo 1
            aux2 = arr2[i];
            arr2[i] = arr2[j];
            arr2[j] = aux2;
            i++;
            j--;
        }

    }while(i <= j);


    if(start < j) quickSortK(arr, arr2, start, j);
    if(end > i) quickSortK(arr, arr2, i, end);
}

void casos_cui(string& fecha, string& archivo){

  ArbolBinario<DatosPacienteF> casos;
  DatosPacienteF dato;

  fstream fin;
  fin.open(archivo, ios::in);
  if(fin.fail()){
      cout<<"No se pudo abrir el csv"<<endl;
  }
  else{
      string line, palabra;
      int columna;
      getline(fin, line);
      stringstream s;
      bool continuar;

      while(getline(fin, line)){
        columna = 0;
        s.clear();
        s.str(line);
        continuar = true;
        while (getline(s, palabra, ',') && continuar){
          if(!palabra.empty()){
            palabra = palabra.substr(1, palabra.size() - 2);
            if(columna == 0){dato.set_id(stoi(palabra));}
            else if(columna == 1){dato.set_sexo(palabra);}
            else if(columna == 2){dato.set_edad(stoi(palabra));}
            else if(columna == 3){dato.set_edad_calif(palabra);}
            else if(columna == 7){dato.set_provincia(palabra);}
            else if(columna == 8){dato.set_fecha_inicio_sintomas(palabra);}
            else if(columna == 12 && palabra == "NO"){dato.set_cui("NO"); continuar = false; continue;}
            else if(columna == 12){dato.set_cui(palabra);}
            else if(columna == 13 && compare_dates(palabra, fecha) == false){continuar = false; continue;}
            else if(columna == 13){dato.set_fecha_cui(palabra);}
            else if(columna == 14){dato.set_fallecido(palabra);}
            else if(columna == 15){dato.set_fecha_fallecimiento(palabra);}
            else if(columna == 20){dato.set_clasif(palabra);}
            else if(columna == 22){dato.set_fecha_diagnostico(palabra);}
          }
          columna++;
        }

        if(dato.get_cui() == "SI" && compare_dates(dato.get_fecha_cui(), fecha)){
          casos.put(dato);
        }
      }

  }
  casos.inorder();

}


void casos_edad(string& archivo, int edad){

  DatosPaciente dato;
  const string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};

  HashMap<string, Pila<DatosPaciente>*> hash_provincias(100);

  string hash;
  for(int i = 0; i < 24; i++){
    hash = provincias[i];
    hash_provincias.put(hash, new Pila<DatosPaciente>);
  }

  fstream fin;
  fin.open(archivo, ios::in);
  if(fin.fail()){
      cout<<"No se pudo abrir el csv"<<endl;
  }
  else{
      string line, palabra;
      getline(fin, line);
      int columna;
      stringstream s(line);
      bool continuar;
      while(getline(fin, line)){
        columna = 0;
        s.clear();
        s.str(line);
        continuar = true;
        while (getline(s, palabra, ',') && continuar){
          if(!palabra.empty()){

            palabra = palabra.substr(1, palabra.size() - 2);
            if(columna == 0){dato.set_id(stoi(palabra));}
            if(columna == 2 && stoi(palabra) != edad){dato.set_edad(-1); continuar = false; break;}
            else if(columna == 2){dato.set_edad(stoi(palabra));}
            else if(columna == 3){dato.set_edad_calif(palabra);}
            else if(columna == 7){dato.set_provincia(palabra);}
            else if(columna == 12){dato.set_cui(palabra);}
            else if(columna == 13){dato.set_fecha_cui(palabra);}
            else if(columna == 14){dato.set_fallecido(palabra);}
            else if(columna == 20){dato.set_clasif(palabra);}
          }
          columna++;
        }
        if(dato.get_edad() == edad){
          hash = dato.get_provincia();
          hash_provincias.get(hash)->push(dato);
        }
      }

  }

  for(int i = 0; i < 23; i++){
      hash = provincias[i];
      while(!hash_provincias.get(hash)->esVacia()){
        cout<<hash_provincias.get(hash)->pop()<<endl;
      }
    }

}

void estad(string& archivo){

    int cantidadCasos = 0;

    int edadConfirmados[13] = {0};   //dice rango etario 10 anios
    int edadFallecidos[13] = {0};

    int contagiados = 0, fallecidos = 0;

    bool anios;

    int edad, columna;


    ifstream fin;
    fin.open(archivo, ios::in);
    if(fin.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else{
        string line, palabra;
        getline(fin, line);
        stringstream s;
        while(getline(fin, line)){

            // Saves memory
            s.clear();
            s.str(line);

            cantidadCasos++;
            columna = 0;
            anios = false;

            while(getline(s, palabra, ',')){
              if(!palabra.empty()){
                palabra = palabra.substr(1, palabra.size() - 2);
                if(columna == 2){edad = stoi(palabra);}
                if(edad > 125){
                    edad = 125;
                }
                else if(columna == 3 && palabra == "Años"){anios = true;}
                else if(columna == 14 && palabra == "SI")
                {
                  fallecidos++;
                  if(anios){
                    edadFallecidos[edad/10]++;
                  }
                  else{
                    edadFallecidos[0]++;
                  }
                }
                else if(palabra == "Confirmado"){
                  contagiados++;
                  if(anios){
                    edadConfirmados[edad/10]++;
                  }
                  else{
                    edadConfirmados[0]++;
                  }
                }
              }
              columna++;
            }
          }
      }

    float porcentajeFallec, porcentajeContagi;
    if(contagiados != 0){
      porcentajeFallec = (float) fallecidos * 100 / contagiados ;
    }
    if(cantidadCasos != 0){
      porcentajeContagi = (float) contagiados * 100 / cantidadCasos;
    }

    cout << "Cantidad de muestras: " << cantidadCasos << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de fallecidos: " << fallecidos << endl;
    cout << "Cantidad de contagiados: " << contagiados << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Porcentaje de Fallecidos sobre Contagiados: " << porcentajeFallec << "%" << endl;
    cout << "Porcentaje de Contagiados sobre Total de Muestras: " << porcentajeContagi << "%" << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de infectados por rango etario (en anios)"<<endl;
    for (int i = 0; i < 13; i++) {
        cout << i * 10 << " y " << (i * 10) + 10 << ": " << edadConfirmados[i] << endl;

    }
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de fallecidos por rango etario (en anios)"<<endl;
    for (int i = 0; i < 13; i++) {
        cout << i * 10 << " y " <<(i * 10) + 10 << ": " << edadFallecidos[i] << endl;
    }
}
