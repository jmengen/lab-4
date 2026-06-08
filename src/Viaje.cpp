#include "../include/Viaje.h"
#include "../include/Reserva.h"
#include "../include/DTConsultaViaje.h"
#include <set>
#include "../include/Vehiculo.h"
#include "DTDetalleVehiculo.h"
#include "../include/Vehiculo.h"
#include "ManejadorViajes.h"
#include "Reserva.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio, Vehiculo* vehiculo) {
    this->codigo = codigo;
    this->fecha = fecha;
    this->origen = origen;
    this->destino = destino;
    this->asientosPublicados = asientosPublicados;
    this->precio = precio;
    this->vehiculo = vehiculo;
}

bool Viaje::ViajeBuscado(DTFecha fecha, std::string origen, std::string destino, int asientos){
    if (this->fecha == fecha && this->origen == origen && this->destino == destino){
        return Entran(asientos);
    } else {
        return false;
    }
}

bool Viaje::Entran(int asientos) const{
    int cantYaReservados = 0;
    std::set<Reserva*>::iterator it;
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it){
        Reserva* actual = *it;
        cantYaReservados += actual->getAsientosReservados();
    } 
    return (cantYaReservados + asientos <= this->asientosPublicados);
}

void Viaje::asociarReserva(Reserva* res){
    this->reservas.insert(res);
}

Reserva* Viaje::asociarReservas(Usuario* u1, Usuario* u2){
    //falta implementar
}

int Viaje::getCodigo() const{
    return this->codigo;
}

DTConsultaViaje Viaje::CrearDTCV(int asientos) const{
    return DTConsultaViaje(this->codigo, vehiculo->getMarca(), vehiculo->getModelo(), vehiculo->getNombreConductor(),vehiculo->getCalifConductor(),this->precio * asientos);
}

Viaje::~Viaje() {}

DTFecha Viaje::getFecha() {
    return this->fecha;
}

DTListarViaje Viaje::getDTListarViaje(){
    return DTListarViaje(this->codigo,this->fecha,this->origen,this->destino,this->vehiculo->getNickConductor());
}

std::set<DTUsuarioViaje> Viaje::obtenerParticipantes(std::string nickRecordado){
    std::set<DTUsuarioViaje> ret;
    
    std::set<Reserva*>::iterator it;
    for (it = this->reservas.begin(); it != this->reservas.end(); ++it){
        Reserva* actual = *it;
        std::string nick = actual->getNickPasajero();
        if (nick != nickRecordado){
            ret.insert(DTUsuarioViaje(nick, TipoPasajero));
        }  
    } 

    std::string nickC = this->vehiculo->getNickConductor();
    if (nickC != nickRecordado){
        ret.insert(DTUsuarioViaje(nickC, TipoConductor));
    }

    return ret;
}

DTDetalleViaje Viaje::getDTDetalleViaje(){
    std::vector<DTDetalleReserva> res;
    return DTDetalleViaje(this->codigo, this->fecha, this->origen, this->destino,  this->asientosPublicados,  this->precio, this->vehiculo->getDTDetalleVehiculo(), res);
}
   
void Viaje::eliminarViaje(){
    if (this->vehiculo != nullptr) {
        this->vehiculo->quitarViaje(this);
    }
    std::set<Reserva*>::iterator it;
    for (it = this->reservas.begin(); it!= this->reservas.end();it++){
       (*it)->eliminarReserva();
    }
}
