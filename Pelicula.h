/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Pelicula
 */

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

class Pelicula: public Video{
    public:
        Pelicula();
        Pelicula(string id, string nombre, string calificacion, string duracion, string fecha, string genero);
        void mostrar();
};


#endif