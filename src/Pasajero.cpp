#include "../include/Pasajero.h"
#include "Reserva.h"
#include <set>

Pasajero::Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento)
    : Usuario(nickname, nombre, contrasena, email) {
    this->ci = documento;
}
std::string Pasajero::getCi() const{
    return this->ci;
}

TipoUsuario Pasajero::getTipoUsuario() const {
    return TipoPasajero;
}

Pasajero::~Pasajero() {}

void Pasajero::quitarReserva(Reserva* r){
     this->reserva.erase(r);
}