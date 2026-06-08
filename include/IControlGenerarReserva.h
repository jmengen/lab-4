#ifndef ICONTROLGENERARRESERVAS_H
#define ICONTROLGENERARRESERVAS_H
#include "DTConsultaViaje.h"
#include <iostream>
#include <string>
#include <set>
#include <list>
using namespace std;

class IControlGenerarReserva{
    public:
        virtual std::set<std::string> listarPasajeros() = 0;
        virtual std::list<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos) = 0;
        virtual bool generarReserva(std::string nickname, int codigo, int asientos) = 0;
        virtual ~IControlGenerarReserva() = default;
};


#endif