//////////////
// PRELUDIO //
//////////////

#include <map>

// Typedef
typedef int Anio;
typedef int Mes;
typedef int Dia;

// MESES
const Mes ENERO = 1;
const Mes FEBRERO = 2;
const Mes MARZO = 3;
const Mes ABRIL = 4;
const Mes MAYO = 5;
const Mes JUNIO = 6;
const Mes JULIO = 7;
const Mes AGOSTO = 8;
const Mes SEPTIEMBRE = 9;
const Mes OCTUBRE = 10;
const Mes NOVIEMBRE = 11;
const Mes DICIEMBRE = 12;


std::map<Mes, int> diasMes = {{ENERO, 31}, {FEBRERO, 28},
                         {MARZO, 31}, {ABRIL, 30},
                         {MAYO, 31}, {JUNIO, 30},
                        {JULIO, 31}, {AGOSTO, 31},
                        {SEPTIEMBRE, 30}, {OCTUBRE, 31},
                        {NOVIEMBRE, 30}, {DICIEMBRE, 31}};


// Ejercicio 1: esBisiesto
bool esBisiesto(Anio anio) {
    bool out = false;
    if(anio % 4==0 ){
        out = true;
    }
    if(anio % 100==0){
        out=false;
    }
    if (anio % 400==0){
        out = true;
    }
    return out;
}

// Ejercicio 2: diasEnMes
int diasEnMes(Anio anio, Mes mes){
    int out;
    if(esBisiesto(anio) & mes==2){
        out=29;
    }
    else{
        out=diasMes[mes];
    }
    return out;
}
//
//

// Para ejercicio 6
class Periodo;

class Fecha {
 public:
  // pre: anio > 0, mes \in [1, 12], dia \in [1, diasEnMes(anio, mes)]
  Fecha(Anio anio, Mes mes, Dia dia);

  Anio anio() const;
  Mes mes() const;
  Dia dia() const;

  bool operator==(Fecha o) const;
  bool operator<(Fecha o) const;

  // Ejercicio 7: sumar período a fecha

 private:
  Anio _anio;
  Mes _mes; 
  Dia _dia;

  // Ejercicio 7: sumar a fecha
  void sumar_anios(int anios);
  void sumar_meses(int meses);
  void sumar_dias(int dias);
};

// Ejercicio 3: Constructor y métodos de Fecha
Fecha::Fecha(Anio anio, Mes mes, Dia dia): _anio(anio), _mes(mes),_dia(dia) {
}

Anio Fecha::anio() const {
    return _anio;
}

// Fecha::mes()
Mes Fecha::mes() const {
    return _mes;
}

// dia
Dia Fecha::dia() const {
    return _dia;
}

// Ejercicio 4: comparadores
bool Fecha::operator==(Fecha o) const {
    bool out=false;
    if( _anio == o.anio() & _mes == o.mes() & _dia ==o.dia()){
        out=true;
    }
    return out;
}

// Fecha::operator<
bool Fecha::operator<(Fecha o) const {
    bool out=false;
    if (_anio < o.anio()) {
        out = true;
    }    
    if( _anio == o.anio() & _mes < o.mes()) {
        out = true;
    }
    if (_anio == o.anio() & _mes == o.mes() &_dia < o.dia()){
        out=true;
    }        
    return out;
}

// Ejercicio 5: comparador distinto
bool operator!=(Fecha f1, Fecha f2) {
}

// Ejercicio 6: clase período
class Periodo {
};


// Ejercicio 8: clase Intervalo
