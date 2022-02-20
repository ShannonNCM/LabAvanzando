//Shannon C. Morales
//Tarea 1.II.2: Modificar la clase persona agregando los metodos de asignacion:
//  nombre, fecha_nacimiento y lugar_origen. Modificar la clase presona agregando
//  los metodos de obtencion: nombre, anio_nacimiento, mes_nacimiento, dia_nacimiento
//  lugar_origen
//  El archivo ha sido modificado respecto al original para facilitar mi comprension
//  En este archivo se inicializan los constructores de la clase

#include <iostream>
#include "persona.hpp"

using namespace std;

//se incia el atributo de clase, solamente se declara porque es inicializado por el constructor
vector<persona*>persona::instancias;


//constructores
//constructor y destructor por defecto
persona::persona()
{
    //colocar los punteros en cero
    Nombre=0;
    Fecha_nacimiento=0;
    Lugar_nacimiento=0;
    DPI=0;
    //cada instancia(objeto) tiene puntero a si misma llamado 'this'
    //se agrega al vector de punteros 'instancia' la direccion de a case que se cera a llamar
    //  este constructor
    instancias.push_back(this);
}

//constructor y destructor de las caracteristicas
persona::persona(string _Nombre, int _Anio_nacimiento, int _Mes_nacimiento, int _Dia_nacimiento, string _Lugar_origen)
{
    //asigna vaores a las caracteristicas
    Nombre=new string(_Nombre);
    Lugar_nacimiento=new string(_Lugar_origen);
    DPI=0;  //dpi no esta en argumentos, se asigna cero para indicar que no esta asignado
    Fecha_nacimiento=new tm; //es un puntero a estructura de tiempo tm de C
    //asigna datos porporcionados a la estructura
    Fecha_nacimiento->tm_year=_Anio_nacimiento-1900;
    Fecha_nacimiento->tm_mon=_Mes_nacimiento-1;
    Fecha_nacimiento->tm_mday=_Dia_nacimiento;
    //se fija la hora ya que el tiempo internamente se almacena de esa manera
    //el tiempo se almacena en un solo numero y se calcula a patir de las proporciones
    Fecha_nacimiento->tm_sec=0;
    Fecha_nacimiento->tm_min=0;
    Fecha_nacimiento->tm_hour=0;
    //direccion de instancia(objeto) que se crea al vecto de punteros 'instancias'
    instancias.push_back(this);
}
persona::~persona() //remueve la instancia eliminada del vector de punteros 'instancias'
{
    for (auto i = instancias.begin(); i != instancias.end(); i++)
    {
        if (*i==this)
        {
            instancias.erase(i);
            break;
        }  
    }
    delete Nombre;
    delete Fecha_nacimiento;
    delete Lugar_nacimiento;
    delete DPI;
}


//metodos
//asignar dpi
int persona::Asignar_DPI(string Num_CUI)    //devuelve 0 si se asigna, 1 si no se asigna
{
    if (!DPI)
    {
        DPI=new string(Num_CUI);
        return 0;
    }

    cout<<"El DPI ya fue asignado"<<endl;
    return 1;
}

//obtener dpi
string persona::Obtener_DPI()   //devuelve un sting con el num de dpi
{
    if (DPI)
    {
        return *DPI;
    }
    return "DPI no asignado";
}

//decir nombre
void persona::Decir_Nombre()    //indica a la instancia(objeto) que debe imprimir su nombre
{
    if (Nombre)
    {
        cout<<"Mi nombre es: "<<*Nombre<<endl;
    }
    else
    {
        cout<<"Nombre no asignado"<<endl;
    }
}

//decir edad
void persona::Decir_edad()
{
    if (Fecha_nacimiento)
    {
        time_t now;
        float Edad;
        time(&now);
        //funcion difftime da diferencia de tiempo en s, esta se pasa a anios
        //  no es edad calendario
        Edad=difftime(now,mktime(Fecha_nacimiento))/31556925.9747;
        cout<<"Mi edad es: "<<Edad<<" anios"<<endl;
    }
    else
    {
        cout<<"Fecha de nacimiento no asignada"<<endl;
    }
}

//decir origen
void persona::Decir_origen()
{
    if (Lugar_nacimiento)
    {
        cout<<"Soy de "<<*Lugar_nacimiento<<endl;
    }
    else
    {
        cout<<"Lugar de nacimiento no asignado"<<endl;
    }
}

//metodo de clase
//llamar todos
void persona::Llamar_todos()    //llama al metodo decir_nombre de todas as instancias
{
    if (instancias.size()!=0)
    {
        for (auto i = instancias.begin(); i != instancias.end(); i++)
        {
            (*i)->Decir_Nombre();
        }
    }
    else
    {
        cout<<"No hay instancias aun"<<endl;
    }
}

//metodos nuevos
//asignar y obtener nombre
int persona::Asignar_Nombre(string Name)    //asigna el nombre
{
    if (!Nombre)
    {
        Nombre=new string(Name);
        return 0;
    }
    cout<<"El nombre ya fue asignado"<<endl;
    return 1;
}
string persona::Obtener_Nombre()   //devuelve un string con el num de dpi
{
    if (Nombre)
    {
        return *Nombre;
    }
    return "Nombre no asignado";
}

//asignar y obtener fecha
int persona::Asignar_Fecha(int year, int month, int day)    //asigna el nombre
{
    if (!Fecha_nacimiento)
    {
        Fecha_nacimiento=new tm;
        Fecha_nacimiento->tm_year=year;
        Fecha_nacimiento->tm_mon=month;
        Fecha_nacimiento->tm_mday=day;
        return 0;
    }
    cout<<"La fecha de nacimiento ya fue asignada"<<endl;
    return 1;
}

int persona::Obtener_anio_nacimiento()   //devuelve el anio de nacimiento
{
    if (Fecha_nacimiento)
    {
        return Fecha_nacimiento->tm_year;
    }
    cout<<"Anio de nacimiento no asignado"<<endl;
    return 1;
}

int persona::Obtener_mes_nacimiento()   //devuelve el mes de nacimiento
{
    if (Fecha_nacimiento)
    {
        return Fecha_nacimiento->tm_mon;
    }
    cout<<"Mes de nacimiento no asignado"<<endl;
    return 1;
}

int persona::Obtener_dia_nacimiento()   //devuelve el dia de nacimiento
{
    if (Fecha_nacimiento)
    {
        return Fecha_nacimiento->tm_mday;
    }
    cout<<"Dia de nacimiento no asignado"<<endl;
    return 0;
}

//asignar y obtener lugar nacimiento
int persona::Asignar_LugarOrigen(string Place)    //asigna el lugar de origen
{
    if (!Lugar_nacimiento)
    {
        Lugar_nacimiento=new string(Place);
        return 0;
    }
    cout<<"El lugar de origen ya fue asignado"<<endl;
    return 1;
}
string persona::Obtener_Lugar_origen()   //devuelve un string con el lugar de origen
{
    if (Lugar_nacimiento)
    {
        return *Lugar_nacimiento;
    }
    return "Lugar origen no asignado";
}