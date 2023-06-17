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

Catalogo::Catalogo(Video *p){
    videos.push_back(p);
}

vector<Video> Catalogo::leerArchivo(){
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");//se abre el archivo

    string linea;
    int numeroLinea=0;

    while (getline(entrada, linea))
    {
        vector<string> datos = separar(linea);//Llama funcion separar
        if (datos.size() == 6)//Signiifica que es película pues tiene menos tokens
        {
            string id = datos[0];
            string nombre = datos[1];
            string genero = datos[3];
            string calificacion = datos[4];
            string duracion = datos[2];
            string fecha = datos[5];
            
            Pelicula* p = new Pelicula(id,nombre,calificacion,duracion,fecha,genero);
            videos.push_back(p);// Se agrega al vector
        }
        else //De lo contrario es Episodio pues tiene mas tokens
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
            videos.push_back(e); //Se agrega al vector
        }
    }

    videos.erase(videos.begin());//Se elimina el primer objeto guardado, pues tiene los titulos y nno el contenido
    
    entrada.close();
    

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
                tokens.push_back(dato); // Guarda en el vector
                numeroTokens++;
            
            }
        }

        return tokens;
}

void Catalogo::desplegarCal(string calificacion){ //Se despliegan videos en general por calificacion mayor o igual a la ingresada
    int contador = 1;
    cout<<"Los videos con una calificacion mayor o igual a "<<calificacion<<" son: "<<endl<<endl;
    for (int i=0;i<videos.size();i++){//Se itera el vector
        if(stod(videos[i]->getCal())>=stod(calificacion)){//Se filtra por la calificacion
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);//Se hace downcasting
            Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);//Se hace downcasting
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<endl<<*pelicula<<endl; //Si es película, que se imprima
            }
            else if (episodio){
                cout<<contador++<<") Episodio: "<<endl<<*episodio<<endl; //Si es eepisodio, que se imprima
            }
            
        }
    }
}

void Catalogo::desplegarGen(string genero){
    int contador = 1;
    cout<<"Los videos con el género "<<genero<<" son: "<<endl<<endl;
    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        if (videos[i]->getGenero().find(genero) != string::npos) {//Busca si el genero tecleado esta en el objeto de esa iteración
            encontrado = true;
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
            Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<endl<<*pelicula<<endl;
            }
            else if (episodio){
                cout<<contador++<<") Episodio: "<<endl<<*episodio<<endl;
            }
    
        }
        
    }
    if (encontrado == false){//Manda mensaje de error si no se encuentra el género
        cout <<"No se encontraron videos con este género, intenta de nuevo por favor. Prueba escribirlo sin acetos y con la primer letra mayúscula."<<endl;
    }
}

void Catalogo::desplegarEp(string serie){//desplegar todos los episodios de una serie
    
    int contador = 1;
    cout<<endl<<"Los episodios disponibles de la serie "<<serie<<" son: "<<endl<<endl;
    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (videos[i]->getNom() == serie) {
                encontrado = true;
                cout<<contador++<<") Episodio: "<<endl<<*episodio<<endl;
            }
        }
    }
    if (encontrado == false){
        cout <<"Tecleaste el nombre de forma incorrecta o alguna serie fuera de nuestro catalogo. Intentalo nuevamante."<<endl;
    }

}

void Catalogo::desplegarPelCal(string calificacion){//Se despliegan solo las películas por calificación
    int contador = 1;
    cout<<endl<<"Las películas con una calificacion mayor o igual a "<<calificacion<<" son: "<<endl<<endl;
    for (int i=0;i<videos.size();i++){
        if(stod(videos[i]->getCal())>=stod(calificacion)){
            Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
            if (pelicula){
                cout<<contador++<<") Pelicula: "<<endl<<*pelicula<<endl;
            }
        }
    }
}

void Catalogo::calificar(){//Califica unn video en general
    int contador = 1;
    cout << "De los siguientes títulos, ¿cuál desas calificar?: "<<endl;
    for (int i=0;i<videos.size();i++){//Se imprimen para darle opción al usuario
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
    cin.ignore();
    getline(cin, titulo);//Se toma la respuesta

    string nuevaCal = "7.1";//Verifica que este en el rango
    while (stod(nuevaCal)> 7||stod(nuevaCal)< 1){
        cout<<"Calificación que se desea asignar (1-7): ";
        cin>>nuevaCal;
    }

    bool encontrado = false;
    for (int i=0;i<videos.size();i++){
        if(videos[i]->getNom()==titulo){
            encontrado = true;
            videos[i]->setCal(nuevaCal);//Cambia la calificación
            cout<<endl<<"¡Se asigno la nueva calificacion exitosamente!"<<endl;
            break;
        }
        
    }
    if (encontrado == false){
        cout<<"No se encontró el título, intentelo nuevamente."<<endl;
    }
    


}

void Catalogo::promedioCal(){//Calcula el promedio de una serie por sus episodios
    cout<<"Las Series disponibles son: "<<endl;
    vector <string> series;
    for (int i=0;i<videos.size();i++){
        Episodio* episodio = dynamic_cast<Episodio*>(videos[i]);
        if (episodio){
            if (find(series.begin(),series.end(), videos[i]->getNom()) == series.end()){
                series.push_back(videos[i]->getNom());//Se agregan las series a un vector series
            }
            
        }
    }
    for (int i = 0; i < series.size(); i++) { //Se imprimen las series disponibles
        cout << i + 1 << ") " << series[i] << endl;
    }
    string serie = "";
    cout<<"Elige una Serie: ";
    cin.ignore();
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
                episodios.push_back(stod(videos[i]->getCal()));//Se agregan las calificacioes a un vector
                double suma = 0;
                for (int i = 0; i < episodios.size(); i++) {
                    suma += episodios[i];
                }
                promedio = suma/episodios.size();// Se calcula el promedio
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

void Catalogo::mostrarSeries(){ //Se muestran las series disponibles
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
}
