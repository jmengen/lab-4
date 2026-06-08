#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>
#include "DTFecha.h"
#include "Viaje.h"
#include <set>
#include "DTVehiculosConductor.h"
#include "DTDetalleVehiculo.h"

class Conductor;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;
    std::set<Viaje*> viajes;
    Conductor * conductor;
public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    std::string getMatricula() const;
    int getCapacidad() const;
    std::string getMarca() const;
    std::string getModelo() const;
    TipoVehiculo getTipo() const;

    std::string getNombreConductor() const;
    std::string getNickConductor() const;
    float getCalifConductor() const;
    
    bool hayViajesFecha(DTFecha fecha);
    bool hayViajesConductor(DTFecha fecha);
    
    void asociarViaje(Viaje* viaje);
    void setConductor(Conductor* conductor);
    DTDetalleVehiculo getDTDetalleVehiculo();
    void quitarViaje(Viaje* vi);

    DTVehiculosConductor getDTVehiculoConductor() const;
    std::set<DTListarViaje> getDTListarViaje() const;

    bool operator<(const Vehiculo& otra) const;

    ~Vehiculo();
};

#endif