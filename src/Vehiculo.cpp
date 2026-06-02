#include "../include/Vehiculo.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
}
std::string Vehiculo::getMatricula() const{
    return this->matricula;
}

int Vehiculo::getCapacidad() const{
    return this->capacidad;
}

std::string Vehiculo::getMarca() const{
    return this->marca;
}

std::string Vehiculo::getModelo() const{
    return this->modelo;
}

TipoVehiculo Vehiculo::getTipo() const{
    return this->tipo;
}

std::string Vehiculo::getNombreConductor() const{
    return this->conductor->getNombre();
}

float Vehiculo::getCalifConductor() const{
    return this->conductor->getCalificacion();
}

Vehiculo::~Vehiculo() {}