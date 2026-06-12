#ifndef MANEJADORVIAJES_H
#define MANEJADORVIAJES_H
#include <iostream>
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
        std::map <int, Viaje*> viajes;
        ManejadorViajes() = default;
        int SiguienteCodigo;


    public:
        static ManejadorViajes* getInstance();
        static void liberarInstancia();
        ~ManejadorViajes();
        std::set<Viaje*> getViajes();
        Viaje * getViaje(int codigo);
        
        bool existeViaje(int codigo);

        std::set<DTListarViaje> getDTListarViajes();
        Viaje* crearViaje(DTFecha fecha, std::string origen, std::string destino, int asientos, float precio,Vehiculo* vehiculo);
        void quitarViaje(int codigo);
};

#endif
