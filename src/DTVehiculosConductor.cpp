#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string modelo, int capacidad) {
    this->matricula = matricula;
    this->modelo = modelo;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const{
    return this->matricula;

    /*
std::string DTVehiculosConductor::getMatricula() {
    return matricula;
}*/

std::string DTVehiculosConductor::getModelo() {
    return modelo;
}

int DTVehiculosConductor::getCapacidad() {
    return capacidad;
}

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
    return this->matricula < otro.matricula;
}

std::string DTVehiculosConductor::getModelo() const{
    return this->modelo;
}

int DTVehiculosConductor::getCapacidad() const{
    return this->capacidad;
}