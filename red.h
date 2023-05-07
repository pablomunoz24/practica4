#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <list>
#include <fstream>
#include<stdlib.h>
#include<time.h>

class red
{
private:
    list <enrutador> n_enrutadores;

    void Conexiones_Iniciales(const string &router_name);
public:
    red();
    ~red();
    void agregar_Enrutador(const string &router_name);
    void eliminar_Enrutador(const string &router_name);
    void Conectar2Enrutadores(const string &name1,const string &name2,int cost);
    void DEsconectar2Enrutadores(const string &name1,const string &name2,int cost);
    int Costo(const string &salida, const string &llegada);
    void MejorCamino(const string &salida, const string &llegada);
    bool comprobar_Enrutador(const string &router_name);
    void Optimizacion(const string &nodoInicial);
    void ActualizarTabla();
    void TablaConexionesRed();
    void TablaCostosRed();
    void TablaConexionesEnrutador(const string &nodo);
    void TablaCostosEnrutador(const string &nodo);
    void OrdenarLista();
    bool ComprobarConexion(const string &nodo,const string &nodo2);

    list<enrutador> getN_enrutadores() const;
    void setN_enrutadores(const list<enrutador> &value);
};

#endif // RED_H
