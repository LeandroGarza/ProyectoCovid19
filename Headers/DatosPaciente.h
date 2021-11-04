#ifndef DATOSPACIENTE_H
#define DATOSPACIENTE_H


using namespace std;

class DatosPaciente{
  private:


    int id;
    int edad;
    string edad_calif;
    string provincia;
    string cui;
    string fecha_cui;
    string fallecido;
    string clasif;


  public:
      DatosPaciente(){
        id = 0;
        edad = 0;
        edad_calif = "";
        provincia = "";
        fecha_cui = "";

      };

      DatosPaciente(int, string, int, string, string, string, string, string, string, string, string, string);

      friend ostream& operator<<(ostream& os, const DatosPaciente& d1);



      int get_id();
      int get_edad();
      string get_edad_calif();
      string get_provincia();
      string get_cui();
      string get_fecha_cui();
      string get_fallecido();
      string get_clasif();

      void set_id(int i);
      void set_edad(int i);
      void set_edad_calif(string s);
      void set_provincia(string s);
      void set_cui(string s);
      void set_fecha_cui(string s);
      void set_fallecido(string s);
      void set_clasif(string s);
  };

DatosPaciente::DatosPaciente(int m_id, string m_sexo, int m_edad, string m_edad_calif,
    string m_provincia, string m_fecha_inicio_sintomas,
    string m_cui, string m_fecha_cui, string m_fallecido, string m_fecha_fallecimiento,
    string m_clasif, string m_fecha_diagnostico){

    id = m_id;
    edad = m_edad;
    edad_calif = m_edad_calif;
    provincia = m_provincia;
    cui = m_cui;
    fecha_cui = m_fecha_cui;
    fallecido = m_fallecido;
    clasif = m_clasif;

  }

ostream& operator<<(ostream& os, const DatosPaciente& d1){
  os << "Id: " << d1.id << " | " << endl;
  os << "Edad: " << d1.edad << " | " << endl;
  os << "Tipo: " << d1.edad_calif << " | " << endl;
  os << "Provincia: " << d1.provincia << " | " << endl;
  os << "Cuidados Intensivos: " << d1.cui << " | " << endl;
  os << "Fecha de Cuidados Intensivos: " << d1.fecha_cui << " | " << endl;
  os << "Fallecido: " << d1.fallecido << " | " << endl;
  os << "Clasificacion: " << d1.clasif << " | " << endl;
  os << "-----------------------------------------------------------------------------------------------"<<endl;

  return os;
};


int DatosPaciente::get_id(){
  return id;
};
int DatosPaciente::get_edad(){
  return edad;
};
string DatosPaciente::get_edad_calif(){
  return edad_calif;
};
string DatosPaciente::get_provincia(){
  return provincia;
};
string DatosPaciente::get_cui(){
  return cui;
};
string DatosPaciente::get_fecha_cui(){
  return fecha_cui;
};
string DatosPaciente::get_fallecido(){
  return fallecido;
};
string DatosPaciente::get_clasif(){
  return clasif;
};

void DatosPaciente::set_id(int i){
  id = i;
};
void DatosPaciente::set_edad(int i){
  edad = i;
};
void DatosPaciente::set_edad_calif(string s){
  edad_calif = s;
};
void DatosPaciente::set_provincia(string s){
  provincia = s;
};
void DatosPaciente::set_cui(string s){
  cui = s;
};
void DatosPaciente::set_fecha_cui(string s){
  fecha_cui = s;
};
void DatosPaciente::set_fallecido(string s){
  fallecido = s;
};
void DatosPaciente::set_clasif(string s){
  clasif = s;
};


#endif //DATOSPACIENTE_H
