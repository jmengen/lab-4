#include "../include/Reserva.h"

Reserva::Reserva(Viaje * vi, Pasajero * p, int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = p;
    this->viaje = vi;
}

Reserva::~Reserva() {}

int Reserva::getAsientosReservados() const{
    return this->asientosReservados;
}

bool Reserva::esReserva(Viaje v, Pasajero p) const{
    return(this->pasajero->getNickname() == p.getNickname() && this->viaje->getCodigo() == v.getCodigo());
}

DTListarViaje Reserva::getDTViaje() const{
    return this->viaje->getDTListarViaje();
}

std::string Reserva::getNickPasajero() const{
    if (this->pasajero == nullptr) {
        return "";
    }
    return this->pasajero->getNickname();
}
