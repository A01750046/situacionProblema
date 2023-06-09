/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Leer archivo
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


vector<string> separar(string linea);

int main(int argc, char const *argv[])
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");

    string linea;
    int numeroLinea;

    while (getline(entrada, linea))
    {
        // cout<<(numeroLinea++)<<": "<<linea<<endl;
        vector<string> datos = separar(linea);

        if (datos.size() == 6)
        {
            cout << "Pelicula";
        }
        else
        {
            cout << "Episodio";
        }
        cout<<endl;
    }

    entrada.close();

    return 0;
}

vector<string> separar(string linea)
{

    vector<string> tokens; // Componentes de la línea

    stringstream entrada(linea); // flujo de datos a partir de cada una cadena

    string dato; // token individual

    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            //cout << dato << endl;
            tokens.push_back(dato); // Guarda en el vector
            numeroTokens++;
        }
    }

    //cout << "tokens: " << numeroTokens << endl

    return tokens;
}