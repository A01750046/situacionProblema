
/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Episodio
 */

#include "Episodio.h"
#include <iostream>
using namespace std;

Episodio::Episodio(){
}

Episodio::Episodio(string id, string nombre, string calificacion, string duracion, string fecha, string genero,string idEp, string nombEp, string temp, string numEp):Video(id, nombre, calificacion, duracion, fecha, genero){//Se usa een los atriburos que se puede al constructor del papá
    this->idEp = idEp;
    this->nombEp = nombEp;
    this->temp = temp;
    this->numEp = numEp;
}

string Episodio::getIdE(){
    return idEp;
}

void Episodio::setIdE(string idEp){
    this->idEp = idEp;
}

string Episodio::getNomE(){
    return nombEp;
}

void Episodio::setNomE(string nombEp){
    this->nombEp = nombEp;
}

string Episodio::getTemp(){
    return temp;
}

void Episodio::setTemp(string temp){
    this->temp = temp;
}

string Episodio::getNumEp(){
    return numEp;
}

void Episodio::setNumEp(string numEp){
    this->numEp = numEp;
}

void Episodio::mostrar(){// Se cambia todo el método del papá
    cout << "Episodio: "<<endl;
    cout << "Nombre Episodio: "<< getNomE() <<endl
    <<"Duracion: "<<getDur()<<" minutos "<<endl
    <<"Serie: "<<getNom()<<endl
    <<"Temporada: "<<getTemp()<<endl
    <<"Número de episodio: "<<getNumEp()<<endl
    <<"Fecha de estreno: "<<getFecha()<<endl
    <<"Género: "<<getGenero()<<endl
    <<"Calificación: "<<getCal()<<endl<<endl;
}

ostream &operator<<(ostream &os, Episodio &e){
    os << "Nombre Episodio: "<< e.getNomE() <<endl;
    os << "Duración: " << e.getDur() << " minutos" << endl;
    os << "Serie: "<< e.getNom() <<endl;
    os << "Temporada: "<< e.getTemp() <<endl;
    os << "Número de episodio: "<< e.getNumEp() <<endl;
    os << "Fecha de estreno: "<<e.getFecha()<<endl;
    os << "Género: "<<e.getGenero()<<endl;
    os << "Calificación: "<<e.getCal()<<endl<<endl; 
    return os;
}
