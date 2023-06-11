/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Video
 */

#include <iostream>
#include "Video.h"
using namespace std;

Video::Video(){
}

Video::Video(string id, string nombre, string calificacion, string duracion, string fecha, string genero){
    this->id = id;
    this->nombre = nombre;
    cout<<" "<<endl;
    this->calificacion = calificacion;
    this->duracion = duracion;
    this->fecha = fecha;
    this->genero = genero;
}

string Video::getId(){
    return id;
}

void Video::setId(string id){
    this->id = id;
}

string Video:: getNom(){
    return nombre;
}

void Video::setNom(string nombre){
    this->nombre = nombre;
}

string Video::getCal(){
    return calificacion;
}

void Video::setCal(string calificacion){
    this->calificacion = calificacion;
}

string Video::getDur(){
    return duracion;
}

void Video::setDur(string duracion){
    this->duracion = duracion;
}

string Video::getFecha(){
    return fecha;
}

void Video::setFecha(string fecha){
    this->fecha = fecha;
}

string Video::getGenero()
{
    return genero;
}

void Video::setGenero(string genero)
{
    this->genero = genero;
}