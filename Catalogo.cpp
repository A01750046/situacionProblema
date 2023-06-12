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

void Catalogo::desplegarEp(){
    cout<<"Las Series disponibles son: "<<endl;
    vector <string> series;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (find(series.begin(),series.end(), videos[i]->getNom()) == series.end()){
                series.push_back(videos[i]->getNom());
            }
            
        }
    }
    for (int i = 0; i < series.size(); i++) {
        cout << i + 1 << ") " << series[i] << endl;
    }
    string serie = "";
    cout<<"Elige una Serie: ";
    getline(std::cin, serie);
    int contador = 1;
    cout<<endl<<"Los episodios disponibles de la serie "<<serie<<" son: "<<endl<<endl;
    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (videos[i]->getNom() == serie) {
                encontrado = true;
                cout<<contador++<<") Episodio: "<<episodio->getNomE()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Temporada: "<<episodio->getTemp()<<endl
                <<"Número de episodio: "<<episodio->getNumEp()<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl;
            }
        }
    }
    if (encontrado == false){
        cout <<"Tecleaste el nombre de forma incorrecta o alguna serie fuera de nuestro catalogo. Intentalo nuevamante."<<endl;
    }
}

void Catalogo::desplegarPelCal(string calificacion){
    int contador = 1;
    cout<<endl<<"Las películas con una calificacion mayor o igual a "<<calificacion<<" son: "<<endl<<endl;
    for (int i=0;i<videos.size();i++){
        if(stod(videos[i]->getCal())>=stod(calificacion)){
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<videos[i]->getNom()<<endl
                <<"Duracion: "<<videos[i]->getDur()<<" minutos "<<endl
                <<"Fecha de estreno: "<<videos[i]->getFecha()<<endl
                <<"Género: "<<videos[i]->getGenero()<<endl
                <<"Calificación: "<<videos[i]->getCal()<<endl<<endl; 

            }
        }
    }
}

void Catalogo::calificar(){
    int contador = 1;
    cout << "De los siguientes títulos, ¿cuál desas calificar?: "<<endl;
    for (int i=0;i<videos.size();i++){
        Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (pelicula){
            cout<<contador++<<") Pelicula: "<<videos[i]->getNom()<<endl;

        }
        else if (episodio){
            cout<<contador++<<") Episodio: "<<episodio->getNomE()<<endl;
        }

    }
    string titulo = "";
    cout<<"Tu respuesta: ";
    getline(std::cin, titulo);

    string nuevaCal = "7.1";
    while (stod(nuevaCal)> 7||stod(nuevaCal)< 1){
        cout<<"Calificación que se desea asignar (1-7): ";
        cin>>nuevaCal;
    }

    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        if(videos[i]->getNom()==titulo){
            encontrado = true;
            videos[i]->setCal(nuevaCal);
            cout<<endl<<"¡Se asigno la nueva calificacion exitosamente!"<<endl;
            break;
        }
        
    }
    if (encontrado == false){
        cout<<"No se encontró el título, intentelo nuevamente."<<endl;
    }
    


}

void Catalogo::promedioCal(){
    cout<<"Las Series disponibles son: "<<endl;
    vector <string> series;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (find(series.begin(),series.end(), videos[i]->getNom()) == series.end()){
                series.push_back(videos[i]->getNom());
            }
            
        }
    }
    for (int i = 0; i < series.size(); i++) {
        cout << i + 1 << ") " << series[i] << endl;
    }
    string serie = "";
    cout<<"Elige una Serie: ";
    getline(std::cin, serie);
    int contador = 1;
    bool encontrado = false;
    vector <double>episodios;
    double promedio;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (videos[i]->getNom() == serie) {
                encontrado = true;
                episodios.push_back(stod(videos[i]->getCal()));
                double suma = 0;
                for (int i = 0; i < episodios.size(); i++) {
                    suma += episodios[i];
                }
                promedio = suma/episodios.size();
            }

        }
    }
    if (encontrado == false){
        cout <<"Tecleaste el nombre de forma incorrecta o alguna serie fuera de nuestro catalogo. Intentalo nuevamante."<<endl;
    }
    else{
        cout<<endl<<"El promedio de la serie "<<serie<<" es: "<<promedio<<endl;
    }
    
}
