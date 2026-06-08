#include "../include/Calificacion.h"
#include "../include/Usuario.h"
#include "../include/Reserva.h"


Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* uCalificado, Usuario* uRealiza, Reserva* reserva){
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificado = uCalificado;
    this->usuarioRealiza = uRealiza;
    this->reserva = reserva;
}

int Calificacion::getPuntaje() const{
    return this->puntaje;
}

bool Calificacion::esCalif(std::string uRealiza, std::string uCalificado){
    return (this->usuarioCalificado->getNickname() == uCalificado) && (this->usuarioRealiza->getNickname() == uRealiza);
}

bool Calificacion::esCalifEntre(Usuario* uRealiza, Usuario* uCalificado, int codigoViaje){
    if ((this->usuarioCalificado->getNickname() == uCalificado->getNickname()) && (this->usuarioRealiza->getNickname() == uRealiza->getNickname())){
        return this->reserva->esReservaDelViaje(codigoViaje);
    } else {
        return false;
    }
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
