#include "enrutador.h"

enrutador::enrutador()
{
    string nombre = "";
    conexiones.clear();
}

enrutador::~enrutador()
{

}

string enrutador::getNombre() const
{
    return nombre;
}

void enrutador::setNombre(const string &value) //se modifica el nombre con lo que tiene value
{
    nombre = value;
}

void enrutador::Conectar_Enrutador(const string &name, int costo)
{
    conexiones[name] = costo;
}

void enrutador::eliminar_Enrutador(const string &name)
{
    conexiones.erase(name);
}

void enrutador::Agregar_Conexion(const string &name, const string &anterior, int costo)
{
    costoNodos[name] = make_pair(costo,anterior);
}

void enrutador::TablaConexiones()
{
    if(conexiones.size()<=21){
        cout << " \t";
        for(it=conexiones.begin();it!=conexiones.end();it++){
            cout << it->first << "\t";
        }
        cout << endl << endl << nombre << "\t";
        for(it=conexiones.begin();it!=conexiones.end();it++){
            cout << it->second << "\t";
        }
    }

    cout << endl;
}

void enrutador::TablaCostos()
{
    if(conexiones.size()<=21){
        cout << " \t";
        for(it2=costoNodos.begin();it2!=costoNodos.end();it2++){
            cout << it2->first << "\t";
        }
        cout << endl << endl << nombre << "\t";
        for(it2=costoNodos.begin();it2!=costoNodos.end();it2++){
            cout << it2->second.first << "\t";
        }
    }

    cout << endl;
}
