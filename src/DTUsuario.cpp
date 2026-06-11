#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre, TipoUsuario tipo)
    {
    this->nickname = nickname;
    this->nombre = nombre;
    this->tipo = tipo;
}

bool DTUsuario::operator<(const DTUsuario& otra) const{
    if (this->tipo != otra.tipo) {
        return this->tipo < otra.tipo;
    }
    return this->nickname < otra.nickname;
}

std::string DTUsuario::getNickname() { return nickname; }
std::string DTUsuario::getNombre() { return nombre; }
