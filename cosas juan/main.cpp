#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include <vector>
#include <cmath>
#include "Hash/HashMap.h"
#include "Arbol/ArbolBinario.h"
using namespace std;


// Clave de Hash analizada aca. Facilita el uso de HashMap con strings
// sin tener que cambiar el codigo
unsigned int getHash(string s, int k){
  unsigned int hash = 0;
  for(int i = 0; i < s.length(); ++i){
    hash += s[i] + i;
  }
  return hash;
}


void chopCSV(string fileName, int lines)
{

    string newName = fileName.substr(0, fileName.find(".csv"));
    newName += to_string(lines) + ".csv";

    fstream fin, fout;
    fin.open("./" + fileName, ios::in);
    fout.open("./" + newName, ios::out);

    string line, word;
    for (int i = 0; i < lines; i++)
    {
        getline(fin, line);
        fout << line << "\n";
    }
}

void exploreCSV(string fileName, HashMap<int, int> hash)
{
    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
        }
        if (row[20].compare("Descartado") == 0)
        {
            int hashed = getHash(row[5], 100);
            hash.set(hashed, hash.get(hashed) + 1);

            confirmed++;
            cout << endl;
        }
    }

    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados." << endl;
}

void exploreHeaders(string fileName)
{

    fstream fin;

    fin.open("./" + fileName, ios::in);

    string headers, header;
    getline(fin, headers);

    stringstream s(headers);
    while (getline(s, header, ','))
    {
        cout << header << endl;
    }
}




HashMap<int, int> loadHashMap(string filepath, int size){
  fstream fin;
  fin.open(filepath, ios::in);

  string text, word;
  getline(fin, text);

  stringstream s(text);

  HashMap<int, int> hashmap(size);
  while (getline(s, word, ',')){
    hashmap.put(getHash(word, size), 0);
  }

  return hashmap;
}


int main(int argc, char **argv)
{

    string filename;

    cout << "Cantidad de argumentos: " << argc << endl; // Debug

    // Carga una tabla de hash de un txt
    HashMap<int, int> contagiadosProvincias = loadHashMap("Archivos/provincias.txt", 100);
    HashMap<int, int> muertosProvincias = loadHashMap("Archivos/provincias.txt", 100);


    for (int i = 0; i < argc; i++)
    {
        cout << "Argumento " << i << ": " << argv[i] << endl;

        // Consigue el archivo en un string
        string argument = argv[i];
        if(argument.substr(argument.size() - 4) == ".csv"){
          filename = argument;
        }
    }

    exploreCSV(filename, contagiadosProvincias);
    contagiadosProvincias.print();

    return 0;
}
