//Shannon C. Morales
//Tarea 1.II.3: Definicion e implementacion de una clase de vectores en tres dimensiones, realizando
//  sobrecarga de operadores
//  Implementacion de la clase

#include <cstdlib>
#include <iostream>
#include "vec_r3.hpp"

using namespace std;

int main()
{
    vec_r3 v1(1,1,1); //se crean los objetos
    vec_r3 v2(2,3,5);
    vec_r3 v3;
    vec_r3 v4;
    vec_r3 v5(2,3,5);
    vec_r3 v6;
    vec_r3 v7(1,2,3);
    vec_r3 v8;

    v8.asignar_x(7);    //asignar x
    v8.asignar_y(4);    //asignar y
    v8.asignar_z(1);    //asignar z
    cout<<"v8= "<<v8<<endl;
    v8.asignar_xyz(8,8,8);  //asignar xyz
    cout<<"v8= "<<v8<<endl;
    cout<<"v1= "<<v1<<endl; //mostrar el vector
    cout<<"v2= "<<v2<<endl;
    cout<<"v1_x= "<<v1.obtener_x()<<endl;   //obtener coordenadas
    cout<<"v2_y= "<<v2.obtener_y()<<endl;
    cout<<"v2_z= "<<v2.obtener_z()<<endl;
    cout<<"Magnitud v1 "<<v1.magnitud()<<endl;  //magnitud de vector
    cout<<"Magnitud v2 "<<v2.magnitud()<<endl;
    v3=v1+v2;   //suma
    cout<<"v1+v2= "<<v3<<endl;
    v4=v1-v2;   //resta
    cout<<"v1-v2= "<<v4<<endl;
    cout<<"v1*v2= "<<v1*v2<<endl;   //prodcuto punto
    cout<<"v1xv2= "<<v1%v2<<endl;   //prodcuto cruz
    v6=v7;  //asignacion
    cout<<"v6= "<<v6<<endl;
    v1==v2; //comparacion
    v2==v5;
    cout<<"-v2= "<<-v2<<endl; //negativo del vector
    cout<<"v1*2= "<<v1*2<<endl; //producto por escalar
    cout<<"v2/3= "<<v2/3<<endl; //division por escalar
    cout<<"3*v2= "<<3*v2<<endl; //escalar por vector
    vec_r3::mostrar_esfericas(true);    //mostrar en esfericas
    cout<<"v2= "<<v2<<endl;
    vec_r3::mostrar_esfericas(false);   //mostara en rectangulares
    cout<<"v2= "<<v2<<endl;

    return 0;
}
