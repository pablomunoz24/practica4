#include <iostream>
#include "red.h"
#include <fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int main()
{
    short opc = 0,costo=0;
    red *network = new red; //Creo una variable tipo red y le reservo espacio de memoria dinamica
    string nombre,nombre2;
    cout<<"          BIENVENIDO AL PROGRAMA PARA ASIGNACION DE ENRUTADORES"<<endl;
    cout << "Ingrese:\n1.Ver tabla de la red.\n2.Ver tabla de un enrutador.\n3.Agregar enrutador a la red.\n";
    cout << "4.Eliminar enrutador de la red.\n5.Conectar 2 enrutadores.\n6.Desconectar 2 enrutadores.\n";
    cout << "7.Conocer costo de envio.\n8.Camino a seguir de un paquete.\n";
    cout << "0.Salir.\nSeleccione una opcion: ";cin >> opc;
    while(opc!=0){
        switch (opc) {
        case 1:{
            cout << "Tabla de conexiones: " << endl;
            cout << "\"Si el valor es -1 los enrutadores no se encunentran conectados directamente.\"\n";
            cout << endl;
            network->TablaConexionesRed();
            cout << "\nTabla de costos: \n" << endl;
            cout << "\"Si el valor es -1 los enrutadores no se puede intercambiar informacion entre los enrutadores.\"\n";
            cout << endl;
            network->TablaCostosRed();
        }
            break;
        case 2:{
            cin.ignore(10000,'\n');
            cout <<"Nombre del enrutador: ";getline(cin,nombre);
            if(network->comprobar_Enrutador(nombre)){
                cout << "Tabla de conexiones:" << endl;
                cout << "\"Si el valor es -1 los enrutadores no se encunentran conectados directamente.\"\n";
                cout << endl;
                network->TablaConexionesEnrutador(nombre);
                cout << "\nTabla de costos:" << endl;
                cout << "\"Si el valor es -1 los enrutadores no se puede intercambiar informacion entre los enrutadores.\"\n";
                cout << endl;
                network->TablaCostosEnrutador(nombre);
            }
            else
                cout << "El enrutador no existe.\n";
        }
            break;
        case 3:{                                //agregar enrutador
            cin.ignore(10000,'\n');
            cout <<"Nombre del enrutador: ";getline(cin,nombre);
            if(network->comprobar_Enrutador(nombre)) //Ingreso a la clase network tipo red y utilizo la funcion com...
                cout << "EL enrutador \"" << nombre << "\" ya existe.\n";
            else{
                network->agregar_Enrutador(nombre);
                network->ActualizarTabla();
                cout << "El enrutador ha sido agregado a la red.\n";
            }
        }
            break;
        case 4:{
            cin.ignore(10000,'\n');
            cout <<"Nombre del enrutador: ";getline(cin,nombre);
            if(network->comprobar_Enrutador(nombre)){
                network->eliminar_Enrutador(nombre);
                network->ActualizarTabla();
                cout << "El enrutador ha sido eliminado de la red.\n";
            }
            else
                cout << "EL enrutador \"" << nombre << "\" no existe.\n";
        }
            break;
        case 5:{
            cin.ignore(10000,'\n');
            cout << "Nombre del primer enrutador: ";getline(cin,nombre);
            cout << "Nombre del segundo enrutador: ";getline(cin,nombre2);
            cout << "costo de de envio: ";cin>>costo;
            if(costo<=0)
                cout << "El costo de envio no puede ser menor o igual a 0.\n";
            else if(network->comprobar_Enrutador(nombre) and network->comprobar_Enrutador(nombre2)){
                network->Conectar2Enrutadores(nombre,nombre2,costo);
                network->ActualizarTabla();
                cout << "Los enrutadores han sido conectados.\n";
            }
            else
                cout << "Uno o ambos enrutados no existen.\n";
        }
            break;
        case 6:{
            cin.ignore(10000,'\n');
            cout << "Nombre del primer enrutador: ";getline(cin,nombre);
            cout << "Nombre del segundo enrutador: ";getline(cin,nombre2);
            if(network->comprobar_Enrutador(nombre) and network->comprobar_Enrutador(nombre2)){
                if(network->Costo(nombre,nombre2)==-1)
                    cout << "los enrutadores" << nombre << " y " << nombre2 << " No estan conectados.\n";
                else{
                    network->Conectar2Enrutadores(nombre,nombre2,-1);
                    network->ActualizarTabla();
                    cout << "Los enrutadores han sido desconectados.\n";
                }
            }
            else
                cout << "Uno o ambos enrutados no existen.\n";
        }
            break;
        case 7:{
            cin.ignore(10000,'\n');
            cout << "Nombre del enrutador que envia: ";getline(cin,nombre);
            cout << "Nombre del enrutador que recibe: ";getline(cin,nombre2);
            if(network->comprobar_Enrutador(nombre) and network->comprobar_Enrutador(nombre2)){
                if(network->Costo(nombre,nombre2)==-1)
                    cout << "los enrutadores" << nombre << " y " << nombre2 << " No estan conectados directa o indirectamente\n";
                else{
                    cout << "El costo desde el enrutador " << nombre << " hasta el enrutador " << nombre2 << " es:\n";
                    cout << nombre << " ----> " << nombre2 << " = "  << network->Costo(nombre,nombre2) << endl;
                }
            }
            else
                cout << "Uno o ambos enrutados no existen.\n";
        }
            break;
        case 8:{
            cin.ignore(10000,'\n');
            cout << "Nombre del enrutador que envia: ";getline(cin,nombre);
            cout << "Nombre del enrutador que recibe: ";getline(cin,nombre2);
            if(network->comprobar_Enrutador(nombre) and network->comprobar_Enrutador(nombre2)){
                if(network->Costo(nombre,nombre2)==-1)
                    cout << "los enrutadores" << nombre << " y " << nombre2 << " No estan conectados directa o indirectamente\n";
                else{
                    cout << "ruta:\n";
                    network->MejorCamino(nombre,nombre2);
                }
            }
            else
                cout << "Uno o ambos enrutados no existen.\n";
        }
            break;

        default:
            cout << "Opcion no valida.\n";
        }
        cout << "\nIngrese:\n1.Ver tabla de la red.\n2.Ver tabla de un enrutador.\n3.Agregar enrutador.\n";
        cout << "4.Eliminar enrutador de la red.\n5.Conectar 2 enrutadores.\n6.Desconectar 2 enrutadores.\n";
        cout << "7.Conocer costo de envio.\n8.Camino a seguir de un paquete.\n";
        cout << "0.Salir.\nSeleccione una opcion: ";cin >> opc;
    }

    delete network;
    return 0;
}
