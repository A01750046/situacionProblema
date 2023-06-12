/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Conforma todas las clases para probar el código
 */

#include <iostream>
#include "Video.h"
#include "Catalogo.h"
using namespace std;

int main(int argc, char const *argv[]){
    Catalogo c1;
    c1.leerArchivo();
    //c1.desplegarCal("6");
    //c1.desplegarGen("Fantasia");
    //c1.desplegarEp();
    //c1.desplegarPelCal("5.8");
    //c1.calificar();
    c1.promedioCal();
    

}