#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include <set>

class Pasajero;
class Viaje;
class Calificacion;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero * pasajero;
    Viaje * viaje;
    std::set<Calificacion*> calificaciones;

public:
    Reserva(Viaje * vi, Pasajero * p, int asientosReservados, DTFecha fecha);
    ~Reserva();
    void eliminarReserva();
    bool esReserva(Viaje v, Pasajero p) const;
    int getAsientosReservados() const;

    DTListarViaje getDTViaje() const;

    std::string getNickPasajero() const;
    bool operator<(const Reserva& otra) const;
    void addCalificacion (Calificacion *c);
};

#endif
