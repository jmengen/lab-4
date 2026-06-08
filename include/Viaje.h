#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include "DTListarViaje.h"
#include "DTDetalleViaje.h"

class Vehiculo;
class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    Vehiculo* vehiculo;
public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo);
    ~Viaje();
    DTListarViaje getDTListarViaje();
    DTFecha getFecha();
    DTDetalleViaje getDTDetalleViaje();
};

#endif
