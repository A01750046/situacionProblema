/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion de la clase Catalogo
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Catalogo.h"
using namespace std;


Catalogo::Catalogo(){
}

Catalogo::Catalogo(Video *p)
{
}

vector<Video> Catalogo::leerArchivo(){
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea=0;

    while (getline(entrada, linea))
    {
        //cout<<(numeroLinea++)<<": "<<linea<<endl;
        vector<string> datos = separar(linea);
        //cout<<datos[0]<<endl;
        if (datos.size() == 6)
        {
            string id = datos[0];
            string nombre = datos[1];
            string genero = datos[3];
            string calificacion = datos[4];
            string duracion = datos[2];
            string fecha = datos[5];
            
            Pelicula p(id,nombre,calificacion,duracion,fecha,genero);
            //cout << "Película";
            videos.push_back(&p);
        }
        else
        {
            //cout << "Episodio";
        }
    }
    
    entrada.close();

    //cout<<videos[0]->getGenero()<<endl;
    

    return vector<Video>();
}

vector<string> Catalogo::separar(string linea)
{
    vector<string> tokens; // Componentes de la línea

        stringstream entrada(linea); // flujo de datos a partir de cada una cadena

        string dato; // token individual

        int numeroTokens = 0;
        while (getline(entrada, dato, ',')){
            if (dato != "" && dato != "\n" && dato != "\r"){
                //cout << dato << endl;
                tokens.push_back(dato); // Guarda en el vector
                numeroTokens++;
            
            }
        }
        //cout<<tokens[1]<<endl;
        //cout << "tokens: " << numeroTokens << endl;

        return tokens;
}

void Catalogo::desplegar()
{
    for (int i=0;i<videos.size();i++){
       cout<<i+1<<") "<<videos[i]->getNom()<<endl; 
    }
}
