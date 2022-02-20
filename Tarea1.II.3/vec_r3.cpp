//Shannon C. Morales
//Tarea 1.II.3: Definicion e implementacion de una clase de vectores en tres dimensiones, realizando
//  sobrecarga de operadores
//  inicializacion de los constructores y metodos de la clase

#include <iostream>
#include <cmath>
#include "vec_r3.hpp"

using namespace std;

//atributo de clase
bool vec_r3::esferica=false;    //inicializa la variable 'esferica'


//constructor y destructor
vec_r3::vec_r3()  //constructor por defecto
{
    //inicializan las variables de las coordenadas
    x, y, z=0;
}
vec_r3::vec_r3(float _x, float _y, float _z)    //constructor con argumentos
{
    x=_x;
    y=_y;
    z=_z;
}
vec_r3::~vec_r3()   //destructor
{
}

//metodos
//asignacion de coordenadas
void vec_r3::asignar_x(float _x)
{
    x=_x;
}
void vec_r3::asignar_y(float _y)
{
    y=_y;
}
void vec_r3::asignar_z(float _z)
{
    z=_z;
}
void vec_r3::asignar_xyz(float _x, float _y, float _z)
{
    x=_x;
    y=_y;
    z=_z;
}
//obtencion de coordenadas
float vec_r3::obtener_x() const
{
    return x;
}
float vec_r3::obtener_y() const
{
    return y;
}
float vec_r3::obtener_z() const
{
    return z;
}
//magnitud del vector
float vec_r3::magnitud() const
{
    return sqrt(x*x + y*y + z*z);
}
//mostrar esfericas
void vec_r3::mostrar_esfericas( bool valor )
{
    esferica = valor;
    if (esferica==true)
    {
        cout<<"Coordendas esfericas activadas"<<endl;
    }
    else
    {
        cout<<"Coordenadas rectangulares activadas"<<endl;
    }
    
}

//sobrecarga de operadores
vec_r3 vec_r3::operator+(const vec_r3& vec) const   //suma de vectores
{
    //declara un vector temporal para almacenar resultados
    vec_r3 tmp;
    //'this' quiere decir el primer operando, al que se le suma el otro vector 'vec'
    //  entonces de 'this' su coordenada mas la coordenada de 'vec'
    tmp.x=this->x+vec.x;
    tmp.y=this->y+vec.y;
    tmp.z=this->z+vec.z;
    return tmp;
}
vec_r3 vec_r3::operator-(const vec_r3& vec) const    //resta de vectores
{
    vec_r3 tmp;
    tmp.x=this->x-vec.x;
    tmp.y=this->y-vec.y;
    tmp.z=this->z-vec.z;
    return tmp;
}
float vec_r3::operator*(const vec_r3& vec) const  //producto punto de vectores
{
    float tmp;
    tmp=this->x*vec.x + this->y*vec.y + this->z*vec.z;
    return tmp;
}
vec_r3 vec_r3::operator%(const vec_r3& vec) const  //producto cruz de dos vectores
{
    vec_r3 tmp;
    tmp.x=this->y*vec.z - this->z*vec.y;
    tmp.y=this->z*vec.x - this->x*vec.z;
    tmp.z=this->x*vec.y - this->y*vec.x;
    return tmp;
}
vec_r3 vec_r3::operator=(const vec_r3& vec) //asignacion
{
    this->x=vec.x;
    this->y=vec.y;
    this->z=vec.z;
    return(*this);
}
bool vec_r3::operator==(const vec_r3& vec)    //comparacion
{
    if (this->x==vec.x && this->y==vec.y && this->z==vec.z)    //se evalua si las coordenadas son iguales
    {
        cout<<"Los vectores son iguales"<<endl;
    }
    else
    {
        cout<<"los vectores son distintos"<<endl;
    }
    return 1;
}

//funciones amigas, no son metodos de los objetos, pero pueden acceder a sus atributos privados
vec_r3 operator-(const vec_r3& vec)    //da el valor negativo del vector
{
    vec_r3 tmp;
    tmp.x=-1*vec.x;
    tmp.y=-1*vec.y;
    tmp.z=-1*vec.z;
    return tmp;
}
vec_r3 operator*(const vec_r3& vec, const float &escalar)  //producto por escalar float
{
    vec_r3 tmp;
    tmp.x=vec.x*escalar;
    tmp.y=vec.y*escalar;
    tmp.z=vec.z*escalar;
    return tmp;
}
vec_r3 operator/(const vec_r3& vec, const float &escalar)  //division por escalar float
{
    vec_r3 tmp;
    tmp.x=vec.x/escalar;
    tmp.y=vec.y/escalar;
    tmp.z=vec.z/escalar;
    return tmp;
}
vec_r3 operator*(const float &_escalar, const vec_r3 &vec)  //float por vector
{
    vec_r3 tmp;
    tmp.x=_escalar*vec.x;
    tmp.y=_escalar*vec.y;
    tmp.z=_escalar*vec.z;
    return tmp;
}
ostream& operator<<(ostream& _cout, const vec_r3& vec)  //mostrar el vector
{
    if (vec_r3::esferica)
    {
        //cout<<"Coordendas esfericas activadas"<<endl;
        float a=sqrt(vec.x*vec.x + vec.y*vec.y);
        float theta=atan2(a,vec.z);
        float phi=atan2(vec.y, vec.x);
        _cout<<"r= "<<vec.magnitud()<<", theta(rad)= "<<theta<<", phi(rad)= "<<phi;
    }
    else
    {
        _cout<<"<"<<vec.x<<","<<vec.y<<","<<vec.z<<">";
    }
    return _cout;
}