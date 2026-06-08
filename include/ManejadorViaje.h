#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H

#include <map>
#include <string>
#include "DTFecha.h"
#include "Viaje.h"
#include "Vehiculo.h"
#include <set>
#include "DTListarViaje.h"

class ManejadorViajes {
private:
    static ManejadorViajes* instancia;
    std::map<int, Viaje*> viajes;
    int SiguienteCodigo;

public:
    static ManejadorViajes* getInstance();
    std::set<Viaje*>getViajes();
    std::set<DTListarViaje> getDTListarViajes();
    Viaje* crearViaje(DTFecha fecha, std::string origen, std::string destino, int asientos, float precio,Vehiculo* vehiculo);
    Viaje* getViaje(int codigo);
    bool existeViaje(int codigo);
};

#endif