#include <iostream>
#include "Headers/Lista.h"
#include "Headers/DatosPaciente.h"
#include "Headers/DatosPacienteF.h"
#include "Headers/HashMap.h"
#include "Headers/ArbolBinario.h"
#include <fstream>
#include <sstream>

using namespace std;

void p_casos(string&, int);
void p_muertes(string&, int);
void quickSortK(int *arr, string *arr2, int start, int end); // ordenar arreglo de strings basado en arreglo de ints
void casos_cui(string&, string&); //recibe la fecha y el nombre de archivo
void casos_edad(string&, int);
void estad(string&); //mostrara las estadisticas

int getHash(string s){
  int hash = 0;
  for(int i = 0; i < s.length(); ++i){
    hash += (s[i]);
  }
  hash += s.size() + s[0];
  return hash;
}


HashMap<int, int> loadHashMap(const string& filepath, int size){
  fstream fin;
  fin.open(filepath, ios::in);

  string text, word;
  getline(fin, text);

  stringstream s(text);

  HashMap<int, int> hashmap(size);
  while (getline(s, word, ',')){
    word = word.substr(1, word.size() - 2);
    hashmap.put(getHash(word), 0);
  }

  return hashmap;
}


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

void p_casos(string& archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<int, int> casos = loadHashMap("provincias.txt", 100);

    fstream fin;
    string provincia, clasif;
    int hash;
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
            if(!palabra.empty()){
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

void p_muertes(string& archivo, int numero){

    string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
    HashMap<int, int> muertes = loadHashMap("provincias.txt", 100);
    string provincia, fallecido;
    int hash;
    int ordenados[24];

    fstream fin;
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
      string line;
      string palabra;
      getline(fin, line);
      while(getline(fin, line)){
        int total = 0;
        stringstream s(line);
        while (getline(s, palabra, ',')){
          if(palabra.size() > 0){
            palabra = palabra.substr(1, palabra.size() - 2);
            if(total == 0){dato.set_id(stoi(palabra));}
            else if(total == 1){dato.set_sexo(palabra);}
            else if(total == 2){dato.set_edad(stoi(palabra));}
            else if(total == 3){dato.set_edad_calif(palabra);}
            else if(total == 7){dato.set_provincia(palabra);}
            else if(total == 8){dato.set_fecha_inicio_sintomas(palabra);}
            else if(total == 12){dato.set_cui(palabra);}
            else if(total == 13){dato.set_fecha_cui(palabra);}
            else if(total == 14){dato.set_fallecido(palabra);}
            else if(total == 15){dato.set_fecha_fallecimiento(palabra);}
            else if(total == 20){dato.set_clasif(palabra);}
            else if(total == 22){dato.set_fecha_diagnostico(palabra);}
          }
          total++;
        }

        if(dato.get_cui() == "SI" && dato.get_fecha_cui() >= fecha){
          casos.put(dato);
        }
      }

  }
  casos.inorder();

}

void casos_edad(string& archivo, int edad){
  ArbolBinario<DatosPaciente> casos;
  DatosPaciente dato;

  const string provincias[] = {"Buenos Aires","CABA","Catamarca","Chaco","Chubut","Córdoba","Corrientes","Entre Ríos","Formosa","Jujuy","La Pampa","La Rioja","Mendoza","Misiones","Neuquén","Río Negro","Salta","San Juan","San Luis","Santa Cruz","Santa Fe","Santiago del Estero","Tierra del Fuego","Tucumán"};
  Lista<DatosPaciente> ordenado;

  fstream fin;
  fin.open(archivo, ios::in);
  if(fin.fail()){
      cout<<"No se pudo abrir el csv"<<endl;
  }
  else{
      string line;
      string palabra;
      getline(fin, line);
      while(getline(fin, line)){
        int total = 0;
        stringstream s(line);
        while (getline(s, palabra, ',')){
          if(palabra.size() > 0){

            palabra = palabra.substr(1, palabra.size() - 2);
            if(total == 0){dato.set_id(stoi(palabra));}
            else if(total == 1){dato.set_sexo(palabra);}
            else if(total == 2){dato.set_edad(stoi(palabra));}
            else if(total == 3){dato.set_edad_calif(palabra);}
            else if(total == 7){dato.set_provincia(palabra);}
            else if(total == 8){dato.set_fecha_inicio_sintomas(palabra);}
            else if(total == 12){dato.set_cui(palabra);}
            else if(total == 13){dato.set_fecha_cui(palabra);}
            else if(total == 14){dato.set_fallecido(palabra);}
            else if(total == 15){dato.set_fecha_fallecimiento(palabra);}
            else if(total == 20){dato.set_clasif(palabra);}
            else if(total == 22){dato.set_fecha_diagnostico(palabra);}
          }
          total++;
        }
        casos.put(dato);
      }

  }

  DatosPaciente buscando, encontrado;
  buscando.set_edad(edad);

  while(true){
    try{
      encontrado = casos.search(buscando);
      ordenado.insertarUltimo(encontrado);
    }
    catch(int error){
      break;
    }
  }

  for(int j = 0; j < 23; j++){
      for(int i = 0; i < ordenado.getTamanio(); i++){
        if(ordenado.getDato(i).get_provincia() == provincias[j]){
          cout<<encontrado;
        }
    }
  }

}

void estad(string& archivo){
    unsigned int cantidadCasos = 0;

    unsigned int edadConfirmados[10] = {0};   //dice rango etario 10 anios
    unsigned int edadFallecidos[10] = {0};

    int contagiados = 0 , fallecidos = 0;


    bool anios;
    int edad, total;
    unsigned int debug = 0;
    fstream fin;
    fin.open(archivo, ios::in);
    if(fin.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
    }
    else{
        string line, palabra;
        getline(fin,line);
        while(getline(fin,line)){

            debug++;
            if(debug % 199000 == 0){
              cout<< (debug)<<endl;
            }
            cantidadCasos++;
            stringstream s(line);
            total = 0;
            anios = false;
            while (getline(s, palabra, ',')){
              if(palabra.size() > 0){
                palabra = palabra.substr(1, palabra.size() - 2);
                if(total == 2){edad = stoi(palabra);}
                else if(total == 3 && palabra == "Años"){anios = true;}
                else if(total == 14 && palabra == "SI")
                {
                  ++fallecidos;
                  if(anios){
                    edadFallecidos[edad/10]++;
                  }
                  else{
                    edadFallecidos[0]++;
                  }
                }
                else if(palabra == "Confirmado"){
                  ++contagiados;
                  if(anios){
                    edadConfirmados[edad/10]++;
                  }
                  else{
                    edadConfirmados[0]++;
                  }
                  }
                }
                total++;
              }

            }
          }

    float porcentajeFallec, porcentajeContagi;
    porcentajeFallec = (fallecidos/contagiados) * 100;
    porcentajeContagi = (contagiados/cantidadCasos) * 100;

    cout << "Cantidad de muestras: " << cantidadCasos << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de fallecidos: " << fallecidos << endl;
    cout << "Cantidad de contagiados: " << contagiados << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Porcentaje de Fallecidos sobre Contagiados: " << porcentajeFallec << "%" << endl;
    cout << "Porcentaje de Contagiados sobre Total de Muestras: " << porcentajeContagi << "%" << endl;
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de infectados por rango etario (en anios)"<<endl;
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << " y " << (i * 10) + 10 << ": " << edadConfirmados[i] << endl;

    }
    cout << "----------------------------------------------------------"<<endl;
    cout << "Cantidad de infectados por rango etario (en anios)"<<endl;
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << " y " <<(i * 10) + 10 << ": " << edadFallecidos[i] << endl;
    }
}
