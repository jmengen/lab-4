#include "../include/Calificacion.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje) {
    this->fecha = fecha;
    this->puntaje = puntaje;
}

int Calificacion::getPuntaje() const{
    return this->puntaje;
}

Calificacion::~Calificacion() {}
