#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H
#include <iostream>
#include "Viaje.h"
#include <string>
#include <map>
#include <set>


class ManejadorViajes {
    private:
        static ManejadorViajes* instancia;

        std::set<Viaje> viajes;
        std::map <int, Viaje*> mapViajes;
        ManejadorViajes() = default;

    public:
        static ManejadorViajes* getInstance();
        std::set<Viaje> getViajes();
        bool existeViaje(int codigo);
        Viaje* getViaje(int codigo);
};

#endif