/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Episodio
 */

#ifndef EPISODIO_H
#define EPISODIO_H
#include "Video.h"

class Episodio: public Video{
    private:
        string idEp;
        string nombEp;
        string temp;
        string numEp;
    public:
        Episodio();
        Episodio(string id, string nombre, string calificacion, string duracion, string fecha, string genero, string idEp, string nombEp, string temp, string numEp);
        string getIdE();
        void setIdE(string idEp);
        string getNomE();
        void setNomE(string nombEp);
        string getTemp();
        void setTemp(string temp);
        string getNumEp();
        void setNumEp(string numEp);
        void mostrar();
        friend ostream& operator<<(ostream& os, Episodio& e); // Sobrecarga del operador "<<" para imprimir Episodio
};


#endif