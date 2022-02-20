//Shannon C. Morales
//Tarea 1.II.2: Modificar la clase persona agregando los metodos de asignacion:
//  nombre, fecha_nacimiento y lugar_origen. Modificar la clase presona agregando
//  los metodos de obtencion: nombre, anio_nacimiento, mes_nacimiento, dia_nacimiento
//  lugar_origen
//  el archivo ha sido modificado respecto al original para facilitar mi comprension
//  en este archivo se inicializan los constructores de la clase

#include <cstdlib>
#include <iostream>
#include "persona.hpp"

using namespace std;

int main()
{
    /*persona Fulano;     //se crea un objeto
    Fulano.Decir_Nombre();
    Fulano.Decir_origen();
    Fulano.Decir_edad();

    persona Juan("Juan Perez", 1980, 7, 2, "Capital"); //se crea otro objeto
    Juan.Decir_Nombre();
    Juan.Decir_origen();
    Juan.Decir_edad();
    Juan.Asignar_DPI("1980130130101");
    Juan.Obtener_DPI();

    persona* Maria=new persona("Maria Gomez", 1990, 12, 3, "Zacapa");

    persona::Llamar_todos();

    delete Maria;*/

    //prueba de los otros metodos
    persona p1; //creamos el objeto persona
    p1.Asignar_Nombre("Suga");
    p1.Asignar_DPI("06132013");
    p1.Asignar_Fecha(1993,3,9);
    p1.Asignar_LugarOrigen("Daegu");
    
    cout<<"Nombre: "<<p1.Obtener_Nombre()<<endl;
    cout<<"ID: "<<p1.Obtener_DPI()<<endl;
    cout<<"Anio: "<<p1.Obtener_anio_nacimiento()<<endl;
    cout<<"Mes: "<<p1.Obtener_mes_nacimiento()<<endl;
    cout<<"Dia: "<<p1.Obtener_dia_nacimiento()<<endl;
    cout<<"Ciudad: "<<p1.Obtener_Lugar_origen()<<endl;

    persona::Llamar_todos();

    return 0;
}