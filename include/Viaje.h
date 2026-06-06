#ifndef VIAJE_H
#define VIAJE_H

#include "Vehiculo.h"
#include "Reserva.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include <string>
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
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo);
    bool ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos) const;
    bool Entran(int asientos) const;
    void asociarReserva(Reserva res);
    int getCodigo() const;
    DTConsultaViaje CrearDTCV(int asientos) const;
    DTListarViaje getDTListarViaje();
    DTFecha getFecha();
    ~Viaje();
};

#endif
