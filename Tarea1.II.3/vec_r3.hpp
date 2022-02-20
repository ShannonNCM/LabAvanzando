//Shannon C. Morales
//Tarea1.II.3: Definicion e implementacion de una clase de vectores en tres dimensiones, realizando
//  sobrecarga de operadores
//  Definicion de la clase

#ifndef __vecr3_hpp__
#define __vecr3_hpp__

#include <iostream>
#include <string>

using namespace std;

//se declara la clase vecr3
class vec_r3
{
private:    //caracteristicas de la clase
    //se declaran las coordenadas
    float x, y ,z;
    //atributo de clase, vector en coordenadas esfericas
    static bool esferica;
public:     //metodos
    //constructor y destructor
    vec_r3();   //constructor sin argumentos
    vec_r3(float _x, float _y, float _z);     //constructor
    ~vec_r3();  //destructor
    
    //metodos
    //asignacion de coordenadas
    void asignar_x(float _x);
    void asignar_y(float _y);
    void asignar_z(float _z);
    void asignar_xyz(float _x, float _y, float _z);
    //obtencion  de coordenadas
    //se usa 'const' para indicar que los metodos no alteran los valores de
    //  la instancia que los llama
    float obtener_x() const;
    float obtener_y() const;
    float obtener_z() const;
    //magnitud del vector
    float magnitud() const;
    //mostrar coordenas polares
    static void mostrar_esfericas(bool valor);

    //sobrecarga de operadores
    //'const' impide que el argumento del operador pueda ser
    //  modificado dentro del metodo
    //'&' se utiliza como un pase por referencia, es decir, pasa el original, se
    //  usa porque es caro copiar esos objetos (listas, vectores...)
    vec_r3 operator+(const vec_r3&) const;  //suma
    vec_r3 operator-(const vec_r3&) const;  //resta
    float operator*(const vec_r3&) const;   //producto punto
    vec_r3 operator%(const vec_r3&) const;  //prod cruz
    vec_r3 operator=(const vec_r3&);  //asignacion
    bool operator==(const vec_r3&);   //comparacion

    //funciones amigas
    friend vec_r3 operator-(const vec_r3&);   //negacion
    friend vec_r3 operator*(const vec_r3&, const float &);  //producto por float
    friend vec_r3 operator/(const vec_r3&, const float &);  //div por un float
    friend vec_r3 operator*(const float &, const vec_r3&); //mult float por un vector
    //el operador cout, funciona como cout<<var, como tiene dos parametros estos
    //  se colocan dentro del parentesis
    friend ostream &operator<<(ostream&, const vec_r3&);  //despliega vector
};

#endif