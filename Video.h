/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Video
 */

#ifndef VIDEO_H
#define VIDEO_H
#include <string>
using std::string;

class Video{

    private:
        string id;
        string nombre;
        string calificacion;
        string duracion;
        string fecha;

    public:
        Video();
        Video(string id, string nombre, string calificacion, string duracion, string fecha);
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

    
};


#endif