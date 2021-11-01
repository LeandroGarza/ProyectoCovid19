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

    void id(int id);
    int id();

    void _edad(int edad);
    int _edad();

    void _aniosMeses(string anio_meses);
    string _aniosMeses();

    void _provincia(string provinc);
    string _provincia();

    void _CUI(string cui);
    string _CUI();

    void _fechaCUI(string fecha);
    string _fechaCUI();

    void _fallecio(string estado);
    string _fallecio();

    void _idProvincia(int idprov);
    int _idProvincia();

    void _clasificacion(string clasifica);
    string _clasificacion();

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

void datosNecesarios::id(int idd){
    id_caso = idd;
}
int datosNecesarios::id(){
    return id_caso;
}

void datosNecesarios::_edad(int edad){
    edad = edad;
}
int datosNecesarios::_edad(){
    return edad;
}

void datosNecesarios::_aniosMeses(string anioMes){
    aniosMeses = anioMes;
}
string datosNecesarios::_aniosMeses(){
    return aniosMeses;
}

void datosNecesarios::_provincia(string provinc){
    provincia = provinc;
}
string datosNecesarios::_provincia(){
    return provincia;
}

void datosNecesarios::_CUI(string cui){
    CUI = cui;
}
string datosNecesarios::_CUI(){
    return CUI;
}

void datosNecesarios::_fechaCUI(string fecha){
    fechaCUI = fecha;
}
string datosNecesarios::_fechaCUI(){
    return fechaCUI;
}

void datosNecesarios::_fallecio(string estado){
    fallecio = estado;
}
string datosNecesarios::_fallecio(){
    return fallecio;
}

void datosNecesarios::_idProvincia(int idprov){
    idProvincia = idprov;
}
int datosNecesarios::_idProvincia(){
    return idProvincia;
}

void datosNecesarios::_clasificacion(string clasifica){
    clasificacion = clasifica;
}
string datosNecesarios::_clasificacion(){
    return clasificacion;
}

datosNecesarios::datosNecesarios(string linea){
    analizarDatos(linea);
}

void datosNecesarios::analizarDatos(string linea){

    stringstream l(linea);
    string palabra;
    for(int columnas = 0; getline(l, palabra, ','); columnas++){
        if(palabra.size() <= 0) {
            if(columnas==7){
                palabra = "SINESPECIFICAR";
            }
            if(columnas == 0 || columnas == 2 || columnas == 17) {
                palabra = "404";
            }
            else{
                palabra = "NA";
            }
        }
        else{
            palabra = palabra.substr(1, palabra.size() - 2);
        }
        switch(columnas) {
            case 0:
                id_caso = (stoi(palabra));
                break;

            case 2:
                edad = (stoi(palabra));
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
                idProvincia = (stoi(palabra));
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
