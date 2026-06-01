#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include <set>

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
}

bool Viaje::ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos){
    if (this->fecha == fecha && this->origen == origen && this->destino == destino){
        int cantYaReservados = 0;
        std::set<Reserva>::iterator it;
        for (it = this->reservas.begin(); it != this->reservas.end(); ++it){
            Reserva actual = *it;
            cantYaReservados += actual.getAsientosReservados();
        } 
        return (cantYaReservados + asientos <= this->asientosPublicados);
    } else {
        return false;
    }
}

Viaje::~Viaje() {}
