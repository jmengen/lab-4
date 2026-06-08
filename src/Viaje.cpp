#include "../include/Viaje.h"
#include "../include/Vehiculo.h"
#include "DTDetalleVehiculo.h"
#include "../include/Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = vehiculo;
}

Viaje::~Viaje() {}
DTFecha Viaje::getFecha() {
    return this->fecha;
}

DTListarViaje Viaje::getDTListarViaje(){
 return DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,this->vehiculo->getNickConductor());
}

DTDetalleViaje Viaje::getDTDetalleViaje(){
    std::vector<DTDetalleReserva> res;
    return DTDetalleViaje(this->codigo, this->fecha, this->origen, this->destino,  this->asientosPublicados,  this->precio, this->vehiculo->getDTDetalleVehiculo(), res);
}

