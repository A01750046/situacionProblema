
/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Episodio
 */

#include "Episodio.h"

Episodio::Episodio(){
}

Episodio::Episodio(string id, string nombre, string calificacion, string duracion, string fecha, string genero,string idEp, string nombEp, string temp, string numEp):Video(id, nombre, calificacion, duracion, fecha, genero){
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
