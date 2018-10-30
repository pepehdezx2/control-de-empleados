//  A01381334 Jose Antonio Hernandez Hernandez
//  Empleado.h
//  tarea4empleado
//
//  Created by Jose Antonio on 22/02/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#ifndef Empleado_h
#define Empleado_h
using namespace std;
class Empleado{
public:
    // declaracion de metodos a utilizar en el encabezado...
    Empleado();
    Empleado(int idem, double fixed, double hora, int tiempo);
    void setId(int idem);
    void setFijo(double fixed);
    void setSueldo(double hora);
    void setHoras(int tiempo);
    int getId();
    double getFijo();
    double getSueldo();
    int getHoras();
    double calcSueldo();
private:
    // declaracion de atributos a utilizar en el encabezado...
    int identificacion, extra;
    double fijo, horas;
};
// constructores de clase...
Empleado::Empleado(){
    identificacion=0;
    extra=0;
    fijo=0;
    horas=0;
}
Empleado::Empleado(int idem, double fixed, double hora, int tiempo){
    identificacion=idem;
    extra=tiempo;
    fijo=fixed;
    horas=hora;
}
// definir metodos...
// metodos de modificacion...
void Empleado::setId(int idem){
    identificacion=idem;
}
void Empleado::setFijo(double fixed){
    fijo=fixed;
}
void Empleado::setSueldo(double hora){
    horas=hora;
}
// metodo que suma horas trabajadas...
void Empleado::setHoras(int tiempo){
    extra+=tiempo;
}
// metodos de acceso...
int Empleado::getId(){
    return identificacion;
}
double Empleado::getFijo(){
    return fijo;
}
double Empleado::getSueldo(){
    return horas;
}
int Empleado::getHoras(){
    return extra;
}
// metodo que calcula el sueldo...
double Empleado::calcSueldo(){
    double sueldo;
    sueldo=fijo+(horas*extra);
    return sueldo;
}


#endif /* Empleado_h */
