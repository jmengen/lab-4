#include "../include/Pasajero.h"
#include "../include/Reserva.h"
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

void Pasajero::asociarReserva(Reserva* res){
    this->reservas.insert(res);
}

Pasajero::~Pasajero() {}

void Pasajero::quitarReserva(Reserva* r){
     this->reservas.erase(r);
}

std::set<DTListarViaje> Pasajero::obtenerDTListarViaje() {
    std::set<DTListarViaje> ret;

    std::set<Reserva*>::iterator it;
    for (it = this->reservas.begin(); it != this->reservas.end(); it++) {
        Reserva* actual = *it;
        ret.insert(actual->getDTViaje());
    }
    return ret;
}