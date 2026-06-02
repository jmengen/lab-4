#include "../include/Usuario.h"

Usuario::Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email) {
    this->nickname = nickname;
    this->nombre = nombre;
    this->contrasena = contrasena;
    this->email = email;
}

std::string Usuario::getNickname() const{
    return this->nickname;
}

std::string Usuario::getNombre() const{
    return this->nombre;
}

std::string Usuario::getContrasena() const{
    return this->contrasena;
}

std::string Usuario::getEmail() const{
    return this->email;
}

float Usuario::getCalificacion() const{
    return this->calificacionPromedio;
}

Usuario::~Usuario() {}
