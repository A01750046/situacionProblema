/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Pelicula
 */
#include "Pelicula.h"

Pelicula::Pelicula(){
}

Pelicula::Pelicula(string id, string nombre, string calificacion, string duracion, string fecha, string genero): Video(id, nombre, calificacion, duracion, fecha, genero){
}
