#ifndef CONTROLGENERARRESERVAS_H
#define CONTROLGENERARRESERVAS_H
#include "IControlGenerarReserva.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"
#include "ManejadorReservas.h"
#include "DTConsultaViaje.h"
#include <iostream>

class ControlGenerarReserva : public IControlGenerarReserva{
    public:
        std::set<std::string> listarPasajeros();
        std::set<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
        bool generarReserva(std::string nickname, int codigo, int asientos);
        ~ControlGenerarReserva();
};

#endif