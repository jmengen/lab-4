#ifndef CONTROLGENERARRESERVAS_H
#define CONTROLGENERARRESERVAS_H
#include "IControlGenerarReserva.h"
#include "ManejadorUsuarios.h"
#include "ManejadorViajes.h"
#include "ManejadorReservas.h"
#include "DTConsultaViaje.h"
#include <iostream>
#include <vector>

class ControlGenerarReserva : public IControlGenerarReserva{
    private:
        static ControlGenerarReserva * instancia;
        ControlGenerarReserva() = default;

    public:
        static ControlGenerarReserva * getInstance();

        std::set<std::string> listarPasajeros();
        std::list<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
        bool generarReserva(std::string nickname, int codigo, int asientos);
        ~ControlGenerarReserva();
};

#endif