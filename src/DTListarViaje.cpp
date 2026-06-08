#include "../include/DTListarViaje.h"

DTListarViaje::DTListarViaje(int codigo, DTFecha fecha, std::string origen, std::string destino, std::string conductor) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->conductor = conductor;
}

int DTListarViaje::getCodigo() const { 
    return codigo; 
}
DTFecha DTListarViaje::getFecha() const { 
    return fecha; 
}
std::string DTListarViaje::getOrigen() const { 
    return origen; 
}
std::string DTListarViaje::getDestino() const { 
    return destino; 
}
std::string DTListarViaje::getConductor() const {
     return conductor; 
}
bool DTListarViaje::operator<(const DTListarViaje& otro) const {
    return this->codigo < otro.codigo;
}
