#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre)
    {
    this->nickname = nickname;
    this->nombre = nombre;
}

bool DTUsuario::operator<(const DTUsuario& otra) const{
    return this->nickname < otra.nickname;
}

std::string DTUsuario::getNickname() { return nickname; }
std::string DTUsuario::getNombre() { return nombre; }
