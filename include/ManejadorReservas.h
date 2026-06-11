#ifndef MANEJADORRESERVAS_H
#define MANEJADORRESERVAS_H
#include <iostream>
#include "Reserva.h"
#include <string>
#include <map>
#include <set>


class ManejadorReservas {
    private:
        static ManejadorReservas* instancia;

        std::set<Reserva*> reservas;
        ManejadorReservas() = default;

    public:
        static ManejadorReservas* getInstance();

        Reserva * obtenerReservaEntre(Pasajero* pas, Viaje * vi);

        bool NoExisteReserva(Viaje vi, Pasajero p);
        Reserva* CrearReserva(Viaje * vi, Pasajero * p, int asientosReservados);
        void quitarReserva(Reserva* reserva);
};

#endif
