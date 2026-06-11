#include "../include/DTUsuarioViaje.h"

DTUsuarioViaje::DTUsuarioViaje(std::string nickname, TipoUsuario tipo, int orden)
    {
    this->nickname = nickname;
    this->tipo = tipo;
    this->orden = orden;
}

bool DTUsuarioViaje::operator<(const DTUsuarioViaje& otra) const{
    if (this->tipo != otra.tipo) {
        return this->tipo < otra.tipo;
    }
    if (this->orden != otra.orden) {
        return this->orden > otra.orden;
    }
    return this->nickname < otra.nickname;
}

std::string DTUsuarioViaje::getNickname() const { return nickname; }
TipoUsuario DTUsuarioViaje::getTipo() const { return tipo; }
