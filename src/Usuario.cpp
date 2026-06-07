#include "../include/Usuario.h"
#include "../include/Calificacion.h"

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

float Usuario::getCalificacion() {
    if (this->califica.empty()) {
        return 0;
    }

    int sum = 0;

    std::set<Calificacion*>::iterator it;
    for (it = this->califica.begin(); it != this->califica.end(); ++it) {
        Calificacion* actual = *it;
        sum += actual->getPuntaje();
    }

    this->calificacionPromedio = (float) sum / this->califica.size();
    return this->calificacionPromedio;
}
DTUsuario Usuario::getDTUsuario() const{
    return DTUsuario(this->nickname, this->nombre);
}

void Usuario::addCalCal (Calificacion* c){
    this->califica.insert(c);
}

void Usuario::addCalRea (Calificacion* c){
    this->realiza.insert(c);
}


Usuario::~Usuario() {}

bool Usuario::operator<(const Usuario& otra) const {
    return this->nickname < otra.nickname;
}
