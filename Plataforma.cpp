/**
 * Autores: Daniel Makoszay Castañón
 * Carrera: IDM
 * Definicion clase Pelicula
 */

#include "Plataforma.h"
#include <string>
#include <iostream>
using namespace std;

void Plataforma::comenzar(){
    Catalogo c1;
    string respuesta = "s";
    int opcion = 0;
    cout<<endl<<"BIENVENIDE A MAKOCINE"<<endl;
    while(respuesta == "s"){
        cout<<endl;
        cout<<"***** MENU PRINCIPAL *****"<<endl;
        cout<<"1) Cargar el archivo"<<endl;
        cout<<"2) Mostrar videos en general"<<endl;
        cout<<"3) Mostrar todos los episodios de una serie"<<endl;
        cout<<"4) Mostrar peliculas por calificación"<<endl;
        cout<<"5) Calificar un video"<<endl;
        cout<<"6) Calcular promedio de calificaciones de una serie"<<endl;
        cout<<"7) Salir"<<endl;
        cout<<endl;
        cout<<"Elige una opción: ";
        cin>>opcion;
        cout<<endl;

        if (opcion==1){
            c1.leerArchivo();
            cout<<"Archivo leído exitosamente"<<endl;
        }

        if (opcion==2){
            int opcion2 = 0;
            cout<<"***** MOSTRAR VIDEOS EN GENERAL *****"<<endl;
            cout<<"Deseas que se muestren por:"<<endl<<endl;
            cout<<"1) Calificacion mayor o igual a la tecleada"<<endl;
            cout<<"2) Un género seleccionado"<<endl<<endl;
            cout<<"Elige una opción: ";
            cin>>opcion2;
            cout<<endl;

            if (opcion2 == 1){
                string opcion3 = "";
                cout<<"Dame una calificacion (1-7): ";
                cin>>opcion3;
                if (stod(opcion3)>7||stod(opcion3)<1){
                    cout<<"Calificación fuera de rango"<<endl;
                }
                else{
                    c1.desplegarCal(opcion3);
                }

            }

            if (opcion2 == 2){
                string opcion4 = "";
                cout<<"Dame una género: ";
                cin>>opcion4;
                c1.desplegarGen(opcion4);
            }
        }

        if (opcion==3){
            cout<<"***** MOSTRAR EPISODIOS DE UNA SERIE *****"<<endl;
            c1.mostrarSeries();
            string serie = "";
            cout<<"Elige una Serie: ";
            cin.ignore();
            getline(cin, serie);
            c1.desplegarEp(serie);

            
        }

        if (opcion==4){
            cout<<"***** MOSTRAR PELÍCULAS POR CALIFICACIÓN *****"<<endl;
            string opcion5 = "";
            cout<<"Dame una calificacion (1-7): ";
            cin>>opcion5;
            if (stod(opcion5)>7||stod(opcion5)<1){
                cout<<"Calificación fuera de rango"<<endl;
            }
            else{
                c1.desplegarPelCal(opcion5);
            }

        }

        if (opcion==5){
            cout<<"***** CALIFICAR UN VIDEO *****"<<endl;
            c1.calificar();
        }

        if (opcion==6){
            cout<<"***** CALCULAR EL PROMEDIO DE CALIFICACIONES DE UNA SERIE *****"<<endl;
            c1.promedioCal();
        }

        if (opcion==7){
            cout<<"Ciao :)"<<endl;
            respuesta = "n";
            cout<<endl;
        }
    }

}