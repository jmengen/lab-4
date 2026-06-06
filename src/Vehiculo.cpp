#include "../include/Vehiculo.h"
#include "../include/DTVehiculosConductor.h"
#include <set>
#include "../include/Viaje.h"
#include "../include/Conductor.h"

Vehiculo::Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo) {
    this->matricula = matricula;
    this->capacidad = capacidad;
    this->marca = marca;
    this->modelo = modelo;
    this->tipo = tipo;
    this->conductor = nullptr;
}
std::string Vehiculo::getMatricula() const{
    return this->matricula;
}

int Vehiculo::getCapacidad() const{
    return this->capacidad;
}

std::string Vehiculo::getMarca() const{
    return this->marca;
}

std::string Vehiculo::getModelo() const{
    return this->modelo;
}

TipoVehiculo Vehiculo::getTipo() const{
    return this->tipo;
}

std::string Vehiculo::getNombreConductor() const{
    return this->conductor->getNombre();
}

float Vehiculo::getCalifConductor() const{
    return this->conductor->getCalificacion();
}

Vehiculo::~Vehiculo() {}

DTVehiculosConductor Vehiculo::getDTVehiculoConductor(){
    DTVehiculosConductor res(this->matricula,this->modelo,this->capacidad);
    return res;
}

bool Vehiculo::hayViajesFecha(DTFecha fecha){
    for (std::set<Viaje*>::iterator it = this->viajes.begin(); it!=this->viajes.end();++it) {
        Viaje* v = *it;
        if (v->getFecha() == fecha){
            return true;
        }
    } return false;
}

bool Vehiculo::hayViajesConductor(DTFecha fecha){
    if (this->conductor == nullptr){
        return false;
    }
    return this->conductor->hayViajesFechaConductor(fecha);
}

std::string Vehiculo::getNickConductor() {
    if (this->conductor == nullptr) {
        return "";
    }
    return this->conductor->getNickname();
}

void Vehiculo::asociarViaje(Viaje* viaje){
    this->viajes.insert(viaje);
}

void Vehiculo::setConductor(Conductor* conductor) {
    this->conductor = conductor;
}
