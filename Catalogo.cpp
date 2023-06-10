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
        if (datos.size() == 6)
        {
            Pelicula p(datos[0],datos[1],datos[4],datos[2],datos[5],datos[3]);
            //cout << "Película";
            videos.push_back(&p);
        }
        else
        {
            //cout << "Episodio";
        }
        cout << endl<<endl;
    }
    
    entrada.close();

    cout<<videos[0]->getGenero()<<endl;

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

        cout << "tokens: " << numeroTokens << endl;

        return tokens;
}

void Catalogo::desplegar()
{
}
