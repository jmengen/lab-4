#include "../include/DTVehiculosConductor.h"

DTVehiculosConductor::DTVehiculosConductor(std::string matricula, std::string marca, int capacidad) {
    this->matricula = matricula;
    this->marca = marca;
    this->capacidad = capacidad;
}

std::string DTVehiculosConductor::getMatricula() const{
    return this->matricula;
}

std::string DTVehiculosConductor::getMarca() const{
    return this->marca;
}

int DTVehiculosConductor::getCapacidad() const{
    return this->capacidad;
}

bool DTVehiculosConductor::operator<(const DTVehiculosConductor& otro) const {
    return this->matricula < otro.matricula;
}