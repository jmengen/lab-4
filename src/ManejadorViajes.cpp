#include "../include/ManejadorViajes.h"
#include "../include/Viaje.h"
#include <set>

ManejadorViajes* ManejadorViajes::instancia = nullptr;

ManejadorViajes *ManejadorViajes::getInstance(){
    if(instancia == nullptr){
        instancia = new ManejadorViajes();
        instancia->SiguienteCodigo = 1;
    }
    return instancia;
}

std::set<Viaje*> ManejadorViajes::getViajes() {
    std::set<Viaje*> res;
    std::map<int, Viaje*>::iterator it;

    for (it = this->viajes.begin(); it != this->viajes.end(); it++) {
        res.insert(it->second);
    }

    return res;
}

bool ManejadorViajes::existeViaje(int codigo){
        return this->viajes.find(codigo) != this->viajes.end();
}

Viaje* ManejadorViajes::getViaje(int codigo) {
    std::map<int, Viaje*>::iterator it;
    it = this->viajes.find(codigo);

    if (it != this->viajes.end()) {
        return it->second;
    }

    return nullptr;
}

std::set<DTListarViaje> ManejadorViajes::getDTListarViajes() {
    std::set<DTListarViaje> res;
    std::map<int, Viaje*>::iterator it;

    for (it = this->viajes.begin(); it != this->viajes.end(); it++) {
        Viaje* v = it->second;
        res.insert(v->getDTListarViaje());
    }

    return res;
}

Viaje* ManejadorViajes::crearViaje(DTFecha fecha, std::string origen, std::string destino, int asientos, float precio,Vehiculo* vehiculo){
    int codigo = this->SiguienteCodigo;
    this->SiguienteCodigo++;

    Viaje* viaje = new Viaje(codigo, fecha, origen, destino, asientos, precio, vehiculo);
    this->viajes[codigo] = viaje;

    return viaje;
}

void ManejadorViajes::quitarViaje(int codigo) {
    std::map<int, Viaje*>::iterator it = this->viajes.find(codigo);
    if (it != this->viajes.end()) {
        Viaje* viaje = it->second;
        this->viajes.erase(it);
        delete viaje;
    }
}
