#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class enrutador
{
private:
    //caracteristicas privadas
    string nombre;

public:
    //caracteristicas publicas
    map<string,int> conexiones; //Con la funcion map guardo las conexiones su nombre y valor
    map<string,pair<int,string>> costoNodos; //Un map con el costo a cada nodo y el nodo de origen
    map<string,int>::iterator it; //funciones para iterar
    map<string,pair<int,string>>::iterator it2;

    //metodos
    enrutador();
    ~enrutador();
    string getNombre() const;
    void setNombre(const string &value);

    void Conectar_Enrutador(const string &name,int costo);
    void eliminar_Enrutador(const string &name);
    void Agregar_Conexion(const string &name,const string &anterior, int cost);
    void TablaConexiones();
    void TablaCostos();
};

#endif // ENRUTADOR_H

