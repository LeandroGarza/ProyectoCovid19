#ifndef PROYECTOCOVID19_DATOSNECESARIOS_H
#define PROYECTOCOVID19_DATOSNECESARIOS_H

//el csv que nos dan tiene muchos datos que NUNCA vamos a usar, por lo que aca solo pondremos los que usamos

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class datosNecesarios {
private:
    int id_caso;
    int edad;
    string aniosMeses;
    string provincia;
    string CUI;
    string fechaCUI;
    string fallecio;
    int idProvincia;
    string clasificacion;

public:

    datosNecesarios();

    void set_id(int id);
    int get_id();

    void set_edad(int edad);
    int get_edad();

    void set_aniosMeses(string anio_meses);
    string get_aniosMeses();

    void set_provincia(string provinc);
    string get_provincia();

    void set_CUI(string cui);
    string get_CUI();

    void set_fechaCUI(string fecha);
    string get_fechaCUI();

    void set_fallecio(string estado);
    string get_fallecio();

    void set_idProvincia(int idprov);
    int get_idProvincia();

    void set_clasificacion(string clasifica);
    string get_clasificacion();

    datosNecesarios(string linea);

    void analizarDatos(string line);
};

datosNecesarios::datosNecesarios(){
    id_caso = 0;
    edad = 0;
    aniosMeses = "Anios";
    CUI = "NO";
    fechaCUI = "2020-01-01";
    fallecio = "NO";
    idProvincia = 0;
    provincia = "SINESPECIFICAR";
    clasificacion = "N/A";
}

datosNecesarios::datosNecesarios(string linea){
    analizarDatos(linea);
}

void datosNecesarios::set_id(int idd){
    id_caso = idd;
}
int datosNecesarios::get_id(){
    return id_caso;
}

void datosNecesarios::set_edad(int edad){
    edad = edad;
}
int datosNecesarios::get_edad(){
    return edad;
}

void datosNecesarios::set_aniosMeses(string anioMes){
    aniosMeses = anioMes;
}
string datosNecesarios::get_aniosMeses(){
    return aniosMeses;
}

void datosNecesarios::set_provincia(string provinc){
    provincia = provinc;
}
string datosNecesarios::get_provincia(){
    return provincia;
}

void datosNecesarios::set_CUI(string cui){
    CUI = cui;
}
string datosNecesarios::get_CUI(){
    return CUI;
}

void datosNecesarios::set_fechaCUI(string fecha){
    fechaCUI = fecha;
}
string datosNecesarios::get_fechaCUI(){
    return fechaCUI;
}

void datosNecesarios::set_fallecio(string estado){
    fallecio = estado;
}
string datosNecesarios::get_fallecio(){
    return fallecio;
}

void datosNecesarios::set_idProvincia(int idprov){
    idProvincia = idprov;
}
int datosNecesarios::get_idProvincia(){
    return idProvincia;
}

void datosNecesarios::set_clasificacion(string clasifica){
    clasificacion = clasifica;
}
string datosNecesarios::get_clasificacion(){
    return clasificacion;
}

void datosNecesarios::analizarDatos(string line){

    stringstream l(line);
    string palabra;
    stringstream s(line);
    int total = -1;
    while (getline(s, palabra, ','))
    {
        total++;
        if (palabra.size() > 0)
        {
            palabra = palabra.substr(1, palabra.size() - 2);
        }
        else
        {
            palabra = "NA";
        }
        switch(total) {
            case 0:
                try{
                  id_caso = (stoi(palabra));
                }
                catch(std::invalid_argument e){
                  id_caso = -1;
                }
                break;

            case 2:
                try{
                  edad = (stoi(palabra));
                }
                catch(std::invalid_argument e){
                  edad = -1;
                }
                break;

            case 3:
                aniosMeses = palabra;
                break;
            case 7:
                provincia = palabra;
                break;

            case 12:
                CUI = palabra;
                break;

            case 13:
                fechaCUI = palabra;
                break;

            case 14:
                fallecio = palabra;
                break;

            case 17:
                try{
                  idProvincia = (stoi(palabra));
                }
                catch(std::invalid_argument e){
                  idProvincia = -1;
                }
                break;

            case 20:
                clasificacion = palabra;
                break;
            default:
                break;
      }
  }
}


#endif //PROYECTOCOVID19_DATOSNECESARIOS_H
