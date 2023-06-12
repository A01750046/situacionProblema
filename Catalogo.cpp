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
        vector<string> datos = separar(linea);
        if (datos.size() == 6)
        {
            string id = datos[0];
            string nombre = datos[1];
            string genero = datos[3];
            string calificacion = datos[4];
            string duracion = datos[2];
            string fecha = datos[5];
            
            Pelicula* p = new Pelicula(id,nombre,calificacion,duracion,fecha,genero);
            videos.push_back(p);
        }
        else
        {
            string id = datos[0];
            string nombre = datos[1];
            string calificacion = datos[4];
            string duracion = datos[2];
            string fecha = datos[5];
            string genero = datos[3];
            string idEp = datos[6];
            string nombEp = datos[7];
            string temp = datos[8];
            string numEp = datos[9];

            Episodio* e = new Episodio(id, nombre, calificacion, duracion, fecha, genero, idEp, nombEp, temp, numEp);
            videos.push_back(e);
        }
    }

    videos.erase(videos.begin());
    
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

void Catalogo::desplegarCal(string calificacion)
{
    int contador = 1;
    cout<<"Los videos con una calificacion mayor o igual a "<<calificacion<<" son: "<<endl<<endl;
    for (int i=0;i<videos.size();i++){
        if(stod(videos[i]->getCal())>=stod(calificacion)){
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
            Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<videos[i]->getNom()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl; 

            }
            else if (episodio){
                cout<<contador++<<") Episodio: "<<episodio->getNomE()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Serie: "<<videos[i]->getNom()<<endl
                <<"Temporada: "<<episodio->getTemp()<<endl
                <<"Número de episodio: "<<episodio->getNumEp()<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl;
            }
            
        }
    }
}

void Catalogo::desplegarGen(string genero){
    int contador = 1;
    cout<<"Los videos con el género "<<genero<<" son: "<<endl<<endl;
    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        if (videos[i]->getGenero().find(genero) != string::npos) {
            encontrado = true;
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
            Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<videos[i]->getNom()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl; 

            }
            else if (episodio){
                cout<<contador++<<") Episodio: "<<episodio->getNomE()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Serie: "<<videos[i]->getNom()<<endl
                <<"Temporada: "<<episodio->getTemp()<<endl
                <<"Número de episodio: "<<episodio->getNumEp()<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl;
            }
    
        }
        
    }
    if (encontrado == false){
        cout <<"No se encontraron videos con este género, intenta de nuevo por favor. Prueba escribirlo sin acetos y con la primer letra mayúscula."<<endl;
    }
}
