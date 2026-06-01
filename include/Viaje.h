#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include <string>
#include "../include/Vehiculo.h"
#include "../include/Reserva.h"
#include <set>


class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;
    Vehiculo * vehiculo;
    std::set<Reserva> reservas;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    bool ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos);
    ~Viaje();
};

#endif
