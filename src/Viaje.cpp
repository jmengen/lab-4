#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include "../include/DTConsultaViaje.h"
#include <set>
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

bool Viaje::ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos) const{
    if (this->fecha == fecha && this->origen == origen && this->destino == destino){
        return Entran(asientos);
    } else {
        return false;
    }
}

bool Viaje::Entran(int asientos) const{
    int cantYaReservados = 0;
    std::set<Reserva>::iterator it;
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it){
        Reserva actual = *it;
        cantYaReservados += actual.getAsientosReservados();
    } 
    return (cantYaReservados + asientos <= this->asientosPublicados);
}

void Viaje::asociarReserva(Reserva res){
    this->reservas.insert(res);
}

int Viaje::getCodigo() const{
    return this->codigo;
}

DTConsultaViaje  Viaje::CrearDTCV(int asientos) const{
    return DTConsultaViaje(this->codigo, vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getNombreConductor(),vehiculo->getCalifConductor(),this->precio * asientos);
}

Viaje::~Viaje() {}

DTFecha Viaje::getFecha() {
    return this->fecha;
}

DTListarViaje Viaje::getDTListarViaje(){
    return DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,this->vehiculo->getNickConductor());
}
