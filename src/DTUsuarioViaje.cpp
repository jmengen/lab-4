#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->tipo = tipo;
}

bool DTUsuarioViaje::operator<(const DTUsuarioViaje& otra) const{
    return this->nickname < otra.nickname;
}

std::string DTUsuarioViaje::getNickname() { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() { return tipo; }
