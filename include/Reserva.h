#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero * pasajero;
    Viaje * viaje;

public:
    Reserva(Viaje * vi, Pasajero * p, int asientosReservados, DTFecha fecha);
    ~Reserva();
    bool esReserva(Viaje v, Pasajero p) const;
    int getAsientosReservados() const;
};

#endif
