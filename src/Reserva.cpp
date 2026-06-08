#include "../include/Reserva.h"
#include "Pasajero.h"
#include "Calificacion.h"

Reserva::Reserva(int asientosReservados, DTFecha fecha) {
    this->asientosReservados = asientosReservados;
    this->fecha = fecha;
    this->pasajero = nullptr;
}

Reserva::~Reserva() {}

void Reserva::eliminarReserva(){
    if (this->pasajero != nullptr) {
        this->pasajero->quitarReserva(this);
    }
    std::set<Calificacion*>::iterator it;
    for (it = this->calificacion.begin();it != this->calificacion.end(); it++){
        (*it)->eliminarCalificacion();
    }
}
