#include "../include/ManejadorReservas.h"
#include "../include/Reserva.h"
#include "../include/Viaje.h"
#include "../include/Pasajero.h"
#include "../include/ControladorFechaActual.h"

ManejadorReservas* ManejadorReservas::instancia = nullptr;

ManejadorReservas *ManejadorReservas::getInstance(){
    if(instancia == nullptr){
        instancia = new ManejadorReservas();
    }
    return instancia;
}

bool ManejadorReservas::NoExisteReserva(Viaje vi, Pasajero p){
    bool ret = true;
    std::set<Reserva>::iterator it;
    for (it = this->reservas.begin(); it != this->reservas.end() && ret; ++it){
        Reserva actual = *it;
        bool e = actual.esReserva(vi,p);
        if (e)
            ret = false;
    } 
    return ret;
}

Reserva ManejadorReservas::CrearReserva(Viaje * vi, Pasajero * p, int asientosReservados){
    ControladorFechaActual * contFech = ControladorFechaActual::getInstance();
    DTFecha fecha = contFech->getFecha();
    Reserva r = Reserva(vi, p, asientosReservados, fecha);
    this->reservas.insert(r);
    return r;
}