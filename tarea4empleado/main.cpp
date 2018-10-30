//  A01381334 Jose Antonio Hernandez Hernandez
//  main.cpp
//  tarea4empleado
//
//  Created by Jose Antonio on 22/02/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//
//
//  main.cpp
//  tarea4
//
//  Created by Jose Antonio on 21/02/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//  algoritmo
//  declarar archivo de entrada, arreglo de objetos y variables
//  ciclo que lee el archivo de entrada y guarda en variables los datos para cada objetos
//  con metodos de acceso construir el arreglo de objetos
//  incluir contador con el tamaño de el arreglo
//  imprimir opciones
//  hacer un ciclo que lea la opcion que tome el usuario y mandarla a un switch
//  definir que hara cada caso en el switch
//  cerrar archivo den entrada
//  casos de prueba
//  entrar el archivo de Empleados.txt
//  presionar A 1 1 se modificara su sueldo fijo a 1
//  presionar B 3 dira que el usuario no existe
//  presionar B 2 -1 dira que el valor es invalido
//  presionar D 2 dira que su sueldo es 23
//  presionar E dira que el sueldo del 1 es 13 y del 2 23
//  presionar F y terminara el programa

#include <iostream>
#include <string>
#include <fstream>
#include "Empleado.h"
using namespace std;
int main() {
    // declaracion de archivo de entrada...
    ifstream archivoentrada("Empleados.txt");
    // declaracion de arreglo de objetos tipo empleado...
    Empleado arre[20];
    // declaracion de variables...
    int idem, trabajadas, empleado, seguir, c=0;
    double porhora, fijo, sueldo;
    string continuar;
    char casos;
    // ciclo que lee el archivo de entrada hasta que termina y guarda en variables los atributos de los objetos...
    while( !archivoentrada.eof()){
        archivoentrada >> idem;
        archivoentrada >> fijo;
        archivoentrada >> porhora;
        archivoentrada >> trabajadas;
        // uso de los metodos de modificacion para llenar el arreglo de objetos...
        arre[c].setId(idem);
        arre[c].setFijo(fijo);
        arre[c].setSueldo(porhora);
        arre[c].setHoras(trabajadas);
        c++;
    }
    // menu que imprime para modificar o agregar horas de trabajo y sueldos...
    cout << "presiona A para modificar sueldo fijo" << endl;
    cout << "presiona B para modificar sueldo por horas" << endl;
    cout << "presiona C para registrar horas trabajadas" << endl;
    cout << "presiona D para calcualar pago del empleado" << endl;
    cout << "presiona E para ver lista de empleados" << endl;
    cout << "presiona F para terminar" << endl;
    // ciclo que realiza la actividad que se pida...
    do{
        // recibe el caracter que el usuario quiere usar y pasa a un switch son los casos...
        cin >> casos;
        // switch con los casos...
        switch (casos)
        {
            case 'A':
                // pregunta al usuario el id y nuevo sueldo si no son validos le dice al usuario...
                cout << "cual es el id del empleado" << endl;
                cin >> idem;
                empleado=21;
                for (int i=0; i<=c; i++){
                    if (idem==arre[i].getId()){
                        empleado=i;
                        cout << "nuevo sueldo fijo" << endl;
                        cin >> fijo;
                        if(fijo>=0){
                            arre[empleado].setFijo(fijo);
                            seguir=0;
                        }
                        else{
                            cout << "el valor no es valido" << endl;
                        seguir=0;
                        }
                    }
                }
                if(empleado==21){
                    cout << "el empleado no existe" << endl;
                }
                seguir=0;
                break;
            case 'B':
                // pregunta al usuario el id y nuevo sueldo si no son validos le dice al usuario...
                cout << "cual es el id del empleado" << endl;
                cin >> idem;
                empleado=21;
                for (int i=0; i<=c; i++){
                    if (idem==arre[i].getId()){
                        empleado=i;
                        cout << "nuevo sueldo por hora" << endl;
                        cin >> porhora;
                        if(porhora>=0){
                            arre[empleado].setSueldo(porhora);
                            seguir=0;
                        }
                        else{
                            cout << "el valor no es valido" << endl;
                            seguir=0;
                        }
                    }
                }
                if(empleado==21){
                    cout << "el empleado no existe" << endl;
                }
                seguir=0;
                
                break;
            case 'C':
                // pregunta al usuario el id y nlas horas trabajadas si no son validos le dice al usuario...
                cout << "cual es el id del empleado" << endl;
                cin >> idem;
                empleado=21;
                for (int i=0; i<=c; i++){
                    if (idem==arre[i].getId()){
                        empleado=i;
                        cout << "horas trabajadas" << endl;
                        cin >> trabajadas;
                        if(trabajadas>=0){
                            arre[empleado].setHoras(trabajadas);
                            seguir=0;
                        }
                        else{
                            cout << "el valor no es valido" << endl;
                            seguir=0;
                        }
                    }
                }
                if(empleado==21){
                    cout << "el empleado no existe" << endl;
                }
                seguir=0;
                
                
                
                break;
            case 'D':
                // pregunta al usuario el id y calcula su sueldo total si no son validos le dice al usuario...
                cout << "cual es el id del empleado" << endl;
                cin >> idem;
                empleado=21;
                for (int i=0; i<=c; i++){
                    if (idem==arre[i].getId()){
                        empleado=i;
                        sueldo=arre[empleado].calcSueldo();
                        cout << "el sueldo del empleado es: " << sueldo << endl;
                        seguir=0;
                        }
                }
                if(empleado==21){
                    cout << "el empleado no existe" << endl;
                }
                seguir=0;
                
                
                break;
            case 'E':
                // imprime lista de empleados con todos sus datos...
                for (int cont=0; cont<c; cont++){
                    cout << "el empleado con id de " << arre[cont].getId() << " tiene un sueldo fijo de " << arre[cont].getFijo() << " un sueldo por hora de " << arre[cont].getSueldo() << " trabajo un total de " << arre[cont].getHoras() << " horas lo cual corresponde a un sueldo final de " << arre[cont].calcSueldo() << endl;
                }
                seguir=0;
                break;
            case 'F':
                // termina el ciclo...
                seguir=1;
        }
        
    }while (seguir==0);
    // cierra el archivo de entrada...
    archivoentrada.close();
    return 0;
}
