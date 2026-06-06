#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include "../include/Conductor.h"
#include <string>
#include "DTFecha.h"
#include "Viaje.h"
#include <set>
#include "DTVehiculosConductor.h"

class Conductor;
class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::set<Viaje*> viajes;
    Conductor* conductor;
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
    DTVehiculosConductor getDTVehiculoConductor();
    bool hayViajesFecha(DTFecha fecha);
    bool hayViajesConductor(DTFecha fecha);
    std::string getNickConductor();
    void asociarViaje(Viaje* viaje);
    void setConductor(Conductor* conductor);
};

#endif