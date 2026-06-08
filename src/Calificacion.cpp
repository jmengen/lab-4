#include "../include/Calificacion.h"
#include "Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje,Usuario* usuarioRealiza, Usuario*usuarioCalificado, Reserva* reserva) {
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioRealiza = usuarioRealiza;
    this->usuarioCalificado = usuarioCalificado;
    this->reserva = reserva;
}

Calificacion::~Calificacion() {}

void Calificacion::eliminarCalificacion(){
    if (this->usuarioRealiza != nullptr) {
        this->usuarioRealiza->quitarCalificacion(this);
    }
    if (this->usuarioCalificado != nullptr) {
        this->usuarioCalificado->quitarCalificacion(this);
    }
}
