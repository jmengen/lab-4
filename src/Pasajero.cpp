#include "../include/Pasajero.h"

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

void Pasajero::asociarReserva(Reserva res){
    this->reservas.insert(res);
}

Pasajero::~Pasajero() {}
