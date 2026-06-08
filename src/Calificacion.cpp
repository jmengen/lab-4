#include "../include/Calificacion.h"
#include "../include/Usuario.h"

Calificacion::Calificacion(DTFecha fecha, int puntaje, Usuario* uCalificado,Usuario* uRealiza){
    this->fecha = fecha;
    this->puntaje = puntaje;
    this->usuarioCalificado = uCalificado;
    this->usuarioRealiza = uRealiza;
}

int Calificacion::getPuntaje() const{
    return this->puntaje;
}

bool Calificacion::esCalif(std::string uRealiza, std::string uCalificado){
    if ((this->usuarioCalificado->getNickname() == uCalificado) && (this->usuarioRealiza->getNickname() == uRealiza))
        return true;
    else return false; 
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
