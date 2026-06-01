#include "../include/Reserva.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
}

Reserva::~Reserva() {}

int Reserva::getAsientosReservados() const{
    return this->asientosReservados;
}
