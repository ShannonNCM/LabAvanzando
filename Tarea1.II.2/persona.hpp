/* 
 * persona.hpp: Definicion de la clase persona.
 * 
 * Ejemplo para la parte III del curso introductorio
 * de ROOT.
 * 
 * Hector Perez, abril 2020
 * 
 */

//Shannon C. Morales
//Tarea 1.II.2: Modificar la clase persona agregando los metodos de asignacion:
//  nombre, fecha_nacimiento y lugar_origen. Modificar la clase presona agregando
//  los metodos de obtencion: nombre, anio_nacimiento, mes_nacimiento, dia_nacimiento
//  lugar_origen
//  El archivo ha sido modificado para facilitar mi comprension
//  En este archivo se define la clase persona

#ifndef __PERSONA_HPP__
#define __PERSONA_HPP__

#include <string>
#include <vector>
#include <ctime>

using namespace std;

//se declara la clase persona
class persona
{
protected:      //no se por que se usa protected en vez de private, aca van las caracteristicas
    //los tipos de variables son punteros (almacena direccion de memoria)
    string* Nombre;
    tm* Fecha_nacimiento;
    string* Lugar_nacimiento;
    string* DPI;
    //atributo(caracteristica) de clase
    //vector de punteros, almacena direciones de cada instancia (objeto)
    static vector<persona*>instancias;

public:     //aca van los metodos
    //constructor (crea objeto inicializando atributos/caracteristicas), constructor por defecto
    persona();
    //constructor que tiene las caracteristicas en protected
    persona(string _Nombre, int _Anio_nacimiento, int _Mes_nacimiento, int _Dia_nacimiento, string _Lugar_origen);
    //destructor
    ~persona();

    //metodos
    int Asignar_DPI(string Num_CUI);    //asigna dpi a una persona con set
    string Obtener_DPI();   //obtiene el dpi de persona con get
    void Decir_Nombre();    //soicita el nombre
    void Decir_edad();      //soicita edad
    void Decir_origen();    //solicita lugar de origen
    //metodo de clase para que todas las instancias (objetos) digan su nombre
    static void Llamar_todos();

    //metodos nuevos
    //metodos de asignacion
    int Asignar_Nombre(string Name);
    int Asignar_Fecha(int year, int month, int day);
    int Asignar_LugarOrigen(string Place);
    //metodos de obtencion
    string Obtener_Nombre();
    int Obtener_anio_nacimiento();
    int Obtener_mes_nacimiento();
    int Obtener_dia_nacimiento();
    string Obtener_Lugar_origen();
};

#endif