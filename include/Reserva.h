#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Pasajero;
class Viaje;

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

    DTListarViaje getDTViaje() const;

    std::string getNickPasajero() const;
    bool operator<(const Reserva& otra) const;
};

#endif
