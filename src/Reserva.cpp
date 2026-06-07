#include "../include/Reserva.h"
#include "../include/Pasajero.h"
#include "../include/Viaje.h"

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

bool Reserva::operator<(const Reserva& otra) const {
    if (this->pasajero->getNickname() != otra.pasajero->getNickname()) {
        return this->pasajero->getNickname() < otra.pasajero->getNickname();
    }

    return this->viaje->getCodigo() < otra.viaje->getCodigo();
}

void Reserva::addCalificacion(Calificacion *c){
    this->calificaciones.insert(c);
}