/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Video
 */

#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using namespace std;

class Video{

    private:
        string id;
        string nombre;
        string calificacion;
        string duracion;
        string fecha;
        string genero;

    public:
        Video();
        Video(string id, string nombre, string calificacion, string duracion, string fecha, string genero);
        string getId();
        void setId(string id);
        string getNom();
        void setNom(string nombre);
        string getCal();
        void setCal(string calificacion);
        string getDur();
        void setDur(string duracion);
        string getFecha();
        void setFecha(string fecha);
        string getGenero();
        void setGenero(string genero);
        virtual void mostrar(); // Función virtual que se reescribirá en sus hijos
        friend ostream& operator<<(ostream& os, Video& v);// Sobrecarga del operador "<<" para imprimir Video
    
};


#endif