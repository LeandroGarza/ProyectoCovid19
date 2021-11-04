#ifndef DATOSPACIENTEF_H
#define DATOSPACIENTEF_H

class DatosPacienteF{
  private:


    int id;
    string sexo;
    int edad;
    string edad_calif;
    string provincia;
    string fecha_inicio_sintomas;
    string cui;
    string fecha_cui;
    string fallecido;
    string fecha_fallecimiento;
    string clasif;
    string fecha_diagnostico;
    bool buscado = false;


  public:
      DatosPacienteF(){
        id = 0;
        sexo = ' ';
        edad = 0;
        edad_calif = "";
        provincia = "";
        fecha_inicio_sintomas = "";
        fecha_cui = "";
        fecha_fallecimiento = "";
        fecha_diagnostico = "";

      };

      DatosPacienteF(int, string, int, string, string, string, string, string, string, string, string, string);

      friend bool operator== (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator!= (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator>= (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator> (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator<= (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator< (const DatosPacienteF& d1, const DatosPacienteF& d2);
      friend bool operator! (const DatosPacienteF& d1);
      friend ostream& operator<<(ostream& os, const DatosPacienteF& d1);
      operator bool() const {return 0 != id;}



      int get_id();
      string get_sexo();
      int get_edad();
      string get_edad_calif();
      string get_provincia();
      string get_fecha_inicio_sintomas();
      string get_cui();
      string get_fecha_cui();
      string get_fallecido();
      string get_fecha_fallecimiento();
      string get_clasif();
      string get_fecha_diagnostico();
      bool get_buscado();

      void set_id(int i);
      void set_sexo(string c);
      void set_edad(int i);
      void set_edad_calif(string s);
      void set_provincia(string s);
      void set_fecha_inicio_sintomas(string s);
      void set_cui(string s);
      void set_fecha_cui(string s);
      void set_fallecido(string s);
      void set_fecha_fallecimiento(string s);
      void set_clasif(string s);
      void set_fecha_diagnostico(string s);
      void set_buscado(bool b);
  };

DatosPacienteF::DatosPacienteF(int m_id, string m_sexo, int m_edad, string m_edad_calif,
    string m_provincia, string m_fecha_inicio_sintomas,
    string m_cui, string m_fecha_cui, string m_fallecido, string m_fecha_fallecimiento,
    string m_clasif, string m_fecha_diagnostico){

    id = m_id;
    sexo = m_sexo;
    edad = m_edad;
    edad_calif = m_edad_calif;
    provincia = m_provincia;
    fecha_inicio_sintomas = m_fecha_inicio_sintomas;
    cui = m_cui;
    fecha_cui = m_fecha_cui;
    fallecido = m_fallecido;
    fecha_fallecimiento = m_fecha_fallecimiento;
    clasif = m_clasif;
    fecha_diagnostico = m_fecha_diagnostico;
    buscado = false;

  }

bool operator== (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.fecha_cui == d2.fecha_cui;
};

bool operator!= (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.id == d2.id;
};

bool operator>= (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.fecha_cui >= d2.fecha_cui;
};
bool operator> (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.fecha_cui > d2.fecha_cui;
};
bool operator<= (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.fecha_cui <= d2.fecha_cui;
};
bool operator< (const DatosPacienteF& d1, const DatosPacienteF& d2){
  return d1.fecha_cui < d2.fecha_cui;
};

bool operator! (const DatosPacienteF& d1){
  return !d1.buscado;
};


ostream& operator<<(ostream& os, const DatosPacienteF& d1){
  os << "Id: " << d1.id << " | " << endl;
  os << "Sexo: " << d1.sexo << " | " << endl;
  os << "Edad: " << d1.edad << " | " << endl;
  os << "Tipo: " << d1.edad_calif << " | " << endl;
  os << "Provincia: " << d1.provincia << " | " << endl;
  os << "Fecha Inicio de Sintomas: " << d1.fecha_inicio_sintomas << " | " << endl;
  os << "Cuidados Intensivos: " << d1.cui << " | " << endl;
  os << "Fecha de Cuidados Intensivos: " << d1.fecha_cui << " | " << endl;
  os << "Fallecido: " << d1.fallecido << " | " << endl;
  os << "Fecha de fallecimiento: " << d1.fecha_fallecimiento << " | " << endl;
  os << "Clasificacion: " << d1.clasif << " | " << endl;
  os << "Fecha de Diagnostico: " << d1.fecha_diagnostico << " | " << endl;
  os << "-----------------------------------------------------------------------------------------------"<<endl;

  return os;
};


int DatosPacienteF::get_id(){
  return id;
};
string DatosPacienteF::get_sexo(){
  return sexo;
};
int DatosPacienteF::get_edad(){
  return edad;
};
string DatosPacienteF::get_edad_calif(){
  return edad_calif;
};
string DatosPacienteF::get_provincia(){
  return provincia;
};
string DatosPacienteF::get_fecha_inicio_sintomas(){
  return fecha_inicio_sintomas;
};
string DatosPacienteF::get_cui(){
  return cui;
};
string DatosPacienteF::get_fecha_cui(){
  return fecha_cui;
};
string DatosPacienteF::get_fallecido(){
  return fallecido;
};
string DatosPacienteF::get_fecha_fallecimiento(){
  return fecha_fallecimiento;
};
string DatosPacienteF::get_clasif(){
  return clasif;
};
string DatosPacienteF::get_fecha_diagnostico(){
  return fecha_diagnostico;
};

bool DatosPacienteF::get_buscado(){
  return buscado;
}

void DatosPacienteF::set_id(int i){
  id = i;
};
void DatosPacienteF::set_sexo(string c){
  sexo = c;
};
void DatosPacienteF::set_edad(int i){
  edad = i;
};
void DatosPacienteF::set_edad_calif(string s){
  edad_calif = s;
};
void DatosPacienteF::set_provincia(string s){
  provincia = s;
};
void DatosPacienteF::set_fecha_inicio_sintomas(string s){
  fecha_inicio_sintomas = s;
};
void DatosPacienteF::set_cui(string s){
  cui = s;
};
void DatosPacienteF::set_fecha_cui(string s){
  fecha_cui = s;
};
void DatosPacienteF::set_fallecido(string s){
  fallecido = s;
};
void DatosPacienteF::set_fecha_fallecimiento(string s){
  fecha_fallecimiento = s;
};
void DatosPacienteF::set_clasif(string s){
  clasif = s;
};
void DatosPacienteF::set_fecha_diagnostico(string s){
  fecha_diagnostico = s;
};

void DatosPacienteF::set_buscado(bool b){
  buscado = b;
}

#endif //DATOSPACIENTEF_H
