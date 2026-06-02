#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "../include/Conductor.h"
#include <string>

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    Conductor * conductor;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    std::string getMatricula() const;
    int getCapacidad() const;
    std::string getMarca() const;
    std::string getModelo() const;
    TipoVehiculo getTipo() const;
    std::string getNombreConductor() const;
    float getCalifConductor() const;
    ~Vehiculo();
};

#endif