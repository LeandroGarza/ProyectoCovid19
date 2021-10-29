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

    void edad(int edad);
    int edad();

    void aniosMeses(string anio_meses);
    string aniosMeses();

    void provincia(string provinc);
    string provincia();

    void CUI(string cui);
    string CUI();

    void fechaCUI(string fecha);
    string fechaCUI();

    void fallecio(string estado);
    string fallecio();

    void idProvincia(int idprov);
    int idProvincia();

    void clasificacion(string clasifica);
    string clasificacion();

    datosNecesarios(string linea);

    void analizarDatos(string line);
};

datosNecesarios::datosNecesarios(){
    id = 0;
    edad = 0;
    aniosMeses = "Anios";
    CUI = "NO";
    fechaCUI = "2020-01-01";
    fallecio = "NO";
    IdProvincia = 0;
    Provincia = "SINESPECIFICAR";
    Clasificacion = "N/A";
}

void datosNecesarios:::ID(int idd){
    id = idd;
}
int datosNecesarios::ID(){
    return id;
}

void datosNecesarios::Edad(int edad){
    edad = edad;
}
int datosNecesarios::edad(){
    return edad;
}

void datosNecesarios::aniosMeses(string anioMes){
    aniosMeses = anioMes;
}
string datosNecesarios::aniosMeses(){
    return aniosMeses;
}

void datosNecesarios::provincia(string provinc){
    provincia = provinc;
}
string datosNecesarios::provincia(){
    return provincia;
}

void datosNecesarios::CUI(string cui){
    CUI = cui;
}
string datosNecesarios::Cui(){
    return CUI;
}

void datosNecesarios::fechaCUI(string fecha){
    fechaCUI = fecha;
}
string datosNecesarios::fechaCUI(){
    return fechaCUI;
}

void datosNecesarios::fallecio(string estado){
    fallecio = estado;
}
string datosNecesarios::fallecio(){
    return fallecio;
}

void datosNecesarios::idProvincia(int idprov){
    idProvincia = idprov;
}
int datosNecesarios::provincia_Id(){
    return idProvincia();
}

void datosNecesarios::clasificacion(string clasifica){
    clasificacion = clasifica;
}
string datosNecesarios::clasificacion(){
    return clasificacion;
}

datosNecesarios::datosNecesarios() {}(string line){
    analizarDatos(line);
}

void datosNecesarios::analizarDatos(string line){

    stringstream l(line);
    string palabra;
    for (int columnas = 0; getline(l, palabra, ','); columnas++){
        if (palabra.size() <= 0) {
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
                idCaso = (stoi(palabra));
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

            case 20
                clasificacion = palabra;
                break;
            default:
                break;
        }
    }
}


#endif //PROYECTOCOVID19_DATOSNECESARIOS_H
