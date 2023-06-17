/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Pelicula
 */
#include "Pelicula.h"
#include <iostream>
using namespace std;

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string id, string nombre, string calificacion, string duracion, string fecha, string genero): Video(id, nombre, calificacion, duracion, fecha, genero){ //Se usa al constructor del papá
}

void Pelicula::mostrar(){ //Se cambiia, pero a la vez se ocupa el método del papá
    cout << "Pelicula: "<<endl;
    Video::mostrar();
}

ostream &operator<<(ostream &os, Pelicula &p){
    os << "Nombre: " << p.getNom() << endl;
    os << "Duración: " << p.getDur() << " minutos" << endl;
    os << "Fecha de estreno: "<< p.getFecha()<<endl;
    os << "Género: "<< p.getGenero()<<endl;
    os << "Calificación: "<< p.getCal()<<endl<<endl; 
    return os;
}
