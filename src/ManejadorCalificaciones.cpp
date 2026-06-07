#include "../include/ManejadorCalificaciones.h"
#include "../include/Usuario.h"

ManejadorCalificaciones* ManejadorCalificaciones::instancia = nullptr;

ManejadorCalificaciones* ManejadorCalificaciones::getInstance(){

    if (instancia == nullptr)
        instancia = new ManejadorCalificaciones;
    return instancia;
}


void ManejadorCalificaciones::crearCalificacion(DTFecha fecha, int puntaje, Usuario* uRealiza, Usuario* uCalificado, Reserva* r){
    Calificacion* c = new Calificacion(fecha, puntaje, uCalificado, uRealiza);
    uRealiza->addCalRea(c);
    uCalificado->addCalCal(c);
    r->addCalificacion(c);
    std::string nickCalificado = uCalificado->getNickname();
    this->CalificacionRecibidas[nickCalificado].push_back(c);
}