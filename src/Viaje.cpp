#include "../include/Viaje.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

bool Viaje::ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos){
    return (this->fecha == fecha && this->origen == origen && this->destino == destino && asientos <= this->asientosPublicados);
}

Viaje::~Viaje() {}
