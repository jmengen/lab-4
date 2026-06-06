#ifndef VIAJE_H
#define VIAJE_H

#include "Vehiculo.h"
#include "Reserva.h"
#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTConsultaViaje.h"
#include "DTUsuarioViaje.h"
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
    void asociarReserva(Reserva res);
    DTFecha getFecha();
    int getCodigo() const;

    bool ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos) const;
    bool Entran(int asientos) const;

    DTConsultaViaje CrearDTCV(int asientos) const;
    DTListarViaje getDTListarViaje();
    std::set<DTUsuarioViaje> obtenerParticipantes(std::string nickRecordado);
    
    ~Viaje();
};

#endif
