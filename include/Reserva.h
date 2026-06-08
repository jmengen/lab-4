#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include <set>

class Pasajero;
class Calificacion;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;
    Pasajero* pasajero;
    std::set<Calificacion*> calificacion;
public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();
    void eliminarReserva();
};

#endif
