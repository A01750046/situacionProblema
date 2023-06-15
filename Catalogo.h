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
        void desplegarCal(string calificacion);
        void desplegarGen(string genero);
        void desplegarEp(string serie);
        void desplegarPelCal(string calificacion);
        void calificar();
        void promedioCal();
        void mostrarSeries();


        

};



#endif