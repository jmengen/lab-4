#include "../include/ManejadorCalificaciones.h"
#include "../include/Usuario.h"

ManejadorCalificaciones* ManejadorCalificaciones::instancia = nullptr;

ManejadorCalificaciones* ManejadorCalificaciones::getInstance(){

    if (instancia == nullptr)
        instancia = new ManejadorCalificaciones;
    return instancia;
}


Calificacion * ManejadorCalificaciones::crearCalificacion(DTFecha fecha, int puntaje, Usuario* uRealiza, Usuario* uCalificado, Reserva* r){
    Calificacion* c = new Calificacion(fecha, puntaje, uCalificado, uRealiza, r);
    uRealiza->addCalRea(c);
    uCalificado->addCalCal(c);
    r->addCalificacion(c);
    std::string nickCalificado = uCalificado->getNickname();
    this->CalificacionRecibidas[nickCalificado].push_back(c);
}

bool ManejadorCalificaciones::existeCalifEntre(Usuario* uRealiza, Usuario* uCalificado, int codigoViaje){
    std::list<Calificacion*> listaCalificaciones = this->CalificacionRecibidas[uCalificado->getNickname()];
    std::list<Calificacion*>::iterator it;
    for (it = listaCalificaciones.begin(); it != listaCalificaciones.end(); ++it){
        Calificacion* actual = *it;
        if (actual->esCalifEntre(uRealiza, uCalificado,codigoViaje)){
            return true;
        } 
    }
   return false; 
}