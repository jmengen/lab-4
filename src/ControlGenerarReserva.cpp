#include "../include/ControlGenerarReserva.h"
using namespace std;

ControlGenerarReserva* ControlGenerarReserva::instancia = nullptr;

ControlGenerarReserva * ControlGenerarReserva::getInstance(){
    if(instancia == nullptr){
        instancia = new ControlGenerarReserva();
    }
    return instancia;
}

std::set<std::string> ControlGenerarReserva::listarPasajeros(){
    ManejadorUsuarios* m = ManejadorUsuarios::getInstance();
    std::set<Pasajero*> p = m->getPasajeros();
    std::set<std::string> ret;
    std::set<Pasajero*>::iterator it;
    for (it = p.begin(); it != p.end(); ++it){
        Pasajero* actual = *it;
        ret.insert(actual->getNickname());
    } 
    return ret;
}

std::list<DTConsultaViaje> ControlGenerarReserva::consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos){
    ManejadorViajes* m = ManejadorViajes::getInstance();
    std::set<Viaje*> vis = m->getViajes();

    std::list<DTConsultaViaje> ret;

    std::set<Viaje*>::iterator it;
    for (it = vis.begin(); it != vis.end(); ++it){
        Viaje* actual = *it;
        bool cond = actual->ViajeBuscado(fecha, origen, destino, asientos);
        if(cond){
            DTConsultaViaje dtcv = actual->CrearDTCV(asientos);
            ret.push_front(dtcv);
        }
    } 
    ret.sort();
    return ret; 
}


bool ControlGenerarReserva::generarReserva(std::string nickname, int codigo, int asientos){
    ManejadorViajes* v = ManejadorViajes::getInstance();
    Viaje * vi = v->getViaje(codigo);
    ManejadorUsuarios* u = ManejadorUsuarios::getInstance();
    Usuario * usu = u->getUsuario(nickname);
    Pasajero * p = static_cast<Pasajero*>(usu);
    bool cond = vi->Entran(asientos);
    ManejadorReservas* r = ManejadorReservas::getInstance();
    if(cond){
        cond = r->NoExisteReserva(*vi,*p);
    }
    if(cond){
        Reserva* res = r->CrearReserva(vi,p,asientos);
        vi->asociarReserva(res);
        p->asociarReserva(res);
    }
    return cond;
}

ControlGenerarReserva::~ControlGenerarReserva() {}