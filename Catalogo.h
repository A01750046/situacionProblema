/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion de la clase Catalogo
 */

#ifndef CATALOGO_H
#define CATALOGO_H
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include <vector>
using namespace std;

class Catalogo{
    public: 
        vector <Video*> videos;
        Catalogo();
        Catalogo(Video* p);
        vector<Video> leerArchivo();
        vector<string> separar(string linea);
        void desplegar();


        

};



#endif