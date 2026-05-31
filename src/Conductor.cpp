#include "../include/Conductor.h"

Conductor::Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs)
    : Usuario(nickname, nombre, contrasena, email) {
    this->libretas = libs;
}

std::set<TipoLibreta> Conductor::getLibretas() const{
    return this->libretas;
}

TipoUsuario Conductor::getTipoUsuario() const {
    return TipoConductor;
}

Conductor::~Conductor() {}
